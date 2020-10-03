

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
       listado[i].legajo=i+500;
       printf("\n\t ...empleado cargado exitosamente!!!");
   }
   else
   {
       printf("no hay espacio");

   }





}


void MostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n%8d\t%8s\t%9s\t%9.2f\t%7d\n",unEmpleado.legajo,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector );
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



void InicializadorEstados(eEmpleado listado[] ,int cant )
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


    printf("\n  LEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
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
            if(listado[i].sector > listado[j].sector)
            {
                OrdenarEmpleadosPorApellido(listado,cant);
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

            if(strcmp(listado[i].apellido,listado[j].apellido)==0 )
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

float CalculaPromedioSalarial(eEmpleado listado[] ,float cant)
{
    int i;
    float promedioSueldos;
    float acumuladorDeSueldos=0;
    float divisor;

    for(i=0; i<cant; i++)
    {

        acumuladorDeSueldos=acumuladorDeSueldos+listado[i].salario;
        divisor=i;



    }
    promedioSueldos=acumuladorDeSueldos/divisor;



    return promedioSueldos;

}

void EliminarEmpleado(eEmpleado listado [], int cant)
{
    int legajo;
    int i;
    int seleccion;


    MostrarNominaEmpleados(listado, cant);
    printf("ingrese legajo del empleado a eliminar: ");
    scanf("%d", &legajo);

    for(i=0; i<cant;i++)
    {

        if(listado[i].legajo==legajo&&listado[i] .isEmpty==0)
        {
            printf("¿Seguro que desea eliminar a este empleado?");
            printf(" '5' para confirmar -- 8 si fue un error  ");
            scanf("%d", &seleccion);

            if(seleccion==5)
            {
                   listado[i].isEmpty=1;
                   printf("\n\t Empleado eliminado con exito!!!");
                   break;

            }
            else
            {
                printf("volviendo al menu!");
                break;
            }
        }

        else
        {
            if(listado[i].isEmpty==1)
            {
                printf("\n\t este empleado ya fue eliminado o no existe aun!!!");
                break;
            }
        }

    }

}


void ModificarDatoEmpleado(eEmpleado listado [],int cant)
{
    int i;
    int legajo;
    eEmpleado nombreModificado;
    eEmpleado apellidoModificado;
    eEmpleado sectorActual;
    eEmpleado salarioActual;
    int opc;


    MostrarNominaEmpleados(listado,cant);
    printf("\n\t\t Ingrese el legajo del empleado a modificar ");
    scanf(" %d",&legajo);

    for(i=0;i<cant ;i++)
    {
        if(listado[i].legajo==legajo&&listado[i] .isEmpty==0)
        {
            printf("\n\t\t ¿Que cambio desea realizar?\n\n ");
            printf("\t\t1.Nombre  2.Apellido   3.Sector   4.Salario  ");
            scanf(" %d",&opc);
            while(opc!=1 &&opc!=2 &&opc!=3 &&opc!=4)
            {

                printf("ingrese una opcion valida!!!");
                printf("\n\t\t ¿Que cambio desea realizar?\n\n ");
                printf("\t\t1.Nombre  2.Apellido   3.Sector   4.Salario  ");
                scanf(" %d",&opc);

            }

            switch(opc)
            {
                case 1:
                    printf("\t ingrese nombre modificado: ");
                    fflush(stdin);
                    gets(nombreModificado.nombre);

                    strcpy(listado[i].nombre,nombreModificado.nombre );
                    printf("\n\t\t Cambio de nombre realizado!!!");
                    break;

                case 2:
                    printf("\t ingrese apellido modificado : ");
                    fflush(stdin);
                    gets(apellidoModificado.apellido);

                    strcpy(listado[i].apellido,apellidoModificado.apellido );
                    printf("\n\t\t Cambio de apellido realizado!!!");
                    break;

                case 3:
                    printf("\t ingrese nuevo sector:  ");
                    fflush(stdin);
                    scanf(" %d",&sectorActual.sector);

                    listado[i].sector=sectorActual.sector;
                    printf("\n\t\t Cambio de sector realizado!!!");
                    break;

                case 4:
                    printf("\t ingrese sueldo actualizado");
                    fflush(stdin);
                    scanf(" %f", & salarioActual.salario);

                    listado[i].salario=salarioActual.salario;
                    printf("Actualizacion de sueldo realizada!!!");
                    break;

            }
            break;


        }
        else
        {
            if(listado[i] .isEmpty==1)
            {
                printf("No hay registro de este usuario!!! ");
                break;
            }
        }
    }
}




