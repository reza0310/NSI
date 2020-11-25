chiffre = int(input("Quelle table?"))
for i in range(20):
    res = (i+1) * chiffre
    etoile = ""
    if res%7 == 0:
        etoile += "**"
    if res%3 == 0:
        etoile += "*"
    print(chiffre,"x",i+1,"=",res,etoile)