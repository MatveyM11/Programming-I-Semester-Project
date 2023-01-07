#ifndef DRAW_H
#define DRAW_H
#include "objects.h"

//Dibuja en pantalla la bala
void drawBullet(bullet actualBullet);

//Dibuja en pantalla los sprites de los enemigos y nave
void drawSprite(const int sprite[25][20],int height,int width,int initialX,int initialY);

//Dibuja en pantalla los números para la puntuacion
void drawNum(const int numberSprite[14][8],int initialX,int initialY);

//Dibuja en pantalla el recuadro naranja de arriba para la puntuación y la vida
void drawUpBackground();

//---------------------------MENUS-----------------------------

//Dibuja en pantalla el menu de pausa
void drawContinueMenu(const int sprite[48][142],int height,int width,int initialX,int initialY);

//Improme en pantalla el menu cuando mueres
void drawDeath(const int sprite[77][144],int height,int width,int initialX,int initialY);

//Dibuja en pantalla el menu inicial(dificultades)
void drawMenuOptimised(const int sprite[286][183],int height,int width,int initialX,int initialY);

//Dibuja en pantalla el recuadro verde de las opciones del menu
void drawOptionsBackground(int initialX, int initialY,int finalX);

//Refresca la pantalla en los menús
void refreshScreen(int lessRefresh);

#endif
