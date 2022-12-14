//
// Created by maxou on 28/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_LIST_H
#define PROJETCGENERATEURDEPHRASEV2_LIST_H
//#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s_node{
    char data;
    struct slist* children;
    int isWord;
    //pointeurs de formes fléchis
}s_node;

typedef s_node* node;
typedef struct s_node* node;

typedef struct s_nodeString{
    char data[25];
    struct s_nodeString* children;
    //pointeurs de formes fléchis
}s_nodeString;

typedef struct s_nodeString* nodeString;

typedef struct s_cell{
    node data;
    struct s_cell* next;
}s_cell;

typedef s_cell* cell;

typedef struct slist{
    cell head;
}slist;

typedef slist* list;

typedef struct slistString{
    nodeString head;
}slistString;

typedef slistString* listString;

list addInListCell(list L,cell cell);
void addInListString(listString L,char* string);
int checkIfInList(listString L,char* string);
void displayStringList(listString L);
cell createCell(node node1);
void addChildrenToNode(node node1,cell cell1);
#endif //PROJETCGENERATEURDEPHRASEV2_LIST_H
