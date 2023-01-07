#include <fstream>
#include <unistd.h>
#include "../gfx/gfx.h"
#include "constants.h"
#include "alphanumericSprites.h"
#include "menuSprites.h"
#include "draw.h"
#include "keyDetection.h"
using namespace std;

//Guarda la puntuación en un archivo externo
void saveScore(int score){
    ofstream Playscore("playscore.md"); // Creates file in Build directory
    // Write to the file
    Playscore << "Your score is - " << score;
    // Close the file
    Playscore.close();
}

//Divide la puntuación en números separados y decide donde se van a pintar
void renderNumber(int playerPoints, int xPos, int yPos){
    int numberReverse;
    
    while(10*playerPoints/10 != 0){
        numberReverse = playerPoints%10;
        switch(numberReverse){
            case 0:
                drawNum(zeroSprite,xPos,yPos);
                break;
            case 1:
                drawNum(unoSprite,xPos,yPos);
                break;
            case 2:
                drawNum(dosSprite,xPos,yPos);
                break;
            case 3:
                drawNum(tresSprite,xPos,yPos);
                break;
            case 4:
                drawNum(cuatroSprite,xPos,yPos);
                break;
            case 5:
                drawNum(cincoSprite,xPos,yPos);
                break;
            case 6:
                drawNum(seisSprite,xPos,yPos);
                break;
            case 7:
                drawNum(sieteSprite,xPos,yPos);
                break;
            case 8:
                drawNum(ochoSprite,xPos,yPos);
                break;
            case 9:
                drawNum(nueveSprite,xPos,yPos);
                break;
        }
        xPos -= 10;
        
        playerPoints = playerPoints/10;    
    }
}

//Menu principal seleccionar dificultad(facil,normal y dificil)
int  menu(){
    int buttonCondition = 1;
    int input;
    bool menuCondition = true;

	while(menuCondition == true){
        while(gfx_event_waiting() == true && menuCondition == true){
            input = gfx_wait();
            if(int(input) == 13) menuCondition = false;
            else buttonCondition= menuKeyDetection(int(input),buttonCondition);
        }

        switch(buttonCondition){ 
            case 1:
                drawOptionsBackground(218,100,260);
                break;

            case 2:
                drawOptionsBackground(218,135,289);
                break;

            case 3:
                drawOptionsBackground(218,170,262);
                break;
        }
        drawMenuOptimised(spriteMenuOptimised,286,183,160, 50);
        refreshScreen(3);
    }
    return buttonCondition;
}
    

//Menu que se muestra al pulsar ESC(menu de pausa) con opciones exit,continue y restart.
bool menuContinue(int playerPoints){
    int buttonCondition = 1,
        input;
    bool restart = false,
        menuCondition = true;


    while(menuCondition == true){
        while(gfx_event_waiting() == true && menuCondition == true){
            input = gfx_wait();
            if(int(input) == 13){
                //EXIT
                if(buttonCondition == 1) exit(0);
                //Restart
                else if(buttonCondition == 3) restart = true;
                
                menuCondition = false;
                saveScore(playerPoints);
            }
            else buttonCondition = menuKeyDetection(int(input),buttonCondition);

            

        }
        //draw options green background
        switch(buttonCondition){ 
            case 1:
                drawOptionsBackground(180,100,225);
                break;

            case 2:
                drawOptionsBackground(240,100,322);
                break;

            case 3:
                drawOptionsBackground(215,132,289);
                break;
        }

        drawContinueMenu(spriteContinueMenu,48,142,180, 100);
        refreshScreen(3);
    }
    return restart;
}

//Menu que se muestra al morir(con opciones restart y exit)
bool menuDeath(int playerPoints){
    int buttonCondition = 1,
        input;
    bool restart = true,
        menuCondition = true;


    while(menuCondition == true){
        while(gfx_event_waiting() == true){
            input = gfx_wait();
            if(int(input) == 13){
                menuCondition = false;
                saveScore(playerPoints);
                
                // restart
                if(buttonCondition == 1) restart = true;
                // exit
                else exit(0); 
            }
            else buttonCondition = menuKeyDetection(int(input),buttonCondition);
        }
        //draw options green background
        switch(buttonCondition){ 
            case 1:
                drawOptionsBackground(159,111,233);
                break;

            case 2:
                drawOptionsBackground(257,111,304);
                break;
        }

        drawDeath(spriteDeath,77,144,160, 50);
        renderNumber(playerPoints, 250, 83);
        refreshScreen(3);
    }
    return restart;
}

