from random import randint

def genereListe():
    return [randint(0, 99) for i in range(100)]

def combienNonPresents(V):
    cpt = 0
    for i in range(100):
        if not i in V:
            cpt += 1
    return cpt

resultats = [combienNonPresents(genereListe()) for i in range(30)]
print(sum(resultats)/len(resultats))