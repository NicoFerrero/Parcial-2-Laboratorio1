#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"
#include "socios.h"

int main()
{
    int opcion;
    char salir;
    int respuesta;
    int orden;
    int turnoU = 1;
    int turnoR = 1;

    ArrayList* listaUrgente = al_newArrayList();
    ArrayList* listaRegular = al_newArrayList();
    ArrayList* listaUrgenteAtendidos = al_newArrayList();
    ArrayList* listaRegularAtendidos = al_newArrayList();
    ArrayList* listaCSV = al_newArrayList();

    if(listaRegular == NULL || listaUrgente == NULL || listaUrgenteAtendidos == NULL || listaRegularAtendidos == NULL)
    {
        printf("No se pudo reservar espacio en memoria");
        exit(1);
    }

    do
    {
        system("cls");
        opcion = menu("1. TRAMITE URGENTE \n2. TRAMITE REGULAR \n3. PROXIMO CLIENTE \n4. LISTAR \n5. INFORMAR \n6. GRABAR \n7. SALIR \nIngrese una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            respuesta = alta(listaUrgente,1,turnoU);
            if(respuesta == -1)
            {
                printf("Numero no asignado\n");
            }
            else
            {
                printf("Numero asignado\n");
                turnoU++;
            }
            system("pause");
            break;

        case 2:
            system("cls");
            respuesta = alta(listaRegular,2,turnoR);
            if(respuesta == -1)
            {
                printf("Numero no asignado\n");
            }
            else
            {
                printf("Numero asignado\n");
                turnoR++;
            }
            system("pause");
            break;

        case 3:
            system("cls");
            respuesta = proximoCliente(listaUrgente,listaRegular,listaUrgenteAtendidos,listaRegularAtendidos);
            if(respuesta == -1)
            {
                printf("No hay clientes para ser atendidos\n");
            }
            else
            {
                printf("Cliente atendido");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            if(listaUrgente->isEmpty(listaUrgente) && listaRegular->isEmpty(listaRegular))
            {
                printf("No hay clientes pendientes en el sistema\n");
                system("pause");
                break;
            }
            orden = menu("1. TRAMITE URGENTE \n2. TRAMITE REGULAR \nIngrese una opcion: ");
            switch(orden)
            {
                case 1:
                    system("cls");
                    ListarClientes(listaUrgente);
                    break;
                case 2:
                    system("cls");
                    ListarClientes(listaRegular);
                    break;
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(listaUrgenteAtendidos->isEmpty(listaUrgenteAtendidos) && listaRegularAtendidos->isEmpty(listaRegularAtendidos))
            {
                printf("No hay clientes pendientes en el sistema\n");
                system("pause");
                break;
            }
            orden = menu("1. TRAMITE URGENTE \n2. TRAMITE REGULAR \nIngrese una opcion: ");
            switch(orden)
            {
                case 1:
                    system("cls");
                    ArrayList* listaOrdenadaAZU = al_newArrayList();
                    if(listaOrdenadaAZU != NULL)
                    {
                        listaOrdenadaAZU = listaUrgenteAtendidos->clone(listaUrgenteAtendidos);
                        listaOrdenadaAZU->sort(listaOrdenadaAZU,sortByDNI,0);
                        ListarClientes(listaOrdenadaAZU);
                    }
                    break;

                case 2:
                    system("cls");
                    ArrayList* listaOrdenadaAZR = al_newArrayList();
                    if(listaOrdenadaAZR != NULL)
                    {
                        listaOrdenadaAZR = listaRegularAtendidos->clone(listaRegularAtendidos);
                        listaOrdenadaAZR->sort(listaOrdenadaAZR,sortByDNI,0);
                        ListarClientes(listaOrdenadaAZR);
                    }
                    break;
            }
            system("pause");
            break;

        case 6:
            system("cls");
            listarCSV(listaUrgente,listaRegular,listaCSV);
            generarCSV(listaCSV);
            break;

        case 7:
                system("cls");
                getSN(&salir,"Realmanete desea salir? (S/N): ", "\nLa opcion ingresada no es valida. Debe ingresar S o N\n");
                if(salir == 's')
                {
                    if(respuesta == 1)
                    {
                        printf("\nNo se ha podido guardar en el archvo\n");
                    }
                    else
                    {
                        printf("\nSe ha guardado la informacion exitosamente\n");
                    }
                }
                system("Pause");
                break;
        }
    }while(salir != 's');
    return 0;
}
