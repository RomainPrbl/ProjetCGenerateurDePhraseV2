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

    node noeud = malloc(sizeof (node));
    noeud->data ='c';
    node noeud2 = malloc(sizeof (node));
    noeud2->data ='k';
    node noeud3 = malloc(sizeof (node));
    noeud3->data ='b';
    s_cell *cellule = malloc(sizeof (s_cell));
    cellule->data = noeud2;
    s_cell *cellule2 = malloc(sizeof (s_cell));
    cellule2->data = noeud3;
    cellule2->next = NULL;
    slist* tete = malloc(sizeof(slist));
    tete->head = cellule;
    noeud->children = tete;
    cellule->next = cellule2;
    tree.root[2] = noeud;
    s_nodeString * noeudMot = malloc(sizeof (s_nodeString));
    strcpy(noeudMot->data,"ckb");
    printf("adresse de node = %d\n",noeud3);
    printf("fct 1 =%d\n",CharIsInNodeChildren('s',noeud));
    printf("fct 2 =%c\n",returnChildrenNodeWithTheCaractereOfANode(noeud,'b')->data);
    printf("\nfct final = %d\n",IsWordAlreadyInthree(tree,noeudMot));
    return 0;
}
