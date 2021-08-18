//
// Created by diego on 17/08/2021.
//

#ifndef EDD_SMARTCLASS_201908327_LISTAENLAZADATAREAS_H
#define EDD_SMARTCLASS_201908327_LISTAENLAZADATAREAS_H
#include <string>
using namespace std;

class ListaEnlazadaTareas {
public:
    ListaEnlazadaTareas* Head;
    ListaEnlazadaTareas* Last;
    ListaEnlazadaTareas* Prev;
    ListaEnlazadaTareas* Next;

    int ID;
    int Carnet;
    string NombreTarea;
    string Descripcion;
    string Materia;
    string Fecha;
    string Hora;
    string Estado;
    int Index;
    string Mes;
    string Dia;

    bool Vacio();
    void EnqueueTareas(int ID, int Carnet, string NombreTarea, string Descripcion, string Materia, string Fecha, string Hora, string Estado, int Index, string mes, string dia);

};


#endif //EDD_SMARTCLASS_201908327_LISTAENLAZADATAREAS_H
