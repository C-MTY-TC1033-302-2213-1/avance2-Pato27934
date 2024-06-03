#include <iostream>
#include <string>
#include <math.h>

#include "Polimorfismo.h"

using namespace std;

    Polimorfismo::Polimorfismo(){
        for (int index = 0; index < MAX_VIDEOS; index++){
            arrPTRVideos[index] = nullptr;
        }
        cantidad = 0;
    }
    void Polimorfismo::leerArchivo(string _nombre){
        Serie* arrPTRSeries[50];
        Pelicula* arrPTRPeliculas[50];
        Episodio episodio;
        fstream entrada;
        string row[7];
        string line, word;
        int cantidadPeliculas = 0;
        int cantidadSeries = 0;
        int iR = 0, index;
        double promedio;

        entrada.open(_nombre, ios::in);

        while ( getline(entrada, line) ) {
            stringstream s(line);
            iR = 0;

            while ( getline(s, word, ',')) {
                row[iR++] = word;
            }

            if (row[0] == "P"){
                arrPTRPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
                cantidadPeliculas++;
            }
            else if (row[0] == "S"){
                arrPTRSeries[cantidadSeries] = new Serie( row[1], row[2], stoi(row[3]), row[4]);
                cantidadSeries++;
            }
            else if (row[0] == "E"){
                index = stoi(row[1]) - 500;
                arrPTRSeries[index]->agregaEpisodio(*(new Episodio( row[2], stoi(row[3]), stoi(row[4]))));
            }
        }
    }

    void Polimorfismo::reporteCalificacion(double _calificacion) {
        for (int index = 0; index < MAX_VIDEOS; index++){
            if (arrPTRPeliculas[index]->getCalificacion() <= _calificacion ) {
                cout << arrPTRPeliculas[index]->str();
            }
        }
    }

    void Polimorfismo::reporteGenero(string _genero) {
        for (int index = 0; index < MAX_VIDEOS; index++){
            if (arrPTRPeliculas[index]->getGenero() == _genero ) {
                cout << arrPTRPeliculas[index]->str();
            }
        }
    }

    void Polimorfismo::reportePeliculas() {
        for (int index = 0; index < MAX_VIDEOS; index++){    
            cout << arrPTRPeliculas[index]->str();
        }
    }

    void Polimorfismo::reporteSeries(){
        for (int index = 0; index < MAX_VIDEOS; index++){    
            cout << arrPTRSeries[index]->str();
        }
    }

    void Polimorfismo::reporteInventario(){
        for (int index = 0; index < MAX_VIDEOS; index++){    
            cout << arrPTRVideos[index]->str();
        }
    }
      
        