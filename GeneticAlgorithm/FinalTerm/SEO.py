import os
import sys
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
        return True, takeCap
    return False, takeCap

def ComputingProfits(itemProfit, binSolve):
    takeProfit = 0
    for idx in range (len(binSolve)):
        takeProfit += (itemProfit[idx] * binSolve[idx])
    return takeProfit

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

def SpotAttack(cap, itemWeight, itemProfit, attacker, defener, _func = 1):
    if (_func == 1): # Random
        c = random.choice([1, 2, 3, 4])
        if (c == 1):
            newDefener = Obtaining(attacker, defener)
            newBin = GenerateBinary(newDefener)
            isVio, _ = IsViolation(cap, itemWeight, newBin)
            if (isVio):
                return defener
            else:
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit = ComputingProfits(itemProfit, newBin)
                if (profit > newProfit):
                    return defener
                else:
                    return newDefener
        if (c == 2):
            newDefener1, newDefener2 = Phishing(attacker, defener)
            newBin1 = GenerateBinary(newDefener1)
            isVio1, _ = IsViolation(cap, itemWeight, newBin1)
            newBin2 = GenerateBinary(newDefener2)
            isVio2, _ = IsViolation(cap, itemWeight, newBin2)
            if (isVio1 and isVio2):
                return defener
            elif (not isVio1 and isVio2):
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit = ComputingProfits(itemProfit, newBin1)
                if (profit > newProfit):
                    return defener
                else:
                    return newDefener1
            elif (isVio1 and not isVio2):
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit = ComputingProfits(itemProfit, newBin2)
                if (profit > newProfit):
                    return defener
                else:
                    return newDefener2
            else:
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit1 = ComputingProfits(itemProfit, newBin1)
                newProfit2 = ComputingProfits(itemProfit, newBin2)
                if (profit > newProfit1):
                    if (profit > newProfit2):
                        return defener
                    else:
                        return newDefener2
                else:
                    if (newProfit1 > newProfit2):
                        return newDefener1
                    else:
                        return newDefener2
        if (c == 3):
            newDefener = DiversionTheft(attacker, defener)
            newBin = GenerateBinary(newDefener)
            isVio, _ = IsViolation(cap, itemWeight, newBin)
            if (isVio):
                return defener
            else:
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit = ComputingProfits(itemProfit, newBin)
                if (profit > newProfit):
                    return defener
                else:
                    return newDefener
        if (c == 4):
            newDefener = Pretext(attacker, defener)
            newBin = GenerateBinary(newDefener)
            isVio, _ = IsViolation(cap, itemWeight, newBin)
            if (isVio):
                return defener
            else:
                binSolve = GenerateBinary(defener)
                profit = ComputingProfits(itemProfit, binSolve)
                newProfit = ComputingProfits(itemProfit, newBin)
                if (profit > newProfit):
                    return defener
                else:
                    return newDefener

def WriteLog(num, attackTimes, maxAttack, cap, itemWeight, itemProfit, attacker, firstWr, t):
    logPath = "./Knapsack01_Log/"
    if (not os.path.exists(logPath)):
        os.mkdir(logPath)

    if (firstWr):
        logFile = open(logPath + "P" + str(num) + "_" + str(attackTimes) + "_" + str(maxAttack) + ".log", "w")
        logFile.write("Initial Solutions" + "\n")
    else:
        logFile = open(logPath + "P" + str(num) + "_" + str(attackTimes) + "_" + str(maxAttack) + ".log", "a")
        logFile.write("Round " + str(t + 1) + "\n")

    binAttacker = GenerateBinary(attacker)
    profitAttacker = ComputingProfits(itemProfit, binAttacker)
    isVio, attackerWeight = IsViolation(cap, itemWeight, binAttacker)

    logFile.write("Attacker Profits:\t" + str(profitAttacker) + "\n")
    logFile.write("Attacker Weights:\t" + str(attackerWeight) + "\n")
    logFile.write("Attacker Violations:\t" + str(isVio) + "\n")
    logFile.write("=" * 150 + "\n")
    for attack in attacker:
        logFile.write(str(round(attack, 4)) + "\t")
    logFile.write("\n")
    logFile.write("-" * 150 + "\n")
    for attack in binAttacker:
        logFile.write(str(attack) + "\t")
    logFile.write("\n")
    logFile.write("=" * 150 + "\n")
    logFile.write("\n")
    
    logFile.close()

if __name__ == "__main__":
    pNumber = int(sys.argv[1])
    attackTimes = int(sys.argv[2])
    maxAttack = int(sys.argv[3])
    cap, itemWeight, itemProfit, itemOptimal = ReadDataset(pNumber)
    
    itemSize = len(itemWeight)
    solve1, solve2 = GenerateInit(itemSize)

    binSolve1 = GenerateBinary(solve1)
    binSolve2 = GenerateBinary(solve2)

    vioSolve1, _ = IsViolation(cap, itemWeight, binSolve1)
    vioSolve2, _ = IsViolation(cap, itemWeight, binSolve2)

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

    # Output
    WriteLog(pNumber, attackTimes, maxAttack, cap, itemWeight, itemProfit, attacker, True, 0)
    # ======

    for t in range (attackTimes):

        for _ignore in range (maxAttack):
            newDenfener = SpotAttack(cap, itemWeight, itemProfit, attacker.copy(), defener.copy())

            binAttacker = GenerateBinary(attacker)
            binDenfener = GenerateBinary(newDenfener)

            vioAttacker, _ = IsViolation(cap, itemWeight, binAttacker)
            vioDenfener, _ = IsViolation(cap, itemWeight, binDenfener)

            if (vioAttacker and vioDenfener):
                attacker = attacker.copy()
                defener = newDenfener.copy()
            elif (not vioAttacker and vioDenfener):
                attacker = attacker.copy()
                defener = newDenfener.copy()
            elif (vioAttacker and not vioDenfener):
                attacker = newDenfener.copy()
                defener = attacker.copy()
            else:
                profitAttacker = ComputingProfits(itemProfit, binAttacker)
                profitDenfener = ComputingProfits(itemProfit, binDenfener)
                if (profitAttacker > profitDenfener):
                    attacker = attacker.copy()
                    defener = newDenfener.copy()
                else:
                    attacker = newDenfener.copy()
                    defener = attacker.copy()

        defener, _ = GenerateInit(itemSize)
        
        # Output
        WriteLog(pNumber, attackTimes, maxAttack, cap, itemWeight, itemProfit, attacker, False, t)
        # ======

    isOptSolve = True
    binAttacker = GenerateBinary(attacker)
    for idx in range (len(binAttacker)):
        if (binAttacker[idx] != itemOptimal[idx]):
            isOptSolve = False
            break
    
    if (isOptSolve):
        print("P" + str(pNumber) + " is find optimal profit.")