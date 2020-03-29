#ObliqueTriangle Connect Anti-ObliqueTriangle
#
#Input:3
#
#|OUTPUT|
#|*     |
#|**    |
#|***   |
#| **   |
#|  *   |
ipt = int(input())
for i in range (ipt):
	for j in range (i+1):
		print("*",end = "")
	print()
for i in range (ipt-1):
	for j in range (i+1):
		print(" ",end = "")
	for j in range (ipt-(i+1)):
		print("*",end = "")
	print()
