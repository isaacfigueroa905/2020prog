

#include "ArrayEmployees.h"
#include <stdlib.h>

#define TAM 3

int main()
{
    eEmpleado empleados[TAM];

    int opcion;
    char opciones;
    int banderaPrimerIngreso;

    banderaPrimerIngreso=0;

    InicializadorEstados(empleados, TAM);
    do
    {
        printf("\n\t\t\t\t\t  MENU:");
        printf("\n\t\t\t\t 1. ALTAS");
        printf("\n\t\t\t\t 2. MODIFICAR");
        printf("\n\t\t\t\t 3. BAJAS");
        printf("\n\t\t\t\t 4. INFORMAR");
        printf("\n\t\t\t\t 0. SALIR");
        printf("\n\t\t\t\t Seleccione una opcion:  ");
        scanf("%d",&opcion);
        while(opcion<0 || opcion>4)
        {
            printf("\nSeleccione una opcion valida!!!:  ");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                 CargarEmpleados(empleados,TAM);
                 banderaPrimerIngreso=1;
            break;
            case 2:
                printf("eliminar");
            break;
            case 3:
                printf("modificar");
            break;
            case 4:
                if(banderaPrimerIngreso==1)
                {
                     printf("\n\t\t\t\t\t A.Mostrar nomina por apellido");
                     printf("\n\t\t\t\t\t B.Mostrar nomina por sector");
                     printf("\n\t\t\t\t\t C.Mostrar promedio de sueldos");
                     printf("\n\t\t\t\t\t D.Mostrar total de sueldos");
                     printf("\n\t\t\t\t\t Seleccione una opcion:  ");

                     scanf("%s",&opciones);
                     while(opciones!='a'&& opciones!='b' && opciones!='c' && opciones!='d')
                    {
                        printf("\n\t\t\t\t ERROR ingrese una opcion valida!!!");
                        scanf("%s",&opciones);

                    }
                    if(opciones=='a')
                    {
                        OrdenarEmpleadosPorApellido(empleados,TAM);//ascendente de a a la z
                        MostrarNominaEmpleados(empleados,TAM);
                    }
                    if(opciones=='b')
                    {
                        OrdenarEmpleadosPorSector(empleados,TAM);//DEL MENOR AL MAYOR
                        MostrarNominaEmpleados(empleados,TAM);
                    }
                    if(opciones=='c')
                    {
                        printf("el sueldo promedio es: %.2f ",CalculaPromedioSalarial(empleados,TAM) );

                    }
                    if(opciones=='d')
                    {
                        printf("\t\t\t\t el sueldo total de todos los empleados es: %.2f  ",TotalSueldos(empleados,TAM) );

                    }


                }
                else
                {
                    printf("\n\t\t\t\t\t Nada para mostrar!!!");

                }

                break;

            case 0:
                printf("\n\t\t\t\t saliendo...");
            break;

        }





    }while(opcion!=0);





    return 0;
}

