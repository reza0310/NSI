def dichotomie_fonct(Val, bornes):
    C = (bornes[0]+bornes[1])/2
    min = bornes[0]; max = bornes[1]
    m = (min, max)
    while max-min > 0.00001:
        if f(C) < Val:
            min = C
        else:
            max = C
        C = (min + max)/2
        m = (min, max)
    print("Valeur trouvée dans l'intervalle", m)

def f(x):
    return (x**3)-(2*(x**2))-2*x+2

bornes = (-3, 0)
Valeur = 0
dichotomie_fonct(Valeur, bornes)