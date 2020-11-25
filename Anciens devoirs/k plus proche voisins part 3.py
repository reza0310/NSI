import matplotlib.pyplot as plt
from math import sqrt

def distance_cible(donnee):
    #return sqrt(abs(donnee["coordonnees"][0] - cible[0])**2 + abs(donnee["coordonnees"][1] - cible[1])**2)
    return abs(donnee["coordonnees"][0] - cible[0]) + abs(donnee["coordonnees"][1] - cible[1])

def k_plus_proches_voisins(table, k):
    table_triee = sorted(table, key = distance_cible)
    proches_voisins = []
    for i in range(k):
        proches_voisins.append(table_triee[i])
    return proches_voisins

donnees = ({"label":"t1", "coordonnees":(1, 28)},
           {"label":"t1", "coordonnees":(3, 27.2)},
           {"label":"t1", "coordonnees":(8, 37.6)},
           {"label":"t1", "coordonnees":(7.5, 34)},
           {"label":"t1", "coordonnees":(13, 40.7)},
           {"label":"t2", "coordonnees":(2, 30)},
           {"label":"t2", "coordonnees":(3, 26)},
           {"label":"t2", "coordonnees":(10, 39)},
           {"label":"t2", "coordonnees":(15, 35.5)})

cible = (7, 30)

nbre = int(input("Combien de voisins? "))

elements = k_plus_proches_voisins(donnees, nbre)

fig, ax = plt.subplots()

plt.axis([0,15, 0, 50]) # Attention [x1,x2,y1,y2]
plt.xlabel('Caractéristique 1')
plt.ylabel('Caractéristique 2')
plt.title('Représentation des deux types')
plt.axis('equal') # pour avoir un repère orthonormé. Faire des tests.
plt.grid()

liste_x_1 = []; liste_y_1 = []; liste_x_2 = []; liste_y_2 = []
for don in donnees:
    if don["label"] == "t1":
        liste_x_1.append(don["coordonnees"][0])
        liste_y_1.append(don["coordonnees"][1])
    else:
        liste_x_2.append(don["coordonnees"][0])
        liste_y_2.append(don["coordonnees"][1])

plt.scatter(liste_x_1,liste_y_1, label='type 1')
plt.scatter(liste_x_2,liste_y_2, label='type 2')
plt.scatter(cible[0],cible[1], label='cible')
plt.legend()

compteur = 1
for element in elements:
    txt = "Voisin n°"+str(compteur)+" : "+element["label"]+" aux coordonnées "+str(element["coordonnees"])
    ax.add_artist(plt.Circle((cible[0], cible[1]), distance_cible(element), edgecolor='b', facecolor='none'))
    compteur += 1
    print(txt)

plt.show()