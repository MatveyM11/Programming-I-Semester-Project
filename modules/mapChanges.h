#ifndef MAP_CHANGES_H
#define MAP_CHANGES_H

/*Modifica el mapa(pantalla) para saber en que casillas hay enemigos y en cuales no.
Cada enemigo llena la matriz del mapa con un número diferente para así saber a cual
ha tocado la bala para borrarlo */
void mapAddEnemy(int mapg[500][500],int height,int width,int xPos,int yPos,int enemyId);
#endif
