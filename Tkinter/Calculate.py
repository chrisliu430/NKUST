from tkinter import *
# Examination
start = 1
sta = 1
s = ""

nBtn = []
sBtn = []
rgS = []

syb = ["+","-","*","/","="]
nSyb = ["7","8","9","4","5","6","1","2","3","0"]

def showNum(event):
    global rgS,s,nSta,sta
    if (sta == 1):
        rgS = []
        s = ""
        dpS.set(s)
        show = Label(textvariable = dpS)
    s = ""
    rgS.append(str(event.widget["text"]))
    for i in range (len(rgS)):
        s += str(rgS[i])
    dpS.set(s)
    sta = 0

def total(event):
    global sta
    #print(show.cget("text"))
    regi = eval(show.cget("text"))
    dpS.set(str(regi))
    show.config(textvariable = dpS)
    sta = 1
    
if "__main__" == __name__:
    root = Tk()
    root.title("")
    if (start == 1):
        dpS = StringVar()
        dpS.set("")
        show = Label(textvariable = dpS)
        show.grid(row = 0,column = 0,columnspan = 10)
        for i in range (10):
            nBtn.append(Button(text = str(i)))
            nBtn[i].bind("<Button-1>",showNum)
            nBtn[i].grid(row = 1,column = i)
        for i in range (5):
            sBtn.append(Button(text = syb[i]))
            if (i == 4):
                sBtn[i].bind("<Button-1>",total)
                sBtn[i].grid(row = 2,column = i)
            else:
                sBtn[i].bind("<Button-1>",showNum)
                sBtn[i].grid(row = 2,column = i)                
        start = 0
    root.mainloop()
