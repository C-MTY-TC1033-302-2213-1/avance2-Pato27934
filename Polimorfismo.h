#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

using namespace std;
const int MAX_VIDEOS = 100;

class Polimorfismo
{
    private:
        Video* arrPTRVideos[MAX_VIDEOS];
        int cantidad;
    public:
        Polimorfismo();
        void leerArchivo(string _nombre);

        void reporteCalificacion(double _calificacion);
        void reporteGenero(string _califica_genero);
        void reportePeliculas();
        void reporteSeries();
        void reporteInventario();
};
#endif