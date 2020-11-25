from random import *
gagne = False
chiffre_a_deviner = randint(0, 100)
min = 0
max = 100
essais = 0
while not gagne:
    chiffre = int((min + max)/2)
    if chiffre > chiffre_a_deviner:
        max = chiffre
        essais += 1
    elif chiffre < chiffre_a_deviner:
        min = chiffre
        essais += 1
    elif chiffre_a_deviner == chiffre:
        essais += 1
        print("VOUS AVEZ GAGNE EN",essais,"ESSAIS!!! BIEN JOUE!!!")
        gagne = True
    print(min,"< ... <",max)

#L * (1/2)**k = 1
#avec L = nombre de possibiltés et k = nombre d'essais
#100*(1/2)**6 > 1
#100*(1/2)**7 < 1