import math
import random

random.seed(11015656)

def ReadDataset(_num):
    finCap = open("./Knapsack01_Dataset/p0" + str(_num) + "_c.txt", "r")
    for s in finCap:
        cap = int(s)
    finCap.close()
    
    itemWeight = []
    finWei = open("./Knapsack01_Dataset/p0" + str(_num) + "_w.txt", "r")
    for s in finWei:
        itemWeight.append(int(s))
    finWei.close()

    itemProfit = []
    finPro = open("./Knapsack01_Dataset/p0" + str(_num) + "_p.txt", "r")
    for s in finPro:
        itemProfit.append(int(s))
    finPro.close()

    itemOptimal = []
    finOpt = open("./Knapsack01_Dataset/p0" + str(_num) + "_s.txt", "r")
    for s in finOpt:
        itemOptimal.append(int(s))
    finOpt.close()

    return cap, itemWeight, itemProfit, itemOptimal

def GenerateInit(_n = 6):
    solve1 = []
    solve2 = []
    for _ in range (_n):
        solve1.append(round(random.random(), 3))
    for _ in range (_n):
        solve2.append(round(random.random(), 3))
    return solve1, solve2

# Attack 3.3.1
def Obtaining(attacker, defener, beta = 0.5):
    newDefener = []
    for idx in range (len(attacker)):
        val1 = defener[idx] * (1 - math.sin(beta) * random.uniform(0, 1))
        val2 = (attacker[idx] + defener[idx]) / 2 * math.sin(beta) * random.uniform(0, 1)
        newDefener.append(val1 + val2)
    return newDefener

# Attack 3.3.2
def Phishing(attacker, defener, beta = 0.5):
    newAttacker = []
    newDefener = []
    for idx in range (len(attacker)):
        aVal1 = attacker[idx] * (1 - math.sin(beta) * random.uniform(0, 1))
        aVal2 = (attacker[idx] + defener[idx]) / 2 * math.sin(beta) * random.uniform(0, 1)
        newAttacker.append(aVal1 + aVal2)

        dVal1 = defener[idx] * (1 - math.sin(math.pi / 2 - beta) * random.uniform(0, 1))
        dVal2 = (attacker[idx] + defener[idx]) / 2 * math.sin(math.pi / 2 - beta) * random.uniform(0, 1)
        newDefener.append(dVal1 + dVal2)
    return newAttacker, newDefener

# Attack 3.3.3
def DiversionTheft(attacker, defener, beta = 0.5):
    newDefener = []
    for idx in range (len(attacker)):
        val1 = defener[idx] * (1 - math.sin(beta) * random.uniform(0, 1))
        val2 = ((attacker[idx] * random.uniform(0, 1) * math.sin(math.pi / 2 - beta)) + defener[idx]) / 2 * math.sin(beta) * random.uniform(0, 1)
        newDefener.append(val1 + val2)
    return newDefener

# Attack 3.3.4
def Pretext(attacker, defener, beta = 0.5):
    newDefener = []
    for idx in range (len(attacker)):
        temp = defener[idx] * random.uniform(0, 1) * math.sin(math.pi / 2 - beta)
        val1 = (temp) * (1 - math.sin(beta) * random.uniform(0, 1))
        val2 = (attacker[idx] + temp) / 2 * math.sin(beta) * random.uniform(0, 1)
        newDefener.append(val1 + val2)
    return newDefener

# def SpotAttack(attacker, defener, _func):
    # if (_func == 1): # Random

def GenerateBinary(solve, _func = 1):
    binSolve = []
    if (_func == 1): # 0.5
        for val in solve:
            if (val >= 0.5):
                binSolve.append(1)
            else:
                binSolve.append(0)
    if (_func == 2): # Average
        totalVal = 0
        for val in solve:
            totalVal += val
        averageVal = round(totalVal / len(solve), 4)
        for val in solve:
            if (val >= averageVal):
                binSolve.append(1)
            else:
                binSolve.append(0)
    if (_func == 3): # Random
        for val in solve:
            if (val >= round(random.random(), 4)):
                binSolve.append(1)
            else:
                binSolve.append(0)
    return binSolve

def IsViolation(cap, itemWeight, binSolve):
    takeCap = 0
    for idx in range (len(binSolve)):
        takeCap += (itemWeight[idx] * binSolve[idx])
    if (takeCap > cap):
        return True
    return False

def ComputingProfits(itemProfit, binSolve):
    takeProfit = 0
    for idx in range (len(binSolve)):
        takeProfit += (itemProfit[idx] * binSolve[idx])
    return takeProfit

if __name__ == "__main__":
    attackTimes = 100
    cap, itemWeight, itemProfit, itemOptimal = ReadDataset(1)
    
    itemSize = len(itemWeight)
    solve1, solve2 = GenerateInit(itemSize)

    binSolve1 = GenerateBinary(solve1)
    binSolve2 = GenerateBinary(solve2)

    vioSolve1 = IsViolation(cap, itemWeight, binSolve1)
    vioSolve2 = IsViolation(cap, itemWeight, binSolve2)

    if (vioSolve1 and vioSolve2):
        if (random.random() >= 0.5):
            attacker = solve1.copy()
            defener = solve2.copy()
        else:
            defener = solve1.copy()
            attacker = solve2.copy()
    elif (vioSolve1 and not vioSolve2):
        defener = solve1.copy()
        attacker = solve2.copy()
    elif (not vioSolve1 and vioSolve2):
        attacker = solve1.copy()
        defener = solve2.copy()
    else:
        profit1 = ComputingProfits(itemProfit, binSolve1)
        profit2 = ComputingProfits(itemProfit, binSolve2)
        if (profit1 > profit2):
            attacker = solve1.copy()
            defener = solve2.copy()
        else:
            defener = solve1.copy()
            attacker = solve2.copy()

    # for _ in range (attackTimes):