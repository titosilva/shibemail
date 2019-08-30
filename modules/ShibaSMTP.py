import socket
from ShibaDomains import IPAddress

class SMTPStream(object):
    def __init__(self, serveraddr='127.0.0.1', port=25):
        self.__serveraddr = serveraddr
        self.__smtpport = port
    def setServerAddr(self, serveraddr):
        #Verify if the given address is actually an IP address
        if IPAddress.validateIP(serveraddr):
            self.__serveraddr = serveraddr
    def setPort(self, port):
        if IPAddress.validatePort(port):
            self.__smtpport = port
