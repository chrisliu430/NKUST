from tkinter import *

def decreasePos():
    global initPos,status
    status = 0
    if (initPos == 0):
        initPos = len(dat)-1
    else:
        initPos -= 1
    createData()

def increasePos():
    global initPos,status
    status = 0
    if (initPos != len(dat)-1):
        initPos += 1
    else:
        initPos = 0
    createData()

def addData():
    global initPos,status
    status = 1
    for i in range (5):
        naEnt[i].delete(0,END)

def delData():
    global initPos,status
    status = 2
    

def refreshData():
    global initPos,status
    if (status == 1):
        ''' Function 1 Add New Data '''
        fout = open("/Users/chris/Desktop/Database/Testing/BaseData.txt","a")
        print(file = fout)
        for i in range (2):
            regiDat = naEnt[i].get()
            print(regiDat,end = " ",file = fout)
        regiDat = varCon.get()
        if (regiDat == 0):
            print("Man",end = " ",file = fout)
        else:
            print("Female",end = " ",file = fout)
        for i in range (2,5):
            regiDat = naEnt[i].get()
            if (i < 4):
                print(regiDat,end = " ",file = fout)
            else:
                print(regiDat,end = "",file = fout)
        fout.close()
    elif (status == 2):
        ''' Function 2 Delete Exist Data From Now '''
        del dat[initPos]
        initPos = 0
        fout = open("/Users/chris/Desktop/Database/Testing/BaseData.txt","w")
        for i in range (len(dat)):
            if (i != 0):
                print(file = fout)
            for j in range (len(dat[i])):
                if (j < len(dat[i])-1):
                    print(dat[i][j],end = " ",file = fout)
                else:
                    print(dat[i][j],end = "",file = fout)
        fout.close()
        #print(dat)
    else:
        ''' Check Data have Change '''
        for i in range (2):
            regiDat = naEnt[i].get()
            if (dat[initPos][i] != regiDat):
                dat[initPos][i] = regiDat;
        regiDat = varCon.get()
        if (regiDat == 0):
            if (dat[initPos][2] != "Man"):
                dat[initPos][2] = "Man";
        else:
            if (dat[initPos][2] != "Female"):
                dat[initPos][2] = "Female";
        for i in range (3,6):
            regiDat = naEnt[i-1].get()
            if (dat[initPos][i] != regiDat):
                dat[initPos][i] = regiDat;
        fout = open("/Users/chris/Desktop/Database/Testing/BaseData.txt","w")
        for i in range (len(dat)):
            if (i != 0):
                print(file = fout)
            for j in range (len(dat[i])):
                if (j < len(dat[i])-1):
                    print(dat[i][j],end = " ",file = fout)
                else:
                    print(dat[i][j],end = "",file = fout)
        fout.close()
    for i in range (len(dat)-1,-1,-1):
        del dat[i]
    fi = open("/Users/chris/Desktop/Database/Testing/BaseData.txt","r")
    for i in fi:
        dat.append(i.strip("\n").split(" "))
    fi.close()
    createData()
    status = 0

def createData():
    global initPos
    if (dat[initPos][2] == "Man"):
        varCon.set(0)
    else:
        varCon.set(1)
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
    root.title("DatabasePro")
    varCon = IntVar()
    varCon.set(0)
    fi = open("/Users/chris/Desktop/Database/Testing/BaseData.txt","r")
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
        elif (i > 2):
            naEnt[i].insert(0,dat[initPos][i])
            naEnt[i].grid(row = i,column = 1)
    for i in range (2):
        che.append(Radiobutton(root,text = chiceMF[i],variable = varCon,value = i))
        che[i].grid(row = 2,column = i)
    incBtn = Button(root,text = "Next",width = 10,height = 2,command = lambda:increasePos())
    incBtn.grid(row = 6,column = 0)
    decBtn = Button(root,text = "Previous",width = 10,height = 2,command = lambda:decreasePos())
    decBtn.grid(row = 6,column = 1)
    addBtn = Button(root,text = "Add",width = 10,height = 2,command = lambda:addData())
    addBtn.grid(row = 7,column = 0)
    delBtn = Button(root,text = "Delete",width = 10,height = 2,command = lambda:delData())
    delBtn.grid(row = 7,column = 1)
    reBtn = Button(root,text = "Refresh",width = 28,height = 2,command = lambda:refreshData())
    reBtn.grid(row = 8,column = 0,columnspan = 2)
    createData()
    root.geometry("250x340")
    root.mainloop()