#-1-#
nbre = int(input("Combien d'éléments? "))
res = 0
nb = 0
while nb < nbre:
    texte = "Valeur n°"+str(nb+1)+" "
    val = float(input(texte))
    nb += 1
    res += val
print("Moyenne:",res/nb)

#-2-#
nbre = int(input("Combien d'éléments? "))
res = []
nb = 0
while nb < nbre:
    texte = "Valeur n°"+str(nb+1)+" "
    val = float(input(texte))
    nb += 1
    res.append(val)
    resu = 0
    for valeur in res:
        resu += valeur
    resu = resu/nb
print("Moyenne:",resu)

#-corec-#
nbre = int(input("Combien d'éléments? "))
def moyenne(n):
    liste=[]
    somme = 0
    for i in range(n):
        nombre = int(input("nombre"))
        somme = somme + nombre
        liste.append(nombre)
        moyenne = somme/len(liste)
    print(moyenne)
moyenne(nbre)

#-Natha-#
moy = 0
li=[]
n=0
try:
    while n>=0:
        n=float(input("le nombre"))
        li.append(n)
        moy= (n+moy)/len(li)
        print(moy)
except:
    print("ce n'est pas un nombre")
print("la moyenne de",li,"est de",moy)
# je sais pas si c'est une bonne idée