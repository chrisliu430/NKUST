import sys

def MatchSubstring(mainPtr, subPtr, mainStr, subStr):
    if ((len(mainStr) - mainPtr) >= len(subStr)):
        for idx in range (subPtr, len(subStr)):
            if (mainStr[mainPtr] == subStr[idx]):
                mainPtr += 1
            else:
                return False, 0
        return True, 0
    else:
        for idx in range (mainPtr, len(mainStr)):
            if (mainStr[idx] == subStr[subPtr]):
                subPtr += 1
            else:
                return False, 0
        return True, len(mainStr) - mainPtr

if __name__ == "__main__":
    if (len(sys.argv) < 2):
        print("No Input file.")
        sys.exit()
        
    if (len(sys.argv) >= 2):
        bioFile = sys.argv[1]
    
    if (len(sys.argv) >= 3):
        assemblyLower = int(sys.argv[2])
    else:
        assemblyLower = 0
    
    storageSlice = []
    storageKey = []
    dictRNA = {}
    dictFlag = False
    key = ""
    value = ""
    
    f = open(bioFile, "r")
    for text in f:
        text = text.strip("\n")
        if (not dictFlag):
            key = text
            storageKey.append(key)
            dictFlag = True
        elif (text[0] != ">"):
            value = text
        else:
            dictRNA[key] = value
            key = text
            storageKey.append(key)
    dictRNA[key] = value
    f.close()
    
    if (len(sys.argv) >= 4):
        assemblyUpper = int(sys.argv[3])
    else:
        assemblyUpper = len(storageKey) - 1
        
    if (len(sys.argv) >= 5):
        outFile = sys.argv[4]
    else:
        outName = bioFile.strip("./")
        outName = outName.strip("txt")
        outName = outName.strip(".")
        outFile = "./out_" + outName + "_" + str(assemblyUpper) + "_" + str(assemblyLower) + ".txt"

    for idx in range (assemblyLower, assemblyUpper + 1):
        storageSlice.append(dictRNA[storageKey[idx]])
    
    assemblyResult = storageSlice[0]
    for sentence in storageSlice[1:]:
        completeFlag = False
        for idx in range (len(assemblyResult) + 1):
            if (idx == len(assemblyResult)):
                break
            elif (assemblyResult[idx] == sentence[0]):
                mergeFlag, mergePos = MatchSubstring(idx, 0, assemblyResult, sentence)
                if (mergeFlag):
                    if (mergePos != 0):
                        assemblyResult = assemblyResult + sentence[mergePos:]
                        completeFlag = True
                        break
                    else:
                        completeFlag = True
                        break
        if (not completeFlag):
            assemblyResult = assemblyResult + sentence
            
    f = open(outFile, "w")
    f.write(assemblyResult + "\n")
    f.close()