#include "Framebuffer.h"
#include "Vertex2.h"

// Constructor que recibe el ancho y alto del framebuffer
Framebuffer::Framebuffer(int ancho, int alto) {
    // Almacenar el ancho y alto del framebuffer
    m_ancho = ancho;
    m_alto = alto;

    // Inicializar el vector de píxeles con el tamaño adecuado
    m_vertices.resize(ancho * alto);

    // Inicializar todos los píxeles a negro
    for (int i = 0; i < m_vertices.size(); i++) {
        m_vertices[i].x = i % ancho;
        m_vertices[i].y = i / ancho;
        m_vertices[i].color = Color(0, 0, 0);
    }
}

// Destructor
Framebuffer::~Framebuffer() {
    // El vector de píxeles se libera automáticamente al salir de la función
}

// Métodos para obtener el ancho y alto del framebuffer
int Framebuffer::ancho() const {
    return m_ancho;
}

int Framebuffer::alto() const {
    return m_alto;
}

// Métodos para obtener y establecer el valor de un píxel en el framebuffer
Color Framebuffer::pixel(int x, int y) const {
    // Buscar el objeto Vertex2 correspondiente
    int indice = x + y * m_ancho;
    return m_vertices[indice].color;
}

void Framebuffer::establecerPixel(int x, int y, const Color& color) {
    // Buscar el objeto Vertex2 correspondiente
    int indice = x + y * m_ancho;
    m_vertices[indice].color = color;
}

// Método para obtener un vector de píxeles
const std::vector<Vertex2>& Framebuffer::vertices() const {
    return m_vertices;
}

// Función para llenar todo el framebuffer con un color específico
void Framebuffer::clear(const Color& clearColor) {
    for (int i = 0; i < m_vertices.size(); i++) {
        m_vertices[i].color = clearColor;
    }
}

void Framebuffer::dibujarPunto(const Vertex2& vertex, const Color& color) {
    // Establecer el valor del píxel correspondiente al vértice con el color especificado
    establecerPixel(vertex.x, vertex.y, color);
}

void Framebuffer::dibujarLinea(const Vertex2& inicio, const Vertex2& fin, const Color& color) {
    // Algoritmo de Bresenham para trazar una línea entre dos puntos
    int x0 = inicio.x;
    int y0 = inicio.y;
    int x1 = fin.x;
    int y1 = fin.y;
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int error = dx - dy;

    while (true) {
        // Dibujar un punto en la posición actual de la línea
        Vertex2 punto = {x0, y0, color};
        dibujarPunto(punto, color);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        int e2 = 2 * error;
        if (e2 > -dy) {
            error -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            error += dx;
            y0 += sy;
        }
    }
}

void Framebuffer::dibujarPoligono(const std::vector<Point>& puntos, const Color& color) {
    // Dibujar una línea desde cada punto hasta el siguiente
    for (int i = 0; i < puntos.size() - 1; i++) {
        Vertex2 one = {puntos[i].x, puntos[i].y};
        Vertex2 two = {puntos[i + 1].x, puntos[i + 1].y};

        dibujarLinea(one, two, color);
    }
    // Dibujar una línea desde el último punto hasta el primero
    Vertex2 atras = {puntos.back().x, puntos.back().y};
    Vertex2 frente = {puntos.front().x, puntos.front().y};

    dibujarLinea(atras, frente, color);
}

bool Framebuffer::estaDentroDelPoligono(const std::vector<Point>& puntos, int x, int y) {
    bool dentro = false;
    for (int i = 0, j = puntos.size() - 1; i < puntos.size(); j = i++) {
        if (((puntos[i].y > y) != (puntos[j].y > y)) &&
            (x < (puntos[j].x - puntos[i].x) * (y - puntos[i].y) / (puntos[j].y - puntos[i].y) + puntos[i].x)) {
            dentro = !dentro;
        }
    }
    return dentro;
}

void Framebuffer::fillPolygon(const std::vector<Point>& puntos, const Color& color) {
    // Encontrar los límites del polígono
    int minX = puntos.front().x;
    int minY = puntos.front().y;
    int maxX = puntos.front().x;
    int maxY = puntos.front().y;
    for (int i = 0; i < puntos.size(); i++) {
        const Point& punto = puntos[i];
        minX = std::min(minX, punto.x);
        minY = std::min(minY, punto.y);
        maxX = std::max(maxX, punto.x);
        maxY = std::max(maxY, punto.y);
    }

    // Rellenar el polígono con puntos
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            if (estaDentroDelPoligono(puntos, x, y)) {
                Vertex2 pun = {x, y};
                dibujarPunto(pun, color);
            }
        }
    }
}

void Framebuffer::renderBuffer() {
    // Abrir un archivo de salida en modo binario
    std::ofstream archivoSalida("out.bmp", std::ios::binary);

    // Escribir el encabezado del archivo BMP
    // Aquí se define el tamaño, la resolución, el número de colores y otros detalles de la imagen
    // Para simplificar, se asume que el framebuffer tiene 24 bits por píxel (16,7 millones de colores)
    int ancho = m_ancho;
    int alto = m_alto;
    int tamanoImagen = ancho * alto * 3;
    char encabezado[54] = {
        'B', 'M',              // Magic number
        tamanoImagen & 0xff,   // Tamaño del archivo en bytes
        (tamanoImagen >> 8) & 0xff,
        (tamanoImagen >> 16) & 0xff,
        (tamanoImagen >> 24) & 0xff,
        0, 0, 0, 0,            // Reservados
        54, 0, 0, 0,           // Offset del comienzo de los datos de imagen
        40, 0, 0, 0,           // Tamaño de la cabecera de información
        ancho & 0xff,          // Ancho de la imagen en píxeles
        (ancho >> 8) & 0xff,
        (ancho >> 16) & 0xff,
        (ancho >> 24) & 0xff,
        alto & 0xff,           // Alto de la imagen en píxeles
        (alto >> 8) & 0xff,
        (alto >> 16) & 0xff,
        (alto >> 24) & 0xff,
        1, 0,                  // Número de planos de color
        24, 0,                 // Profundidad de color (bits por píxel)
        0, 0, 0, 0,            // Compresión de imagen (0 = sin compresión)
        tamanoImagen & 0xff,   // Tamaño de los datos de imagen en bytes
        (tamanoImagen >> 8) & 0xff,
        (tamanoImagen >> 16) & 0xff,
        (tamanoImagen >> 24) & 0xff,
        0, 0, 0, 0,            // Resoluciones X e Y
        0, 0, 0, 0,            // Número de colores en la paleta
        0, 0, 0, 0             // Número de colores importantes
    };
    archivoSalida.write(encabezado, sizeof(encabezado));

    // Escribir los datos de la imagen
    const std::vector<Vertex2>& vertices = m_vertices;
    for (int i = 0; i < vertices.size(); i++) {
        // Convertir el color de cada píxel a un valor binario de 24 bits (BGR)
        char pixel[3] = {
            vertices[i].color.blue(),
            vertices[i].color.green(),
            vertices[i].color.red()
        };
        archivoSalida.write(pixel, sizeof(pixel));
    }

    // Cerrar el archivo
    archivoSalida.close();
}