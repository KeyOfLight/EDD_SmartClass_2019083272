//
// Created by diego on 13/08/2021.
//

#include "ListaTareas.h"
using namespace std;
#include <iostream>
#include <string>


ListaTareas::ListaTareas(int ID, int Carnet, string NombreTarea, string Descripcion, string Materia, string Fecha, string Hora, string Estado, string Mes, string Dia){

    this->ID = ID;
    this->Carnet = Carnet;
    this->NombreTarea = NombreTarea;
    this->Descripcion = Descripcion;
    this->Materia = Materia;
    this->Fecha = Fecha;
    this->Hora = Hora;
    this->Estado = Estado;
    this->Mes = Mes;
    this->Dia = Dia;

}



