'''
Algorithme:

Tests possibles:
Vérifier que l'utilisateur n'ai pas rentré n'importe quoi
Vérifier qu'il ne reste pas de monnaie à rendre à la fin
Vérifier que la somme ne dépasse pas les centimes

Initialisation:
chiffre <- Demander à l'utilisateur
liste de pieces <- Constante de l'énnoncé (tuple) triée par ordre décroissant
paquet à rendre <- liste des pieces / pile des pieces à rendre

Coeur du programme:
Pour chaque piece par ordre décroissant,
    Tant que la somme à rendre est supérieure à la valeur de la piece,
        Ajouter la piece au paquet à rendre
        Retirer la valeur de la piece de la somme encore a rendre
Si la somme restante est nulle alors,
    Rendre le paquet à rendre
Sinon,
    Dire que la machine ne dispose pas de la monnaie nécessaire car
    il ne peut s'agir que de pièces inférieures à la plus petite de la liste.
'''


pieces = (2, 1, 0.5, 0.2, 0.1, 0.05)
chiffre = 0
while type(chiffre) != float:
    try:
        chiffre = float(input("Combien voulez-vous retirer? "))
    except:
        print("La valeur demandée est un nombre")
result = []
nbre = 0
for piece in pieces:
    while chiffre >= piece:
        chiffre = round(chiffre - piece, 3)
        result.append(piece)
        nbre += 1
if chiffre != 0.0:
    print("On a pas la monnaie nécessaire...")
else:
    print("Voilà vos",nbre,"pièces:", result)