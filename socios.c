#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "socios.h"
#include "lib.h"

eCliente* Cliente_new(void)
{
    eCliente* returnAux = NULL;
    returnAux = (eCliente*) malloc(sizeof(eCliente));

    if(returnAux != NULL)
    {
        returnAux->turno = 0;
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->apellido, "");
        returnAux->dni = 0;
        returnAux->numTurno = 0;
    }

    return returnAux;
}

eCliente* Cliente_new_Parametros(char* nombre, char* apellido, long dni, int turnoID, int turno)
{
    eCliente* returnAux = NULL;
    returnAux = Cliente_new();

    if(returnAux != NULL)
    {
        returnAux->turno = turno;
        strcpy(returnAux->nombre, nombre);
        strcpy(returnAux->apellido, apellido);
        returnAux->dni = dni;
        returnAux->numTurno = turnoID;
    }

    return returnAux;
}

int alta(ArrayList* lista, int turno, int turnoID)
{
    int paso = 0;
    int returnAux = 0;
    int respuesta;
    char nombre[30];
    char apellido[30];
    long dni;
    eCliente* ClienteAux;

    do
    {
        switch(paso)
        {
            case 0:
                system("cls");
                respuesta = getStringLetras(nombre,"Ingrese el nombre del socio o 'cancelar' para volver al menu principal: ","\nERROR. El nombre debe contener entre 1 y 30 caracteres",1,30);
                if(respuesta == -1)
                {
                    paso = -1;
                    returnAux = -1;
                    system("pause");
                }
                if(respuesta == -2)
                {
                    paso = 3;
                    returnAux = -1;
                }
                paso++;
                break;

            case 1:
                system("cls");
                respuesta = getStringLetras(apellido,"Ingrese el apellido del socio o 'cancelar' para volver al menu principal: ","\nERROR. El apellido debe contener entre 1 y 30 caracteres",1,30);
                if(respuesta == -1)
                {
                    paso = -1;
                    returnAux = -1;
                    system("pause");
                }
                if(respuesta == -2)
                {
                    paso = 3;
                    returnAux = -1;
                }
                paso++;
                break;

            case 2:
                system("cls");
                respuesta = getLong(&dni,"Ingrese el DNI del socio o 'cancelar' para volver al menu principal: ","ERROR. El DNI debe estar comprendido entre 1000000 y 99999999",1000000,99999999);
                if(respuesta == -1)
                {
                    paso = -1;
                    returnAux = -1;
                    system("pause");
                }
                if(respuesta == -2)
                {
                    paso = 3;
                    returnAux = -1;
                }
                paso++;

            case 3:
                printf("Su turno es: %d\n",turnoID);
                ClienteAux = Cliente_new_Parametros(nombre,apellido,dni,turnoID, turno);
                lista->add(lista,ClienteAux);
                paso++;
                break;
        }
    }while(paso > -1 && paso < 4);

    return returnAux;
}

int proximoCliente(ArrayList* listaU, ArrayList* listaR, ArrayList* listaUA, ArrayList* listaRA)
{
    int i;
    int returnAux;
    eCliente* clienteAux;

    if(listaU->isEmpty(listaU))
    {
        if(listaR->isEmpty(listaR))
        {
            returnAux = -1;
        }
        else
        {
            for(i=0;i<listaR->len(listaR);i++)
            {
                clienteAux = (eCliente*)listaR->get(listaR,i);
                printf("El proximo cliente a ser atendido es:\n");
                ImprimirCliente(clienteAux);
                printf("TRAMITE REGULAR\n");
                listaRA->add(listaRA,clienteAux);
                clienteAux = (eCliente*)listaR->remove(listaR,i);
                returnAux = 0;
                break;
            }
        }
    }
    else
    {
        for(i=0;i<listaU->len(listaU);i++)
        {
            clienteAux = (eCliente*)listaU->get(listaU,i);
            printf("El proximo cliente a ser atendido es:\n");
            ImprimirCliente(clienteAux);
            printf("TRAMITE URGENTE\n");
            listaUA->add(listaUA,clienteAux);
            clienteAux = (eCliente*)listaU->remove(listaU,i);
            returnAux = 0;
            break;
        }
    }
    return returnAux;
}

void ImprimirCliente(eCliente* cliente)
{
    if(cliente != NULL)
    {
        printf("Nombre: %s  Apellido: %s  DNI: %li  turno: %d\n",cliente->nombre,cliente->apellido,cliente->dni,cliente->numTurno);
    }
}

void ListarClientes(ArrayList* lista)
{
    int i;
    eCliente* cliente;
    for(i=0;i<lista->len(lista);i++)
    {
      cliente = (eCliente*)lista->get(lista,i);
      ImprimirCliente(cliente);
    }
}

int generarCSV(ArrayList* lista)
{
	FILE* miArchivo;
	int i;
	int returnAux = 0;
	eCliente* cliente;
	char turnoAux[20];

	miArchivo = fopen("Clientes.csv","w");
	if(miArchivo == NULL)
    {
        returnAux = -1;
    }
    else
    {
        fprintf(miArchivo,"nombre,apellido,dni,turno\n");
        for(i=0;i<lista->len(lista);i++)
        {
            cliente = (eCliente*)lista->get(lista,i);
            if(cliente->turno == 1)
            {
                strcpy(turnoAux,"Tramite Urgente");
            }
            if(cliente->turno == 2)
            {
                strcpy(turnoAux,"Tramite Regular");
            }

            fprintf(miArchivo,"%s,%s,%li,%s\n",cliente->nombre,cliente->apellido,cliente->dni,turnoAux);
        }
        fclose(miArchivo);
    }
    return returnAux;
}

int sortByDNI(void* clienteA, void* clienteB)
{
    int returnAux = 0;
    eCliente* clienteAuxA = (eCliente*)clienteA;
    eCliente* clienteAuxB = (eCliente*)clienteB;

    if(clienteAuxA->dni > clienteAuxB->dni)
    {
        returnAux = 1;
    }
    if(clienteAuxA->dni < clienteAuxB->dni)
    {
        returnAux = -1;
    }

    return returnAux;
}

void listarCSV(ArrayList* listaU, ArrayList* listaR, ArrayList* listaARC)
{
    int i = 0;
    eCliente* cliente;

    for(i=0;i<listaU->len(listaU);i++)
    {
        cliente = Cliente_new();
        cliente = (eCliente*)listaU->get(listaU,i);
        listaARC->add(listaARC,cliente);
    }
    for(i=0;i<listaR->len(listaR);i++)
    {
        cliente = Cliente_new();
        cliente = (eCliente*)listaR->get(listaR,i);
        listaARC->add(listaARC,cliente);
    }
}
