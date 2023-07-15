#include <iostream>
#include "Color.h"
#include "Framebuffer.h"
#include "Point.h"

Color clearColor(0, 0, 0);
Color currentColor(122, 122, 122);

void render() {
    Framebuffer framebuffer(800, 600);

    framebuffer.clear(clearColor);

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
    framebuffer.dibujarPoligono(puntos, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos, Color(255,255,0));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
