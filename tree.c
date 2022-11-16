//
// Created by maxou on 26/10/2022.
//

#include "tree.h"


tree createInitialThree(){
    tree mytree;
    for (int i=0;i<26;i++){
        char lettre = (char)(i+97);
        mytree.root[i]=malloc(sizeof(node));
        mytree.root[i]->data=lettre;
        mytree.root[i]->children = malloc(sizeof (slist));
        mytree.root[i]->children->head=NULL;
        mytree.root[i]->isWord=0;
    }
    return mytree;
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