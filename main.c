#include <stdio.h>
#include <stdlib.h>
#include "display/searchInTxt.h"
#include "tree.h"
#include "menu/menu.h"
int main() {
//    startMenu();
//    controlStartMenu();
    listString test = malloc(sizeof (slistString));
    test->head=NULL;
    test= getBasesFormesNom("../test.txt");
    displayStringList(test);
    tree tree=createInitialTree();
    addBasesFormesInTree(test,&tree);
}
