# Project - Martian Doom

## Resources:

1. - [gfx: A Simple Graphics Library](https://www3.nd.edu/~dthain/courses/cse20211/fall2013/gfx/)


### Game Resources

#### Project compilation - 

1. Download it - https://github.com/mt106-ua/Programacion-I-Proyect/blob/main/sprites.h
2. CD into it's directory
3. Compile
```bash 
 g++ -o proyecto.out proyecto.cpp gfx.c drawSprite.h -lX11 -lm 
 ``` 
4. Run
```bash
./proyecto.out
```
* OR - use a script in the projects folder - [MartiandDoom_build.sh](https://github.com/mt106-ua/Programacion-I-Proyect/blob/main/Build/MartianDoom_build.sh)
* CMake - Work In Progress.

#### Sprites

- Pathway - [sprites.h](https://github.com/mt106-ua/Programacion-I-Proyect/blob/main/sprites.h)

- All sprites are made with [Krita](https://krita.org/en/)
- Image to byte array converter - [FileToCArray](https://notisrac.github.io/FileToCArray/)
* Alternative Option - https://github.com/bitbank2/image_to_c



Hell Skull aka hell_skull

- It's reference with a dimensions "rulers" - orange and green lines
![hell skull](https://user-images.githubusercontent.com/90862738/204928156-67bd5324-a169-4410-8dbb-f638bfa3bc6d.png)

- Bigger

![imagen](https://user-images.githubusercontent.com/90862738/204928447-a76739ec-abce-4d95-8d0f-376ef9318e75.png)

- And it's in-game matrix, implemented as a 2d C-array.
```cpp
int sprite[25][20] = {
        {1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1},
        {0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0},
        {0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0},
        {0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0},
        {0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0},
        {1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0},
        {1 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1},
        {1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,1},
        {1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1},
        {0 ,1 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1},
        {0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0},
        {0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,0},
        {0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0},
        {0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0},
        {0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0},
        {0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0},
        {0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0},
        {0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
};
```

- RGB 8bit * sprite with rulers
```cpp
int sprite = {
  0, 0, 0, 0, 0, 177, 173, 205, 205, 205, 205, 205, 205, 173, 177, 0, 0, 0, 0, 0, 
  177, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 173, 
  173, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 173, 
  205, 255, 255, 255, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 255, 255, 255, 205, 
  205, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 205, 
  173, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 255, 173, 
  177, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 173, 
  0, 0, 255, 255, 255, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 255, 255, 255, 0, 0, 
  0, 255, 255, 255, 0, 0, 255, 0, 255, 255, 255, 255, 0, 255, 0, 0, 255, 255, 255, 0, 
  0, 255, 255, 255, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 255, 255, 255, 0, 
  0, 0, 149, 117, 0, 255, 255, 255, 0, 150, 150, 0, 255, 255, 255, 0, 117, 149, 0, 0, 
  177, 0, 255, 223, 0, 0, 0, 0, 0, 223, 223, 0, 0, 0, 0, 0, 223, 255, 0, 173, 
  173, 32, 255, 255, 0, 0, 255, 255, 117, 222, 222, 117, 255, 255, 0, 0, 255, 255, 32, 173, 
  205, 32, 255, 255, 255, 255, 255, 255, 117, 223, 223, 117, 255, 255, 255, 255, 255, 255, 32, 205, 
  205, 32, 0, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 0, 32, 205, 
  205, 255, 0, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 0, 255, 205, 
  205, 255, 0, 0, 255, 255, 255, 255, 117, 223, 223, 117, 255, 255, 255, 255, 0, 0, 255, 205, 
  205, 255, 255, 0, 0, 255, 255, 255, 117, 222, 222, 117, 255, 255, 255, 0, 0, 255, 255, 205, 
  205, 255, 255, 255, 0, 0, 255, 255, 149, 223, 223, 149, 255, 255, 0, 0, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 0, 255, 0, 255, 0, 0, 255, 0, 255, 0, 255, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 0, 255, 0, 255, 0, 0, 255, 0, 255, 0, 255, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 0, 255, 0, 255, 0, 0, 255, 0, 255, 0, 255, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 255, 255, 255, 205, 
  205, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 205
};
```
- In-game render
![imagen](https://user-images.githubusercontent.com/90862738/204940535-edf0a393-0dac-43c6-8ded-cb61919c21cf.png)


#### Sounds 

Sounds are being runned by exectuion of the script - [sounds.sh](https://github.com/mt106-ua/Programacion-I-Proyect/blob/main/Sounds/sounds.sh), with an '&' ampersand argument that tells command line to run process in the background.
Driving code - 
```cpp
system("./sound.sh&"); // & - ampersand argument of the command line keeps a process in the background
system("pkill mpg123"); // kills sounds after end of the game
```

Sounds are taken from the original DOOM, justified by the FAIR USE for the EDUCATIONAL PURPOSES, all rights reserved by the "id Software".

1. Background sound -  [At Doom's Gate](https://github.com/mt106-ua/Programacion-I-Proyect/blob/main/Sounds/music.mp3)
