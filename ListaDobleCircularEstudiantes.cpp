//
// Created by diego on 11/08/2021.
//
using namespace std;
#include <iostream>
#include <string>
#include "ListaDobleCircularEstudiantes.h"
#include "Lectura.h"

Lectura *Lec = new Lectura();

ListaDobleCircularEstudiantes::ListaDobleCircularEstudiantes(){

    Head = NULL;
    Last = NULL;
    Next = NULL;
    Prev = NULL;
}

bool ListaDobleCircularEstudiantes::Vacio() {

    if (Head == NULL){
        return true;
    }
    else{
        return false;
    }
}




void ListaDobleCircularEstudiantes::EnqueueE(int C, string N, string D,string ca, string co, string pas, int cre, int e) {

    ListaDobleCircularEstudiantes* Nuevo;
    Nuevo = new ListaDobleCircularEstudiantes();

    Nuevo->Carnet = C;
    Nuevo->Nombre = N;
    Nuevo->DPI = D;
    Nuevo->Carrera = ca;
    Nuevo->Correo = co;
    Nuevo->Password = pas;
    Nuevo->Creditos = cre;
    Nuevo->edad = e;

    if (Vacio()){
        Head = Nuevo;
        Last = Nuevo;
        Head->Next = Head;
        Head->Prev = Head;
    }
    else{
        Last->Next = Nuevo;
        Nuevo->Prev = Last;
        Nuevo->Next = Head;
        Last = Nuevo;
        Head->Prev = Last;
    }

}

void ListaDobleCircularEstudiantes::imprimirEstudiantes() {
    ListaDobleCircularEstudiantes* Moverse = Head;

    cout <<"Lista de todos los elementos guardados en la lista\n";



    while (Moverse != Last){

        cout <<"-->";
        cout <<"Nombre: "<< Moverse->Nombre<<" DPI: "<< Moverse->DPI<< "El correo es: "<< Moverse->Correo<< endl;

        Moverse = Moverse->Next;
    }
    if (Moverse == Last){
        cout <<"-->";
        cout <<"Nombre: "<< Moverse->Nombre<<" DPI: "<< Moverse->DPI<< "El correo es: "<< Moverse->Correo<< endl;


    }
}

void ListaDobleCircularEstudiantes::ModE(string D) {
    bool Encontrado = false;
    int Desicion;
    int IntReemplazado;

    string StringReemplazado;
    ListaDobleCircularEstudiantes* Tempo1 = Last;
    while (Tempo1 != Head){
        if (Tempo1->DPI == D){
            Encontrado = true;
            break;
        }
        else{
            Tempo1 = Tempo1->Prev;
        }
    }
    if (Tempo1 == Head){
        if (Tempo1->DPI == D){
            Encontrado = true;
        }
    }

    if (Encontrado == true){
        cout<<"Elija que desea modificar\n 1) Carnet \n 2) Dpi \n 3) Nombre \n 4) Carrera \n 5) Correo \n 6) Password \n 7) Creditos \n 8) Edad"<<endl;

        cin >> Desicion;

        switch (Desicion) {

            case 1:
                cout <<"Ingrese el nuevo carnet"<<endl;
                cin >> StringReemplazado;
                if (Lec->ValidarCarne(StringReemplazado)){
                    IntReemplazado = stoi(StringReemplazado);
                    Tempo1->Carnet = IntReemplazado;
                    cout << Tempo1->Carnet;
                }

            case 2:
                cout <<"Ingrese el nuevo DPI"<<endl;
                cin >> StringReemplazado;
                if (Lec->ValidarDPI(StringReemplazado)){
                    Tempo1->DPI = StringReemplazado;
                    cout << Tempo1->DPI;
                }

            case 3:
                cout <<"Ingrese el nuevo Nombre"<<endl;
                cin >> StringReemplazado;
                    Tempo1->Nombre = StringReemplazado;
                    cout << Tempo1->Nombre;

            case 4:
                cout <<"Ingrese la nueva carrera"<<endl;
                cin >> StringReemplazado;
                Tempo1->Carrera = StringReemplazado;
                cout << Tempo1->Carrera;

            case 5:
                cout <<"Ingrese el nuevo correo"<<endl;
                cin >> StringReemplazado;
                if (Lec->ValidarCorreo(StringReemplazado)){
                    Tempo1->Correo = StringReemplazado;
                    cout << Tempo1->Correo;
                }

            case 6:
                cout <<"Ingrese la nueva contraseña"<<endl;
                cin >> StringReemplazado;
                Tempo1->Carrera = StringReemplazado;
                cout << Tempo1->Carrera;

            case 7:
                cout <<"Ingrese los nuevos creditos"<<endl;
                cin >> StringReemplazado;
                IntReemplazado = stoi(StringReemplazado);
                Tempo1->Creditos = IntReemplazado;
                cout << Tempo1->Creditos;

            case 8:
                cout <<"Ingrese la nueva edad"<<endl;
                cin >> StringReemplazado;
                IntReemplazado = stoi(StringReemplazado);
                Tempo1->edad = IntReemplazado;
                cout << Tempo1->edad;
        }
    }
}

bool ListaDobleCircularEstudiantes::BuscarCarne(string Carne){

    ListaDobleCircularEstudiantes* Tempo1 = Last;
    while (Tempo1 != Head){
        if (Tempo1->Carnet == stoi(Carne)){
            return true;
            break;
        }
        else{
            Tempo1 = Tempo1->Prev;
        }
    }

    if (Tempo1 == Head){
        if (Tempo1->Carnet == stoi(Carne)){
            return  true;
        }

    }

    return false;
}

void ListaDobleCircularEstudiantes::BorrarE(string D) {
    ListaDobleCircularEstudiantes* Buscar = Last;

    while (Buscar != Head){
        if (Buscar->DPI == D){

            Buscar->Prev->Next= Buscar->Next;
            Buscar->Next->Prev= Buscar->Prev;
            break;

        }
        else{
            Buscar = Buscar->Prev;
        }

    }

    if (Buscar == Head){
        if (Buscar->DPI == D){

            Buscar->Prev->Next= Buscar->Next;
            Buscar->Next->Prev= Buscar->Prev;

        }
        else{
            cout<<"No encontrado, no se pudo borrar"<<endl;
        }
    }





}