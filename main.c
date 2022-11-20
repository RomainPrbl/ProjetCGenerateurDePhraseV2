#include <stdio.h>
#include <stdlib.h>
#include "display/displayTxt.h"
#include "three.h"
int main() {
<<<<<<< Updated upstream
    //three *ThreeForAllLetter=createInitialThree(); //Creer un three avec un tableau de toutes les lettres en root
    //listString test = getBasesFormes("D:\\generateurdemot\\ProjetCGenerateurDePhraseV2\\dictionnaire.txt");
    //displayStringList(test);
    listString test = malloc(sizeof (slistString));
    test->head=NULL;
<<<<<<< Updated upstream
    test= getBasesFormesNom("D:/generateurdemot/ProjetCGenerateurDePhraseV2/test.txt");
    //displayStringList(test);
    //displayStringList(test);
    three tree=createInitialThree();
    addBasesFormesInTree(test,&tree);
    printf("print :%c",tree.root[18]->children->head->next->data->data);
    return 0;
=======
//    startMenu();
//    controlStartMenu();
    listString test = malloc(sizeof(slistString));
    test->head = NULL;
    test = getBasesFormesNom("../test.txt");
    displayStringList(test);
    tree tree = createInitialTree();
    addBasesFormesInTree(test, &tree);
>>>>>>> Stashed changes
=======
    test= getBasesFormesNom("../test.txt");
    //displayStringList(test);
    tree tree=createInitialTree();
    addBasesFormesInTree(test,&tree);
    printf("%s",generateRandomWord(tree)->data);
>>>>>>> Stashed changes
}
