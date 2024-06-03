#ifndef Video_h
#define Video_h

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
class Video {
    private:
        string iD;
        string titulo;
        int duracion;
        string genero;
        double calificacion;
    public:
        Video();
        Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);
    //Setters y Getters
        void setID(string _iD);
        void setTitulo(string _titulo);
        void setDuracion(int _duracion);
        void setGenero(string _genero);
        void setCalificacion(double _calificacion);
        string getID();
        string getTitulo();
        int getDuracion();
        string getGenero();
        double getCalificacion();
    //Funciones
        virtual string str();
};

#endif