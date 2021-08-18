//
// Created by diego on 15/08/2021.
//

#include "Lectura.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <regex>
#include "ListaDobleCircularEstudiantes.h"
#include "ListaTareas.h"
#include <sstream>
#include <stdlib.h>
#include "ListaEnlazadaTareas.h"

using namespace std;
ListaDobleCircularEstudiantes *LdobE = new ListaDobleCircularEstudiantes();
ListaEnlazadaTareas *LTareas = new ListaEnlazadaTareas();
ListaTareas *Matriz[5][30][9];

void Lectura::LecturaTareas(string Direccion){
    string Valores[9];
    int ID = 1;
    string Item;
    ifstream Archivo;
    Archivo.open(Direccion,ios::in);
    string Datos;
    string Verificar;
    int Counter = 0;
    string FechaJunta;


    if(Archivo.fail()){
        cout<<"no se puedo abrir con exito el archivo";

    }
    while (!Archivo.eof()){
        getline(Archivo,Datos);
        istringstream div(Datos);

        while (getline(div, Item, ',')){
            Valores[Counter] = Item;
            Counter++;
        }
        Matriz[IndexMes(Valores[0])][stoi(Valores[1])-1][Indexhora(Valores[2])] = new ListaTareas(ID,stoi(Valores[3]),Valores[4],Valores[5],Valores[6],Valores[7],Valores[2],Valores[8],Valores[0],Valores[1]);
        ID ++;
        /*if (BuscarCarnet(Valores[3])){
            if (ValidarFecha(Valores[0],Valores[1])){
                if (ValidarHora(Valores[2])){
                    FechaJunta = Valores[0]+","+Valores[1];
                    LTareas->EnqueueTareas(ID, stoi(Valores[3]),Valores[4],Valores[5],Valores[6],FechaJunta,Valores[2],Valores[8]);
                    ID++;

                }//Manejo de errores de hora

            }//Manejo de errores de fecha
        }
        else{
            cout <<"No se encontro el carnet"<<endl; //Manejo ded errores
        }*/
        Counter = 0;

    }
    Archivo.close();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 9; ++k) {
                if (Matriz[i][j][k]!=NULL){
                    if (ValidarHora(Matriz[i][j][k]->Hora)){
                        if (ValidarFecha(Matriz[i][j][k]->Mes, Matriz[i][j][k]->Hora)){//HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            if (ValidarEstrucFecha(Matriz[i][j][k]->Fecha)){
                                LTareas->EnqueueTareas(Matriz[i][j][k]->ID, Matriz[i][j][k]->Carnet,Matriz[i][j][k]->NombreTarea,Matriz[i][j][k]->Descripcion,
                                                       Matriz[i][j][k]->Materia, Matriz[i][j][k]->Fecha, Matriz[i][j][k]->Hora, Matriz[i][j][k]->Estado,k+9*(j+30*5),Matriz[i][j][k]->Mes,Matriz[i][j][k]->Dia);
                            }else{cout<<"Error en el formato de la fecha YYYY/MM/DD"<<endl;}
                            }else{cout<<"Error en la fecha ingresada (Dias|horas fuera de rango)"<<endl;}
                    }else{cout<<"Error en la hora ingresada "<<Matriz[i][j][k]->Hora<<endl;}
                } else
                    LTareas->EnqueueTareas(-1, 0,"","","", "", "", "",k+9*(j+30*5),"","");
            }
        }
    }



}

bool Lectura::ValidarEstrucFecha(string Fecha){

    const regex  expReg("2021\\/(0[7-9]|1[0-1])\\/(0[0-9]|1[0-9]|2[0-9]|3[0])");
    return regex_match(Fecha, expReg);


}


bool Lectura::ValidarHora(string Hora) {

    if (stoi(Hora)>=8 && stoi(Hora)<=16){
        return true;
    }

    return false;

}

bool Lectura::ValidarFecha(string Mes, string Dia){

    if (stoi(Mes)<12 && stoi(Mes)>6){
        if (stoi(Dia)<31 && stoi(Dia)>0){

            return true;
        }
    }
    else{
        return false;
    }
}

