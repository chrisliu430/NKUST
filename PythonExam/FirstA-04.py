#Translate Temperature Type
#
#Problem Description
#Translate Fahrenheit To Celsius
#
#Asking Condition
#OUTPUT NEED WRITE TO NOTE
fo = open("Q01_Fahrenheit.txt","w")
tem = int(input("Celsius Temperature:"))
tem *= (9/5)
tem += 32
print(int(tem),file = fo)
fo.close()
