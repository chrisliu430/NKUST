def maxNumWords(m, k):
    cnt = 0
    idx = 0
    while(idx + k <= m):
        cnt += 1
        idx += 1
    return idx

def actualNumWords(s, k):
    cnt = 0
    idx = 0
    strList = []
    while(idx + k <= len(s)):
        strList.append(s[idx:idx + k])
        cnt += 1
        idx += 1
    strSet = set(strList)
    return len(strSet)

def lingComplexity(s):
    var = 0
    for k in range (1, 11):
        maxN = maxNumWords(len(s), k)
        actN = actualNumWords(s, k)
        var += (actN / maxN)
    return var

fStr = []
f = open("NC_045512.fasta", "r")
for text in f:
    text = text.strip("\n")
    fStr.append(text)
f.close()

f = open("Out_NC_045512.txt", "w")
for text in fStr:
    val = lingComplexity(text)
    f.write(str(val) + "\n")
f.close()