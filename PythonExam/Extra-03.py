#Process Input Data to be Number-List
#
#Problem Description
#Input  Multiple Test Data and Process it that to be Array
#One statement number need to equal three Number
#One Number of statement is Starting Conunter Position
#Two Number of statement is End Counter Position
#Three Number of statement is Maximum Random Range that add to Previous Number 
import random
fi = open("Input.txt","r")
ipt = []
for i in fi:
	ipt.append(i.strip("\n"))
for i in range (0,len(ipt)):
	ipt[i] = list(map(int,ipt[i].split()))
	print(ipt[i])
	while (ipt[i][0] < ipt[i][1]):
		print(ipt[i][0],end = " ")
		regi = random.randint(1,ipt[i][2])
		ipt[i][0] += regi
	print(ipt[i][0])
