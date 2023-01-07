#ifndef ENEMIES_H
#define ENEMIES_H 
#include "objects.h"
#include "constants.h"


//Añade a los enemigos a la lista de enemigos
void appendEnemy(enemy enemiesArray[MAX_ENEMIES_NUMBER], enemy  actualEnemy);

//Crea los enemigos
void createEnemy(int map[500][500], enemy enemiesArray[MAX_ENEMIES_NUMBER], int enemyId);

#endif