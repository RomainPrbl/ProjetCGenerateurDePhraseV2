#include <stdio.h>
#include <stdlib.h>
#include "display/displayTxt.h"
#include "three.h"
int main() {
    //three *ThreeForAllLetter=createInitialThree(); //Creer un three avec un tableau de toutes les lettres en root
    //listString test = getBasesFormes("D:\\generateurdemot\\ProjetCGenerateurDePhraseV2\\dictionnaire.txt");
    //displayStringList(test);
    listString test = malloc(sizeof (listString));
    test->head=NULL;
    addInListString(test,"premier");
    addInListString(test,"deux");
    printf("%d",test->head->children->data);
    displayStringList(test);
    return 0;
}
