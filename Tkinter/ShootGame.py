from tkinter import *
from tkinter import messagebox
from threading import Timer
import random as rand

bulBtn = []

bul = []
coBul = []
regi = 0

data = []
rePos = 0
cntBul = 0
live = 10

change = 1

tf = ("Helvetica",16)
fgc = "#AAAEEE"
hlbg = "#444444"
bW = 2
bH = 2

#fi = open("~/Desktop/Course/py_tk/Py-ShootData.txt","r")
fi = open("/Users/chris/Desktop/Course/py_tk/Py-ShootData.txt","r")

def chkIpt(event):
    checkInput()

def timeCon():
    global live
    control = 0
    t = Timer(1,timeCon)
    t.start()
    if (live == 0):
        gMod.config(text = "GAME OVER")
        inE.config(state = "disabled")
        gMod.grid(row = 0,column = 0,columnspan = 10)
        t.cancel()
        control = 1
    else:
        gMod.config(text = "GAMING")
        gMod.grid(row = 0,column = 0,columnspan = 10)
        posRand()
    if (control):
        messagebox.showinfo("SHOOT GAME","Bullet Score:" + str(cntBul))
        control = 0
    
def posRand():
    global regi
    regi = rand.randint(0,9)
    posPro()

def posPro():
    global regi,live
    for i in range (9):
        for j in range (10):
            coBul[i+1][j] = bul[i][j]
    coBul[0][regi] = 1
    for i in range (10):
        for j in range (10):
            bul[i][j] = coBul[i][j]
    for i in range (10):
        for j in range (10):
            coBul[i][j] = 0
    for i in range (10):
        for j in range (10):
            if (bul[i][j] == 1):
                bulBtn[i][j].config(text = "V",width = bW,height = bH,state = "disabled")
                bulBtn[i][j].grid(row = i+1,column = j)
            else:
                bulBtn[i][j].config(text = "",width = bW,height = bH,state = "disabled")
                bulBtn[i][j].grid(row = i+1,column = j)
    for i in range (10):
        if (bul[9][i] == 1):
            live -= 1
            break
    dataShow()

def dataShow():
    global rePos,cntBul,live,change
    if (change):
        rePos = rand.randint(0,len(data)-1)
        show.config(text = data[rePos])
        show.grid(row = 11,column = 0,columnspan = 5)
        change = 0
    bulCnt.config(text = "Bullet:" + str(cntBul))
    bulCnt.grid(row = 12,column = 0,columnspan = 5)
    health.config(text = "Live:" + str(live))
    health.grid(row = 12,column = 5,columnspan = 5)

def checkInput():
    global rePos,cntBul,change
    check = 0
    ipt = inE.get()
    if (ipt == data[rePos]):
        correct = 1
    else:
        correct = 0
    if (correct):
        for i in range (9,-1,-1):
            for j in range (10):
                if (bul[i][j] == 1):
                    bul[i][j] = 0
                    cntBul += 1
                    check = 1
                    break
            if (check):
                check = 0
                break
        correct = 0
    for i in range (10):
        for j in range (10):
            if (bul[i][j] == 1):
                bulBtn[i][j].config(text = "V",width = bW,height = bH,state = "disabled")
                bulBtn[i][j].grid(row = i+1,column = j)
            else:
                bulBtn[i][j].config(text = "",width = bW,height = bH,state = "disabled")
                bulBtn[i][j].grid(row = i+1,column = j)
    inE.delete(0,END)
    change = 1
    dataShow()

if __name__ == "__main__":
    root = Tk()
    root.title("Shoot Game")
    show = Label()
    health = Label()
    bulCnt = Label()
    gMod = Label()
    inE = Entry(width = 10)
    inE.bind("<Return>",chkIpt)
    inE.grid(row = 11,column = 5,columnspan = 5)
    for i in range (10):
        bul.append([])
        coBul.append([])
        bulBtn.append([])
        for j in range (10):
            bul[i].append(0)
            coBul[i].append(0)
            bulBtn[i].append(Button())
    for i in fi:
        data.append(i.strip("\n"))
    timeCon()
    dataShow()
    root.mainloop()