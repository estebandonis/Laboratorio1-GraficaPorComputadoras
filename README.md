# CC2018-lab1
Renderizar Polígonos con C++
## Using MacOS
Para compilarlo, debemos de ejecutar el siguiente comando en la terminal:
```shell
g++ -c main.cpp Color.cpp Vertex2.cpp Framebuffer.cpp Point.cpp
```
Luego debemos de enlazar todos los archivos .o:
```shell
g++ main.o Vertex2.o Color.o Framebuffer.o Point.o -o main
```
Por último ya solo debemos de ejectuar main:
```shell
./main
```
Esto último genera el archivo out.bmp.