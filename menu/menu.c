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
    printf("|       1. Generer une phrase        |\n");
    printf("|                                    |\n");
    printf("|       2. Voir les listes de mots   |\n");
    printf("|                                    |\n");
    printf("|       3. Sortie                    |\n");
    printf("|------------------------------------|\n");
}
void controlStartMenu(){
    int size;
    int val = controlInput(1,3);
    switch(val){
        case 1:
            printf("Fonctionnalite non disponible pour l'instant\n");
            break;

        case 2:

            break;


        case 3:
            exit(0);
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