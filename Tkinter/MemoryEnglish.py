from tkinter import *
import random

path = "/Users/chris/Desktop/Database/Testing/"
eng = []
chi = []
cnt = 0
regi = 0
score = 0


tf = ("Helvetica",16)
fgc = "#AAAEEE"
hlbg = "#444444"

root = Tk()
root.title("ENG MEMORY")

def Rand():
    global regi
    regiStr = ""
    regi = random.randint(0,cnt-1)
    storageStr = eng[regi]
    print(storageStr)
    print(len(storageStr))
    regiStr += "*"
    for j in range (1,len(storageStr)):
        x = random.randint(0,1)
        if (x):
            regiStr += storageStr[j]
        else:
            regiStr += "*"
    inE.delete(0, END)
    engshow.config(text = regiStr)
    chishow.config(text = chi[regi])

def dataGet():
    global regi,score
    ipt = inE.get()
    if (ipt == eng[regi]):
        score += 1
    scoreShow.config(text = str(score))
    scoreShow.grid(row = 2,column = 0)
    Rand()

def dataEntry(event):
    dataGet()
    
if "__main__" == __name__:
    fi = open(path + "WordList.txt","r")
    for i in fi:
        index = i.find(' ')
        key = i[:index]
        val = i[index:].strip("\n")
        eng.append(key)
        chi.append(val)
        cnt += 1
    print(eng)
    print(chi)
    inE = Entry(root)
    inE.bind("<Return>",dataEntry)
    inE.grid(row = 3,column = 0)
    next = Button(root,text = "NEXT",font = tf,foreground = fgc,highlightbackground = hlbg,command = lambda:dataGet())
    next.grid(row = 4,column = 0)
    engshow = Label(root,text = eng[regi])
    engshow.grid(row = 0,column = 0)
    chishow = Label(root,text = chi[regi])
    chishow.grid(row = 1,column = 0)
    scoreShow = Label(root,text = str(score))
    scoreShow.grid(row = 2,column = 0)
    Rand()
    root.mainloop()