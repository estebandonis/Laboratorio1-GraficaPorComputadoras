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
    std::vector<Point> puntos4;
    Point punto1 = {413, 177};
    Point punto2 = {448, 159};
    Point punto3 = {502, 88};
    Point punto4 = {553, 53};
    Point punto5 = {535, 36};
    Point punto6 = {676, 37};
    Point punto7 = {660, 52};
    Point punto8 = {750, 145};
    Point punto9 = {761, 179};
    Point punto10 = {672, 192};
    Point punto11 = {659, 214};
    Point punto12 = {615, 214};
    Point punto13 = {632, 230};
    Point punto14 = {580, 230};
    Point punto15 = {597, 215};
    Point punto16 = {552, 214};
    Point punto17 = {517, 144};
    Point punto18 = {466, 180};

    puntos4.push_back(punto1);
    puntos4.push_back(punto2);
    puntos4.push_back(punto3);
    puntos4.push_back(punto4);
    puntos4.push_back(punto5);
    puntos4.push_back(punto6);
    puntos4.push_back(punto7);
    puntos4.push_back(punto8);
    puntos4.push_back(punto9);
    puntos4.push_back(punto10);
    puntos4.push_back(punto11);
    puntos4.push_back(punto12);
    puntos4.push_back(punto13);
    puntos4.push_back(punto14);
    puntos4.push_back(punto15);
    puntos4.push_back(punto16);
    puntos4.push_back(punto17);
    puntos4.push_back(punto18);

    // Dibujar el polígono en el framebuffer con el color rojo
    framebuffer.dibujarPoligono(puntos4, Color(255, 255, 255));
    framebuffer.fillPolygon(puntos4, Color(0,255,0));

    std::vector<Point> puntos5;
    Point punto1_5 = {682, 175};
    Point punto2_5 = {708, 120};
    Point punto3_5 = {735, 148};
    Point punto4_5 = {739, 170};

    puntos5.push_back(punto1_5);
    puntos5.push_back(punto2_5);
    puntos5.push_back(punto3_5);
    puntos5.push_back(punto4_5);


    framebuffer.fillPolygon(puntos5, Color(0,0,0));

    framebuffer.renderBuffer();
}

int main() {
    render();
    
    return 0;
}
