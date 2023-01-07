#include <unistd.h>
#include "../gfx/gfx.h"
#include "constants.h"
#include "objects.h"


//Dibuja la bala
void drawBullet(bullet actualBullet){
    gfx_color(255,0,0);  
    for (int i = 0; i < actualBullet.height; i++){
        gfx_line(actualBullet.xPos,actualBullet.yPos+i,
        actualBullet.xPos+actualBullet.width,actualBullet.yPos+i);
    }
}

//Dibuja los sprites
void drawSprite(const int sprite[25][20],int height,int width,int initialX,int initialY){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(sprite[i][j] == 1){
                gfx_color(100+i*3,120+i*2,10*j*3);
                gfx_line(initialX+j,initialY+i,initialX+j,initialY+i);
            }

        }
    }
}

//Dibuja los números para el marcador
void drawNum(const int numberSprite[14][8],int initialX,int initialY){
    gfx_color(77,33,185);
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 8; j++){
            if(numberSprite[i][j] != 0){
                gfx_line(initialX+j,initialY+i,initialX+j,initialY+i);
            }
        }
    }
}

//Dibuja el marco de arriba de la pantalla
void drawUpBackground(){
    gfx_color(232,130,34);
    
    for(int i = 0; i < 20; i++){
        gfx_line(0,i,500,i);
    }
}

//---------------------------MENUS-----------------------------

//Dibuja el menu de espera(cuando pulsas ESC)
void drawContinueMenu(const int sprite[48][142],int height,int width,int initialX,int initialY){
    gfx_color(100,100,100);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(sprite[i][j] != 0){
                gfx_line(initialX+j,initialY+i,initialX+j,initialY+i);
            }

        }
    }
}

//Dibuja la pantalla de muerte
void drawDeath(const int sprite[77][144],int height,int width,int initialX,int initialY){
    gfx_color(100,100,100);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(sprite[i][j] != 0){
                gfx_line(initialX+j,initialY+i,initialX+j,initialY+i);
            }

        }
    }
}

//Dibuja el menú
void drawMenuOptimised(const int sprite[286][183],int height,int width,int initialX,int initialY){
    gfx_color(100,100,100);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(sprite[i][j] != 0){
                gfx_line(initialX+j,initialY+i,initialX+j,initialY+i);
            }

        }
    }
}

//Dibuja el recuadro verde de las opciones
void drawOptionsBackground(int initialX, int initialY,int finalX){
    gfx_color(0,200,0);
    for(int i = 0; i < 16; i++){
        gfx_line(initialX, initialY+i,finalX,initialY+i);
    }
}

//Refresca la pantalla
void refreshScreen(int lessRefresh){
    //Fuerza a que se dibujen todos los elementos pendientes.
    gfx_flush();
    //Espera 0.033s para refrescar la pantalla(es lo equivalente a 30fps)
    usleep(REFRESH_TIME/(4-lessRefresh));
    //Limpia la pantalla
    gfx_clear();
}