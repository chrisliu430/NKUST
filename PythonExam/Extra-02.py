#Check Data whether is the Prime-Number
spa = []
while(1):
	time = 0
	sta = 0
	ipt = int(input())
	if (ipt < 2):
		break
	while (ipt != 1):
		for i in range (2,ipt+1):
			if (ipt % i == 0):
				spa.append(i)
				ipt //= i
				regi = i
				break
		for i in range (0,len(spa)):
			if (regi == spa[i]):
				time += 1
			if (time > 1):
				sta = 1
				break
		time = 0
		if (sta == 1):
			break
	if (sta == 1):
		print("不是")
	else:
		print("是")
	for i in range (len(spa)-1,-1,-1):
		spa.remove(spa[i])
