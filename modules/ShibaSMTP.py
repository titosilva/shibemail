import socket
from ShibaTCP import ShibaTCPClient

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
        self.__stream = ShibaTCPClient()

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
    def setHelo(self, helo: str):
        self.__helo = helo

    # Functions that get private values
    def getMailFrom(self):
        return self.__mailfrom
    def getRcptTo(self):
        return self.__rcptto
    def getServerAddr(self):
        return self.__serveraddr
    def getSMTPPort(self):
        return self.__smtpport
    def setHelo(self, helo: str):
        return self.__helo

    # Send message contained in msg
    def send(self, msg: str):
        try:
            self.__stream.connect(self.__serveraddr, self.__smtpport)
        except:
            raise

        # Receives the first message
        received = self.__stream.getMessage(1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 220:
            raise SMTPError

        # HELO message
        received = self.__stream.require('HELO ' + self.__helo + '\r\n', 1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 250:
            raise SMTPHeloError
        
        # MAIL FROM message
        received = self.__stream.require('MAIL FROM: <' + self.__mailfrom + '> \r\n', 1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 250:
            raise SMTPMailFromError

        # RCPT TO message
        received = self.__stream.require('RCPT TO: <' + self.__mailfrom + '> \r\n', 1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 250:
            raise SMTPRcptToError

        # DATA message
        received = self.__stream.require('DATA \r\n', 1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 354:
            raise SMTPDataError

        received = self.__stream.require(msg+'\r\n.\r\n', 1024)

        # Verifies if received message was fine
        if not int(received[0:3]) == 250:
            raise SMTPDataError

        self.__stream.sendMessage('quit\r\n')
        