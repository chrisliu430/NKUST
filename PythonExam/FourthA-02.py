#Odd Number Translate To Chinese
#
#Problem Description
#Input the number that slice this number storage to array
#If the number of array is odd translate the number to be chrinese & show
chi = []
while(1):
	ipt = int(input())
	if (ipt == -1):
		break
	while(ipt > 0):
		regi = ipt % 10
		if (regi % 2 != 0):
			if (regi == 1):
				print("一",end = "")
			if (regi == 3):
				print("三",end = "")
			if (regi == 5):
				print("五",end = "")
			if (regi == 7):
				print("七",end = "")
			if (regi == 9):
				print("九",end = "")
		ipt //= 10
	'''
	for i in range (0,len(chi)):
		print(chi[i],end = "")
	for i in range (len(chi)-1,-1,-1):
		chi.remove(chi[i])
	'''
	print()
