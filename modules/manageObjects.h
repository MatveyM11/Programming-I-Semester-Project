#ifndef MANAGE_OBJECTS_H
#define MANAGE_OBJECTS_H

//Controla la posición de los enemigos 
void enemiesManage(int mapg[500][500],enemy enemiesArray[MAX_ENEMIES_NUMBER],bool alternate, bool& YouDied, int playerY, int playerX, int& health, int& damageClock, int& moveState, int& moveClock);

//Controla la posición de la bala y si ha colisionado con algún enemigo
void bulletManage(int mapg[500][500],bullet& damageBullet,enemy enemiesArray[MAX_ENEMIES_NUMBER],int playerXpos, int playerYpos, int& points);

//Controla la posición de la bala enemiga y si ha colisionado con la nave
void bulletEnemyManage(int mapg[500][500], bullet& damageBulletEnemy,enemy enemiesArray[MAX_ENEMIES_NUMBER],int playerXpos, int playerYpos, int& health, int& randomEnemy);

//Llama a la función de dibujar la bala
void spacecraftManage(int mapg[500][500], int spacecraftX, int spacecraftY);

//Controla la posición en pantalla de la vida y llama a otra función para dibujarla
void renderHealth(int health);

#endif
