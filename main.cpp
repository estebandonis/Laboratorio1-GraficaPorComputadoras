#include <iostream>
#include "Color.h"
#include "Framebuffer.h"
#include "Point.h"

Color clearColor(0, 0, 0);
Color currentColor(122, 122, 122);

void render() {
    Framebuffer framebuffer(800, 600);

    framebuffer.clear(clearColor);

    Color NewCurrent(100,100,100);
    currentColor = NewCurrent;

    // Definir un polígono con cuatro puntos
    std::vector<Point> puntos2;
    Point punto1_2 = {321, 335};
    Point punto2_2 = {288, 286};
    Point punto3_2 = {339, 251};
    Point punto4_2 = {374, 302};

    puntos2.push_back(punto1_2);
    puntos2.push_back(punto2_2);
    puntos2.push_back(punto3_2);
    puntos2.push_back(punto4_2);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos2, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos2, Color(0,0,255));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
