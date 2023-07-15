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
    std::vector<Point> puntos;
    Point punto1 = {377, 249};
    Point punto2 = {411, 197};
    Point punto3 = {436, 249};

    puntos.push_back(punto1);
    puntos.push_back(punto2);
    puntos.push_back(punto3);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos, Color(255,0,0));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
