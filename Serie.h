#ifndef Serie_h
#define Serie_h

#include <iostream>
#include <string>
#include <math.h>
#include "Video.h"
#include "Episodio.h"

using namespace std;
const int MAX_EPISODIOS = 6;
class Serie : public Video {
    private:
        Episodio episodios[MAX_EPISODIOS];
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
        int calculaDuracion();
        double calculaPromedio();
};

#endif