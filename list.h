//
// Created by maxou on 28/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_LIST_H
#define PROJETCGENERATEURDEPHRASEV2_LIST_H
#include "three.h"



typedef struct cell{
    node data;
    struct cell* next;
}cell;


typedef struct slist{
    cell head;
}slist;

typedef slist* list;
#endif //PROJETCGENERATEURDEPHRASEV2_LIST_H
