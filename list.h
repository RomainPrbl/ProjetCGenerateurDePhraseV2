//
// Created by maxou on 28/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_LIST_H
#define PROJETCGENERATEURDEPHRASEV2_LIST_H
#include "three.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct s_node* node;


typedef struct s_cell{
    node data;
    struct s_cell* next;
}s_cell;

typedef s_cell* cell;

typedef struct slist{
    cell head;
}slist;

typedef slist* list;
#endif //PROJETCGENERATEURDEPHRASEV2_LIST_H
