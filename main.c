#include <stdio.h>
#include <stdlib.h>
#include "display/displayTxt.h"
#include "three.h"
int main() {
    displayLines("D:\\generateurdemot\\ProjetCGenerateurDePhraseV2\\dictionnaire_non_accentue.txt");
    three *ThreeForAllLetter=createInitialThree(); //Creer un three avec un tableau de toutes les lettres en root
    return 0;
}
