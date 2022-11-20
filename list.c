//
// Created by maxou on 28/10/2022.
//

#include "list.h"

void addInListString(listString L,char* string){
    nodeString new= malloc(sizeof (s_nodeString));
    strcpy(new->data,string);
    new->children=NULL;
    if(L->head==NULL){
        L->head=new;
    }
    else{
        nodeString temp=L->head;
        while(temp->children!=NULL){
            temp=temp->children;
        }
        temp->children= new;
    }
}


int checkIfInList(listString L,char* string){

    if(L->head==NULL){
        return 0;
    }
    else{
        nodeString temp=L->head;
        while(temp!=NULL){
            if(strcmp(temp->data,string)==0){
                return 1;
            }
            else{
                temp=temp->children;
            }
        }
        return 0;
    }
}

void displayStringList(listString L) {
    if (L->head == NULL) {
        printf("Liste Vide");
    } else {
        nodeString temp = L->head;
        while (temp->children != NULL) {
            printf("%s->", temp->data);
            temp = temp->children;
        }
        printf("%s->",temp->data);
      //  printf("\n head : %s\n",L->head->data);
        printf("NULL");
    }
}

void addChildrenToNode(node node1,cell cell1) {

//    if (node1->children == NULL) {
//        list Liste = node1->children;
//        Liste = malloc(sizeof(slist));
//        Liste->head = NULL;
 //   }

    list Liste = node1->children;
    if (Liste == NULL) {    //TOUJOURS EGALE A NULL JE SAIS PAS PK
        Liste = malloc(sizeof(slist));
        Liste->head = NULL;
         //n'add pas à la liste
    }
    node1->children = addInListCell(Liste, cell1);
}

    list addInListCell(list L, cell cellToAdd) {
        ///WIP
        if (L->head == NULL) {
            L = malloc(sizeof(slist));
            L->head = cellToAdd;
            return L;
        }
        cell temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cellToAdd;
        return L;
    }


cell createCell(node node1){
    cell newCell= malloc(sizeof (s_cell));
    newCell->data=node1;
    newCell->next=NULL;
    return newCell;
}