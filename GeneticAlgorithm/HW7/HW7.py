import random

population = 3
gene = 7
crossover = 0.8
mutation = 0.2
evolution = 4

kg = 150
bagValue = [10, 40, 30, 50, 35, 40, 30]
bagWeight = [35, 30, 60, 50, 40, 10, 25]

def CheckWeight(sel):
    value = 0
    weight = 0
    for i in range (len(sel)):
        if (sel[i]):
            weight += bagWeight[i]
            value += bagValue[i]
    if (weight > kg):
        return weight, 5
    else:
        return weight, value

def InitGene():
    p = []
    for _ in range (population):
        g = []
        for __ in range (gene):
            g.append(random.choice([0, 1]))
        p.append(g)
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
            if (vList[i] > bestV):
                best = i
                bestV = vList[i]
        return best

def Crossover(sel):
    s1 = 0
    s2 = 0
    while(s1 == s2):
        s1 = random.randint(1, len(sel) - 1)
        s2 = random.randint(1, len(sel) - 1)
    for i in range (len(sel)):
        if (random.uniform(0, 1) < crossover):
            temp = sel[s1][i]
            sel[s1][i] = sel[s2][i]
            sel[s2][i] = temp
    return sel

def Mutation(sel):
    for i in range (1, len(sel)):
        for j in range (len(sel[i])):
            if (random.uniform(0, 1) < mutation):
                sel[i][j] ^= 1
    return sel

p = InitGene()
print(0, end = "\t")
for i in range (gene):
    print(i, end = "\t")
print("Value\tProb\tWeight")

print("-" * 90)

totalValue = 0
vList = []
probList = []
for i in range (len(p)):
    _, v = CheckWeight(p[i])
    totalValue += v
    vList.append(v)

for i in range (len(p)):
    print(i, end = "\t")
    w, v = CheckWeight(p[i])
    for j in range (len(p[i])):
        print(p[i][j], end = "\t")
    prob = round(v / totalValue, 1)
    probList.append(prob)
    print(v, "\t", prob, "\t", w)
    
print("=" * 90)

for t in range (evolution):

    totalValue = 0
    vList = []
    probList = []
    newP = []
    
    for i in range (len(p)):
        _, v = CheckWeight(p[i])
        totalValue += v
        vList.append(v)
    
    for i in range (len(p)):
        _, v = CheckWeight(p[i])
        prob = round(v / totalValue, 1)
        probList.append(prob)
    
    while(len(newP) < population):
        choiceIdx = ChoiceFunc(vList, 1)
        newP.append(p[choiceIdx].copy())
    
    for i in range (len(newP)):
        if (random.uniform(0, 1) >= 0.5):
            newP = Crossover(newP)
            
    for i in range (len(newP)):
        if (random.uniform(0, 1) >= 0.5):
            newP = Mutation(newP)
    
    p = newP.copy()
    
    totalValue = 0
    vList = []
    probList = []
    for i in range (len(p)):
        _, v = CheckWeight(p[i])
        totalValue += v
        vList.append(v)
    
    for i in range (len(p)):
        _, v = CheckWeight(p[i])
        prob = round(v / totalValue, 1)
        probList.append(prob)
    
    print(t + 1, end = "\t")
    for i in range (gene):
        print(i, end = "\t")
    print("Value\tProb\tWeight")
    
    print("-" * 90)
    
    for i in range (len(p)):
        print(i, end = "\t")
        w, v = CheckWeight(p[i])
        for j in range (len(p[i])):
            print(p[i][j], end = "\t")
        prob = round(v / totalValue, 1)
        probList.append(prob)
        print(v, "\t", prob, "\t", w)
    
    print("=" * 90)