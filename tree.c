//
// Created by maxou on 26/10/2022.
//

#include "tree.h"


tree createInitialTree(){
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

int CharIsInNodeChildren(char caractere,node noeud){
    // je suis dans un noeud et je me demande si dans ses enfants il y a le caractere 'a' par ex
    if (noeud == NULL) return -1;
    if(noeud->children == NULL) return 0;
    s_cell* temp = noeud->children->head;
    while(temp != NULL){
        if (temp->data->data == caractere){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

node returnChildrenNodeWithTheCaractereOfANode(node noeud, char caractere){
    s_cell* temp;
    temp = noeud->children->head;
    while (temp != NULL){
        if (temp->data->data == caractere) {
            return temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

int IsWordAlreadyIntree(tree arbre, s_nodeString* noeudMot){
    // check si le mot en paramètre est dans l'arbre si oui -> 1 sinon -> 0
    if (noeudMot->data[0]=='\0') return 0;
    if ( ! ((noeudMot->data[0] <=122) && (noeudMot->data[0]>=97) )) return -1;
    char indexPremiereLettre = noeudMot->data[0]-97;
    node noeud = arbre.root[indexPremiereLettre];

    int i = 1;

    while (i < strlen(noeudMot->data)){
        if (! CharIsInNodeChildren(noeudMot->data[i],noeud)){
            return 0;
        }
        //la le noeud a bien la lettre en enfant
        noeud = returnChildrenNodeWithTheCaractereOfANode(noeud,noeudMot->data[i]);
        i++;
    }
    return 1;
}

node getNodeInNodeByChar(node startNode, char charToFind) {
    cell temporaryCell = startNode->children->head;
    while (temporaryCell != NULL) {
        if (temporaryCell->data->data == charToFind) {
            return temporaryCell->data;
        }
        temporaryCell = temporaryCell->next;
    }
    return NULL;
}

void addBasesFormesInTree(listString List,tree *tree){
    if(List==NULL){
        printf("La liste n'est pas remplie de ses formes de bases");
    } else {
        nodeString temp = List->head;
        int index=0;
        nodeString mot = malloc(sizeof (s_nodeString));
        strcpy(mot->data,"");
        mot->children=NULL;
        cell newCell;
        node currentNode= malloc(sizeof (s_node));
        currentNode->children = NULL;
        currentNode->data = 0;
        while(temp!=NULL) {
            mot->data[0]=temp->data[0];
            mot->data[1]='\0';
            index=0;
            while (temp->data[index] != '\0') {
                if(index==0){
                    currentNode=tree->root[((int)temp->data[0])-'a'];
                } else if (!IsWordAlreadyIntree(*tree,mot)) {
                    newCell= createCell(createNode(temp->data[index]));
                    addChildrenToNode(currentNode,newCell);
                    currentNode=newCell->data;
                } else {
                    currentNode = getNodeInNodeByChar(currentNode, mot->data[index]);
                }
                index++;
                mot->data[index]=temp->data[index];
                mot->data[index+1]='\0';
            }
            strcpy(mot->data,"");
            currentNode->isWord=1;
            temp=temp->children;
        }
    }
}
