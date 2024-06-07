#include <iostream>
#include <string>
#include <math.h>
#include "Video.h"

    Video::Video(){
        iD = "0000";
        titulo = "Sin Nombre";
        duracion = 0;
        genero = "Sin Genero";
        calificacion = 0;
    }

    Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) {
        iD = _iD;
        titulo = _titulo;
        duracion = _duracion;
        genero = _genero;
        calificacion = _calificacion;
    }

    void Video::setID(string _iD){
        iD = _iD;
    }

    void Video::setTitulo(string _titulo){
        titulo = _titulo;
    }

    void Video::setDuracion(int _duracion){
        duracion = _duracion;
    }
    void Video::setGenero(string _genero){
        genero = _genero;
    }
    void Video::setCalificacion(double _calificacion){
        calificacion = _calificacion;
    }

    string Video::getID(){
        return iD;
    }

    string Video::getTitulo(){
        return titulo;
    }

    int Video::getDuracion(){
        return duracion;
    }

    string Video::getGenero(){
        return genero;
    }

    double Video::getCalificacion(){
        return calificacion;
    }

//FUNCIONES
    string Video::str() {
        cout << iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " ";
        return "";
    }

    //ostream& operator<< (ostream &out, const Video &video){
    //    string acum = "";
    //}