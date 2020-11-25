import time
import timeit

n = int(input("Nombre"))
res = 1

#-1-#
debut = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
for i in range(n, 0, -1):
    res = res * i
print(res)
fin = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
print("Méthode 1 en",fin-debut)
res = 1

#-2-#
debut = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
i = 1
while i != n+1:
    res = res * i
    i += 1
print(res)
fin = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
print("Méthode 2 en",fin-debut)
res = 1

#-3-#
debut = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
def mult(un, deux):
    return un * deux

nombres = []
i = 1
while i != n+1:
    nombres.append(i)
    i += 1
for nombre in nombres:
    res = mult(res, nombre)
print(res)
fin = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
print("Méthode 3 en",fin-debut)
res = 1

#-4-#
'''def fact(n):
    global res
    if n > 1:
        res = fact(n-1)+n  #En cours
    else:
        res += 1
    return res
print(fact(n))'''
#corec:
debut = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
def fact(n):
    if n == 1:
        return(n)
    else:
        return(n*fact(n-1))
print(fact(n))
fin = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
print("Méthode 4 en",fin-debut)