#ifndef OBJECTS_H
#define OBJECTS_H

//Declaración de los tipos de objetos que tenemos enemigos, la nave(que dispara) y la bala
//La posicion siempre es arriba izquierda del sprite    
struct enemy
{   
    //Cuando el id=0 significará que el enemigos está eliminado y no se esta dibujando
    int id; 
    int xPos;
    int yPos;
    int height; //25
    int width; //20

};
struct spacecraft
{   
    int points; // 0 on start, 1 kill = 10pts.
    int health;
    int xPos;
    int yPos;
    const int height; //25
    const int width; //20
};
struct bullet
{   
    int xPos;
    int yPos;
    int height; //5
    int width; //2
};

#endif
