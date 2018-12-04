import json

def CalculateHash(word):
    value = 0


    primeList =  [20771,20773,20789,20807,20809,20849,20857,20873,20879,20887,20899,20903,20921,20929,20939]
    primeList2 = [21121,21139,21143,21149,21157,21163, 21169,21179,21187,21191,21193,21211,21221,21227,21247,212692]
    primeList3 = [20261,20269,20287,20297,20323,20327,20333,20341,20347,20353, 19423,19427,19429,19433,19441,19447,19457,19463,19469,19471]
    primeList.extend(primeList2)
    primeList.extend(primeList3)
    for char in word.lower():
        position = ord(char) - ord('a')
        if position >=0 and position <= 25:
           value = (value + primeList[position])%(10**9 + 7)
    return value

wordSet = [(x, CalculateHash(x)) for x in  (json.loads(open("").read()).iterkeys())]

def isAnagram(w1, w2):
    return len(w1) == len(w2) and sorted(w1) == sorted(w2)
cntr = 0
hashDict = dict()
col = []
for hashAndWord in wordSet:
    if hashAndWord[1] in hashDict:
        hashDict[hashAndWord[1]].append(hashAndWord[0])
    else:
        hashDict[hashAndWord[1]] = [hashAndWord[0]]

cntr = 0
for words in hashDict.itervalues():
    for i in range(0, len(words)):
        for j in range(0, len(words)):
            if i == j:
                continue
            if not isAnagram(words[i], words[j]):
                print(words[i], words[j], len(words[i]), len(words[j]))
                cntr += 1
print(cntr)
   

