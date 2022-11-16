//
// Created by maxou on 28/10/2022.
//

#include "displayTxt.h"


void displayLines(char *filename)
{
    FILE *dicofile = fopen(filename, "rt");
    char flechie[35];
    char base[35];
    char formes[35];
    if (dicofile != NULL)
    {
        while (fscanf(dicofile,"%s\t%s\t%s",flechie, base, formes) != EOF)
        {
            printf("%s - %s - %s\n", base, formes,flechie);
        }
    }

    fclose(dicofile);

    //return;
}

listString getBasesFormes(char *filename)
{
    listString BasesFormes=malloc(sizeof (listString));
    BasesFormes->head =NULL;
    FILE *dicofile = fopen(filename, "rt");
    char flechie[35];
    char base[35];
    char formes[35];
    if (dicofile != NULL)
    {
        while (fscanf(dicofile,"%s\t%s\t%s",flechie, base, formes) != EOF)
        {
            if (!checkIfInList(BasesFormes,base)){
                addInListString(BasesFormes,base);
            }
        }
    }
    fclose(dicofile);
    return BasesFormes;
}

listString getBasesFormesNom(char *filename)
{
    listString BasesFormesNom=malloc(sizeof (listString));
    BasesFormesNom->head =NULL;
    FILE *dicofile = fopen(filename, "rt");
    char flechie[35];
    char base[35];
    char formes[35];
    if (dicofile != NULL)
    {
        while (fscanf(dicofile,"%s\t%s\t%s",flechie, base, formes) != EOF)
        {
            if (!checkIfInList(BasesFormesNom,base) && formes[0]=='N'){
                addInListString(BasesFormesNom,base);
            }
        }
    }
    fclose(dicofile);
    return BasesFormesNom;
}

listString getBasesFormesVerbe(char *filename)
{
    listString BasesFormesNom=malloc(sizeof (listString));
    BasesFormesNom->head =NULL;
    FILE *dicofile = fopen(filename, "rt");
    char flechie[35];
    char base[35];
    char formes[35];
    if (dicofile != NULL)
    {
        while (fscanf(dicofile,"%s\t%s\t%s",flechie, base, formes) != EOF)
        {
            if (!checkIfInList(BasesFormesNom,base) && formes[0]=='V'){
                addInListString(BasesFormesNom,base);
            }
        }
    }
    fclose(dicofile);
    return BasesFormesNom;
}

listString getBasesFormesAdjective(char *filename)
{
    listString BasesFormesNom=malloc(sizeof (listString));
    BasesFormesNom->head =NULL;
    FILE *dicofile = fopen(filename, "rt");
    char flechie[35];
    char base[35];
    char formes[35];
    if (dicofile != NULL)
    {
        while (fscanf(dicofile,"%s\t%s\t%s",flechie, base, formes) != EOF)
        {
            if (!checkIfInList(BasesFormesNom,base) && formes[0]=='A'){
                addInListString(BasesFormesNom,base);
            }
        }
    }
    fclose(dicofile);
    return BasesFormesNom;
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

int IsWordAlreadyInthree(three arbre, s_nodeString* noeudMot){
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



void addBasesFormesInTree(listString List,three *tree){
    if(List==NULL){
        printf("La liste n'est pas remplie de ses formes de bases");
    }
    else {
        nodeString temp = List->head;
        int index=0;
        nodeString mot = malloc(sizeof (s_nodeString));
        strcpy(mot->data,"");
        mot->children=NULL;
        cell newCell;
        node currentNode= malloc(sizeof (s_node));
        while(temp!=NULL) {
            char letterOne=temp->data[0];
            strcat(mot->data,&letterOne);
            mot->data[1]='\0';
            while (temp->data[index] != '\0') {
                if(index==0){
                    currentNode=tree->root[((int)temp->data[0])-97];
                }
                if((IsWordAlreadyInthree(*tree,mot)) && ((index>0))){
                    printf("1");
                    currentNode = FindNodeWithValue(currentNode,mot->data[index]);
                    printf("\nICI2 :%c\n",currentNode->data);
                }
                if (!IsWordAlreadyInthree(*tree,mot)) {
                newCell= createCell(createNode(temp->data[index]));
                newCell->data->children=NULL;
                addChildrenToNode(currentNode,newCell); //Pas bon 2 eme mot
                }

                if(!(index<=1) && IsWordAlreadyInthree(*tree,mot)) {
                    currentNode=newCell->data;
                }
                index++;
                mot->data[index]=temp->data[index];
                mot->data[index+1]='\0';
        }
            strcpy(mot->data,"");
            index=0;
            currentNode->isWord=1;
            temp=temp->children;
        }
    }
    printf("%c\n",tree->root[18]->children->head->data->data);
}