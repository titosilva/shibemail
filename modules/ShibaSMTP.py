import socket

class SMTPError(Exception):
    pass

class SMTPNoConnection(SMTPError):
    pass

class SMTPHeloError(SMTPError):
    pass
        
class SMTPMailFromError(SMTPError):
    pass

class SMTPRcptToError(SMTPError):
    pass

class SMTPDataError(SMTPError):
    pass

class SMTPMsgError(SMTPError):
    pass

class SMTPPortError(SMTPError):
    pass

class SMTPMail(object):
    # Constructor
    def __init__(self, mailfrom: str, rcptto: str, serveraddr: str = '127.0.0.1', smtpport: int = 25, helo: str = 'shibemail.com'):
        self.__mailfrom = mailfrom
        self.__rcptto = rcptto
        self.__serveraddr = serveraddr
        self.__smtpport = smtpport
        self.__helo = helo

    # Functions that set private values
    def setMailFrom(self, mailfrom: str):
        self.__mailfrom = mailfrom
    def setRcptTo(self, rcptto: str):
        self.__rcptto = rcptto
    def setServerAddr(self, serveraddr: str):
        self.__serveraddr = serveraddr
    def setSMTPPort(self, smtpport: int):
        if smtpport<65535 and smtpport>0:
            self.__smtpport = smtpport
        else:
            raise SMTPPortError

    # Functions that get private values
    def getMailFrom(self):
        return self.__mailfrom
    def getRcptTo(self):
        return self.__rcptto
    def getServerAddr(self):
        return self.__serveraddr
    def getSMTPPort(self):
        return self.__smtpport

    # Send message contained in msg
    def send(self, msg: str):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp:
            # Tries to connect to the server
            try:
                tcp.connect((self.__serveraddr, self.__smtpport))
            except:
                tcp.close()
                raise SMTPNoConnection
            
            received = tcp.recv(1024)

            # Verifies if server Answer is fine
            if not int(received[0:3]) == 220:
                tcp.close()
                raise SMTPError

            print(1)
            print(received)

            # Send Helo
            tcp.send(b'helo shibemail.com\r\n')
            received = tcp.recv(1024)

            # Verifies if server Answer to Helo is fine
            if not int(received[0:3]) == 250:
                tcp.send(b'quit')
                tcp.close()
                raise SMTPHeloError

            print(1)
            print(received)

            # Send mail from
            tcp.send(bytes('mail from: <' + self.__mailfrom + '> \r\n', encoding='ascii'))
            received = tcp.recv(1024)

            # Verifies if server Answer to mail from is fine
            if not int(received[0:3]) == 250:
                tcp.send(b'quit')
                tcp.close()
                raise SMTPMailFromError

            print(1)

            # Send rcpt to
            tcp.send(bytes('rcpt to: <' + self.__rcptto + '> \r\n', encoding='ascii'))
            received = tcp.recv(1024)

            # Verifies if server Answer to rcpt tp is fine
            if not int(received[0:3]) == 250:
                tcp.send(b'quit')
                tcp.close()
                raise SMTPRcptToError

            print(1)
            print(received
            )
            # Send 'data'
            tcp.send(b'data\r\n')
            received = tcp.recv(1024)

            # Verifies server answer to 'data'
            if not int(received[0:3]) == 354:
                tcp.send(b'quit')
                tcp.close()
                raise SMTPDataError

            # Sends the message
            tcp.send(bytes(msg + '\r\n.\r\n', encoding='ascii'))
            received = tcp.recv(1024)
            
            # Verifies server answer to message sent
            if not int(received[0:3]) == 250:
                tcp.send(b'quit')
                tcp.close()
                raise SMTPMsgError

            print(received)

            # Closes communication
            tcp.send(b'quit\r\n')

            received = tcp.recv(1024)
            print(received)
            
            tcp.close()

if __name__ == "__main__":
    teste = SMTPMail(mailfrom = "ratchet@test.com", rcptto = "ratchet@shibemail.com")
    try: 
        teste.send('sent from shibasmtp mod')
    except SMTPNoConnection:
        print('Could not connect to server!')
    except:
        raise
