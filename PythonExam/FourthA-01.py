#Find Maximum Number in statement
#
#Problem Description
#Input the Multiple Data and slice the data to be one number on statement
#Find the maximum number in same statement
fi = open("Q01_Input.txt","r")
regi = 0
for i in fi:
	ipt = i.strip("\n").split(" ")
	for i in range (0,len(ipt)):
		ipt[i] = int(ipt[i])
	for i in range (0,len(ipt)):
		if (ipt[i] > regi):
			regi = ipt[i]
	print(regi)
	regi = 0
