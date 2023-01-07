#include <stdlib.h>
#include "../gfx/gfx.h"
#include "sprites.h"
#include "constants.h"
#include "objects.h"
#include "mapChanges.h"
#include "draw.h"



//Controla la posición de los enemigos 
void enemiesManage(int mapg[500][500],enemy enemiesArray[MAX_ENEMIES_NUMBER],bool alternate, bool& YouDied, int playerY, int playerX, int& health, int& damage_clock, int& move_state, int& move_clock){
    bool invulnerability = false;

    for(int i = 0; i < MAX_ENEMIES_NUMBER; i++){
        if(move_state == 1 && enemiesArray[i].xPos == 0 && enemiesArray[i].id != 0){
        move_state = 2;
        move_clock = 0;
        }
        else if(move_state == 2 && move_clock == 1){
            move_state = 3;
        }
        else if(move_state == 3 && enemiesArray[i].xPos >= 480){
            move_state = 1;
        }
        

        if(enemiesArray[i].id != 0){
            if(alternate){
                if(move_state == 1 && enemiesArray[i].xPos != 0 && enemiesArray[i].id != 0){
                    enemiesArray[i].xPos -= 1;
                }
                else if(move_state == 2 && move_clock == 0 && enemiesArray[i].id != 0){
                    enemiesArray[i].yPos += 1;
                }
                else if(move_state == 3 && enemiesArray[i].xPos != 480 && enemiesArray[i].id != 0){
                    enemiesArray[i].xPos += 1;
                }
                
                if(enemiesArray[i].yPos >=500){
                    YouDied = 1;
                }
                else if(enemiesArray[i].yPos >= playerY && enemiesArray[i].xPos >= playerX){
                    if(damage_clock == 5 && invulnerability == false){
                        health--;
                        damage_clock = 0;
                        invulnerability = true;
                    }
                    
                }
            }
            //Choose witch enemy are going to draw
            if(i%2==0){
                if (alternate){
                    drawSprite(spriteEnemyOneState1,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);
                }
                else{
                    drawSprite(spriteEnemyOneState2,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);            
                }
            }
            else if(i%3==0){
                if (alternate){
                    drawSprite(spriteEnemyTwoState1,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);
                }
                else{
                    drawSprite(spriteEnemyTwoState2,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);            
                }
            }
            else if(i%5==0){
                if (alternate){
                    drawSprite(spriteEnemyThreeState1,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);
                }
                else{
                    drawSprite(spriteEnemyThreeState2,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);            
                }
            }
            else if(i%7==0){
                if (alternate){
                    drawSprite(spriteEnemyFourState1,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);
                }
                else{
                    drawSprite(spriteEnemyFourState2,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);            
                }
            }
            else {
                if (alternate){
                    drawSprite(spriteEnemyFiveState1,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);
                }
                else{
                    drawSprite(spriteEnemyFiveState2,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos);            
                }
            }
            mapAddEnemy(mapg,enemiesArray[i].height,enemiesArray[i].width,enemiesArray[i].xPos,enemiesArray[i].yPos,enemiesArray[i].id);
        }
    }
    
}

//Controla la posición de la bala y si ha colisionado con algún enemigo
void bulletManage(int mapg[500][500],bullet &damageBullet,enemy enemiesArray[MAX_ENEMIES_NUMBER],
                int playerXpos, int playerYpos, int& points){

    int y = 10;
    drawBullet(damageBullet);

    damageBullet.yPos = damageBullet.yPos - y;

    for(int i = 0; i < MAX_ENEMIES_NUMBER; i++){
        
        if(damageBullet.yPos >= enemiesArray[i].yPos && damageBullet.xPos >= enemiesArray[i].xPos
           && damageBullet.yPos <= enemiesArray[i].yPos+25 && damageBullet.xPos <= enemiesArray[i].xPos+20 && enemiesArray[i].id != 0){
            points += 10;
            enemiesArray[i] = {};
            damageBullet.xPos = {};
            damageBullet.yPos = {};
            damageBullet.xPos = playerXpos;
            damageBullet.yPos = playerYpos;
        }
    }
    if(damageBullet.yPos <= 20){
        damageBullet.yPos = playerYpos;
        damageBullet.xPos = playerXpos;
    }
}

//Controla la posición de la bala enemiga y si ha colisionado con la nave
void bulletEnemyManage(int mapg[500][500], bullet &damageBulletEnemy,enemy enemiesArray[MAX_ENEMIES_NUMBER],
                    int playerXpos, int playerYpos, int& health, int& randomEnemy){
        
        int y = 10;

        if(enemiesArray[randomEnemy].id != 0 && damageBulletEnemy.yPos == 500 && damageBulletEnemy.xPos == 500){
            damageBulletEnemy.yPos = enemiesArray[randomEnemy].yPos;
            damageBulletEnemy.xPos = enemiesArray[randomEnemy].xPos;
            }
        
        drawBullet(damageBulletEnemy);
        damageBulletEnemy.yPos = damageBulletEnemy.yPos + y;

        if(damageBulletEnemy.yPos >= 500){
            randomEnemy = rand() % 40;
            damageBulletEnemy.xPos = 500;
            damageBulletEnemy.yPos = 500;
        }

        if(damageBulletEnemy.yPos >= playerYpos && damageBulletEnemy.xPos >= playerXpos
           && damageBulletEnemy.yPos <= playerYpos+25 && damageBulletEnemy.xPos <= playerXpos+20){
            health--;
            
            damageBulletEnemy.xPos = 500;
            damageBulletEnemy.yPos = 500;
            randomEnemy = rand() % 40;
        }


}

//Llama a la función de dibujar la bala
void spacecraftManage(int mapg[500][500], int spacecraftX, int spacecraftY){
    drawSprite(spriteSpacecraft, 25, 20, spacecraftX, spacecraftY);
}

//Controla la posición en pantalla de la vida y llama a otra función para dibujarla
void renderHealth(int health){
    int numX = 50, numY = 3, space = 20;
    for(int i = health; i > 0; i--){
        drawNum(healthSprite,numX,numY);
        numX -= space;
    }
}