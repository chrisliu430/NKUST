#Permutations
#
#Asking Condition
#NEED USING RECURSIVE FUNCTION
#數學：排列組合
#Ｃ(M取N)：不存在重複之可能性
def Combo_Function(n):
	if (n == 1):
		return 1
	else:
		return n*Combo_Function(n-1)
def C_Function(m,n):
	if (n == 0 or n == m or n == (m-n)):
		return 1
	else:
		return m*C_Function(m-1,n-1)
while(1):
	ipt = input().split(" ")
	for i in range (len(ipt)):
		ipt[i] = int(ipt[i])
	if (ipt[0] < ipt[1]):
		break
	else:
		print(C_Function(ipt[0],ipt[1])//Combo_Function(ipt[1]))
