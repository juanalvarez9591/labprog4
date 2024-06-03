#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>

class Comentario {
public:
    Comentario(std::string autor, std::string texto);

private:
    std::string autor;
    std::string texto;
};

#endif