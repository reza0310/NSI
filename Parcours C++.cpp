#include <iostream>

char f[2] = {NULL, NULL};
char h[2] = {NULL, NULL};
char i[2] = {NULL, NULL};
char k[2] = {NULL, NULL};
char m[2] = {NULL, NULL};
char j[2] = {*m, NULL};
char e[2] = {*k, NULL};
char d[2] = {*i, *j};
char c[2] = {NULL, *h};
char b[2] = {*e, *f};
char a[2] = {*c, *d};
char r[2] = {*a, *b};

void parcoursPrefixe(char* arbre) {
    std::cout << arbre << ", " << std::endl;
    if (arbre[0] != NULL) {
        parcoursPrefixe(&arbre[0]);
	}
    if (arbre[1] != NULL) {
        parcoursPrefixe(&arbre[1]);
	}
}

void parcoursInfixe(char* arbre) {
    if (arbre[0] != NULL) {
        parcoursInfixe(&arbre[0]);
	}
    std::cout << arbre << ", " << std::endl;
    if (arbre[1] != NULL) {
        parcoursInfixe(&arbre[1]);
	}
}

void parcoursPostfixe(char* arbre) {
    if (arbre[0] != NULL) {
        parcoursPostfixe(&arbre[0]);
	}
    if (arbre[1] != NULL) {
        parcoursPostfixe(&arbre[1]);
	}
    std::cout << arbre << ", " << std::endl;
}

int main() {
	parcoursPrefixe(r);
	parcoursPostfixe(r);
	parcoursInfixe(r);
	
	char fin;
	std::cin >> fin;
	return(0);
}
