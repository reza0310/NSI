#-------------------------------------------------------------------------------
def dist_hamming(m1,m2,l1,l2):
    if l1>l2:
        d=l1-l2
    elif l2>l1:
        d=l2-l1
    else:
        d = 0
    for a,b in zip(m1,m2):
        if a != b :
            d += 1
    return d

mot1=input("Première chaîne : ")
lon1=len(mot1)
mot2=input("Seconde chaîne : ")
lon2=len(mot2)
dist=dist_hamming(mot1,mot2,lon1,lon2)
print ("Distance de Hamming entre ",mot1, " et ", mot2," = ",dist)

