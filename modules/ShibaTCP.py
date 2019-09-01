# Using sockets to create a tcp connection for the client
import socket

class ShibaTCPClient(object):
    # Creates a socket and sets the state to not connected
    def __init__(self):
        self.__socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__connected = False

    # Connects to a server through the socket
    def connectToServer(self, host: str, port: int):
        if self.__connected:
            self.__socket.close()

        try:
            self.__socket.connect((host, port))
            self.__connected = True
        except:
            self.__connected = False
            raise

    # Only receives a message of max size answerlength and returns it
    def getMessage(self, answerlength: int) -> bytes:
        if not self.__connected:
            raise Exception("Not connected to a server!")
        
        return self.__socket.recv(answerlength)

    # Only sends a message
    def sendMessage(self, message):
        if not self.__connected:
            raise Exception("Not connected to a server!")
        
        self.__socket.send(bytes(message, encoding='ascii'))

    # Sends a Message and returns server answer as bytes
    def require(self, query, answerlength: int) -> bytes:
        if not self.__connected:
            raise Exception("Not connected to a server!")

        self.sendMessage(query)
        return self.getMessage(answerlength)

    def __del__(self):
        if self.__connected:
            self.__socket.close()
