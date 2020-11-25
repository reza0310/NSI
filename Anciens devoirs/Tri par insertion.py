liste = [12, 15, 34, 38, 35, 17]
i = 0
while i < len(liste)-1: #len(liste) passages maximum comme mminimum
    i += 1
    j = i
    while j >= 1 and liste[j] < liste[j-1]: #i passages maximum par itération de l'autre boucle soit len(liste)+1 * len(liste) passages maximum = len(liste)/2 * (liste[0] + liste[-1])
        x = liste[j]; liste[j] = liste[j-1]; liste[j-1] = x
        j -= 1
print(liste)