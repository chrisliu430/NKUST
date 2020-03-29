#Translate Temperature Type
#
#Problem Description
#Translate Celsius To Fahrenheit
#
#Asking Condition
#OUTPUT NEED WRITE TO NOTE
fo = open("Q01_Celsius.txt","w")
tem = int(input("Fahrenheit Temperature:"))
tem -= 32
tem *= (5/9)
print(int(tem),file = fo)
fo.close()
