import socket

class SMTPStream(object):
    def __init__(self, serveraddr, port):
        self.__serveraddr = serveraddr
        self.__port = port