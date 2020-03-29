from tkinter import *
from threading import Timer
import random

modeT = [40,35,25,15,10]
tInitPos = 0
hamCls = ["X","Y","Z"]
hamBtn = []
hamSta = []
scrNum = 0
hCls = 0
tNum = 0
cnter = 0
stgNum = 1
hM = 0
cntScr = 0

def checkData(dat,x,y):
    global hCls,scrNum,cntScr
    hamBtn[x][y].config(state = "disable")
    if (hCls+1 != dat and scrNum != 0):
        scrNum -= 1
        scrShow.set(str(scrNum))
    elif (hCls+1 == dat):
        scrNum += 1
        cntScr += 1
        scrShow.set(str(scrNum))
    else:
        scrNum = 0
        scrShow.set(str(scrNum))

def clearAll():
    for i in range (10):
        for j in range (10):
            hamBtn[i][j].config(text = "",state = "disable",highlightbackground = "White")
            hamSta[i][j] = 0

def initBtn():
    global hCls,hM
    for i in range (len(hamCls)):
        if (i == hCls):
            hM = random.randint(1,15)
            hamClsLab.config(text = hamCls[hCls] + "/" + str(hM))
            for m in range (hM):
                while(1):
                    xPos = random.randint(0,9)
                    yPos = random.randint(0,9)
                    if (hamSta[xPos][yPos] == 0):
                        hamSta[xPos][yPos] = i + 1
                        hamBtn[xPos][yPos].config(text = hamCls[i],highlightbackground = "Blue",state = "active",command = lambda wH = i + 1,x = xPos,y = yPos:checkData(wH,x,y))
                        break
        else:
            randNum = random.randint(1,15)
            for m in range (randNum):
                while(1):
                    xPos = random.randint(0,9)
                    yPos = random.randint(0,9)
                    if (hamSta[xPos][yPos] == 0):
                        hamSta[xPos][yPos] = i + 1
                        hamBtn[xPos][yPos].config(text = hamCls[i],state = "active",command = lambda wH = i + 1,x = xPos,y = yPos:checkData(wH,x,y))
                        break

def timerControl():
    global tInitPos,cnter,stgNum,hCls,tNum,hM,cntScr,scrNum,cntScr
    stgLab.config(text = str(stgNum) + "/5")
    tNum = int(modeT[tInitPos])-int(cnter)
    timerLab.config(text = str(tNum))
    t = Timer(1,timerControl)
    t.start()
    if (cnter == 0):
        clearAll()
        initBtn()
    elif (cnter == int(modeT[tInitPos]) or hM == cntScr):
        tInitPos += 1
        cntScr = 0
        cnter = 0
        stgNum += 1
        tNum = 0
        t.cancel()
        if (stgNum != 6):
            chooseHamCls()
        else:
            for i in range (10):
                for j in range (10):
                    hamBtn[i][j].config(text = "",state = "disable")
                    hamSta[i][j] = 0
            hamBtn[4][3].config(text = "G",foreground = "black")
            hamBtn[4][4].config(text = "A",foreground = "black")
            hamBtn[4][5].config(text = "M",foreground = "black")
            hamBtn[4][6].config(text = "E",foreground = "black")
            hamBtn[5][3].config(text = "O",foreground = "black")
            hamBtn[5][4].config(text = "V",foreground = "black")
            hamBtn[5][5].config(text = "E",foreground = "black")
            hamBtn[5][6].config(text = "R",foreground = "black")
            hamBtn[5][7].config(text = "!",foreground = "black")
    cnter += 1

def chooseHamCls():
    global hCls
    hCls = random.randint(0,2)
    timerControl()

if "__main__" == __name__:
    root = Tk()
    root.title("HamsterPromote")
    for i in range (10):
        hamBtn.append([])
        hamSta.append([])
        for j in range (10):
            hamBtn[i].append(Button(state = "disable",width = 2,height = 2))
            hamBtn[i][j].grid(row = i + 1,column = j)
            hamSta[i].append(0)
    stgLab = Label(root)
    stgLab.grid(row = 0,column = 0,columnspan = 5)
    hamClsLab = Label(root)
    hamClsLab.grid(row = 0,column = 5,columnspan = 5)
    timerLab = Label(root)
    timerLab.grid(row = 11,column = 0,columnspan = 5)
    scrShow = StringVar()
    scrShow.set(str(scrNum))
    scoreLab = Label(root,textvariable = scrShow)
    scoreLab.grid(row = 11,column = 5,columnspan = 5)
    chooseHamCls()
    root.mainloop()