import tkinter as tk
import sys
from PIL import ImageTk,Image

tours = ["joueur 1","joueur 2", "IA"]
tournages = 0

def debut():
    global tst, dim_x, dim_y, Param, Travail

    Param = tk.Tk()
    Param.title("Paramètres")  # mettre en place fenètre 1 (paramètres)
    Travail = tk.Tk()
    Travail.title("Puissance 4")  # mettre en place fenètre 2 (jeu)

    Label1 = tk.Label(Param, text='Quelle taille?')
    Label1.grid(row=0, column=0)

    Label2 = tk.Label(Param, text='Dimension x de l\'écran')
    Label2.grid(row=1, column=0)

    Label3 = tk.Label(Param, text='Dimension y de l\'écran')
    Label3.grid(row=2, column=0)
    # texte qui demande les dimensions du jeu

    tst = tk.StringVar()
    Champ = tk.Entry(Param, textvariable=tst, bg='white', fg='black')
    Champ.focus_set()
    Champ.grid(row=0, column=1)

    dim_x = tk.StringVar()
    Champ2 = tk.Entry(Param, textvariable=dim_x, bg='white', fg='black')
    Champ2.focus_set()
    Champ2.grid(row=1, column=1)

    dim_y = tk.StringVar()
    Champ3 = tk.Entry(Param, textvariable=dim_y, bg='white', fg='black')
    Champ3.focus_set()
    Champ3.grid(row=2, column=1)
    # entrées de texte pour paramètres

    Bouton = tk.Button(Param, text='Valider', command=initialisation)
    Bouton.grid(row=1, column=2)
    # valider + redirige sur initialisation

    Lab = tk.Label(Param, text='-----')
    Lab.grid(row=4, column=1)

    Bouton = tk.Button(Param, text='vs ia', command=vs_joueurs)
    Bouton.grid(row=5, column=1)

    Bouton = tk.Button(Param, text='vs joueur', command=vs_joueurs)
    Bouton.grid(row=6, column=1)

    Bouton = tk.Button(Param, text='modifs', command=modifs)
    Bouton.grid(row=7, column=1)

    Param.mainloop()

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def initialisation():
    global nbre_lignes_cols, dim_x, dim_y, tableau, taille_dune_colonne, taille_dune_ligne, Canevas,grille,Travail  # rend nbre_lignes_cols existant en dehors de la fonction
    nbre_lignes_cols = int(tst.get())  # récup le nombre de cases par ligne et colonne ## récup = .get
    dim_x = int(dim_x.get())
    dim_y = int(dim_y.get())
    Param.destroy()  # enlève les paramètres.

    Travail = tk.Tk()
    Travail.title("Puissance 4")  # mettre en place fenètre 2 (jeu)
    global grille
    grille = Image.open("grille.png")
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    tableau = ["vide"] * nbre_lignes_cols ** 2  # contient l'information des cases | nbre_lignes_cols²*rien | copie rien fois le nombre de nbre_lignes_cols au carré / nbre_lignes_cols² = nombre de cases par ligne fois nombre de cases par colonne / nombre de case au carré
    taille_dune_ligne = (dim_x) // (nbre_lignes_cols)
    taille_dune_colonne = (dim_y) // (nbre_lignes_cols)

    grille = grille.resize((taille_dune_ligne, taille_dune_colonne), Image.ANTIALIAS)
    grille = ImageTk.PhotoImage(grille)

    print("nbre_lignes_cols = ", nbre_lignes_cols)
    print("taille ligne = ", taille_dune_ligne)
    print("taille colonne = ", taille_dune_colonne)
    print("nombre de cases = ", len(tableau))

    Canevas = tk.Canvas(Travail, width=dim_x, height=dim_y)
    Canevas.pack()
    Canevas.bind("<Button-1>", click)
    refresh()
    Travail.after(10, refresh)
    Travail.mainloop()
    # créée un graphisme (a modifier par moi)

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def vs_joueurs():

    Bouton = tk.Button(Param, text ='2 joueurs', command = None)
    Bouton.grid(row = 5, column = 2)

    Bouton = tk.Button(Param, text ='3 joueurs', command = None)
    Bouton.grid(row = 6, column = 2)

    Bouton = tk.Button(Param, text ='online', command = None)
    Bouton.grid(row = 7, column = 2)

    Bouton = tk.Button(Param, text ='local', command = None)
    Bouton.grid(row = 8, column = 2)

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def modifs():

    Bouton = tk.Button(Param, text ='mode tetris', command = None)
    Bouton.grid(row = 7, column = 3)

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def refresh():
    global grille
    debut_axe_x = 0
    debut_axe_y = 0
    fin_axe_x = debut_axe_x + taille_dune_ligne
    fin_axe_y = debut_axe_y + taille_dune_colonne
    for i in range (0,nbre_lignes_cols*nbre_lignes_cols,nbre_lignes_cols):
        for y in range (0,nbre_lignes_cols):
            nb_ds_list = i+y
            ta = tableau[nb_ds_list]
            if ta == "vide":
                couleur = 'black'
            elif ta == tours[0]:
                couleur = 'red'
            elif ta == tours[1]:
                couleur = 'yellow'

            Canevas.create_rectangle(debut_axe_x+1, debut_axe_y+1, fin_axe_x-1, fin_axe_y-1, fill=couleur)
            Canevas.create_image((debut_axe_x+fin_axe_x)/2, (debut_axe_y+fin_axe_y)/2,image=grille)

            debut_axe_x = fin_axe_x
            fin_axe_x = fin_axe_x + taille_dune_ligne
        debut_axe_x = 0
        fin_axe_x = debut_axe_x + taille_dune_ligne
        debut_axe_y = fin_axe_y
        fin_axe_y = fin_axe_y + taille_dune_colonne
    for i in range (0, len(tableau)-nbre_lignes_cols):
            if tableau[i] != "vide" and tableau[i+nbre_lignes_cols] == "vide":
                gravite()
    victoire()
