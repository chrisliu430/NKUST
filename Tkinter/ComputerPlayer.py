# Examination
from tkinter import *
from random import randint

storage = ["剪刀","石頭","布"]

start = 1
star = []
faCnt = 0
winCnt = 0
flaCnt = 0

def winPrint(x):
    global faCnt,winCnt,flaCnt
    com = randint(0,2)
    print(storage[com])
    if (com == x):
        flaCnt += 1
        dpS.set("玩家"+storage[x]+"  電腦"+storage[com]+"  目前玩家"+str(winCnt)+"勝"+str(faCnt)+"負"+str(flaCnt)+"平")
    elif ((com == 0 and x == 1) or (com == 1 and x == 2) or (com == 2 and x == 0)):
        winCnt += 1
        dpS.set("玩家"+storage[x]+"  電腦"+storage[com]+"  目前玩家"+str(winCnt)+"勝"+str(faCnt)+"負"+str(flaCnt)+"平")
    else:
        faCnt += 1
        dpS.set("玩家"+storage[x]+"  電腦"+storage[com]+"  目前玩家"+str(winCnt)+"勝"+str(faCnt)+"負"+str(flaCnt)+"平")
        
if "__main__" == __name__:
    root = Tk()
    dpS = StringVar()
    dpS.set("目前玩家"+str(winCnt)+"勝"+str(faCnt)+"負"+str(flaCnt)+"平")
    if (start == 1):
        winShow = Label(textvariable = dpS)
        winShow.grid(row = 0,column = 0,columnspan = 3)
        for i in range (3):
            star.append(Button(text = storage[i]))
            star[i].config(command = lambda x = i:winPrint(x))
            star[i].grid(row = 1,column = i)
        start = 0
    root.mainloop()
