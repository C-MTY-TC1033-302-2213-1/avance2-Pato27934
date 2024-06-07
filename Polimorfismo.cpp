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

        for(int index = 0; index < cantidadSeries; index++){
            promedio =  arrPTRSeries[index]->calculaPromedio();
            arrPTRSeries[index]->setCalificacion(promedio);
            arrPTRSeries[index]->calculaDuracion();
            arrPTRVideos[cantidad++] = arrPTRSeries[index];
        }

        for(int index = 0; index < cantidadPeliculas; index++){
            arrPTRVideos[cantidad++] = arrPTRPeliculas[index];
        }

        entrada.close();
    }

    // SECCION DE FUNCIONES
    void Polimorfismo::reporteCalificacion(double _calificacion) {
        int total = 0;
        for (int index = 0; index < cantidad; index++){
            if (arrPTRVideos[index]->getCalificacion() == _calificacion ) {
                total = total + 1;
                cout << arrPTRVideos[index]->str();
            }
        }
        cout << "Total = " + to_string(total);
    }

    void Polimorfismo::reporteGenero(string _genero) {
        int total = 0;
        for (int index = 0; index < cantidad; index++){
            if (arrPTRVideos[index]->getGenero() == _genero) {
                total = total + 1;
                cout << arrPTRVideos[index]->str();
            }
        }
        cout << "Total = " + to_string(total);
    }

    void Polimorfismo::reportePeliculas() {
        int total = 0;
        for (int index = 0; index < cantidad; index++){  
            if(typeid(*arrPTRVideos[index]) == typeid(Pelicula)){
                total = total + 1;
                cout << arrPTRVideos[index]->str();
            }
        }
        if (total == 0){
            cout << "No Peliculas";
        }
        else {
            cout << "Total Peliculas = " + to_string(total);
        }
    }

    void Polimorfismo::reporteSeries(){
        int total = 0;
        for (int index = 0; index < cantidad; index++){  
            if(typeid(*arrPTRVideos[index]) == typeid(Serie)){
                total = total + 1;
                cout << arrPTRVideos[index]->str();
            }
        }
        if (total == 0){
            cout << "No series";
        }
        else {
            cout << "Total Series = " + to_string(total);
        }
    }

    void Polimorfismo::reporteInventario(){
        int total = 0;
        int totalPeli = 0;
        int totalSerie = 0;
        for (int index = 0; index < cantidad; index++){ 
            if(typeid(*arrPTRVideos[index]) == typeid(Serie)){
                totalSerie += 1;
                cout << arrPTRVideos[index]->str();
            }
            else if(typeid(*arrPTRVideos[index]) == typeid(Pelicula)){
                totalPeli += 1;
                cout << arrPTRVideos[index]->str();
            }
        }
        total = totalPeli + totalSerie;
        cout << "Peliculas = " + to_string(totalPeli) + "\n";
        cout << "Series = " + to_string(totalSerie) + "\n";
    }
      
        