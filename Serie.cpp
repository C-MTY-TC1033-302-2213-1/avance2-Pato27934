#include <iostream>
#include <string>
#include <math.h>
#include "Serie.h"

    Serie::Serie():Video(){
        cantidad = 0;
    }
    
    Serie::Serie(string _iD, string _titulo, int _duracion, string _genero):Video(_iD, _titulo, _duracion, _genero, 0){
        cantidad = 0;
    }


    //Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
    //    oscares = _oscares;
    //}

    void Serie::setEpisodio(int _index, Episodio _episodio){
        if (_index >= 0 && _index < cantidad ) {
            episodios[_index] = _episodio;
        }
    }

    void Serie::setCantidad(int _cantidad){
        if (_cantidad >= 0 && _cantidad <= 5){
            cantidad = _cantidad;
        }
    }

    Episodio Serie::getEpisodio(int _index){
        if (_index >= 0 && _index < cantidad ) {
            return episodios[_index];
        }
        Episodio episodioDefault;
        return episodioDefault;
    }

    int Serie::getCantidad(){
        return cantidad;
    }

    string Serie::str(){
        cout << getID() + " " + getTitulo() + " " + to_string(calculaDuracion()) + " " + getGenero() + " " + to_string(getCalificacion()) + " " + to_string(cantidad)+ "\n";
        for (int index = 0; index < cantidad; index++) {
            cout << episodios[index].str();
        }
        cout << "\n";
        return "";
    }

    void Serie::agregaEpisodio(Episodio episodio){
        if (cantidad < MAX_EPISODIOS){
            episodios[cantidad++] = episodio;
        }
        Video::setCalificacion(calculaPromedio());
    }

    double Serie::calculaPromedio(){
        double acum = 0.0;
        if (cantidad == 0){
            return acum;
        }
        for (int index = 0; index < cantidad; index++) {  
            acum += episodios[index].getCalificacion();
        }
        acum = acum / cantidad;
        return acum;
    }

    int Serie::calculaDuracion(){
        int acum = 0;
        if (cantidad == 0){
            return acum;
        }
        for (int index = 0; index < cantidad; index++) {  
            acum = acum + episodios[index].getTemporada();
        }
        return acum;
    }

