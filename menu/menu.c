//
// Created by raphou on 14/11/2022.
//

#include "menu.h"


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}




void startMenu(){
    Color(9, 0);
    printf("|-------------Bienvenue--------------|\n");
    Color(15, 0);
    printf("|                                    |\n");
    printf("|     Que souhaitez-vous faire ?     |\n");
    printf("|                                    |\n");
    printf("|                                    |\n");
    Color(11, 0);
    printf("|       1. Generer une phrase        |\n");
    Color(15, 0);
    printf("|                                    |\n");
    Color(11, 0);
    printf("|       2. Voir les listes de mots   |\n");
    Color(15, 0);
    printf("|                                    |\n");
    Color(4, 0);
    printf("|       3. Sortie                    |\n");
    Color(15, 0);
    printf("|------------------------------------|\n");
}
void controlStartMenu(){
    int val = controlInput(1,3);
    switch(val){
        case 1:
            GeneratorMenu();
            controlGeneratorMenu();
            break;

        case 2:
            listMenu();
            controlListMenu();
            break;


        case 3:
            exit(0);
            break;
    }

}

void controlGeneratorMenu(){
    int val = controlInput(1,3);
    switch(val){
        case 1:
            printf("Fonctionnalite non disponible pour l'instant\n");
            controlGeneratorMenu();
            break;

        case 2:
            printf("Fonctionnalite non disponible pour l'instant\n");
            controlGeneratorMenu();
            break;

        case 3:
            startMenu();
            controlStartMenu();
            break;
    }

}
void GeneratorMenu(){
    Color(11, 0);
    printf("|---------Generer une phrase---------|\n");
    Color(15, 0);
    printf("|                                    |\n");
    printf("|       1. Avec les formes de bases  |\n");
    printf("|                                    |\n");
    printf("|       2. Avec les formes flechies  |\n");
    printf("|                                    |\n");
    printf("|       3. Retour                    |\n");
    printf("|------------------------------------|\n");
}
void listMenu(){
    Color(11, 0);
    printf("|------Voir les listes de mots-------|\n");
    Color(15, 0);
    printf("|                                    |\n");
    printf("|       1. Nom                       |\n");
    printf("|                                    |\n");
    printf("|       2. Adjectif                  |\n");
    printf("|                                    |\n");
    printf("|       3. Verbe                     |\n");
    printf("|                                    |\n");
    printf("|       4. Adverbe                   |\n");
    printf("|                                    |\n");
    printf("|       5. Retour                    |\n");
    printf("|------------------------------------|\n");
}

void controlListMenu(){
    int val = controlInput(1,5);
    listString list;
    switch(val){
        case 1:
            list = getBasesFormesAdverbe("../test.txt");
            displayStringList(list);
            printf("\n");
            controlListMenu();
            break;

        case 2:
            list = getBasesFormesAdjective("../test.txt");
            displayStringList(list);
            printf("\n");
            controlListMenu();
            break;

        case 3:
            list = getBasesFormesVerbe("../test.txt");
            displayStringList(list);
            printf("\n");
            controlListMenu();
            break;

        case 4:
            list = getBasesFormesAdverbe("../test.txt");
            displayStringList(list);
            printf("\n");
            controlListMenu();

        case 5:
            startMenu();
            controlStartMenu();
            break;
    }

}



int controlInput(int min,int max){
    int n;
    printf("Votre choix : ");
    scanf("%d", &n);

    while ((n<min) || (n>max)){
        printf("Erreur, ressaisiser :\n");
        scanf("%d", &n);
    }
    return n;
}