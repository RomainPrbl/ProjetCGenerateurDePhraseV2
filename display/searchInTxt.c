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

