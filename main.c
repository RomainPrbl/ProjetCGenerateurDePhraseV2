#include <stdio.h>
#include <stdlib.h>
#include "display/displayTxt.h"
#include "three.h"
int main() {
    //three *ThreeForAllLetter=createInitialThree(); //Creer un three avec un tableau de toutes les lettres en root
    //listString test = getBasesFormes("D:\\generateurdemot\\ProjetCGenerateurDePhraseV2\\dictionnaire.txt");
    //displayStringList(test);
    listString test = malloc(sizeof (slistString));
    test->head=NULL;
    test= getBasesFormesNom("D:/generateurdemot/ProjetCGenerateurDePhraseV2/test.txt");
    //displayStringList(test);
    //displayStringList(test);
    three tree=createInitialThree();

    node test2 =malloc(sizeof (node));
    test2->data = 'c';
    test2->children = NULL;
    s_cell * cellule = malloc(sizeof (s_cell));
    cellule->data = test2;
    cellule->next =NULL;
    tree.root[7]->children->head = cellule;
    printf("la : %d",CharIsInNodeChildren('c',tree.root[7]));
    node nodeTest = NULL;
    s_nodeString* nodeStringtest = malloc(sizeof (s_nodeString));
    strcpy(nodeStringtest->data,"hello");
    IsWordAlreadyInthree(tree,nodeStringtest);
    return 0;
}
