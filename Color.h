#pragma once

class Color {
public:
    // Constructor por defecto
    Color() : m_red(0), m_green(0), m_blue(0) {}

    // Constructor que recibe los valores de los componentes de color
    Color(unsigned int red, unsigned int green, unsigned int blue);

    // Métodos para obtener los valores de los componentes de color
    unsigned int red() const;
    unsigned int green() const;
    unsigned int blue() const;

    // Método para obtener el valor RGB como un entero de 32 bits
    unsigned int rgb() const;
private:
    unsigned int m_red;
    unsigned int m_green;
    unsigned int m_blue;
};