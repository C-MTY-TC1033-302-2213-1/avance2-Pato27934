#ifndef Episodio_h
#define Episodio_h

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
class Episodio {
    private:
        string titulo;
        int temporada;
        double calificacion;
    public:
        Episodio();
        Episodio(string _titulo, int _temporada, double _calificacion);
    //Setters y Getters
        void setTitulo(string _titulo);
        void setTemporada(int _duracion);
        void setCalificacion(double _calificacion);
        string getTitulo();
        int getTemporada();
        double getCalificacion();
    //Funciones
        string str();
};

#endif