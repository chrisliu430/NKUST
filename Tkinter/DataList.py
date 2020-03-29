from tkinter import *

def decreasePos():
    global initPos
    if (initPos == 0):
        initPos = len(dat)-1
    else:
        initPos -= 1
    createData()

def increasePos():
    global initPos
    if (initPos != len(dat)-1):
        initPos += 1
    else:
        initPos = 0
    createData()

def createData():
    global initPos
    if (dat[initPos][2] == "Man"):
        varCon.set(0)
    else:
        varCon.set(1)
    for i in range (2):
        che.append(Radiobutton(root,text = chiceMF[i],variable = varCon,value = i))
        che[i].grid(row = 2,column = i)
    for i in range (5):
        if (i < 2):
            naEnt[i].delete(0,END)
            naEnt[i].insert(0,dat[initPos][i])
            naEnt[i].grid(row = i,column = 1)
        else:
            naEnt[i].delete(0,END)
            naEnt[i].insert(0,dat[initPos][i+1])
            naEnt[i].grid(row = i+1,column = 1)

if __name__ == "__main__":
    tyLab = []
    naEnt = []
    che = []

    tyNa = ["Number","Name","Department","Address","Phone Number"]
    chiceMF = ["Man","Female"]

    dat = []
    initPos = 0
    status = 0
    root = Tk()
    root.title("Database")
    varCon = IntVar()
    varCon.set(0)
    fi = open("/Users/chris/Desktop/TextData/Testing/Py-PersonalData.txt","r")
    for n in fi:
        dat.append(n.strip("\n").split(" "))
    fi.close()
    for i in range (5):
        tyLab.append(Label(text = tyNa[i],width = 10,height = 2))
        if (i < 2):
            tyLab[i].grid(row = i,column = 0)
        else:
            tyLab[i].grid(row = i+1,column = 0)
    for i in range (5):
        naEnt.append(Entry(width = 15))
        if (i < 2):
            naEnt[i].insert(0,dat[initPos][i])
            naEnt[i].grid(row = i,column = 1)
        else:
            naEnt[i].insert(0,dat[initPos][i+1])
            naEnt[i].grid(row = i+1,column = 1)
    incBtn = Button(root,text = "Next",width = 10,height = 2,command = lambda:increasePos())
    incBtn.grid(row = 6,column = 0)
    decBtn = Button(root,text = "Previous",width = 10,height = 2,command = lambda:decreasePos())
    decBtn.grid(row = 6,column = 1)
    createData()
    root.geometry("250x280")
    root.mainloop()