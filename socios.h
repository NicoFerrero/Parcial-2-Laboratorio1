#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
   char nombre[31];
   char apellido[31];
   long dni;
   int turno;
   int numTurno;

}eCliente;

eCliente* Cliente_new(void);
eCliente* Cliente_new_Parametros(char* nombre, char* apellido, long dni, int turnoID, int turno);
int alta(ArrayList* lista, int turno, int turnoID);
void ImprimirCliente(eCliente* cliente);
void ListarClientes(ArrayList* lista);
int proximoCliente(ArrayList* listaU, ArrayList* listaR, ArrayList* listaUA, ArrayList* listaRA);
int sortByDNI(void* clienteA, void* clienteB);
int generarCSV(ArrayList* lista);
void listarCSV(ArrayList* listaU, ArrayList* listaR, ArrayList* listaARC);

#endif // SOCIOS_H_INCLUDED
