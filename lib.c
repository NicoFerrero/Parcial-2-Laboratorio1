#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "lib.h"

int getInt(int* input,char* mensaje,char* eMensaje,int lowLimit,int hiLimit)
{
    int aux;
    char auxChar[256];

    getString(mensaje,auxChar);
     if(strcmpi(auxChar,"cancelar") == 0)
     {
            printf("Operacion cancelada por el usuario\n");
            return -2;
    }
    if(esNumerico(auxChar) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    aux = atoi(auxChar);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

int getLong(long* input,char* mensaje,char* eMensaje,long lowLimit,long hiLimit)
{
    long aux;
    char auxChar[256];

    getString(mensaje,auxChar);
     if(strcmpi(auxChar,"cancelar") == 0)
     {
            printf("Operacion cancelada por el usuario\n");
            return -2;
    }
    if(esNumerico(auxChar) == -1)
    {
        printf("Este campo solo admite numeros enteros\n");
        return -1;
    }
    aux = atol(auxChar);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

int getStringLetras(char* input,char* mensaje,char* eMensaje,int lowLimit,int hiLimit)
{
    char aux[256];

    getString(mensaje,aux);
     if(strcmpi(aux,"cancelar") == 0)
     {
            printf("Operacion cancelada por el usuario\n");
            return -2;
    }
    if(esSoloLetras(aux) == -1)
    {
        printf("Este campo solo admite letras\n");
        return -1;
    }
    if(strlen(aux) < lowLimit || strlen(aux) > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    formatoTitulo(aux);
    strcpy(input,aux);
    return 0;
}

void getSN(char* input,char* mensaje,char* eMensaje)
{
    char aux;
    printf("%s", mensaje);
    aux = tolower(getche());
    if(aux != 's' && aux != 'n')
    {
        printf("%s", eMensaje);
    }
    else
    {
        *input = aux;
    }
}

void getString(char* mensaje, char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esNumerico(char* string)
{
    int i = 0;
    int returnAux = 0;

    while(string[i] != '\0')
    {
        if((string[i] < '0' || string[i] > '9'))
        {
            returnAux = -1;
        }
        i++;
    }
    return returnAux;
}

int esSoloLetras(char* string)
{
    int i = 0;
    int returnAux = 0;

    while(string[i] != '\0')
    {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            returnAux = -1;
        }
        i++;
    }
    return returnAux;
}

void formatoTitulo(char* string)
{
    int largo = strlen(string);
    int i;

    for(i=0;i<largo;i++)
    {
        string[i] = tolower(string[i]);
        if(string[i] == ' ')
        {
            string[i+1] = toupper(string[i+1]);
        }
        if(string[0] != ' ')
        {
            string[0] = toupper(string[0]);
        }
    }
}

int menu(char* listado)
{
    int opcion;
    char aux[256];

    printf("%s", listado);
    fflush(stdin);
    gets(aux);
    if(!esNumerico(aux))
    {
        opcion = atoi(aux);
        return opcion;
    }
    else
    {
        printf("Este campo solo admite numeros enteros\n");
        system("pause");
        return 0;
    }
}
