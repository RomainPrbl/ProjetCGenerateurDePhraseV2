//
// Created by maxou on 28/10/2022.
//

#include "searchInTxt.h"


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


void addBasesFormesInTree(listString List,three *tree){
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
                } else if (!IsWordAlreadyInthree(*tree,mot)) {
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
    printf("%c\n",tree->root[18]->children->head->data->data);
}