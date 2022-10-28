//
// Created by maxou on 26/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_THREE_H
#define PROJETCGENERATEURDEPHRASEV2_THREE_H
#include "list.h"


typedef struct s_node{
    char data;
    list children;
}s_node;

typedef s_node* node;



//faire struct de données pour formes fléchées

typedef struct three{
    node[26] root;
}three;

#endif //PROJETCGENERATEURDEPHRASEV2_THREE_H
