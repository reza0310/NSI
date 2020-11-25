liste = [1, 2, 4, 5, 7, 12, 24, 43, 58, 59]
chiffre = int(input("Quel chiffre à décomposer? "))
while chiffre not in liste:
    chiffre = int(input("Quel chiffre à décomposer? "))

num = 0
resultat = []
while num < chiffre:
    index = liste.index(chiffre)
    comp = liste[index-1]
    while comp > chiffre-num:
        index -= 1
        comp = liste[index-1]
    num += comp
    resultat.append(comp)
print(resultat)