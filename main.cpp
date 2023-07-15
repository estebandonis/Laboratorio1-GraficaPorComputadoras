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
    std::vector<Point> puntos1;
    Point punto1_1 = {165, 380};
    Point punto2_1 = {185, 360};
    Point punto3_1 = {180, 330};
    Point punto4_1 = {207, 345};
    Point punto5_1 = {233, 330};
    Point punto6_1 = {230, 360};
    Point punto7_1 = {250, 380};
    Point punto8_1 = {220, 385};
    Point punto9_1 = {205, 410};
    Point punto10_1 = {193, 383};

    puntos1.push_back(punto1_1);
    puntos1.push_back(punto2_1);
    puntos1.push_back(punto3_1);
    puntos1.push_back(punto4_1);
    puntos1.push_back(punto5_1);
    puntos1.push_back(punto6_1);
    puntos1.push_back(punto7_1);
    puntos1.push_back(punto8_1);
    puntos1.push_back(punto9_1);
    puntos1.push_back(punto10_1);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos1, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos1, Color(255,255,0));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
