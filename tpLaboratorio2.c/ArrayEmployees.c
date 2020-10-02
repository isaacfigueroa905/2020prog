

#include "ArrayEmployees.h"
#include <string.h>

eEmpleado Ingreso()
{
     eEmpleado unEmpleado;

    printf("\n\t Carga de empleado\n\n ");
    printf("\t ingrese nombre: ");
    fflush(stdin);
    scanf("\n%s", unEmpleado.nombre);
    printf("\n\t ingrese apellido: ");
    fflush(stdin);
    scanf("\n%s", unEmpleado.apellido);
    printf("\n\t ingrese sector (del 1 al 10): ");
    scanf("\n%d", &unEmpleado.sector);
    while(unEmpleado.sector<1 || unEmpleado.sector>10)
    {
        printf("\n\t ERROR ingrese un sector valido (1 a 10): ");
        scanf("\n%d", &unEmpleado.sector);
    }
    printf("\n\t ingrese salario: ");
    scanf("\n%f", &unEmpleado.salario);

    return unEmpleado;
}



void CargarEmpleados(eEmpleado listado[] , int cant)
{
   int i;
   i=BuscarLibre(listado, cant);
   if(i!=-1)
   {
       listado[i] = Ingreso() ;
       listado[i].idLegajo=i+500;
       printf("\n\t ...empleado cargado exitosamente!!!");
   }
   else
   {
       printf("no hay espacio");

   }





}


void MostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n%8d\t%8s\t%9s\t%9.2f\t%7d\n",unEmpleado.idLegajo,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector );
}

int BuscarLibre(eEmpleado listado[], int cant)
{

    int indiceRetornado=-1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(listado[i].isEmpty==1)
        {
            indiceRetornado=i;
            break;
        }
    }



    return indiceRetornado;
}



int InicializadorEstados(eEmpleado listado[] ,int cant )
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].isEmpty=1;
    }
}


void MostrarNominaEmpleados(eEmpleado listado [] , int cant)
{
    int i;


    printf("\n\tLEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
    for(i=0; i<cant; i++)
    {
        if(listado[i].isEmpty==0)
        {
             MostrarEmpleado(listado[i] );
        }

    }
}
void OrdenarEmpleadosPorSector(eEmpleado listado[], int cant)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(listado[i].sector > listado[j].sector)
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }

        }
    }
}
void OrdenarEmpleadosPorApellido(eEmpleado listado[], int cant)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(listado[i].apellido,listado[j].apellido)>0 )
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }
        }
    }
}
float TotalSueldos(eEmpleado listado[], int cant )
{
    int i;
    float acumuladorDeSueldos=0;

    for(i=0; i<cant; i++)
    {
        acumuladorDeSueldos=acumuladorDeSueldos+listado[i].salario;
    }
    return acumuladorDeSueldos;
}

float CalculaPromedioSalarial(eEmpleado listado[] ,int cant)
{
    int i;
    float promedioSueldos;
    float acumuladorDeSueldos=0;
    int divisor;

    for(i=0; i<cant; i++)
    {

        acumuladorDeSueldos=acumuladorDeSueldos+listado[i].salario;
        divisor=i;

    }
    promedioSueldos=acumuladorDeSueldos/divisor;







    return promedioSueldos;

}


