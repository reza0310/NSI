from math import sqrt

def mesurer(p1, p2):
    if p1[0] >= p2[0]:
        terme1 = p1[0]-p2[0]
    else:
        terme1 = p2[0]-p1[0]
    if p1[1] >= p2[1]:
        terme2 = p1[1]-p2[1]
    else:
        terme2 = p2[1]-p1[1]
    return round(sqrt((terme1**2) + (terme2**2)), 2)

unite = input("Unité?")
taille = mesurer((25, 10), (2, 2))
print(taille, unite)