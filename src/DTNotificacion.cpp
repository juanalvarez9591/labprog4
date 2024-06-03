#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion()
{
    asunto = "";
    texto = "";
}

DTNotificacion::DTNotificacion(string asunto, string texto)
{
    this->asunto = asunto;
    this->texto = texto;
}
