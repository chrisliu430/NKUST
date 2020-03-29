#Oblique Triangle
#
#Input:4
#
#|Output|
#|   *  |
#|  **  |
#| ***  |
#|****  |
ipt = int(input("The Opposite Triangle Raw:"))

for i in range(1,ipt+1):
    for j in range(0,ipt-i):
        print(" ",end = "")
    for j in range(0,i):
        print("*",end = "")
    print()
