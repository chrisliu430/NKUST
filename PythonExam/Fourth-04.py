#Make the Anti-Triangle By Char A & B
#
#Input:4
#
#|OUTPUT |
#|A A A A|
#| B B B |
#|  A A  |
#|   B   |
sta = True
while(1):
	ipt = int(input())
	if (ipt == -1):
		break
	for i in range (ipt,0,-1):
		for j in range (0,ipt-i):
			print(" ",end = "")
		if (sta == True):
			for j in range (i,0,-1):
				print("A",end = " ")
			sta = False
		else:
			for j in range (i,0,-1):
				print("B",end = " ")
			sta = True
		print()
