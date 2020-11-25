from math import sqrt

def distance_cible(donnee):
    return sqrt(abs(donnee["coordonnees"][0] - cible[0])**2 + abs(donnee["coordonnees"][1] - cible[1])**2)

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

elements = k_plus_proches_voisins(donnees, len(donnees))
compteur = 1
for element in elements:
    txt = "Voisin n°"+str(compteur)+" : "+element["label"]+" aux coordonnées "+str(element["coordonnees"])
    compteur += 1
    print(txt)