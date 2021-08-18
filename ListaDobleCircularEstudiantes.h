//
// Created by diego on 11/08/2021.
//

#ifndef EDD_SMARTCLASS_201908327_LISTADOBLECIRCULARESTUDIANTES_H
#define EDD_SMARTCLASS_201908327_LISTADOBLECIRCULARESTUDIANTES_H
#include <string>

using namespace std;

class ListaDobleCircularEstudiantes {
public:
    ListaDobleCircularEstudiantes* Head;
    ListaDobleCircularEstudiantes* Last;
    ListaDobleCircularEstudiantes* Next;
    ListaDobleCircularEstudiantes* Prev;

    int Carnet;
    string Nombre;
    string DPI;
    string Carrera;
    string Correo;
    string Password;
    int Creditos;
    int edad;

    ListaDobleCircularEstudiantes();
    bool Vacio();
    void EnqueueE(int C, string N, string D,string ca, string co, string pas, int cre, int e);
    int DequeueE(string Dp);
    void ModE(string D);
    void BorrarE(string D);
    void imprimirEstudiantes();

    bool BuscarCarne(string Carne);
};


#endif //EDD_SMARTCLASS_201908327_LISTADOBLECIRCULARESTUDIANTES_H
