#include <iostream>
#include <string>
#include <math.h>
#include "Pelicula.h"

    Pelicula::Pelicula():Video(){
        oscares = 0;
    }

    Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
        oscares = _oscares;
    }

    void Pelicula::setOscares(int _oscares){
        oscares = _oscares;
    }

    int Pelicula::getOscares(){
        return oscares;
    }

    string Pelicula::str(){
        cout << Video::str() + to_string(oscares) + "\n";
        return "";
    }

