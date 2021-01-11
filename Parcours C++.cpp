#include <iostream>


char arbre[6][18] = { {'r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                   {'a', 'b', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                   {'c', 'd', 'e', 'f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                   {NULL, 'h', 'i', 'j', 'k', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                   {NULL, NULL, NULL, NULL, NULL, NULL, 'm', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                   {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL} };

char* get_etage(int x) {
    return arbre[x];
}

void parcoursPrefixe(char* ligne, int etage, int place) {
    std::cout << ligne[place] << ", ";
    if (get_etage(etage + 1)[2*place] != NULL) {
        parcoursPrefixe(get_etage(etage + 1), etage + 1, 2 * place);
    }
    if (get_etage(etage + 1)[2*place + 1] != NULL) {
        parcoursPrefixe(get_etage(etage + 1), etage + 1, 2 * place + 1);
    }
}

void parcoursInfixe(char* ligne, int etage, int place) {
    if (get_etage(etage + 1)[2*place] != NULL) {
        parcoursInfixe(get_etage(etage + 1), etage + 1, 2 * place);
    }
    std::cout << ligne[place] << ", ";
    if (get_etage(etage + 1)[2*place + 1] != NULL) {
        parcoursInfixe(get_etage(etage + 1), etage + 1, 2 * place + 1);
    }
}

void parcoursPostfixe(char* ligne, int etage, int place) {
    if (get_etage(etage + 1)[2*place] != NULL) {
        parcoursPostfixe(get_etage(etage + 1), etage + 1, 2 * place);
    }
    if (get_etage(etage + 1)[2*place + 1] != NULL) {
        parcoursPostfixe(get_etage(etage + 1), etage + 1, 2 * place + 1);
    }
    std::cout << ligne[place] << ", ";
}

int main() {
    parcoursPrefixe(get_etage(0), 0, 0);
    std::cout << std::endl;
    parcoursPostfixe(get_etage(0), 0, 0);
    std::cout << std::endl;
    parcoursInfixe(get_etage(0), 0, 0);
    std::cout << std::endl;

    char fin;
    std::cin >> fin;
    return(0);
}
