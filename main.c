#include <stdio.h>
#include <stdlib.h>

int main() {
    char data[20];
    FILE* dictionnaire;
    dictionnaire = fopen("dictionnaire_non_accentue.txt","r");

    if(dictionnaire == NULL){
        printf("Le fichier ne peux pas être ouvert");
    }else{
        fscanf(dictionnaire,"%s",&data);
        fclose(dictionnaire);
    }

    return 0;
}
