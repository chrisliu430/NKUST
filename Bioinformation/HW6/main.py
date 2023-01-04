import random

def AverageDegrees(g):
    totalDegress = 0
    for i in range (len(g)):
        for j in range (i + 1, len(g[i])):
            if (g[i][j] == 1):
                totalDegress += 1
    return (totalDegress / len(g))

def RandomGraph(n, p = 0.5):
    g = []
    for i in range (n):
        v = []
        for j in range (i):
            if (random.uniform(0, 1) >= p):
                v.append(1)
            else:
                v.append(0)
        v.append(0)
        g.append(v)
    for i in range (n):
        for j in range (i + 1, n):
            g[i].append(g[j][i])
    return g

if __name__ == "__main__":
    randomG = RandomGraph(1000)
    # print(randomG)
    avgDegrees = AverageDegrees(randomG)
    print(avgDegrees)