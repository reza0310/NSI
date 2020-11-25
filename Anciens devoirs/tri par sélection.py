'''
Algo:

Hérédité:
Pour chaque valeur de "index" variant de 1 a len:
-Pour chaque valeur "traité" variant de index+1 a len:
--min = traité
--Si l'élément traité < l'élément min alors min <- traité
-Intervertir l'élément index+1 de liste avec l'élément min de liste

Variables:
len = longueur de la liste initiale
liste = liste a trier
min = index du minimum
'''

liste = [18, 12, 25, 32, 67, 50, 10, 59, 10, 28, 31]

for index in range(len(liste)):
    traite = index+1
    min = index
    while traite < len(liste):
        if liste[traite] < liste[min]:
            min = traite
        traite += 1
    temp = liste[index]; liste[index] = liste[min]; liste[min] = temp

print(liste)