//
// Created by diego on 17/08/2021.
//

#include "ListaEnlazadaTareas.h"
using namespace std;
#include <iostream>
#include <string>

bool ListaEnlazadaTareas::Vacio(){

    if (Head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void ListaEnlazadaTareas::EnqueueTareas(int ID, int Carnet, string NombreTarea, string Descripcion, string Materia, string Fecha, string Hora, string Estado, int Index, string mes, string dia){
    ListaEnlazadaTareas* Nuevo;
    Nuevo = new ListaEnlazadaTareas();

    Nuevo->ID = ID;
    Nuevo->Carnet = Carnet;
    Nuevo->NombreTarea = NombreTarea;
    Nuevo->Descripcion = Descripcion;
    Nuevo->Materia = Materia;
    Nuevo->Fecha = Fecha;
    Nuevo->Hora = Hora;
    Nuevo->Estado = Estado;
    Nuevo->Index = Index;
    Nuevo->Mes = mes;
    Nuevo->Dia = dia;

    if (Vacio()){
        Head = Nuevo;
        Last = Nuevo;
        Head->Next = Head;
    }
    else{
        Last->Next=Nuevo;
        Nuevo->Prev = Last;
        Nuevo->Next = NULL;
        Last = Nuevo;
    }
}
