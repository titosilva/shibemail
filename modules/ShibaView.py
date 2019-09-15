# This module is loaded in the beginning of the execution and is the program itself
# It implements the GUI and its interactions with the other modules
import tkinter as tk
import tkinter.messagebox
from tkinter import filedialog

import os

from modules.ShibaSMTP import *
from modules.ShibaMIME import *

# Container da mensagem
mimemail = ShibaMIME()

def add_Image_click():
    pathtofile = tk.filedialog.askopenfilename(initialdir='/', title='Select Image File', filetypes=(("Image files", "*.jpg *.jpeg *.png *.bmp"),("All Files", "*")))
    if os.path.isfile(str(pathtofile)):
        try:
            mimemail.addImage(pathtofile)
            tk.messagebox.showinfo("Shibemail", "File loaded successfully!")
        except:
            tk.messagebox.showerror("Shibemail error", "Could not open file!")

def text_File_click():
    pathtofile = tk.filedialog.askopenfilename(initialdir='/', title='Select Text File', filetypes=(("Text Files", "*.txt"), ("All Files", "*")))
    if os.path.isfile(pathtofile):
        try:
            mimemail.addTextFile(pathtofile)
            tk.messagebox.showinfo("Shibemail", "File loaded successfully!")
        except:
            tk.messagebox.showerror("Shibemail error", "Could not open file!")

def reset_click():
    ToEntry.delete(0, tk.END)
    FromEntry.delete(0, tk.END)
    SubjectEntry.delete(0, tk.END)
    Body.delete("1.0", 'end')

# This function handles the process of sending the mail
# First, it gets the informations from the entries where
# the user writes the Server Address, Mail From, Destination
# and the mail itself
def send_click():
    From = FromEntry.get()
    To = ToEntry.get()
    Message = Body.get('1.0','end')
    Subject = SubjectEntry.get()

    try:
        if mimemail.getNumOfObjects() > 0:
            mail = ShibaSMTPMail(From, To)
            mail.setServerAddr(ServerAddrEntry.get())

            mimemail.addTextFromString(Message)
            mimemail.setFrom(From)
            mimemail.setTo(To)
            mimemail.setSubject(Subject)

            mail.send(mimemail.getMessageAsString())
        else:
            mail = ShibaSMTPMail(From, To)
            mail.setServerAddr(ServerAddrEntry.get())
            mail.send(Message)
    except ShibaSMTPNoConnection:
        tk.messagebox.showerror("Shibemail error", "Could not connect to server!")
    except ShibaSMTPRcptToError:
        tk.messagebox.showerror("Shibemail Error", "Rcpt to adress incorrect!")
    except ShibaSMTPMsgError:
        tk.messagebox.showerror("Shibemail Error", "Cannot send message to this server")
    except ShibaSMTPError:
        tk.messagebox.showerror("Shibemail Error", "An Error ocurred")
    else:
        tk.messagebox.showinfo("Shibemail", "Mail sent successfully!")

# Building the GUI using tkinter module
root = tk.Tk()
root.title("Welcome to Shibemail :)")
HEIGHT = 720
WIDTH = 1280
canvas = tk.Canvas(root, height=HEIGHT, width=WIDTH)
canvas.pack()

# Loads background Image and sets it
background_image = tk.PhotoImage(file='BG.png')
background_label = tk.Label(root, image=background_image)
background_label.place(relwidth=1, relheight=1)

# Server Address Entry
ServerAddrLabel = tk.Label(root,text="Server Address:",bg='#fce5ac',font=40)
ServerAddrLabel.place(relx=0.075,rely=0.225, relheight=0.05, relwidth=0.1)

ServerAddrEntry = tk.Entry(root, font=40)
ServerAddrEntry.place(relx=0.185,rely=0.225,relwidth=0.54, relheight=0.04)

# From Entry
FromLabel = tk.Label(root,text="From :",bg='#fce5ac',font=40)
FromLabel.place(relx=0.1,rely=0.295, relheight=0.05, relwidth=0.1)

FromEntry = tk.Entry(root, font=40)
FromEntry.place(relx=0.185,rely=0.3,relwidth=0.54, relheight=0.04)

# To Entry
ToLabel = tk.Label(root,text="To :",bg='#fce5ac',font=40)
ToLabel.place(relx=0.11,rely=0.365, relheight=0.05, relwidth=0.1)

ToEntry = tk.Entry(root, font=40)
ToEntry.place(relx=0.185,rely=0.37,relwidth=0.54, relheight=0.04)

# Subject Entry
SubjectLabel = tk.Label(root,text="Subject :",bg='#fce5ac',font=40)
SubjectLabel.place(relx=0.095,rely=0.435, relheight=0.05, relwidth=0.1)

SubjectEntry = tk.Entry(root, font=40)
SubjectEntry.place(relx=0.185,rely=0.435,relwidth=0.54, relheight=0.04)

# Message (body)
BodyLabel = tk.Label(root,text="Mail :",bg='#fce5ac',font=40)
BodyLabel.place(relx=0.1,rely=0.505, relheight=0.05, relwidth=0.1)

Body= tk.Text(root, font=40 )
Body.place(relx=0.185,rely=0.51,relwidth=0.54, relheight=0.32)

# Send button
Send = tk.Button(root, text="Send", bg='#FFB778',font=1,activebackground='#E06906', command=send_click)
Send.place(relx=0.85,rely=0.88, relheight=0.05, relwidth=0.1)

# Reset button
Reset = tk.Button(root, text="Clear Entries", bg='#FFB778',font=1,activebackground='#E06906', command=reset_click)
Reset.place(relx=0.725,rely=0.88, relheight=0.05, relwidth=0.1)

# AddImage button
AddImage = tk.Button(root, text="Add Image", bg='#FFB778',font=1,activebackground='#E06906', command=add_Image_click)
AddImage.place(relx=0.2,rely=0.88, relheight=0.05, relwidth=0.2)

# From Text File button
AddTextFile = tk.Button(root, text="Add Text File", bg='#FFB778',font=1,activebackground='#E06906', command=text_File_click)
AddTextFile.place(relx=0.5,rely=0.88, relheight=0.05, relwidth=0.2)

root.mainloop()
