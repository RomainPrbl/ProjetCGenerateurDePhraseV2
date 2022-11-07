//
// Created by maxou on 28/10/2022.
//

#ifndef PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
#define PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include <string.h>
void displayLines(char *filename);
listString getBasesFormes(char *filename);
listString getBasesFormesNom(char *filename);
void addBasesFormesInThree(listString List,three three);
#endif //PROJETCGENERATEURDEPHRASEV2_DISPLAY_TXT_H
