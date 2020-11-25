# dichotomie sur liste
Liste=[1,6,7,8,9,11,15,17,22,25,27,34,35,36,45,47,51,77,78,82,84,86,90,98,101,110,111,121] # = [0,100]
longueur_de_la_liste=len(Liste) # = 100

V=int(input("Valeur cherchée ? ")) # aléatoire
index_du_milieu=longueur_de_la_liste//2 # int((min + max)/2)
#C_old=0 # l'ancien C
milieu=Liste[index_du_milieu] # L'élément du milieu de la liste
min=0; max=longueur_de_la_liste-1 #min = 0 et max = 100

while milieu!=V:
    if milieu<V:
        min=index_du_milieu+1
    else:
        max=index_du_milieu-1
    #C_old=index_du_milieu
    index_du_milieu=int((min + max)/2)
    milieu=Liste[index_du_milieu]

#if  C==C_old:
#    print (V," n'est pas une valeur de la liste")
#else:
print("Valeur ",V," trouvée au rang ",index_du_milieu)
