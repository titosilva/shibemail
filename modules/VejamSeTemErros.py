import tkinter as tk
root = tk.Tk()

# Função que pega o conteudo escrito em From, To e Body, quando Send é apertado
def Send_click():
    print("entrou no Send_Click \n")
    From = From.get()
    To = To.get()
    Mensagem = Body.get()
    #Um if pra entrar somente se todas caixas estão com texto
    #if((len(From) > 0) && (len(To) > 0) && (len(Mensagem > 0)):
    mail = ShibaSMTPMail(From, To)
    mail.send(Mensagem)



HEIGHT = 720
WIDTH = 1280
canvas = tk.Canvas(root, height=HEIGHT, width=WIDTH)
canvas.pack()

background_image = tk.PhotoImage(file='BG.png')
background_label = tk.Label(root, image=background_image)
background_label.place(relwidth=1, relheight=1)

FromLabel = tk.Label(root,text="From :",bg='#fce5ac',font=40)
FromLabel.place(relx=0.1,rely=0.295, relheight=0.05, relwidth=0.1)

From = tk.Entry(root, font=40)
From.place(relx=0.185,rely=0.3,relwidth=0.54, relheight=0.04)


ToLabel = tk.Label(root,text="To :",bg='#fce5ac',font=40)
ToLabel.place(relx=0.11,rely=0.365, relheight=0.05, relwidth=0.1)

To = tk.Entry(root, font=40)
To.place(relx=0.185,rely=0.37,relwidth=0.54, relheight=0.04)

DescripitonLabel = tk.Label(root,text="Descripiton :",bg='#fce5ac',font=40)
DescripitonLabel.place(relx=0.081,rely=0.435, relheight=0.05, relwidth=0.1)

Descripiton= tk.Entry(root, font=40)
Descripiton.place(relx=0.185,rely=0.44,relwidth=0.54, relheight=0.04)

BodyLabel = tk.Label(root,text="Body :",bg='#fce5ac',font=40)
BodyLabel.place(relx=0.1,rely=0.505, relheight=0.05, relwidth=0.1)

Body= tk.Text(root, font=40 )
Body.place(relx=0.185,rely=0.51,relwidth=0.54, relheight=0.32)

#----------------------- esse command que eu coloquei, teoricamente ele abriria a funçao quando Send fosse precionado
Send = tk.Button(root, text="Send", bg='#FFB778',font=1,activebackground='#E06906', command=Send_click)
Send.place(relx=0.85,rely=0.88, relheight=0.05, relwidth=0.1)

root.mainloop()
