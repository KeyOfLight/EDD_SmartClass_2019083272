#include <iostream>
#include "string"
#include "CUsuarios.h"
#include "Lectura.h"
#include "ListaDobleCircularEstudiantes.h"
#include "ListaTareas.h"

using namespace std;

int main() {
    Lectura *Lec = new Lectura();
    Lec->InicializarTareas();
    string Dir;
    int Decision;
    string DPIIng;

    do {

        int Decision_IngresoUs;
        int Decision3;
        cout <<"---------Menu--------------- \n 1) Carga de Usuarios \n 2) carga de Tareas \n 3) Ingreso Manual \n 4) Reportes"    <<endl;
        cin >> Decision;

        switch (Decision) {

            case 1:
                cout << "Ingrese la opcion que desea realizar"<<endl;
                cout <<" 1) Ingreso Masivo (Archivo csv xd)"<<endl;
                cout <<" 4) Mostrar Usuarios en consola"<< endl;

                cin >> Decision_IngresoUs;

                switch (Decision_IngresoUs) {

                    case 1:
                            cout << "Ingrese la direccion donde se encuentre la lista de usuarios" <<endl;
                            cin >> Dir;
                            Lec->LecturaEstudiantes(Dir);
                            break;

                    case 3:


                    case 4:
                        Lec->ImprimirEstu();
                        break;

                }



                break;

                case 2:
                    cout << "Carga de Tareas masivo\n ingrese la direccion del archivo" <<endl;
                    cin >> Dir;
                    Lec->LecturaTareas(Dir);

                    break;


                case 3:
                    cout << "Ingrese la opcion que desea realizar"<<endl;
                    cout <<" 1) Usuarios"<<endl;
                    cout <<" 2) Tareas"<<endl;

                    cin >> Decision_IngresoUs;

                    switch (Decision_IngresoUs) {

                        case 1:
                            cout << "Ingrese la opcion que desea realizar"<<endl;
                            cout << "Ingresar Manualmente"<<endl;
                            cout << "modificar"<<endl;
                            cout << "Elminar"<<endl;

                            switch (Decision3) {

                                case 1:
                                    Lec->IngresoManual();
                                    break;

                                case 2:
                                    cout<<"Ingrese el numero de DPI que desea buscar"<<endl;
                                    cin >> DPIIng;
                                    Lec->ModificarEstudiante(DPIIng);
                                    break;

                                case 3:
                                    cout<<"Ingrese el numero de DPI que desea buscar"<<endl;
                                    cin >> DPIIng;
                                    Lec->BorrarEstudiante(DPIIng);
                                    break;

                            }

                    }

                default:
                        cout  <<"Opcion defaulta"<< endl;
                        break;


        }
    }
    while (Decision !=0);


    return 0;
};
