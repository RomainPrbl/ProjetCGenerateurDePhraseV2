//
// Created by maxou on 26/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_THREE_H
#define PROJETCGENERATEURDEPHRASEV2_THREE_H
#include "list.h"
#include <stdlib.h>
#include <stdio.h>











//faire struct de données pour formes fléchées

typedef struct tree{
    node root[26];
}tree;


tree createInitialTree();
node createNode(char a);
void addBasesFormesInTree(listString List,tree *tree);
node returnChildrenNodeWithTheCaractereOfANode(node noeud, char caractere);
int IsWordAlreadyIntree(tree arbre, s_nodeString* noeudMot);
int CharIsInNodeChildren(char caractere,node noeud);

#endif //PROJETCGENERATEURDEPHRASEV2_THREE_H
