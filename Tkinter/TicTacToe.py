#| Python GUI Source |#
#|-------------------|#
#|-Tic Tac Toe------X|#
#| |---| |---| |---| |#
#|                   |#
#| |---| |---| |---| |#
#|                   |#
#| |---| |---| |---| |#
#| |---------------| |#
#| |     WINNER    | |#
#| |---------------| |#
#|-------------------|#
from tkinter import *

btn = []
sta = [[2,2,2],[2,2,2],[2,2,2]]
ox = ["O","X"]
num = 3
sts = 0

#Main Frame
frame = Tk()
frame.title("Tic Tac Toe")

def control(x,y):
    global sts
    if (sts % 2 == 0):
        btn[x][y].config(text="O",font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E")
        btn[x][y].config(state="disabled")
        sta[x][y] = 0
        sts += 1
    elif(sts % 2 == 1):
        btn[x][y].config(text="X",font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E")
        btn[x][y].config(state="disabled")
        sta[x][y] = 1
        sts += 1
    for i in range (2):
        if((sta[x][0]==i and sta[x][1]==i and sta[x][2]==i) or (sta[0][y]==i and sta[1][y]==i and sta[2][y]==i) or (x==y and (sta[0][0]==i and sta[1][1]==i and sta[2][2]==i)) or ((x+y)==2 and (sta[0][2]==i and sta[1][1]==i and sta[2][0]==i))):
            win.config(text = ox[i] + " Win")
            dis()
            break
        elif(sts == 9):
            win.config(text = "Flat")

def dis():
    for i in range (3):
        for j in range (3):
            btn[i][j].config(state="disabled")

for i in range (num):
    btn.append([])
    for j in range (num):
        btn[i].append(Button(frame,width = 10,height = 5,font=('Andale Mono', 14),foreground="#AAAEB6",highlightbackground ="#31343E"))
        btn[i][j].config(command = lambda x = i,y = j:control(x,y))
        btn[i][j].grid(row = i,column = j)

win = Label(frame,width = 8,height = 4,font=('Andale Mono', 18),foreground="#AAAEB6",highlightbackground ="#31343E")
win.grid(row = 4,column = 1)

frame.geometry("320x350")
frame.mainloop()
