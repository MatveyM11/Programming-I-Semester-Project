#include <stdlib.h>
#include "../gfx/gfx.h"
#include "menu.h"
#include "constants.h"
#include "objects.h"
#include "manageObjects.h"
#include "draw.h"
#include "sprites.h"
#include "enemies.h"
#include "enemies.cc"
#include "keyDetection.h"


//Bucle principal
void mainLoop(){
    char inputKey;

    int map[500][500] = {},
        alternateInt = 0,
        difficultyRefresh,
        damage_clock = 0,
        moveClock = 0,
        gameClock = 0,
        randomEnemy = rand() % 40,
        moveState = 1;

    bool alternate = false,
        YouDied = false,
        restart;

    //Inicia la pantalla del juego
    gfx_open(screenHeight,ScreenWidth,"Martian Doom");

    //Bucle infinito    
    while(true){      
        //---------------MENÚ---------------
        difficultyRefresh = menu(); 
        

        //---------------------INICIO---------------------
        
        //Array de enemigos
        enemy enemiesArray[MAX_ENEMIES_NUMBER] = {};

        //Crea los enemigos
        for(int i = 0; i < MAX_ENEMIES_NUMBER; i++){
            createEnemy(map,enemiesArray,i+1);
        }
        //Crea los structs 
        spacecraft player = {0,3,250,473,25,20};
        bullet damageBullet = {player.xPos+8, player.yPos-5,10,3};
        bullet damageBulletEnemy = {500, 500, 10, 3};
        
        
        restart = false;
        //Bucle principal infinito
        while(restart == false){

            //Variables para que cada cosa se refresque en un momento diferente
            gameClock++;
            if((gameClock%60 == 0) && damage_clock < 5){ // at 33333 microsecond, 5 damage clocks = 5 seconds.
                damage_clock++;
            }

            if((gameClock%60 == 0) && moveClock < 1){ // at 33333 microsecond, 1 move clocks = 1 seconds.
                moveClock++;
            }
            

            while(gfx_event_waiting() == true){
                inputKey = gfx_wait();
                
                if(int(inputKey) == 27) restart = menuContinue(player.points);
                player.xPos = spacecraftMovement(int(inputKey),player.xPos);                 
            }
        
            if(alternateInt == 20){
                if(alternate) alternate = false;
                else alternate = true;
                alternateInt = 0;
            }
            else alternateInt++;
            

            drawUpBackground(); //Imprime la barra de arriba
            renderHealth(player.health);
            renderNumber(player.points, 480, 3); //Draw numbers, this will show your points, draws from right to left
            spacecraftManage(map, player.xPos, player.yPos);
            enemiesManage(map, enemiesArray, alternate, YouDied, player.yPos, player.xPos, player.health, damage_clock, moveState, moveClock);
            bulletManage(map, damageBullet, enemiesArray, player.xPos+8, player.yPos-5, player.points);

            bulletEnemyManage(map, damageBulletEnemy, enemiesArray, player.xPos, player.yPos, player.health, randomEnemy);


            //Refresca la pantalla
            refreshScreen(difficultyRefresh);

            if(YouDied == 1 or player.health <= 0){
                restart = menuDeath(player.points);
            }
        }
    }
}



