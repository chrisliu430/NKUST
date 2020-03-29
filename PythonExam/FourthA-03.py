#Make the Triangle By Char A & B
#
#Input:4
#
#|OUTPUT |
#|   A   |
#|  B B  |
#| A A A |
#|B B B B|
while(1):
	ipt = int(input())
	if (ipt == -1):
		break
	for i in range (0,ipt):
		for j in range (0,ipt-(i+1)):
			print(" ",end = "")
		if (i % 2 == 0):
			for j in range (0,i+1):
				print("A",end = "")
				if (i != 0):
					print(" ",end = "")
		else:
			for j in range (0,i+1):
				print("B",end = " ")
		print()
