#| Python GUI Course |#
#|-KeyBorad---------X|#
from tkinter import *
from tkinter import messagebox

# Button List
eBtn = []
nBtn = []
sBtn = []

# Symbol of Button
em = []
syb = ["+","-","*","/","="]
nSyb = ["<-","*Lock","Enter","7","8","9","4","5","6","1","2","3","0",".","Clear"]
nSyP = 0

rgS = []
noS = 0

s = ""

# State Control
pos = 0 # EnglishMode
eSta = 0 # English Caps Lock
eBSta = 0 # English Disabled
nSta = 0 # Number Disabled
start = 0 # Initial Setup

tf = ("Helvetica",16)
fgc = "#AAAEEE"
hlbg = "#444444"
btnW = 5
btnH = 2

def func(x):
    global rgS,noS,s
    s = ""
    if (x == 1):
        if (noS != 0):
            if (rgS[-1] != "@"):
                del rgS[-1]
                for i in range (len(rgS)):
                    if (rgS[i] != "@"):
                        s += str(rgS[i])
                    else:
                        s += str("\n")
                dpS.set(s)
            else:
                del rgS[-1]
                for i in range (len(rgS)):
                    if (rgS[i] != "@"):
                        s += str(rgS[i])
                    else:
                        s += str("\n")
                dpS.set(s)
            noS -= 1
        elif (noS == 0):
            messagebox.showwarning(title = "Error",message = "No Any Chars.")
    elif (x == 2):
        for i in range (len(rgS)-1,-1,-1):
            del rgS[i]
        dpS.set("")
        s = ""
    elif (x == 3):
        rgS.append("@")
        #rgS = dpy.cget("text") + str(event.widget["text"])
        #print(rgS)
        #for i in range(len(rgS)):
            #dpy['text']=dpy.cget()+rgs[i]
        for i in range (len(rgS)):
            if (rgS[i] != "@"):
                s += str(rgS[i])
            else:
                s += str("\n")
        dpS.set(s)
        noS += 1

def eShow(event):
    global rgS,noS,s
    s = ""

    rgS.append(str(event.widget["text"]))
    for i in range (len(rgS)):
        if (rgS[i] != "@"):
            s += str(rgS[i])
        else:
            s += str("\n")
    dpS.set(s)
    noS += 1

def nShow(event):
    global rgS,noS,s,nSta
    if (nSta == 0):
        s = ""
        rgS.append(str(event.widget["text"]))
        for i in range (len(rgS)):
            if (rgS[i] != "@"):
                s += str(rgS[i])
            else:
                s += str("\n")
        dpS.set(s)
        noS += 1

def sShow(event):
    global rgS,noS,s
    s = ""
    rgS.append(str(event.widget["text"]))
    for i in range (len(rgS)):
        if (rgS[i] != "@"):
            s += str(rgS[i])
        else:
            s += str("\n")
    dpS.set(s)
    noS += 1

def eLock():
    global eSta,eStart
    if (eSta == 0):
        eSta = 1
        for i in range (26):
            n = i + 97
            em[i] = chr(n)
    else:
        eSta = 0
        for i in range (26):
            n = i + 65
            em[i] = chr(n)
    eKbBtn()
    nKbBtn()

def disBtn():
    global eBSta
    if (eBSta == 0):
        for i in range (3):
            for j in range (9):
                eBtn[i][j].config(state = "disabled")
        eBSta = 1
    else:
        for i in range (3):
            for j in range (9):
                eBtn[i][j].config(state = "active")
        eBSta = 0

def nLock():
    global nSta
    if (nSta == 1):
        for i in range (5):
            sBtn[i].config(state = "active")
        for i in range (1,5):
            for j in range (3):
                nBtn[i][j].config(state = "active")
        nSta = 0
    elif (nSta == 0):
        for i in range (5):
            sBtn[i].config(state = "disabled")
        for i in range (1,5):
            for j in range (3):
                nBtn[i][j].config(state="disabled")
        nSta = 1

def eKbBtn():
    global pos
    for i in range (3):
        eBtn.append([])
        for j in range (9):
            eBtn[i].append(Button())
            eBtn[i][j].config(text = em[pos],width = btnW,height = btnH,font = tf,foreground = fgc,highlightbackground = hlbg)
            eBtn[i][j].grid(row = i+2,column = j)
            if (i != 2 or j != 8):
                eBtn[i][j].bind("<Button-1>",eShow)
            pos += 1
    eBtn[2][8].config(command = lambda:eLock())
    pos = 0

def nKbBtn():
    global nSyP,sInSta
    for i in range (5):
        nBtn.append([])
        for j in range (3):
            nBtn[i].append(Button())
            nBtn[i][j].config(text = nSyb[nSyP],width = btnW,height = btnH)
            nBtn[i][j].config(font = tf,foreground = fgc,highlightbackground = hlbg)
            nBtn[i][j].grid(row = i,column = j + 9)
            nSyP += 1
    for i in range (1,5):
        for j in range (3):
            nBtn[i][j].bind("<Button-1>",nShow)
            if (i == 4 and j == 1):
                break
    nBtn[0][0].config(command = lambda:func(1))
    nBtn[0][1].config(command = lambda:nLock())
    nBtn[0][2].config(command = lambda:func(3))
    nBtn[4][2].config(command = lambda:func(2))
    for i in range (5):
        sBtn.append(Button())
        sBtn[i].config(text = syb[i],width = btnW,height = btnH,font = tf,foreground = fgc,highlightbackground = hlbg)
        sBtn[i].grid(row = i,column = 12)
        sBtn[i].bind("<Button-1>",sShow)

kb = Tk()
kb.title("KeyBorad")
if (start == 0):
    for i in range (26):
        n = i + 97
        em.append(chr(n))
    em.append("Caps")
    eLock()
    start = 1
dpS = StringVar()
dpS.set("")
dpy = Label(kb,textvariable = dpS,width = btnW*13,height = btnH*2,wraplength = 300,justify = "center",font = tf)
dpy.grid(row = 0,column = 0,columnspan = 9,rowspan = 2)
kb.mainloop()
