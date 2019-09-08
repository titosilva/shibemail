import tkinter as tk
import tkinter.messagebox
from modules.ShibaSMTP import *

# Função que pega o conteudo escrito em From, To e Body, quando Send é apertado
def send_click():
    From = FromEntry.get()
    To = ToEntry.get()
    Mensagem = Body.get('1.0','end')

    try:
        mail = ShibaSMTPMail(From, To)
        mail.setServerAddr(ServerAddrEntry.get())
        mail.send(Mensagem)
    except ShibaSMTPNoConnection:
        tk.messagebox.showerror("Shibemail error", "Could not connect to given server!")
    except ShibaSMTPRcptToError:
        tk.messagebox.showerror("Shibemail Error", "Rcpt to adress incorrect!")
    except ShibaSMTPMsgError:
        tk.messagebox.showerror("Shibemail Error", "Cannot send message to this server")
    except ShibaSMTPError:
        tk.messagebox.showerror("Shibemail Error", "An Error ocurred")
    else:
        print('mensagem enviada!')

root = tk.Tk()
root.title("Welcome to Shibemail :)")
HEIGHT = 720
WIDTH = 1280
canvas = tk.Canvas(root, height=HEIGHT, width=WIDTH)
canvas.pack()

background_image = tk.PhotoImage(file='BG.png')
background_label = tk.Label(root, image=background_image)
background_label.place(relwidth=1, relheight=1)

ServerAddrLabel = tk.Label(root,text="Server Address:",bg='#fce5ac',font=40)
ServerAddrLabel.place(relx=0.075,rely=0.225, relheight=0.05, relwidth=0.1)

ServerAddrEntry = tk.Entry(root, font=40)
ServerAddrEntry.place(relx=0.185,rely=0.225,relwidth=0.54, relheight=0.04)

FromLabel = tk.Label(root,text="From :",bg='#fce5ac',font=40)
FromLabel.place(relx=0.1,rely=0.295, relheight=0.05, relwidth=0.1)

FromEntry = tk.Entry(root, font=40)
FromEntry.place(relx=0.185,rely=0.3,relwidth=0.54, relheight=0.04)


ToLabel = tk.Label(root,text="To :",bg='#fce5ac',font=40)
ToLabel.place(relx=0.11,rely=0.365, relheight=0.05, relwidth=0.1)

ToEntry = tk.Entry(root, font=40)
ToEntry.place(relx=0.185,rely=0.37,relwidth=0.54, relheight=0.04)

DescripitonLabel = tk.Label(root,text="Descripiton :",bg='#fce5ac',font=40)
DescripitonLabel.place(relx=0.081,rely=0.435, relheight=0.05, relwidth=0.1)

Descripiton= tk.Entry(root, font=40)
Descripiton.place(relx=0.185,rely=0.44,relwidth=0.54, relheight=0.04)

BodyLabel = tk.Label(root,text="Body :",bg='#fce5ac',font=40)
BodyLabel.place(relx=0.1,rely=0.505, relheight=0.05, relwidth=0.1)

Body= tk.Text(root, font=40 )
Body.place(relx=0.185,rely=0.51,relwidth=0.54, relheight=0.32)

#----------------------- esse command que eu coloquei, teoricamente ele abriria a funçao quando Send fosse precionado
Send = tk.Button(root, text="Send", bg='#FFB778',font=1,activebackground='#E06906', command=send_click)
Send.place(relx=0.85,rely=0.88, relheight=0.05, relwidth=0.1)

root.mainloop()
