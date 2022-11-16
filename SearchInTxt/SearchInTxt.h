//
// Created by maxou on 28/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
#define PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include <string.h>
void displayLines(char *filename);
listString getBasesFormes(char *filename);
listString getBasesFormesNom(char *filename);
void addBasesFormesInTree(listString List,tree *tree);
int IsWordAlreadyInthree(tree arbre, s_nodeString* noeudMot);
int CharIsInNodeChildren(char caractere,node noeud);
node returnChildrenNodeWithTheCaractereOfANode(node noeud, char caractere);
#endif //PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
