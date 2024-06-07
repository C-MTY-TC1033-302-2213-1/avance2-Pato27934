#ifndef Pelicula_h
#define Pelicula_h

#include <iostream>
#include <string>
#include <math.h>
#include "Video.h"

using namespace std;

class Pelicula : public Video {
    private:
        int oscares;
    public:
        Pelicula();
        Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);
        void setOscares(int _oscares);
        int getOscares();
    //Funciones
        string str();
};

#endif