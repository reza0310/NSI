class Noeud:
    def __init__(self, key, rank, exp):
        self.gauche=None
        self.droite=None
        self.value=key
        self.rank=rank
        self.exp=exp

    def developper(self):
        calculs = prios(self.exp[0:self.rank])
        if len(calculs) != 0:
            self.gauche = Noeud(calculs[0][0],calculs[0][1],self.exp[0:self.rank])
            self.gauche.developper()
        else:
            self.gauche = Noeud(self.exp[0:self.rank],None,None)
        calculs = prios(self.exp[self.rank+1:])
        if len(calculs)!=0:
            self.droite = Noeud(calculs[0][0],calculs[0][1],self.exp[self.rank+1:])
            self.droite.developper()
        else:
            self.droite = Noeud(self.exp[self.rank+1:],None,None)

    def pprint(self, level=0):
        if self.droite:
            self.droite.pprint(level+1)
        print(f"{' '* 4 * level}{self.value}")
        if self.gauche:
            self.gauche.pprint(level+1)

    def calculer(self):
        if self.value == "+":
            return self.gauche.calculer()+self.droite.calculer()
        elif self.value == "-":
            return self.gauche.calculer()-self.droite.calculer()
        elif self.value == "/":
            return self.gauche.calculer()/self.droite.calculer()
        elif self.value == "*":
            return self.gauche.calculer()*self.droite.calculer()
        else:
            if self.value != "":
                return int(self.value)
            else:
                return 0

def prios(exp):
    res=[]
    ops = ["+","-","/","*"]
    for i in range(len(exp)):
        if exp[i] in ops:
            res.append((exp[i],i))
    for i in range(len(res)):
        j=i
        while j>=1 and ops.index(res[j][0]) < ops.index(res[j-1][0]):
            res[j],res[j-1] = res[j-1],res[j]
            j-=1
    return res

Exp = input("Entrez l'expression ici: (Notez que les parenthèses ne fonctionnent pas encore...) ")
#Exp = "5*2+3*2/3+5"
calculs = prios(Exp)
if calculs:
    root = Noeud(calculs[0][0],calculs[0][1],Exp)
    root.developper()
    root.pprint()
    print(root.calculer())
else:
    print("Ce n'est même pas une expression... Donc forcément, le résultat est",Exp)