import random
from re import L
import numpy as np
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings('ignore')
random.seed(1101)

def SimulatedAnnealing(numSize = 1, epochTime = 10, recursionTime = 100, temperature = 100, beta = 0.99):
    coordinateList= []
    for _ in range (numSize):
        coordinateList.append(random.randint(10, 100))
    temperatureXlim = temperature
    acceptList = []
    temperatureList = []
    ansList = []

    for epoch in range (epochTime):

        countAccept = 0
        
        for t in range (recursionTime):

            deltaCoordinateList = []
            for idx in range (len(coordinateList)):
                deltaCoordinateList.append(coordinateList[idx] + random.uniform(-0.5, 0.5))
            
            tempSum = 0
            tempMul = 1
            tempDeltaSum = 0
            tempDeltaMul = 1
            for idx in range (numSize):
                tempSum += abs(coordinateList[idx])
                tempMul *= abs(coordinateList[idx])
                tempDeltaSum += abs(deltaCoordinateList[idx])
                tempDeltaMul *= abs(deltaCoordinateList[idx])

            tempDelta = tempDeltaSum + tempDeltaMul
            temp = tempSum + tempMul

            if (tempDelta <= temp):
                for idx in range (numSize):
                    coordinateList[idx] = deltaCoordinateList[idx]
            else:
                if (random.random() * np.exp((tempDelta - temp) / temperature) <= 1):
                    countAccept += 1
                    for idx in range (numSize):
                        coordinateList[idx] = deltaCoordinateList[idx]

        temperatureList.append(temperature)
        ansList.append(temp)
        acceptList.append(countAccept)

        temperature *= beta

    plt.figure(figsize=(32, 12))
    plt.grid(True)
    plt.plot(temperatureList, ansList)
    plt.xlim([temperatureXlim, 0])
    plt.savefig("./SA_" + str(epochTime) + "_Simulated.png", bbox_inches = "tight")

    plt.figure(figsize=(32, 12))
    plt.grid(True)
    plt.plot(temperatureList, acceptList)
    plt.xlim([temperatureXlim, 0])
    plt.savefig("./SA_" + str(epochTime) + "_Acception.png", bbox_inches = "tight")

def TabuList(index = [0, 1, 2, 3], iter = 1):
    flow = [
        [0, 5, 3, 1],
        [5, 0, 3, 0],
        [3, 3, 0, 1],
        [1, 0, 1, 0]
    ]
    distance = [
        [0, 1, 2, 3],
        [1, 0, 1, 2],
        [2, 1, 0, 1],
        [3, 2, 1, 0]
    ]
    tabuDictKey = []
    tabuDictValue = []
    for iter in range (iter):
        x1 = 0
        x2 = 1
        valueList = []
        FDList = []
        for c in range (7):
            value = 0
            for i in range (len(index)):
                for j in range (len(index)):
                    value += flow[i][j] * distance[index[i]][index[j]]
            FDList.append(index.copy())
            valueList.append(value)
            if (c != 0):
                temp = index[x1]
                index[x1] = index[x2]
                index[x2] = temp
                if (x2 == 3):
                    x1 += 1
                    x2 = x1 + 1
                else:
                    x2 += 1
            if (c == 6):
                break
            temp = index[x1]
            index[x1] = index[x2]
            index[x2] = temp
        maxIndex = 0
        for i in range (len(valueList) - 1):
            for j in range (i + 1, len(valueList)):
                if (valueList[i] > valueList[j]):
                    temp = valueList[i]
                    valueList[i] = valueList[j]
                    valueList[j] = temp
                    tempList = FDList[i].copy()
                    FDList[i] = FDList[j].copy()
                    FDList[j] = tempList
        if (len(tabuDictKey) == 0):
            i = np.argmin(valueList)
            tabuDictKey.append(FDList[i].copy())
            tabuDictValue.append(valueList[i])
            index = FDList[maxIndex]
        else:
            for i in range (len(FDList)):
                judge = []
                for key in (tabuDictKey):
                    count = 0
                    for k in range (len(FDList[i])):
                        if (FDList[i][k] == key[k]):
                            count += 1
                    judge.append(count == len(key))
                temp = 0
                for res in judge:
                    temp += res
                if (temp == 0):
                    maxIndex = i
                    break
            tabuDictKey.append(FDList[maxIndex].copy())
            tabuDictValue.append(valueList[maxIndex])
            index = FDList[maxIndex]
    # print(tabuDictKey)
    # print(tabuDictValue)
    f = open("./TabuList.txt", "w")
    for i in range (len(tabuDictKey)):
        for j in range (len(tabuDictKey[i])):
            f.write(str(tabuDictKey[i][j]) + " ")
        f.write(" : " + str(tabuDictValue[i]) + "\n")
    f.close()

if __name__ == "__main__":
    # SimulatedAnnealing(numSize = 5, epochTime = 1000, recursionTime = 10, beta = 0.95)
    TabuList(index = [0, 2, 1, 3], iter = 3)