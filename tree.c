//
// Created by maxou on 26/10/2022.
//

#include "tree.h"


three createInitialThree(){
    three mythree;
    for (int i=0;i<26;i++){
        char lettre = (char)(i+97);
        mythree.root[i]=malloc(sizeof(node));
        mythree.root[i]->data=lettre;
        mythree.root[i]->children = malloc(sizeof (slist));
        mythree.root[i]->children->head=NULL;
        mythree.root[i]->isWord=0;
    }
    return mythree;
}

node createNode(char a){
    node newNode = malloc(sizeof (s_node));
    list enfant = malloc(sizeof (slist));
    newNode->data=a;
    newNode->children=enfant;
    enfant->head=NULL;
    newNode->isWord=0;
    return newNode;
}