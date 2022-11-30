import random

citySize = 5
population = 4
gene = citySize + 1
func = "PBX"
crossover = 0.8
mutation = 0.2
evolution = 4

city = [
    [0, 7, 10, 2, 6],
    [7, 0, 4, 9, 3],
    [10, 4, 0, 5, 1],
    [2, 9, 5, 0, 8],
    [6, 3, 1, 8, 0],
]

def InitGene(geneSize):
    g = []
    while(1):
        if (len(g) == geneSize):
            break
        elif (len(g) == geneSize - 1):
            for i in range (geneSize):
                if i not in g:
                    g.append(i)
                    break
        else:
            rNum = int(random.uniform(0, geneSize - 1))
            if (rNum not in g):
                g.append(rNum)
    g.append(g[0])
    return g

def Fitness(g):
    score = 0
    for idx in range (len(g) - 1):
        score += city[g[idx]][g[idx + 1]]
    return score

# PBX Crossover
def PBX(pickSize, n):
    pickList = []
    cnt = 0
    while (1):
        rNum = int(random.uniform(0, pickSize - 1))
        if (rNum not in pickList):
            pickList.append(rNum)
            cnt += 1
        if (cnt >= n):
            break
    return pickList

def Crossover(p):
    s1 = 0
    s2 = 0
    while(s1 == s2):
        s1 = random.randint(0, len(p) - 1) # Main
        s2 = random.randint(0, len(p) - 1) # Paste
    newGene = []
    for idx in range (len(p[s1])):
        newGene.append(-1)
    pbxList = PBX(len(p[s1]) - 1, 3)
    for pbxIdx in pbxList:
        newGene[pbxIdx] = p[s1][pbxIdx]
    for i in range (len(p[s2])):
        if (p[s2][i] not in newGene):
            for j in range (len(newGene)):
                if (newGene[j] == -1):
                    newGene[j] = p[s2][i]
                    break
    newGene[len(p[s1]) - 1] = newGene[0]
    return newGene

def OptChoice(lenGene, opt = 2):
    if (opt == 2):
        pick1 = 0
        pick2 = 0
        while(pick1 == pick2):
            pick1 = int(random.uniform(0, len(lenGene) - 2))
            pick2 = int(random.uniform(0, len(lenGene) - 2))
        return pick1, pick2
    else:
        pick1 = 0
        pick2 = 0
        pick3 = 0
        while(pick1 == pick2 or pick2 == pick3 or pick1 == pick3):
            pick1 = int(random.uniform(0, len(lenGene) - 2))
            pick2 = int(random.uniform(0, len(lenGene) - 2))
            pick3 = int(random.uniform(0, len(lenGene) - 2))
        return pick1, pick2, pick3

def Mutation(p):
    for i in range (1, len(p)):
        if (random.uniform(0, 1) < mutation):
            p1, p2 = OptChoice(p)
            temp = p[i][p1]
            p[i][p1] = p[i][p2]
            p[i][p2] = temp
            if (p1 == 0 or p2 == 0):
                lastIdx = len(p[i]) - 1
                p[i][lastIdx] = p[i][0]
    return p

def ChoiceFunc(vList, mode = 0):
    if (mode == 0): # Random
        sortV = []
        for i in range (len(vList)):
            sortV.append(i)
        for i in range (len(vList) - 1):
            for j in range (i + 1, len(vList)):
                if (vList[i] < vList[j]):
                    temp = vList[i]
                    vList[i] = vList[j]
                    vList[j] = temp
                    temp = sortV[i]
                    sortV[i] = sortV[j]
                    sortV[j] = temp
        stepV = [vList[0]]
        for i in range (1, len(vList)):
            stepV.append(vList[i] + stepV[i - 1])
        randUni = round(random.uniform(0, 0.999999), 2)
        for i in range (len(stepV)):
            if (randUni <= stepV[i]):
                return i
    if (mode == 1): # Best
        best = 0
        bestV = vList[0]
        for i in range (1, len(vList)):
            if (vList[i] < bestV):
                best = i
                bestV = vList[i]
        return best

p = []
for _ in range (population):
    g = InitGene(citySize)
    p.append(g.copy())

# First Time
print(0, end = "\t")
for i in range (gene):
    print(i, end = "\t")
print("Value\tProb")

print("-" * 90)

totalValue = 0
vList = []
probList = []
for i in range (len(p)):
    v = Fitness(p[i])
    vList.append(v)
    totalValue += v

for i in range (len(p)):
    print(i, end = "\t")
    for j in range (len(p[i])):
        print(p[i][j], end = "\t")
    prob = round(vList[i] / totalValue, 3)
    probList.append(prob)
    print(vList[i], "\t", prob)
    
print("=" * 90)

# Second to Infinite
for t in range (evolution):
    
    totalValue = 0
    vList = []
    probList = []
    newP = []
    selP = []
    
    for i in range (len(p)):
        v = Fitness(p[i])
        vList.append(v)
        totalValue += (v)

    for i in range (len(p)):
        v = Fitness(p[i])
        prob = round(v / totalValue, 3)
        probList.append(prob)
    
    choiceIdx = ChoiceFunc(vList, 1)
    newP.append(p[choiceIdx].copy())
    cnt = 0
    while(len(newP) < population):
        newP.append(p[cnt].copy())
        cnt += 1
    
    selP.append(newP[0])
    while(len(selP) < population):
        if (random.uniform(0, 1) >= crossover):
            selP.append(Crossover(newP))
            
    for i in range (len(newP)):
        if (random.uniform(0, 1) >= 0.5):
            newP = Mutation(selP)
    
    p = selP.copy()
    
    totalValue = 0
    vList = []
    probList = []
    for i in range (len(p)):
        v = Fitness(p[i])
        totalValue += v
        vList.append(v)
    
    for i in range (len(p)):
        v = Fitness(p[i])
        prob = round(v / totalValue, 1)
        probList.append(prob)
    
    print(t + 1, end = "\t")
    for i in range (gene):
        print(i, end = "\t")
    print("Value\tProb")

    print("-" * 90)

    for i in range (len(p)):
        print(i, end = "\t")
        for j in range (len(p[i])):
            print(p[i][j], end = "\t")
        prob = round(vList[i] / totalValue, 3)
        probList.append(prob)
        print(vList[i], "\t", prob)

    print("=" * 90)