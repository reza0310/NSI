"""class PILE():
    def __init__(self):
        self.contenu = []

    def ajouter(self, elements):
        self.contenu += [elements]

    def retirer(self):
        return self.contenu.pop(len(self.contenu)-1)


class FILE():
    def __init__(self):
        self.contenu = []

    def ajouter(self, elements):
        self.contenu.insert(0, elements)

    def retirer(self):
        return self.contenu.pop(len(self.contenu)-1)


pile = PILE()
pile.ajouter(1)
print(pile.contenu)
pile.ajouter(2)
print(pile.contenu)
pile.ajouter(3)
print(pile.contenu)
pile.retirer()
print(pile.contenu)

print()

file = FILE()
file.ajouter(1)
print(file.contenu)
file.ajouter(2)
print(file.contenu)
file.ajouter(3)
print(file.contenu)
file.retirer()
print(file.contenu)"""

MEMOIRE = []
for i in range(10):
    MEMOIRE.append([])
for x in MEMOIRE:
    for i in range(10):
        x.append([])

MEMOIRE[1][2] = [1, (1, 4)]
MEMOIRE[1][4] = [122, (-1)]
liste = {"deb":(1,2)}