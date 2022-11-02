//
// Created by maxou on 26/10/2022.
//

#include "three.h"


three* createInitialThree(){
    three *mythree = malloc(sizeof (three));
    for (int i=0;i<27;i++){
        char lettre = (char)(i+65);
        mythree->root[i]=malloc(sizeof (node));
        mythree->root[i]->data=lettre;
    }
    return mythree;
}