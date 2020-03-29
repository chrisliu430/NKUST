#Find Minimum Common Number By Array
#
#Output Description
#Make Input-Data to be Array and Show & Show Minimum Number
#
#Asking Condition
#READ DATA FROM "Input.txt"
fi = open("Q01_Input.txt","r")
ipt = []
for i in fi:
	ipt.append(i.strip("\n").split(" "))
print(ipt)
for i in range (0,len(ipt)):
	ipt[i] = list(map(int,ipt[i]))
for i in range (0,len(ipt)):
	for k in range (min(ipt[i]),0,-1):
		if(max(ipt[i]) % k == 0 and min(ipt[i]) % k == 0):
			print(k)
			break
