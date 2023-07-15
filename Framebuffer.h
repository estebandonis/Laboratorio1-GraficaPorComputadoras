#pragma once
#include <vector>
#include "Color.h"
#include "Vertex2.h"
#include "Point.h"
#include <fstream>

class Framebuffer {
public:
    // Constructor que recibe el ancho y alto del framebuffer
    Framebuffer(int ancho, int alto);

    // Destructor
    ~Framebuffer();

    // Métodos para obtener el ancho y alto del framebuffer
    int ancho() const;
    int alto() const;

    // Métodos para obtener el valor de un píxel en el framebuffer
    Color pixel(int x, int y) const;

    // Método para establecer el valor de un píxel en el framebuffer
    void establecerPixel(int x, int y, const Color& color);

    // Método para obtener un vector de píxeles
    const std::vector<Vertex2>& vertices() const;

    // Función para llenar todo el framebuffer con un color específico
    void clear(const Color& clearColor);

    void dibujarPunto(const Vertex2& vertex, const Color& color);

    void dibujarLinea(const Vertex2& inicio, const Vertex2& fin, const Color& color);

    void dibujarPoligono(const std::vector<Point>& puntos, const Color& color);

    bool estaDentroDelPoligono(const std::vector<Point>& puntos, int x, int y);

    void fillPolygon(const std::vector<Point>& puntos, const Color& color);

    // Función para renderizar el framebuffer en un archivo BMP
    void renderBuffer();
private:
    int m_ancho;
    int m_alto;
    std::vector<Vertex2> m_vertices;
};