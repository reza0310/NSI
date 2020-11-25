def carre(n):
    if n > 0:
        return carre(abs(n)-1)+2*abs(n)-1
    else:
        return 0

def souschaine(mot, debut, fin):
    return mot[debut:fin]

def palindrome(mot):
    if len(mot) == 1 or (len(mot) == 2 and mot[0] == mot[1]):
        return True
    elif mot[0] != mot[-1]:
        return False
    else:
        return palindrome(mot[1:-1])

print(carre(10))
print(palindrome("raddar"))
print(palindrome("radar"))
print(palindrome("test"))
print(palindrome("kayak"))