class PILE():
    def __init__(self):
        self.contenu = []

    def empiler(self, elements):
        self.contenu += [elements]
        #print(self.contenu)

    def depiler(self):
        return self.contenu.pop(len(self.contenu)-1)

    def haut_de_pile(self):
        return self.contenu[-2], self.contenu[-1]

    def retourner(self):
        self.contenu.reverse()

    def simplifer_haut(self):
        num2, op, num1 = self.depiler(), self.depiler(), self.depiler()
        print("Calcul de "+str(num1)+" "+str(op)+" "+str(num2)+" effectué.")
        if op == "*":
            self.empiler(num1*num2)
        elif op == "/":
            self.empiler(num1/num2)
        elif op == "-":
            self.empiler(num1-num2)
        else:
            self.empiler(num1+num2)

    def simplifer_haut_nbres_pas_inverses(self):
        num1, op, num2 = self.depiler(), self.depiler(), self.depiler()
        print("Calcul de "+str(num1)+" "+str(op)+" "+str(num2)+" effectué.")
        if op == "*":
            self.empiler(num1*num2)
        elif op == "/":
            self.empiler(num1/num2)
        elif op == "-":
            self.empiler(num1-num2)
        else:
            self.empiler(num1+num2)

expression = input("Entrez l'expression: ") #[x for x in input("Entrez l'expression: ") if x != " "] #Séparer tou les caractères
expression_decoupee = []
pile = PILE()
buffer = ""
chiffres = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
for x in expression:
    if x not in chiffres and buffer == "" and x != " ":
        expression_decoupee.append(x)
    elif x in chiffres:
        buffer += x
    elif x != " ":
        expression_decoupee.append(int(buffer))
        buffer = ""
        expression_decoupee.append(x)
if buffer != "":
    expression_decoupee.append(int(buffer))

print(expression_decoupee)

"""i = 0
while i < len(expression_decoupee):
    if expression_decoupee[i] == "/":
        p = [1 ,2 ,3 ,4]
        p[0] = i #Parenthèse 1 / 4
        paren = 0
        while (p[0]>1 and expression_decoupee[p[0]] != "+" and expression_decoupee[p[0]] != "-" and paren >= 0) or paren>0:
            p[0] -= 1
            if expression_decoupee[p[0]] == ")":
                paren += 1
            elif expression_decoupee[p[0]] == "(":
                paren -= 1
        p[1] = i #Parenthèse 2 / 4
        p[2] = i+1 #Parenthèse 3 / 4
        p[3] = i+1 #Parenthèse 4 / 4
        paren = 0
        while (p[3]<len(expression_decoupee)-1 and paren == 0 and (expression_decoupee[p[3]] != "+" or expression_decoupee[p[3]] != "-")) or paren < 0:
            p[3] += 1
            if expression_decoupee[p[3]] == ")":
                paren += 1
            elif expression_decoupee[p[3]] == "(":
                paren -= 1
        for y in range(len(p)):
            p[y]+=y
        expression_decoupee.insert(p[0]+1, "(")
        expression_decoupee.insert(p[1], ")")
        expression_decoupee.insert(p[2], "(")
        expression_decoupee.insert(p[3]+1, ")")
        i += 4
    i += 1

txt = ""
for chose in expression_decoupee:
    txt += str(chose)
print(txt)"""

i=0
while i < len(expression_decoupee):
    pile.empiler(expression_decoupee[i])
    if (expression_decoupee[i] == "*" or expression_decoupee[i] == "/") and expression_decoupee[i+1] != "(":
        pile.empiler(expression_decoupee[i+1])
        pile.simplifer_haut()
        i += 1
    elif expression_decoupee[i] == ")":
        pile.depiler()
        while pile.haut_de_pile()[0] != "(":
            pile.simplifer_haut()
        save = pile.depiler()
        pile.depiler()
        pile.empiler(save)
    i += 1
#print("Passage hors priorités")
pile.retourner()
while len(pile.contenu) > 1:
    pile.simplifer_haut_nbres_pas_inverses()

print("Le résultat est "+str(pile.contenu[0]))