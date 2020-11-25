class str_modif(str):
    def __len__(self):
        super().__len__()
        n=0
        save = self
        while save != "":
            n += 1
            save = save[1:]
        print("42! Ha nan... "+str(n))
        return n

texte = str_modif("Cadeau!")
print(len(texte))