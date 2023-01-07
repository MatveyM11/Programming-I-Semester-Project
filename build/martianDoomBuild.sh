 #!/bin/bash doom

 g++  -o build/proyecto.out main.cc gfx/gfx.c modules/keyDetection.cc modules/bucle.cc  modules/manageObjects.cc modules/mapChanges.cc modules/draw.cc modules/menu.cc -lX11 -lm 
