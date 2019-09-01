# This file handles different file requests
import os

class ShibaFiles:
    path_sentmail = "../mailstorage/sent"
    path_receivedmail = "../mailstorage/received"

    @staticmethod
    def verifyPaths():
        if not os.path.exists(ShibaFiles.path_receivedmail):
            os.mkdir(ShibaFiles.path_receivedmail)
        if not os.path.exists(ShibaFiles.path_sentmail):
            os.mkdir(ShibaFiles.path_sentmail)

    @staticmethod
    def listSentMails():
        ShibaFiles.verifyPaths()
        if 

    @staticmethod
    def saveToSentMails(title, date, text):
        ShibaFiles.verifyPaths()
