#Even Number Translate To Chinese
#
#Problem Description
#Input the number that slice this number storage to array
#If the number of array is even translate the number to be chrinese & show
chi = []
while(1):
	ipt = int(input())
	if (ipt == -1):
		break
	while(ipt > 0):
		regi = ipt % 10
		if (regi % 2 == 0):
			if (regi == 2):
				chi.append("二")
			if (regi == 4):
				chi.append("四")
			if (regi == 6):
				chi.append("六")
			if (regi == 8):
				chi.append("八")
		ipt //= 10
	for i in range (0,len(chi)):
		print(chi[i],end = "")
	for i in range (len(chi)-1,-1,-1):
		chi.remove(chi[i])
	print()
