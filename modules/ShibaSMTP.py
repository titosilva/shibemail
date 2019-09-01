import socket
from ShibaDomains import IPAddress

class SMTPMail(object):
    def __init__(self, mailfrom: str, rcptto: str, serveraddr: str = '127.0.0.1', smtpport: int = 25):
        self.__mailfrom = mailfrom
        self.__rcptto = rcptto
        self.__serveraddr = serveraddr
        self.__smtpport = smtpport

    def setMailFrom(self, mailfrom: str):
        self.__mailfrom = mailfrom
    def setRcptTo(self, rcptto: str):
        self.__rcptto = rcptto
    def setServerAddr(self, serveraddr: str):
        self.__serveraddr = serveraddr
    def setSMTPPort(self, smtpport: int):
        self.__smtpport = smtpport

    def send(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp:
            # Connects to the server
            try:
                tcp.connect((self.__serveraddr, self.__smtpport))
            except:
                print("Could not connect to server!")
                return 0
            received = tcp.recv(1024)
            # Verifies if server Answer is fine
            if not int(received[0:3]) == 220:
                return 0
            print(received)
            tcp.send(b'quit')
            tcp.close()

if __name__ == "__main__":
    teste = SMTPMail("ratchet@test.com", "ratchet@shibemail.com")
    teste.send()
