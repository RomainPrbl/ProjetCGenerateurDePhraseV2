//
// Created by maxou on 28/10/2022.
//

#include "list.h"

void addInListString(listString L,char* string){
    nodeString string1 = malloc(sizeof (nodeString));
    strcpy(string1->data,string);
    string1->children=NULL;
    if(L->head==NULL){
        L->head=string1;
    }
    else{
        nodeString temp=L->head;
        while(temp->children!=NULL){
            temp=temp->children;
        }
        temp->children=string1;
    }
}

int checkIfInList(listString L,char* string){
    printf("\n");
    if(L->head==NULL){
        return 0;
    }
    else{
        nodeString temp=L->head;
        while(temp!=NULL){
            printf("temp : %s string : %s \t",temp->data,string);
            if(temp->data==string){
                return 1;
            }
            temp=temp->children;
        }
        return 0;
    }
}

//faire fonction vérification si mot existe
