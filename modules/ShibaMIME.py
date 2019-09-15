# Here we implement the MIME format for images
import os
from email.mime.image import MIMEImage
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

class ShibaMIMEError(Exception):
    pass

class ShibaMIMEBadPath(ShibaMIMEError):
    pass

class ShibaMIMEFileNotRead(ShibaMIMEError):
    pass

class ShibaMIME(object):
    def __init__(self, from__: str = '', to__: str = '', subject__: str = ''):
        self.__msg = MIMEMultipart()
        self.setFrom(from__)
        self.setTo(to__)
        self.setSubject(subject__)
        self.__numofobj = 0

    # Set Header informations
    def setFrom(self, _from: str):
        self.__msg['From'] = _from
    def setTo(self, _to: str):
        self.__msg['To'] = _to
    def setSubject(self, _subject: str):
        self.__msg['Subject'] = _subject

    # Returns the MIME text to be sent or processed
    def getMessageAsString(self) -> str:
        return self.__msg.as_string()
    def getMessageAsBytes(self) -> bytes:
        return self.__msg.as_bytes()

    # Returns the current number of objects
    def getNumOfObjects(self):
        return self.__numofobj

    # Opens a file, reads its content and attaches it to the MIME file
    def addImage(self, pathToFile: str):
        if not os.path.isfile(pathToFile):
            raise ShibaMIMEBadPath
        else:
            with open(pathToFile, 'rb') as fp:
                try:
                    img = MIMEImage(fp.read())
                    self.__msg.attach(img)
                    self.__numofobj = self.__numofobj+1
                except:
                    raise ShibaMIMEFileNotRead

    # Opens a file, reads its content and attaches it to the MIME file
    def addTextFile(self, pathToFile: str):
        if not os.path.isfile(pathToFile):
            raise ShibaMIMEBadPath
        else:
            with open(pathToFile, 'r') as fp:
                try:
                    textmime = MIMEText(fp.read())
                    self.__msg.attach(textmime)
                    self.__numofobj = self.__numofobj+1
                except:
                    raise ShibaMIMEFileNotRead

    # Appends text from string to MIME file
    def addTextFromString(self, text: str):
        textmime = MIMEText(text)
        self.__msg.attach(textmime)
        self.__numofobj = self.__numofobj+1

if __name__ == "__main__":
    test = ShibaMIME("Alguem", "Voce")
    test.addTextFromString("Jesus te ama")
    # test.addImage("/home/titosilva/Pictures/ratchet_logo.png")
    # test.addTextFromString("Jesus te ama muito mesmo")
    print(test.getMessageAsString())


