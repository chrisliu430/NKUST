#ObliqueTriangle of Number
#
#Problem Description
#Input two number and using space to slice two number
#While previous number is less than behind number that Stopping this execute
#When previous number is bigger than behind number
#Make the continue-number to be statement and decrement when number equal behind number
#Stopping this execute
while(1):
	ipt = input().split(" ")
	for i in range (len(ipt)):
		ipt[i] = int(ipt[i])
	#print(ipt)
	if (ipt[0] < ipt[1]):
		break
	else:
		for i in range (ipt[0],0,-1):
			for j in range (ipt[0]-i):
				print(" ",end = "")
			for j in range (i,0,-1):
				print(j,end = "")
			print()
			if (i == ipt[1]):
				break
