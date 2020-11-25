def dichotomie(V, T2):
    C = len(T2)/2
    if type(C) != "int":
        C = int(C)
    m = T2[C]
    min = 1; max = len(T2)
    while m != V:
        if m < V:
            min = C+1
        else:
            max = C-1
        C = int((min + max)/2)
        m = T2[C]
    print("Valeur trouvée au rang", C)

def dichotomie_corrigé1(V, T2):
    if V in T2:
        C = len(T2)/2
        if type(C) != "int":
            C = int(C)
        m = T2[C]
        min = 1; max = len(T2)
        while m != V:
            if m < V:
                min = C+1
            else:
                max = C-1
            C = int((min + max)/2)
            m = T2[C]
        print("Valeur trouvée au rang", C)
    else:
        print("Valeur hors liste")

def dichotomie_corrigé2(V, T2):
    C = len(T2)/2
    min = 1; max = len(T2)
    if type(C) != "int":
        C = int(C)
    m = T2[C]
    while m != V:
        if m < V:
            min = C+1
        else:
            max = C-1
        if min > max:
            print('hors liste')
            C = "hors liste"
            break
        C = int((min + max)/2)
        if C < len(T2):
            m = T2[C]
        else:
            print('hors liste')
            C = "hors liste"
            break
    print("Valeur trouvée au rang", C)

liste = [1,6,7,8,9,11,15,17,22,25,27,34,35,36,45,47,51,77,78,82,84,86,90,98,101,110,111,121]
valeur = int(input("Entrez la valeur"))
dichotomie_corrigé2(valeur, liste)