import numpy as np
import sys

def BestString(x, y, mismatch, gap):
    i = 0
    j = 0

    m = len(x)
    n = len(y)
     
    matrix = np.zeros([m+1,n+1], dtype = int)

    matrix[0 : (m+1), 0] = [ i * gap for i in range(m+1) ]
    matrix[0, 0 : (n+1)] = [ i * gap for i in range(n+1) ]
 
    i = 1
    while (i <= m):
        j = 1
        while (j <= n):
            if (x[i - 1] == y[j - 1]):
                matrix[i][j] = matrix[i - 1][j - 1]
            else:
                matrix[i][j] = min(matrix[i - 1][j - 1] + mismatch, matrix[i - 1][j] + gap, matrix[i][j - 1] + gap)
            j += 1
        i += 1
     
    l = n + m
    i = m
    j = n
     
    xPos = l
    yPos = l
 
    xAns = np.zeros(l+1, dtype = int)
    yAns = np.zeros(l+1, dtype = int)

    while (not (i == 0 or j == 0)):
        if (x[i - 1] == y[j - 1]):       
            xAns[xPos] = ord(x[i - 1])
            yAns[yPos] = ord(y[j - 1])
            xPos -= 1
            yPos -= 1
            i -= 1
            j -= 1
        elif ((matrix[i - 1][j - 1] + mismatch) == matrix[i][j]):
            xAns[xPos] = ord(x[i - 1])
            yAns[yPos] = ord(y[j - 1])
            xPos -= 1
            yPos -= 1
            i -= 1
            j -= 1
        elif ((matrix[i - 1][j] + gap) == matrix[i][j]):
            xAns[xPos] = ord(x[i - 1])
            yAns[yPos] = ord('_')
            xPos -= 1
            yPos -= 1
            i -= 1
        elif ((matrix[i][j - 1] + gap) == matrix[i][j]):
            xAns[xPos] = ord('_')
            yAns[yPos] = ord(y[j - 1])
            xPos -= 1
            yPos -= 1
            j -= 1

    while (xPos > 0):
        if (i > 0):
            i -= 1
            xAns[xPos] = ord(x[i])
            xPos -= 1
        else:
            xAns[xPos] = ord('_')
            xPos -= 1
     
    while (yPos > 0):
        if (j > 0):
            j -= 1
            yAns[yPos] = ord(y[j])
            yPos -= 1
        else:
            yAns[yPos] = ord('_')
            yPos -= 1

    id = 1
    i = l
    while (i >= 1):
        if (chr(yAns[i]) == '_') and chr(xAns[i]) == '_':
            id = i + 1
            break        
        i -= 1

    i = id
    xSeq = ""
    while (i <= l):
        xSeq += chr(xAns[i])
        i += 1

    i = id
    ySeq = ""
    while (i <= l):
        ySeq += chr(yAns[i])
        i += 1

    ptr = ""
    if (len(xSeq) > len(ySeq)):
        ptr = "y"
        minLen = len(ySeq)
    else:
        ptr = "x"
        minLen = len(xSeq)

    bestGene = ""
    for i in range (minLen):
        if (xSeq[i] == "_"):
            bestGene += ySeq[i]
        elif (ySeq[i] == "_"):
            bestGene += xSeq[i]
        elif (ptr == "x"):
            bestGene += xSeq[i]
        else:
            bestGene += ySeq[i]
    if (len(xSeq) != len(ySeq)):
        if (ptr == "x"):
            bestGene += ySeq[minLen:]
        else:
            bestGene += xSeq[minLen:]
    return bestGene

if __name__ == "__main__":
    bioFile1 = "./covid19_strains.fa"

    mismatchScore = 3
    gapScore = 2
    bioGene1 = ""

    geneList = []

    f = open(bioFile1, "r")
    for text in f:
        text = text.strip("\n")
        text = text.upper()
        if (text[0] == "A" or text[0] == "T" or text[0] == "C" or text[0] == "U" or text[0] == "G"):
            bioGene1 += text
        else:
            if (bioGene1 != ""):
                geneList.append(bioGene1)
                bioGene1 = ""
    if (text[0] == "A" or text[0] == "T" or text[0] == "C" or text[0] == "U" or text[0] == "G"):
        bioGene1 += text
    if (bioGene1 != ""):
        geneList.append(bioGene1)
    f.close()

    bioGene1 = geneList[0]
    bioGene2 = geneList[1]

    selectRange = 100
    actualRange = min(selectRange, len(bioGene1), len(bioGene2))

    print(len(bioGene1))
    print(len(bioGene2))

    geneSeq1 = bioGene1[:actualRange]
    geneSeq2 = bioGene2[:actualRange]

    bestGene = BestString(geneSeq1, geneSeq2, mismatchScore, gapScore)
    actualRange = len(bestGene)
    
    for gene in geneList[2:]:
        bioGene1 = gene
        bioGene2 = bestGene

        actualRange = len(bestGene)

        geneSeq1 = bioGene1[:actualRange]
        geneSeq2 = bioGene2[:actualRange]
        bestGene = BestString(geneSeq1, geneSeq2, mismatchScore, gapScore)
    
    outFile = "./out_" + str(selectRange) + "_" + str(actualRange) + "_BestGenes.txt"
    f = open(outFile, "w")
    f.write("Best Gene:\n")
    f.write(bestGene + "\n")
    f.close()