# Mise à jour de l'affichage

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def click(click):
    colonne = click.x/(taille_dune_ligne)
    colonne = int(colonne)
    if tableau[colonne] == "vide":
        tour_de = tournicoti()
        tableau[colonne] = tour_de
        refresh()
    else:
        print("Haut du tableau dépassé")
# définit ce qu'il ce passe quand on clic

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def victoire():
    for i in range (0, len(tableau)-1):
        if tableau[i] != "vide":
            if tableau[i+1] == tableau[i] and tableau[i+2] == tableau[i] and tableau[i+3] == tableau[i]:
                def click():
                    return
                Victoire = tk.Tk()
                Victoire.title(Victoire)
                Texte = tableau[i]+" a gagné."
                Lab = tk.Label(Victoire, text=Texte)
                Lab.pack()
                Victoire.mainloop()
            try:
                if tableau[i+nbre_lignes_cols] == tableau[i] and tableau[i+2*nbre_lignes_cols] == tableau[i] and tableau[i+3*nbre_lignes_cols] == tableau[i]:
                    def click():
                        return
                    Victoire = tk.Tk()
                    Victoire.title(Victoire)
                    Texte = tableau[i]+" a gagné."
                    Lab = tk.Label(Victoire, text=Texte)
                    Lab.pack()
                    Victoire.mainloop()
            except:
                continue
            try:
                if tableau[i+nbre_lignes_cols+1] == tableau[i] and tableau[i+2*nbre_lignes_cols+2] == tableau[i] and tableau[i+3*nbre_lignes_cols+3] == tableau[i]:
                    def click():
                        return
                    Victoire = tk.Tk()
                    Victoire.title(Victoire)
                    Texte = tableau[i]+" a gagné."
                    Lab = tk.Label(Victoire, text=Texte)
                    Lab.pack()
                    Victoire.mainloop()
            except:
                continue
            try:
                if tableau[i+nbre_lignes_cols-1] == tableau[i] and tableau[i+2*nbre_lignes_cols-2] == tableau[i] and tableau[i+3*nbre_lignes_cols-3] == tableau[i]:
                    def click():
                        return
                    Victoire = tk.Tk()
                    Victoire.title(Victoire)
                    Texte = tableau[i]+" a gagné."
                    Lab = tk.Label(Victoire, text=Texte)
                    Lab.pack()
            except:
                continue

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def tournicoti():
    global tournages
    tour_de = tours[tournages]
    tournages += 1
    if tournages == len(tours)-1:
        tournages = 0
    return tour_de

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

def gravite():

    for i in range (0, len(tableau)-nbre_lignes_cols):
        if tableau[i] != "vide" and tableau[i+nbre_lignes_cols] == "vide":
            tableau[i+nbre_lignes_cols] = tableau[i]
            tableau[i] = 'vide'
        else:
            continue
    refresh()

# ------------------------------------------------------------------------------------------------------------------------------------------------------------

debut()