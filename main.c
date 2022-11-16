#include <stdio.h>
#include <stdlib.h>
#include "SearchInTxt/SearchInTxt.h"
#include "tree.h"
int main() {
    //three *ThreeForAllLetter=createInitialThree(); //Creer un three avec un tableau de toutes les lettres en root
    //listString test = getBasesFormes("D:\\generateurdemot\\ProjetCGenerateurDePhraseV2\\dictionnaire.txt");
    //displayStringList(test);
    listString test = malloc(sizeof (slistString));
    test->head=NULL;
    test= getBasesFormesNom("D:/generateurdemot/ProjetCGenerateurDePhraseV2/test.txt");
    //displayStringList(test);
    //displayStringList(test);
    tree tree=createInitialThree();
    addBasesFormesInTree(test,&tree);
    printf("print :%c",tree.root[18]->children->head->next->data->data);
    return 0;
}
