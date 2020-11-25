import tkinter as tk
from random import randint
import time
from PIL import Image, ImageTk

tours = ["joueur 1","joueur 2", "IA"]
tournages = 0
load = Image.open("grille.png")
render = ImageTk.PhotoImage(load)

def tournicoti():
    global tournages
    tour_de = tours[tournages]
    tournages +=1
    if tournages == len(tours)-1:
        tournages = 0
    return tour_de

#------------------------------------------------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------------------------------------------------------------------------------

def gravite():
    #Pour cases pas dernière ligne
    #Si case remplie
    #Remplir case d'en dessous
    #Vider case
    #refresh
    #sinon
    #renvoyer "c'est bon"
    for i in range (0, len(tableau)-a):
        if tableau[i]['contenu'] != "vide" and tableau[i+a]['contenu'] == "vide":
            tableau[i+a]['contenu'] = tableau[i]['contenu']
            tableau[i]['contenu'] = 'vide'
        else:
            continue
    refresh()

#------------------------------------------------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------------------------------------------------------------------------------

def assign_a():
    global a # rend a existant en dehors de la fonction
    a = int(tst.get()) #récup le nombre de cases par ligne et colonne ## récup = .get
    global dim_x, dim_y #récup et globalise les dimensions en pixels
    dim_x = int(dim_x.get())
    dim_y = int(dim_y.get())
    Param.destroy() #enlève les paramètres.
    c = 1 #num première colonne
    l = 1 #num première ligne de coque
    global tableau
    tableau = ["rien"]*a**2 #contient l'information des cases | a²*rien | copie rien fois le nombre de a au carré / a² = nombre de cases par ligne fois nombre de cases par colonne / nombre de case au carré
    for i in range (0, a*a, a): #déclanche la suite autant de fois qu'il y a de case par colonne
       for y in range (0,a): #déclanche la suite autant de fois qu'il y a de case par ligne
           infos = {"contenu":"vide"}
           infos["emplacement"] = str(c)+"|"+str(l)
##           i+y == y+(c-1)*a       enlevée car toujours vraie donc intéressante
           tableau[i+y] = infos
           l += 1 #change de ligne
       c += 1 #change de colonne
       l = 1 #réintialise la ligne
    global t_c, t_l
    t_l = (dim_x*a) // (a**2)
    t_c = (dim_y*a) // (a**2)
    print("a = ",a)
    print("taille ligne = ",t_l)
    print("taille colonne = ",t_c)
    print("nombre de cases = ",len(tableau))
    print("tableau = ",tableau)
    #marque tout les paramètres version physique
    global Canevas
    Canevas = tk.Canvas(Travail ,width = dim_x, height = dim_y)
    Canevas.pack()
    Canevas.bind("<Button-1>", click)
    refresh()
    #créée un graphisme (à modifié par moii )
#------------------------------------------------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------------------------------------------------------------------------------
def click(click):
    colonne = 1

    ligne = click.x/(t_l-1)
    l2 = round(ligne, 0)
    if l2 < ligne:
        ligne += 1
    ligne = round(ligne, 0)

    emp = str(int(colonne))+str("|")+str(int(ligne))
    for dico in tableau:
        if dico["emplacement"] == emp:
            if dico["contenu"] == "vide":
                tour_de = tournicoti()
                dico["contenu"] = tour_de
                refresh()
            elif dico["contenu"] in tours:
                dico["contenu"] = "vide"
                refresh()

#définit ce qu'il ce passe quand on clic
#------------------------------------------------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------------------------------------------------------------------------------
def refresh():
    x = 0
    fx = 0
    fy = 0
    dx = 0
    dy = 0
    fx = dx + t_l
    fy = dy + t_c
    for i in range (0,a*a,a):
        for y in range (0,a):
            nb_ds_list = i+y
            ta = tableau[nb_ds_list]
            if ta["contenu"] == "vide":
                couleur = 'black'
            elif ta["contenu"] == tours[0]:
                couleur = 'red'
            elif ta["contenu"] == tours[1]:
                couleur= 'yellow'
            Travail.after(1, colorer(dx, dy, fx, fy, couleur))
            dx = fx
            fx = fx + t_l
        dx = 0
        fx = dx + t_l
        dy = fy
        fy = fy + t_c
    for i in range (0, len(tableau)-a):
            if tableau[i]['contenu'] != "vide" and tableau[i+a]['contenu'] == "vide":
                gravite()
#remise a zero
#------------------------------------------------------------------------------------------------------------------------------------------------------------

def colorer(dx, dy, fx, fy, couleur):
    Canevas.create_rectangle(dx+1, dy+1, fx-1, fy-1, fill=couleur)

def vs_joueurs():

    Bouton = tk.Button(Param, text ='2 joueurs', command = assign_a)
    Bouton.grid(row = 5, column = 2)
    Bouton.pack

    Bouton = tk.Button(Param, text ='3 joueurs', command = assign_a)
    Bouton.grid(row = 6, column = 2)
    Bouton.pack

    Bouton = tk.Button(Param, text ='online', command = assign_a)
    Bouton.grid(row = 7, column = 2)
    Bouton.pack

    Bouton = tk.Button(Param, text ='local', command = assign_a)
    Bouton.grid(row = 8, column = 2)
    Bouton.pack

def modifs():

    Bouton = tk.Button(Param, text ='mode tetris', command = assign_a)
    Bouton.grid(row = 7, column = 3)
    Bouton.pack


#------------------------------------------------------------------------------------------------------------------------------------------------------------
Param = tk.Tk()
Param.title("Paramètres") #mettre en place fenètre 1 (paramètres)
Travail = tk.Tk()
Travail.title("Puissance 4") #mettre en place fenètre 2 (jeu)

Label1 = tk.Label(Param, text = 'Quelle taille?')
Label1.grid(row = 0, column = 0)

Label2 = tk.Label(Param, text = 'Dimension x de l\'écran')
Label2.grid(row = 1, column = 0)

Label3 = tk.Label(Param, text = 'Dimension y de l\'écran')
Label3.grid(row = 2, column = 0)
# texte qui demande les dimensions du jeu

tst = tk.StringVar()
Champ = tk.Entry(Param, textvariable= tst, bg ='white', fg='black')
Champ.focus_set()
Champ.grid(row = 0, column = 1)

dim_x = tk.StringVar()
Champ2 = tk.Entry(Param, textvariable= dim_x, bg ='white', fg='black')
Champ2.focus_set()
Champ2.grid(row = 1, column = 1)

dim_y = tk.StringVar()
Champ3 = tk.Entry(Param, textvariable= dim_y, bg ='white', fg='black')
Champ3.focus_set()
Champ3.grid(row = 2, column = 1)
#entrées de texte pour paramètres

Bouton = tk.Button(Param, text ='Valider', command = assign_a)
Bouton.grid(row = 1, column = 2)
Bouton.pack
#valider + redirige sur assign_a

Lab = tk.Label(Param, text ='-----', command = None)
Lab.grid(row = 4, column = 1)
Lab.pack

Bouton = tk.Button(Param, text ='vs ia', command = vs_joueurs)
Bouton.grid(row = 5, column = 1)
Bouton.pack

Bouton = tk.Button(Param, text ='vs joueur', command = vs_joueurs)
Bouton.grid(row = 6, column = 1)
Bouton.pack

Bouton = tk.Button(Param, text ='modifs', command = modifs)
Bouton.grid(row = 7, column = 1)
Bouton.pack

Param.mainloop()
Travail.mainloop()
#lancement des fenètres

#------------------------------------------------------------------------------------------------------------------------------------------------------------