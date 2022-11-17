#include <stdio.h>
#include <stdlib.h>
#include "display/searchInTxt.h"
#include "tree.h"
#include "menu/menu.h"
int main() {
    //startMenu();
    //controlStartMenu();
    tree ThreeForAllLetter=createInitialTree(); //Creer un three avec un tableau de toutes les lettres en root
    listString test = getBasesFormes("../dictionnaire_non_accentue.txt");
    tree tree=createInitialTree();
    addBasesFormesInTree(test,&tree);
        return 0;
}
