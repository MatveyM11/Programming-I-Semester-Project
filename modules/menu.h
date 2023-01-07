#ifndef MENU_H
#define MENU_H
#include "objects.h"

//Guarda la puntuación en un archivo externo
void saveScore(int score);

//Divide la puntuación en números separados y decide donde se van a pintar
void renderNumber(int playerPoints, int xPos, int yPos);


//---------------------------MENUS-----------------------------

//Menu principal seleccionar dificultad(facil,normal y dificil)
int menu();

//Menu que se muestra al pulsar ESC(menu de pausa) con opciones exit,continue y restart.
bool menuContinue(int playerPoints);

//Menu que se muestra al morir(con opciones restart y exit)
bool menuDeath(int playerPoints);




#endif
