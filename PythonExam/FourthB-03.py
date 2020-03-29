#Read Score & Write the Data To Be Array
ipt = []
chi = []
opt = []
optchi = []
regi = 0
fi = open("Q04_Input.txt","r")
for i in fi:
	i = i.strip("\n").split(" ")
	ipt.append(i)
for i in range (1,len(ipt)):
	for j in range (1,len(ipt[i])):
		ipt[i][j] = int(ipt[i][j])
for i in range (1,len(ipt[0])):
	chi.append(ipt[0][i])
for i in range (1,len(ipt[0])):
	for j in range (1,len(ipt)):
		if (regi < ipt[j][i]):
			regi = ipt[j][i]
			pos = j
	opt.append(regi)
	regi = 0
	optchi.append(ipt[pos][0])
for i in range (0,len(chi)):
	print(chi[i],end = ":")
	print(optchi[i],end = " ")
	print(opt[i])
