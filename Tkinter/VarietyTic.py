#| Python GUI Source |#
#|-------------------|#
#|-Variety Tic------X|#      #|-Variety Tic------------X|# -
#| |---| |---| |---| |#      #| |---| |---| |---| |---| |# |
#|                   |#      #|                         |#
#| |---| |---| |---| |# <+>  #| |---| |---| |---| |---| |#
#|                   |# ---> #|                         |# 4
#| |---| |---| |---| |#      #| :.... :.... :.... :.... |#
#|                   |#      #|                         |#
#| |- RESET -| |-+-| |#      #| |---  RESET  ---| |-+-| |# |
#|-------------------|#      #|-------------------------|# _
from tkinter import *
import random

btn = []
sta = []
ox = ["O","X"]
num = 3
sts = 0

#Main Frame
frame = Tk()
frame.title("Variety Tic")

'''
def des():
    for i in range (num-1):
        for j in range (num-1):
            btn[i][j].grid_forget()
            btn[i][j].destroy()
    res.config(command = lambda:res.grid_forget())
    res.destroy()
    add.config(command = lambda:add.grid_forget())
    add.destroy()
'''

# Delete Data from Sta-Array
def rmsta():
    for i in range (num-1,-1,-1):
        del sta[i]

# Check Input Data whether it is win
def check(x):
    resta = 0
    for i in range (4):
        if (i == 0):
            for n in range (num):
                for m in range (num):
                    if (sta[n][m] == x):
                        resta += 1
                    else:
                        resta = 0
                        break
                if (resta == num):
                    break
        if (i == 1 and resta != num):
            for n in range (num):
                for m in range (num):
                    if (sta[m][n] == x):
                        resta += 1
                    else:
                        resta = 0
                        break
                if (resta == num):
                    break
        if (i == 2 and resta != num):
            for n in range (num):
                if (sta[n][n] == x):
                    resta += 1
                else:
                    resta = 0
                    break
        if (i == 3 and resta != num):
            for n in range (num):
                if (sta[n][num-(n+1)] == x):
                    resta += 1
                else:
                    resta = 0
                    break
    if (resta == num):
        return 1
    else:
        return 0

# Add 1 to _Num
def addnum():
    global num
    #des()
    restart()
    rmsta()
    num += 1
    initsta()
    initbtn()

#Restart Btn Set up
def restart():
    global sts
    sts = 0
    for i in range (num):
        for j in range (num):
            sta[i][j] = 2
    win.config(text = "",font=('Andale Mono', 18),foreground="#AAAEB6",highlightbackground ="#31343E")
    for i in range (num):
        for j in range (num):
            btn[i][j].config(text="",font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E")
            btn[i][j].config(state="active")

# Control Disabled Button and Write OX status to Array
def control(x,y):
    global sts
    if (sts % 2 == 0):
        btn[x][y].config(text="O",font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E")
        btn[x][y].config(state="disabled",foreground="#AAAEEE",highlightbackground ="#100000")
        sta[x][y] = 0
        sts += 1
    else:
        '''
        while(1):
            x = random.randrange(0, num)
            y = random.randrange(0, num)
            if (sta[x][y] == 2):
                break
        '''
        btn[x][y].config(text="X",font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E")
        btn[x][y].config(state="disabled",foreground="#AAAEEE",highlightbackground ="#300000")
        sta[x][y] = 1
        sts += 1
    #Check Btn State of Win Condition
    for i in range (2):
        if(check(i)):
            win.config(text = ox[i] + " Win")
            dis()
            break
        elif(sts == (num*num)):
            sts = 0
            win.config(text = "Flat")
            dis()

# Disable All Button
def dis():
    for i in range (num):
        for j in range (num):
            btn[i][j].config(state="disabled")

# Create Btn Array & Set up Btn Position
def initbtn():
    global sts
    for i in range (num):
        btn.append([])
        for j in range (num):
            btn[i].append(Button(frame,width = 5,height = 2,font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E"))
            btn[i][j].config(command = lambda x = i,y = j:control(x,y))
            btn[i][j].grid(row = i,column = j)
    res.grid(row = num,column = num-2)
    add.grid(row = num,column = num-1)
    win.grid(row = num,column = 0)

# Set up Status of Btn Array
def initsta():
    for i in range (num):
        sta.append([])
        for j in range (num):
            sta[i].append(2)
            #print(sta[i][j],end = " ")
        #print(sta)

# Create Restart Btn
res = Button(frame,text = "Res",width = 5,height = 2,font = ('Andale Mono',14),foreground = "#AAAEB6",highlightbackground = "#31343E")
res.config(state = "active",command = lambda:restart())

# Create Expend Btn of OX-Btn Array
add = Button(frame,text = "Exp",width = 5,height = 2,font = ('Andale Mono',14),foreground = "#AAAEB6",highlightbackground = "#31343E")
add.config(state = "active",command = lambda:addnum())

# Show Winner
win = Label(frame,width = 4,height = 2,font=('Andale Mono', 18),foreground="#AAAEB6",highlightbackground ="#31343E")

# Call them
initbtn()
initsta()

#Init frame size 320x360
frame.geometry("")
frame.mainloop()
