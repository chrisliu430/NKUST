#Oblique Triangle
#
#Input:4
#
#|Output|
#|****  |
#| ***  |
#|  **  |
#|   *  |
ipt = int(input("The Opposite Triangle Raw:"))

for i in range(ipt,0,-1):
    for j in range(0,ipt-i):
        print(" ",end = "")
    for j in range(i,0,-1):
        print("*",end = "")
    print()
