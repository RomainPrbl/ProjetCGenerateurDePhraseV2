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


void addInListCell(list L,cell cellToAdd){
    if(L==NULL){
        L= malloc(sizeof (slist));
        L->head=cellToAdd;
    }
    else{
        cell temp = L->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next= cellToAdd;
    }
}