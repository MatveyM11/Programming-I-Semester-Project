#include "constants.h"
#include "objects.h"

//Añade a los enemigos a la lista de enemigos
void appendEnemy(enemy enemiesArray[MAX_ENEMIES_NUMBER], enemy  actualEnemy){
    for (int i = 0; i < MAX_ENEMIES_NUMBER; i++){
        if(enemiesArray[i].id == 0){
            enemiesArray[i] = actualEnemy;
            break;
        }
    }
}

//Crea los enemigos
void createEnemy(int map[500][500], enemy enemiesArray[MAX_ENEMIES_NUMBER], int enemyId){
    int x, y,
        height = 25,
        width = 20,
        lineCounter;
    if(enemyId == 1){
        y = 20; 
        lineCounter = 0; 
        x = 140;
    } 
    else if(lineCounter != 10){
        x += 20;
    } 
    else{
        lineCounter = 0;
        x = 140;
        y += 25;
    }
    lineCounter++;

    enemy actualEnemy = {enemyId,x,y,height,width}; 
    appendEnemy(enemiesArray,actualEnemy);

}
