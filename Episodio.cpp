#include <iostream>
#include <string>
#include <math.h>
#include "Episodio.h"

    Episodio::Episodio(){
        titulo = "Sin Nombre";
        temporada = 1;
        calificacion = 0;
    }

    Episodio::Episodio(string _titulo, int _temporada, int _calificacion) {
        titulo = _titulo;
        temporada = _temporada;
        calificacion = _calificacion;
    }

    void Episodio::setTitulo(string _titulo){
        titulo = _titulo;
    }

    void Episodio::setTemporada(int _temporada){
        temporada = _temporada;
    }

    void Episodio::setCalificacion(int _calificacion){
        calificacion = _calificacion;
    }


    string Episodio::getTitulo(){
        return titulo;
    }

    int Episodio::getTemporada(){
        return temporada;
    }

    int Episodio::getCalificacion(){
        return calificacion;
    }

//FUNCIONES
    string Episodio::str() {
        cout << titulo + " " + to_string(temporada) + " " + to_string(calificacion) + "\n";
        return "";
    }