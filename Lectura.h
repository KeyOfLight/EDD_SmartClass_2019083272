//
// Created by diego on 15/08/2021.
//

#ifndef EDD_SMARTCLASS_201908327_LECTURA_H
#define EDD_SMARTCLASS_201908327_LECTURA_H

using namespace std;
#include <string>
#include <conio.h>

class Lectura {

public:
    string Direccion;

    void LecturaEstudiantes(string Direccion);
    bool ValidarDPI(string Verificar);
    bool ValidarCarne(string Verificar);
    bool ValidarCorreo(string Verificar);
    void IngresoManual();
    void ImprimirEstu();
    void ModificarEstudiante(string Dpi);
    void BorrarEstudiante(string Dpi);


    bool BuscarCarnet(string Carnet);
    void LecturaTareas(string Direccion);
    bool ValidarFecha(string Mes, string Dia);
    bool ValidarHora(string Hora);
    bool ValidarEstrucFecha(string Fecha);


    void InicializarTareas();
    int IndexMes(string mes);
    int Indexhora(string Hora);



};


#endif //EDD_SMARTCLASS_201908327_LECTURA_H
