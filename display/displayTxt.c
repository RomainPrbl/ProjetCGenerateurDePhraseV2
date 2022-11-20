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
}

/////////////////////////////////////////////////////////


void numberOfWord(node noeud,int* compteur) {
    printf("noeud %c et compteur = %d\n",noeud->data,*compteur);
    if (!((noeud->children == NULL) || (noeud)->children->head == NULL)) {
        printf("hey\n");
        s_cell *temp = noeud->children->head;
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

int numberOfWordInthree(three arbre){
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
    if ((noeudParent->children == NULL) || (noeudParent->children->head == NULL)  ){
        printf("Il n'y a pas d'enfant au noeud ( %c )",noeudParent->data);
        return -1;
    }
    s_cell* temp = noeudParent->children->head;
    while(temp != NULL){
        compteurEnfants++;
        temp = temp->next;
    }
    return compteurEnfants;


}

s_nodeString* generateRandomWord(three arbre){
    //le type de mot generé depend de l'arbre en parametre
    s_nodeString * mot = malloc(sizeof (s_nodeString));
    mot->children = NULL;
    int lettreDeDepart = randomNumber(0,25);
    int enfantAleatoire = 0;
    int i = 1 ;
    int trouve = 0;
    int indexDuMotEnConstruction = 0;
    int nbDeMotDansArbre = numberOfWordInthree(arbre);
    int idMot = numberOfWordInthree(arbre);
    node noeud = arbre.root[lettreDeDepart];
    while (trouve != 1){
        s_cell * temp = noeud->children->head;
        enfantAleatoire = randomNumber(1, childrensNumberOfaNode(noeud));
        while(i < enfantAleatoire){
            temp = temp->next;
            i++;
        }
        mot->data[indexDuMotEnConstruction] = temp->data->data;
        if( (noeud->isWord == 1) && (randomNumber(1,nbDeMotDansArbre) == idMot)){
            trouve = 1;
            mot->data[indexDuMotEnConstruction+1] = '\0';
        }
        noeud = temp->data;
        indexDuMotEnConstruction++;
        i = 1;
    }
    return mot;
}

int randomNumber(int min, int max){
    srand(time(NULL));
    return rand()%(max-min+1) + min;
}

void generateRandomSentence(s_ListOfThree listePrincipale,int modele){
    if (modele == 1){

    }else if (modele == 2){

    }else{
        printf("Ce modele n'existent pas \n");
        return;
    }
}