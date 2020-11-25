'''
Algorithme:

Initialisation:
i <- 1
result <- []
place_r <- 15

Hérédité:
Tant que i < ou = nbre_objets,
-Tant que place_r < ou = poids[i],
--Retirer poids[i] a place_r
--Ajouter objet[i] a result
-Incrémenter i de 1
Afficher result

Variables:
i: Variable d'itération
nbre_objets: Nombre d'objets
liste_objets: liste des objets triés par ordre décroissant de prix/poids
place_r: Place restante dans le sac
poids: Liste des poids
result: Liste des objets que l'on prendras
'''

class objet():
    ordre = []
    def __init__(self, numero, poids, prix):
        self.prix = prix
        self.poids = poids
        self.num = numero
        self.rapport = prix/poids
        index = 0
        for i in range(len(objet.ordre)):
            if self.rapport < objet.ordre[i].rapport:
                index += 1
        objet.ordre.insert(index, self)

objets = [objet(1, 12, 4), objet(2, 2, 2), objet(3, 1, 2), objet(4, 1, 1), objet(5, 4, 10)]
objets_ordones = []
for i in range(len(objets)):
    objets_ordones.append(objets[objet.ordre[i].num-1])

i = 0
result = []
place_r = 15
while i <= len(objets_ordones)-1:
    while place_r >= objets_ordones[i].poids:
        place_r -= objets_ordones[i].poids
        result.append(objets_ordones[i])
    i += 1
print("Nous embarquerons:")
precedent = result[0]
nombre = 0
for truc in result:
    if truc != precedent:
        if nombre > 1:
            s = "s"
        else:
            s = ""
        texte = "-"+str(nombre)+" objet"+s+" numéro "+str(precedent.num)+" de masse"+s+" "+str(precedent.poids)+"kg pour un prix de "+str(precedent.prix)+"€"
        print(texte)
        nombre = 1
    else:
        nombre += 1
    precedent = truc

if nombre > 1:
    s = "s"
else:
    s = ""
texte = "-"+str(nombre)+" objet"+s+" numéro "+str(precedent.num)+" de masse"+s+" "+str(precedent.poids)+"kg pour un prix de "+str(precedent.prix)+"€"
print(texte)