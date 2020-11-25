def fctA():
    print("Début fonction A")
    i=0
    while i<5:
        print(f"fctA {i}")
        i = i + 1
    print("Fin fonction A")

def fctB():
    print("Début fonction B")
    i=0
    while i<5:
        if i==3:
            fctA()
            print("Retour à la fonction B")
        print(f"fctB {i}")
        i = i + 1
    print("Fin fonction B")

fctB()