import threading #Ca annonce la couleur
from random import randint
import time

def selection(liste):
    for index in range(len(liste)):
        traite = index + 1
        min = index
        while traite < len(liste):
            if liste[traite] < liste[min]:
                min = traite
            traite += 1
        temp = liste[index]
        liste[index] = liste[min]
        liste[min] = temp
    print("Tri par sélection terminé en",time.time()-debut,"secondes.")
    print(liste)

def insertion(liste):
    i = 0
    while i < len(liste) - 1:  # len(liste) passages maximum comme mminimum
        i += 1
        j = i
        while j >= 1 and liste[j] < liste[j - 1]:  # i passages maximum par itération de l'autre boucle soit len(liste)+1 * len(liste) passages maximum = len(liste)/2 * (liste[0] + liste[-1])
            x = liste[j]; liste[j] = liste[j - 1]; liste[j - 1] = x
            j -= 1
    print("Tri par insertion terminé en",time.time()-debut,"secondes.")
    print(liste)

def insertion2(liste):
    i = 0
    while i < len(liste) - 1:  # len(liste) passages maximum comme mminimum
        i += 1
        j = i
        while j >= 1 and liste[j] < liste[j - 1]:  # i passages maximum par itération de l'autre boucle soit len(liste)+1 * len(liste) passages maximum = len(liste)/2 * (liste[0] + liste[-1])
            x = liste[j]; liste[j] = liste[j - 1]; liste[j - 1] = x
            j -= 1
    return liste

def quicksort(liste):
    murs = []
    calc = len(liste) // 10
    for i in range(1, 11):
        murs.append(liste[i*calc-1])
    murs = insertion2(murs)
    listes = [[], [], [], [], [], [], [], [], [], [], []]
    for element in liste:
        traite = False
        for i in range(10):
            if element < murs[i] and not traite:
                listes[i].append(element)
                traite = True
        if not traite:
            listes[-1].append(element)
    for liste in listes:
        liste = insertion2(liste)
    lf = []
    for i in range(10):
        lf.append(murs[i])
        lf.extend(listes[i])
    lf.extend(listes[-1])
    for element in murs:
        lf.pop(lf.index(element))
    print("Tri par quicksort terminé en",time.time()-debut,"secondes.")
    print(lf)

def tri_de_leval_1(tab):
    n=len(tab)
    nb_passage=0
    while nb_passage<n-1:
        for j in range(0, n-1):
            if tab[j]>tab[j+1]:
                x=tab[j+1];tab[j+1]=tab[j];tab[j]=x
        nb_passage=nb_passage+1
    print("Tri par tri_de_leval_1 terminé en",time.time()-debut,"secondes.")
    print(tab)

def tri_bulle(liste):
    permutation = True
    passage = 0
    while permutation == True:
        permutation = False
        passage = passage + 1
        for en_cours in range(0, len(liste) - passage):
            if liste[en_cours] > liste[en_cours + 1]:
                permutation = True
                # On echange les deux elements
                liste[en_cours], liste[en_cours + 1] = \
                    liste[en_cours + 1], liste[en_cours]
    print("Tri par tri bulle terminé en",time.time()-debut,"secondes.")
    print(liste)

donnees = []
for i in range(2000):
    donnees.append(randint(0, 100))

#donnees = [100,99,98,97,1,2,3,4,5,97,93,91]

print("Les données de base sont:", donnees)
tri1 = threading.Thread(target=selection, args=[donnees])
tri2 = threading.Thread(target=insertion, args=[donnees])
tri3 = threading.Thread(target=quicksort, args=[donnees])
tri4 = threading.Thread(target=tri_de_leval_1, args=[donnees])
tri5 = threading.Thread(target=tri_bulle, args=[donnees])
debut = time.time()
tri1.start()
tri2.start()
tri3.start()
tri4.start()
tri5.start()
tri1.join()
tri2.join()
tri3.join()
tri4.join()
tri5.join()