void Lectura::LecturaEstudiantes(string Direccion){


    string Valores[8];
    string Item;
    ifstream Archivo;
    Archivo.open(Direccion,ios::in);
    string Datos;
    string Verificar;
    int numero1;
    int numero3;
    int numero4;
    int Counter = 0;

    if(Archivo.fail()){
        cout<<"no se puedo abrir con exito el archivo";

    }

    while (!Archivo.eof()){
        getline(Archivo,Datos);
        istringstream div(Datos);

        while (getline(div, Item, ',')){
            Valores[Counter] = Item;
            Counter++;
        }

        if (ValidarCarne(Valores[0])){
            if (ValidarDPI(Valores[1])){
                if (ValidarCorreo(Valores[7])){
                    numero1 = stoi(Valores[0]);
                    numero3 = stoi(Valores[5]);
                    numero4 = stoi(Valores[6]);

                    LdobE->EnqueueE(numero1,Valores[2],Valores[1],Valores[3],Valores[7],Valores[4],numero3,numero4);
                    if (ValidarDPI(Valores[1])){
                        cout<<"Llego";
                    }

                }
                //Else para el if del correo  EN ESTAS PARTES TIENES QQUE METER LAS MIERDAS DE LOS ERRORES
                else{
                    cout<<"El Correo: " << Valores[7] << " Es invalido"<< endl;
                }

            }
            //Else para el if del DPI EN ESTAS PARTES TIENES QQUE METER LAS MIERDAS DE LOS ERRORES
            else{
                cout<<"El DPI: " << Valores[1] << " Es invalido"<< endl;
            }
        }
        //Else para el if del carnet EN ESTAS PARTES TIENES QQUE METER LAS MIERDAS DE LOS ERRORES
        else{
            cout<<"El carne: " << Valores[0] << "Es invalido"<< endl;
        }

        Counter = 0;




    }
    Archivo.close();



}

int Lectura::IndexMes(string mes) {

    switch (stoi(mes)) {
        case 7:
            return 0;

        case 8:
            return 1;

        case 9:
            return 2;

        case 10:
            return 3;

        case 11:
            return 4;

    }


}

int Lectura::Indexhora(string Hora) {

    switch (stoi(Hora)) {
        case 8:
            return 0;

        case 9:
            return 1;

        case 10:
            return 2;

        case 11:
            return 3;

        case 12:
            return 4;

        case 13:
            return 5;

        case 14:
            return 6;

        case 15:
            return 7;

        case 16:
            return 8;


    }
}



void Lectura::InicializarTareas() {



    for (int i = 0; i <5 ; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 9; ++k) {
                Matriz[i][j][k] = NULL;
            }
        }
    }
}

void Lectura::ModificarEstudiante(string Dpi) {
    LdobE->ModE(Dpi);
}

void Lectura::BorrarEstudiante(string Dpi) {
    LdobE->BorrarE(Dpi);
}

void Lectura::ImprimirEstu(){
    LdobE->imprimirEstudiantes();

}

void Lectura::IngresoManual() {

    int Car;
    string Dep;
    string Nombre;
    string Carrera;
    string Correo;
    string Contra;
    int Creditos;
    int edad;


    cout << "Ingrese Numero de carnet"<<endl;
    cin >> Car;
    system("cls");

    cout << "Ingrese Numero de DPI" <<endl;
    cin >> Dep;
    system("cls");

    cout << "Ingrese Nombre" <<endl;
    cin >> Nombre;
    system("cls");

    cout << "Ingrese Carrera" <<endl;
    cin >> Carrera;
    system("cls");

    cout << "Ingrese Correo electronico" <<endl;
    cin >> Correo;
    system("cls");

    cout << "Ingrese Contra" <<endl;
    cin >> Contra;
    system("cls");

    cout << "Ingrese numero de creditos" <<endl;
    cin >> Creditos;
    system("cls");

    cout << "Ingrese edad" <<endl;
    cin >> edad;
    system("cls");

    if (ValidarDPI(Dep)){
        if (ValidarCarne(to_string(Car))){
            if (ValidarCorreo(Correo)){
                LdobE->EnqueueE(Car, Nombre, Dep, Carrera, Correo, Contra, Creditos, edad);
            } else{cout<<"Correo invalido"<<endl;}
        }else{cout<<"Carnet invalido"<<endl;} //Maanejo de errores pedazo de imbecil
    } else{cout<<"Dpi invalido"<<endl;}


}

bool Lectura::ValidarDPI(string Verificar){

    const regex expReg("[0-9]{13}");

    return regex_match(Verificar, expReg);

}

bool Lectura::ValidarCarne(string Verificar){

    const regex  expReg("[0-9]{9}");
    return regex_match(Verificar, expReg);

}

bool Lectura::ValidarCorreo(string Verificar){

    const regex  expReg("^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$");
    return regex_match(Verificar, expReg);

}

bool  Lectura::BuscarCarnet(string Carnet){

    if (ValidarCarne(Carnet)){
        if(LdobE->BuscarCarne(Carnet)){
            return true;
        }



    }
    else{
        cout<<"Carnet no aceptado"<<endl;
        return false;
    }
}
