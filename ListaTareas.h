//
// Created by diego on 13/08/2021.
//

#ifndef EDD_SMARTCLASS_201908327_LISTATAREAS_H
#define EDD_SMARTCLASS_201908327_LISTATAREAS_H
#include <string>

using namespace std;

class ListaTareas {


public:
    int ID;
    int Carnet;
    string NombreTarea;
    string Descripcion;
    string Materia;
    string Fecha;
    string Hora;
    string Estado;
    string Mes;
    string Dia;


    ListaTareas(int ID, int Carnet, string NombreTarea, string Descripcion, string Materia, string Fecha, string Hora, string Estado, string Mes, string Dia);





};


#endif //EDD_SMARTCLASS_201908327_LISTATAREAS_H
