# Examination
from tkinter import *

start = 1
star = []

def starPrint(x):
    for i in range (x,-1,-1):
        for j in range (i):
            print("*",end = "")
        print()
        

if "__main__" == __name__:
    root = Tk()
    root.title("MemoryGame")
    if (start == 1):
        for i in range (12):
            star.append(Button(text = str(i+1)))
            star[i].config(command = lambda x = i+1:starPrint(x))
            star[i].grid(row = 0,column = i)
        start = 0
    root.mainloop()
