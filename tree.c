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
s_nodeString* generateRandomWord(tree arbre){
    //le type de mot generé depend de l'arbre en parametre
    s_nodeString * mot = malloc(sizeof (s_nodeString));
    mot->children = NULL;
    int lettreDeDepart = randomNumber(0,25);
    printf("index de depart pour root %d\n",lettreDeDepart);
    int enfantAleatoire = 0;
    int i = 1 ;
    int trouve = 0;
    int indexDuMotEnConstruction = 1;
    node noeud = arbre.root[lettreDeDepart];
    mot->data[0] = noeud->data;
    printf("premiere de l'arbre : %c\n",noeud->data);
    while (trouve != 1){
        // si il a pas d'enfant
        if(childrensNumberOfaNode(noeud) == -1){
            printf("plus d'enfant et mot non fini\n");
            printf("-----------------------------\n");
            generateRandomWord(arbre);
        }
        else {
            printf("il y a des enfants\n");
            printf("IsWorld = %d\n",noeud->isWord);
            s_cell *temp = noeud->children->head;
            enfantAleatoire = randomNumber(1, childrensNumberOfaNode(noeud));
            while (i < enfantAleatoire) {
                temp = temp->next;
                i++;
            }
            mot->data[indexDuMotEnConstruction] = temp->data->data;
            printf("lettre du mot = %c\n",mot->data[indexDuMotEnConstruction]);
            if (noeud->isWord == 1) { // && (randomNumber(1, 10) == 5)
                trouve = 1;
                mot->data[indexDuMotEnConstruction + 1] = '\0';
            }
            noeud = temp->data;
            indexDuMotEnConstruction++;
            i = 1;
        }
    }
    return mot;
}

int randomNumber(int min, int max){
    return rand()%(max-min+1) + min;
}

void numberOfWord(node noeud,int* compteur) {
    printf("noeud %c et compteur = %d\n",noeud->data,compteur);
    if (!((noeud->children == NULL) || (noeud)->children->head == NULL)) {
        printf("hey\n");
        s_cell* temp = noeud->children->head;
        if (noeud->isWord == 1){
            (*compteur)++;
        }
        while (temp != NULL) {
            numberOfWord(temp->data, compteur);
            temp = temp->next;
        }
    }else{
        printf("ce noeud na pas d'enfants ^\n");
    }
}
int numberOfWordIntree(tree arbre){
    int cpt = 26;
    int temp = 0;
    for (int i = 0 ; i < 26 ; i ++){
        temp = 0;
        numberOfWord(arbre.root[i],&temp);
        cpt += temp;
    }
    return cpt;
}

int childrensNumberOfaNode(node noeudParent){
    int compteurEnfants = 0;
    printf("hey\n");
    /*if (noeudParent->children == NULL){
        printf("Il n'y a pas d'enfant");
        return -1;
    }else */if ( noeudParent->children->head == NULL){
        printf("Il n'y a pas d'enfant2\n");
        return -1;
    }
    printf("hey2\n");
    s_cell* temp = noeudParent->children->head;
    while(temp != NULL){
        compteurEnfants++;
        temp = temp->next;
    }
    return compteurEnfants;


}

