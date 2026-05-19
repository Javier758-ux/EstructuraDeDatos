#ifndef ABMMIGO_H
#define ABMMIGO_H

#include "Amigo.h"

class ABMmigo {

private:
    char nomArchivo[50];

public:
    ABMmigo(const char nomArch[]);

    void introducirDatos(Amigo& amig);

    void alta();
    void baja();
    void actualizar();
    void listar();
    void consultar();
};

#endif