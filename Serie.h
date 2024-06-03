#ifndef Serie_h
#define Serie_h

#include <iostream>
#include <string>
#include <math.h>
#include "Video.h"
#include "Episodio.h"

using namespace std;

class Serie : public Video {
    private:
        Episodio episodios[5];
        int cantidad;
    public:
        Serie();
        Serie(string _iD, string _titulo, int _duracion, string _genero);
        void setEpisodio(int _index, Episodio _episodio);
        void setCantidad(int _cantidad);
        Episodio getEpisodio(int _index);
        int getCantidad();
    //Funciones
        string str();
        void agregaEpisodio(Episodio _episodio);
        void calculaDuracion();
        double calculaPromedio();
};

#endif