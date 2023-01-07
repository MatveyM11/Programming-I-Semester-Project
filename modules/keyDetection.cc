//Detecta la tecla pulsada y devuelve la posición en el menú
int menuKeyDetection(int input, int buttonCondition){
    switch(input){
        //W
        case 119:
            if(buttonCondition == 2 || buttonCondition == 3) buttonCondition--;
            break; 
        //A
        case 97:
            if(buttonCondition == 2 || buttonCondition == 3) buttonCondition--;
            break;
        //S
        case 115:
            if(buttonCondition == 1 || buttonCondition == 2) buttonCondition++;
            break;
        //D
        case 100:
            if(buttonCondition == 1 || buttonCondition == 2) buttonCondition++;
            break;
        
        //UP ARROW
        case 82:
            if(buttonCondition == 2 || buttonCondition == 3) buttonCondition--;
            break; 
        //LEFT ARROW
        case 81:
            if(buttonCondition == 2 || buttonCondition == 3) buttonCondition--;
            break; 
        //DOWN ARROW
        case 84:
            if(buttonCondition == 1 || buttonCondition == 2) buttonCondition++;
            break;
        //RIGHT ARROW
        case 83:
            if(buttonCondition == 1 || buttonCondition == 2) buttonCondition++;    
            break;
    }
    return buttonCondition;
}

//controla la posicion de la nave
int spacecraftMovement(int input,int playerXpos){  
    switch (input){
        //A
        case 97:
            if(playerXpos> 3){ // Borde izquierdo
            playerXpos -= 5;
            }
            break;
        //D
        case 100:
            if(playerXpos < 480){ // Borde derecho
            playerXpos += 5;
            }
            break;
        //Flecha izquierda
        case char(81): 
            if(playerXpos > 3){ // Borde izquierdo
            playerXpos -= 5;
            }
            break;
        //Flecha derecha
        case char(83):
            if(playerXpos < 480){ // Borde derecho
            playerXpos += 5;
            }
            break;
    }
    return playerXpos;
}



