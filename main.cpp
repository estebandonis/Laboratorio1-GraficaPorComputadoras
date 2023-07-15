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
    std::vector<Point> puntos3;
    Point punto1_3 = {377, 249};
    Point punto2_3 = {411, 197};
    Point punto3_3 = {436, 249};

    puntos3.push_back(punto1_3);
    puntos3.push_back(punto2_3);
    puntos3.push_back(punto3_3);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos3, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos3, Color(255,0,0));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
