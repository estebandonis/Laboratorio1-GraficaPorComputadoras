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
