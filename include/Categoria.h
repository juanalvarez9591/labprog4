#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

enum class Categoria {
    Ropa,
    Electrodomestico,
    Otro
};

inline std::string toString(Categoria categoria) {
    switch (categoria) {
        case Categoria::Ropa:
            return "Ropa";
        case Categoria::Electrodomestico:
            return "Electrodomestico";
        default:
            return "Otro";
    }
}

inline Categoria fromString(const std::string& str) {
    if (str == "Ropa" || str == "ropa") {
        return Categoria::Ropa;
    } else if (str == "Electrodomestico" || str == "electrodomestico") {
        return Categoria::Electrodomestico;
    } else {
        return Categoria::Otro;
    }
}

#endif