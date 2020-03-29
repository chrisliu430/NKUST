#Judge the Number whether is the Prime-Number
#
#Problem Description
#Input the Number & Judge the Number
ipt = int(input("The Number For Judge:"))
#Run Loop for % Number
for i in range(2,ipt):
    if ((i<2) or (ipt%i) == 0):
        print("非質數")
        break
    else:
        break
