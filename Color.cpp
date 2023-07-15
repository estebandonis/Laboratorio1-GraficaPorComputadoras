#include "Color.h"

// Constructor que recibe los valores de los componentes de color
Color::Color(unsigned int red, unsigned int green, unsigned int blue) {
    // Asegurarse de que los valores están en el rango de 0 a 255
    m_red = red > 255 ? 255 : red;
    m_green = green > 255 ? 255 : green;
    m_blue = blue > 255 ? 255 : blue;
}

// Métodos para obtener los valores de los componentes de color
unsigned int Color::red() const {
    return m_red;
}

unsigned int Color::green() const {
    return m_green;
}

unsigned int Color::blue() const {
    return m_blue;
}

// Método para obtener el valor RGB como un entero de 32 bits
unsigned int Color::rgb() const {
    return (m_red << 16) | (m_green << 8) | m_blue;
}