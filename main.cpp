#include <iostream>
#include "Color.h"
#include "Framebuffer.h"
#include "Point.h"

Color clearColor(0, 0, 0);
Color currentColor(122, 122, 122);

void render() {
    Framebuffer framebuffer(800, 600);

    Color prueba(10, 10, 10);
    clearColor = prueba;

    framebuffer.clear(clearColor);

    Color NewCurrent(100,100,100);
    currentColor = NewCurrent;

    Vertex2 ver1 = {500, 500, Color(255, 0, 0)};
    Vertex2 ver2 = {50, 50, Color(255, 0, 0)};

    framebuffer.dibujarPunto(ver1, currentColor);
    framebuffer.dibujarPunto(ver2, currentColor);

    Vertex2 inicio = {100, 100, Color(255, 0, 0)};
    Vertex2 fin = {200, 200, Color(255, 0, 0)};
    Color verde(0, 255, 0);
    framebuffer.dibujarLinea(inicio, fin, verde);

    // Definir un polígono con cuatro puntos
    std::vector<Point> puntos;
    Point punto1 = {165, 380};
    Point punto2 = {185, 360};
    Point punto3 = {180, 330};
    Point punto4 = {207, 345};
    Point punto5 = {233, 330};
    Point punto6 = {230, 360};
    Point punto7 = {250, 380};
    Point punto8 = {220, 385};
    Point punto9 = {205, 410};
    Point punto10 = {193, 383};

    puntos.push_back(punto1);
    puntos.push_back(punto2);
    puntos.push_back(punto3);
    puntos.push_back(punto4);
    puntos.push_back(punto5);
    puntos.push_back(punto6);
    puntos.push_back(punto7);
    puntos.push_back(punto8);
    puntos.push_back(punto9);
    puntos.push_back(punto10);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos, Color(255, 0, 0));
    framebuffer.fillPolygon(puntos, Color(255,255,255));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
