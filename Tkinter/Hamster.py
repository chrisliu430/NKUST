from tkinter import *
from threading import Timer
import random

btn = []

stgn = 1

start = 1
cnt = 1

score = 0

soeX = []

tf = ("Helvetica",16)
fgc = "#AAAEEE"
hlbg = "#444444"
bW = 1
bH = 1

def btnCik(x,y):
    global score
    score += 1
    sct.set(str(score))
    btn[x][y].config(state = "disabled")

def incre():
    global cnt,stgn
    btnAr()
    for i in range (len(soeX)):
        del soeX[-1]
    rand()
    stgt = StringVar()
    stgt.set(str(stgn) + "/5")
    stg = Label(frame,textvariable = stgt,width = 5,height = 2)
    stg.grid(row = 0,column = 0,columnspan = 5)
    t = Timer(5,incre)
    t.start()
    while (cnt == 5):
        t.cancel()
        #frame.destory()
    stgn += 1
    cnt += 1

def rand():
    sta = 1
    n = random.randint(1,10)
    x = random.randint(0,9)
    y = random.randint(0,9)
    btnSet(x,y)
    hnt = StringVar()
    hnt.set(str(n))
    hn = Label(frame,textvariable = hnt,width = 5,height = 2)
    hn.grid(row = 0,column = 5,columnspan = 5)
    soeX.append(x)
    for i in range (n-1):
        while (1):
            x = random.randint(0,9)
            y = random.randint(0,9)
            for j in range (len(soeX)):
                if (soeX[j] == x):
                    sta = 1
                    break
                else:
                    sta = 0
            if (sta == 0):
                sta = 1
                btnSet(x,y)
                break

def btnSet(x,y):
    btn[x][y].config(text = "X",state = "active")
    btn[x][y].grid(row = x+1,column = y)
    btn[x][y].config(command = lambda:btnCik(x,y))

def btnAr():
    for i in range (10):
        for j in range (10):
            btn[i][j].config(text = "")
            btn[i][j].config(state = "disabled")


if "__main__" == __name__:
    frame = Tk()
    frame.title("Hamster")
    if (start):
        start = 0
        for i in range (10):
            btn.append([])
            for j in range (10):
                btn[i].append(Button())
                btn[i][j].config(text = "",width = bW,height = bH,font = tf,foreground = fgc,highlightbackground = hlbg)
                btn[i][j].config(state = "disabled")
                btn[i][j].grid(row = i+1,column = j)
        incre()
    sct = StringVar()
    sct.set(str(score))
    sc = Label(frame,textvariable = sct,width = 10,height = 2)
    sc.grid(row = 11,column = 0,columnspan = 10)
    frame.mainloop()