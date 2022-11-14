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
    // je suis dans un noeud et je me demande si dans c'est enfants il y a le caractere 'a' par ex
    if (noeud == NULL) return -1;
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

int IsWordAlreadyInthree(three arbre, s_nodeString noeudMot){
    // check si le mot en paramètre est dans l'arbre si oui -> 1 sinon -> 0
    if ( ! ((noeudMot.data[0] <=122) && (noeudMot.data[0]>=97) )) return -1;
    char indexPremiereLettre = noeudMot.data[0]-97;
    node noeud = arbre.root[indexPremiereLettre];

    printf(" cc %d \n",strlen(noeudMot.data));
    int i = 1;

    while (i < strlen(noeudMot.data)){
        if (! CharIsInNodeChildren(noeudMot.data[i],noeud)){
            return 0;
        }
        //la le noeud a bien la lettre en enfant
        noeud = returnChildrenNodeWithTheCaractereOfANode(noeud,noeudMot.data[i]);
        i++;
    }
    return 1;
}

void createThreeWithListString(listString listeCarcatere){
    three arbre = createInitialThree();

}
/*
void addBasesFormesInTree(listString List,three *three){
    if(List==NULL){
        printf("La liste n'est pas remplie de ses formes de bases");
    }
    else{
        list L=NULL;
        nodeString temp = List->head;
        cell new= malloc(sizeof (s_cell));;
        node currentNode=NULL;
       while(temp!=NULL){
           int index=0;
           while(temp->data[index] != '\0'){
               if(index==0){
                   currentNode=three->root[(temp->data[0])-97];
                   index++;
               }
               new->data=createNode(temp->data[index]);
               new->next=NULL;
               addInListCell(L,new); //pb ICI
               currentNode->children=L;
               currentNode =new->data;
               index++;
           }

           temp=temp->children;
           currentNode=NULL;
       }
    }
}*/