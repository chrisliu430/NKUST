#Find Maximum Number
#
#Problem Description
#Find Maximum Number of the list in the File
#
#Asking Condition
#WRITE DATA IN "Input.txt" & READ THIS FILE
fi = open("Q02_Input.txt","r") #Read File
sta = 0 #Store the Number status

#Run Loop for data in Q02_Input.txt
for i in fi:
    #Store the First Number
    if (sta == 0):
        n1 = int(i)
        sta = 1
    #Compare Which Number is bigger
    #[n1] is the bigger
    else:
        n2 = int(i)
        if (n1 < n2):
            regi = n2
            n2 = n1
            n1 = regi
print(n1)
