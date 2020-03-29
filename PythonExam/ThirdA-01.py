#Counter the Number Apperance Frequency
#
#Problem Description
#Input the Number and Slice the Number by 10
#Counter the number of this number apperance frequency
#Compare all number frequency that find minimum frequency
#Show Minimum frequency & which number
'''
#Function 1
num = ['0','1','2','3','4','5','6','7','8','9']
count = [0,0,0,0,0,0,0,0,0,0]
ipt = input()
regi = 999999999
for i in range (0,len(ipt)):
	for j in range (0,len(num)):
		if (ipt[i] == num[j]):
			count[j] += 1
			break
for i in range (0,len(count)):
	if (regi > count[i] and count[i] != 0):
		regi = count[i]
print("出現最少的數字：")
for i in range (0,len(count)):
	if (count[i] == regi):
		print(i," ",end = "")
print("\n出現最少的次數：")
print(regi)
'''

#Function 2
num = [0,1,2,3,4,5,6,7,8,9]
count = [0,0,0,0,0,0,0,0,0,0]
ipt = int(input())
regi = 999999999
while(ipt != 0):
	for i in range (0,len(num)):
		if (ipt%10 == num[i]):
			#print(num[i])
			count[i] += 1
			break
	ipt //= 10
for i in range (0,len(count)):
	if (regi > count[i] and count[i] != 0):
		regi = count[i]
print("出現最少的數字：")
for i in range (0,len(count)):
	if (count[i] == regi):
		print(i," ",end = "")
print("\n出現最少的次數：")
print(regi)
