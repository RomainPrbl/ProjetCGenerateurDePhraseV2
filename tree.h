//
// Created by maxou on 26/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_THREE_H
#define PROJETCGENERATEURDEPHRASEV2_THREE_H
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node{
    char data;
    struct slist* children;
    int isWord;
    //pointeurs de formes fléchis
}s_node;

typedef s_node* node;

typedef struct s_nodeString{
    char data[25];
    struct s_nodeString* children;
    //pointeurs de formes fléchis
}s_nodeString;

typedef s_nodeString* nodeString;



//faire struct de données pour formes fléchées

typedef struct tree{
    node root[26];
}tree;


tree createInitialThree();
node createNode(char a);

#endif //PROJETCGENERATEURDEPHRASEV2_THREE_H
