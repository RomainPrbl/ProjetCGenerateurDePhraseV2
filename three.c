//
// Created by maxou on 26/10/2022.
//

#include "three.h"


three createInitialThree(){
    three mythree;
    for (int i=0;i<26;i++){
        char lettre = (char)(i+97);
        mythree.root[i]=malloc(sizeof(node));
        mythree.root[i]->data=lettre;
        mythree.root[i]->children = NULL;
    }
    return mythree;
}

node createNode(char a){
    node newNode = malloc(sizeof (s_node));
    list enfant = malloc(sizeof (slist));
    newNode->data=a;
    newNode->children=enfant;
    newNode->isWord=0;
    return newNode;
}