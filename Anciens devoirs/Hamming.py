'''
Algo:

Initialisation:
a <- chaine 1
b <- chaine 2
Hamming <- taille de la chaine la plus longue
i <- 1

Hérédité:
Tant que i <= taille de la chaine la plus longue:
-Si element i de a = element i de b:
--Hamming <- Hamming - 1
'''

a = "lolililu"
b = "momililully"
if len(a) > len(b):
    Hamming = len(a)
else:
    Hamming = len(b)
liste = list(zip(a,b))
for element in liste:
    if element[0] == element[1]:
        Hamming -= 1
print(Hamming)