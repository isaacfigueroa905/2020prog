

#include <stdio.h>

typedef struct
{
    int idLegajo;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;


}eEmpleado;



//---------Funciones de Carga.


/** \brief Carga la cantidad deseada de empleados.
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void CargarEmpleados(eEmpleado[], int);



/** \brief Carga un solo empleado, funcion creada para ser usada dentro de otra.
 *
 * \return eEmpleado
 *
 */
eEmpleado Ingreso();







//----------Funciones de Muestra.

/** \brief Muestra todos los empleados ingresados.
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void MostrarNominaEmpleados(eEmpleado[], int);




/** \brief Muestra un empleado, funcion creada para ser usada dentro de otra.
 *
 * \param eEmpleado
 * \return void
 *
 */
void MostrarEmpleado(eEmpleado);





//-------Funciones de Ordenamiento.

/** \brief Ordena alfabeticamente los apellidos de los empleados de forma creciente.
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void OrdenarEmpleadosPorApellido(eEmpleado[], int);



/** \brief Ordena los empleados segun sector de forma creciente.
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void OrdenarEmpleadosPorSector(eEmpleado[], int);


//---------Funciones de Calculo.



//int CantidadQueSuperanSueldoPromedio(eEmpleado listado[], int cant );

/** \brief La suma de los sueldos de todos los empleados.
 *
 * \param [] eEmpleado variable usada para acumular los sueldos.
 * \param int variable de control 'i'.
 * \return float Retorna el total de los sueldos.
 *
 */
float TotalSueldos(eEmpleado [], int  );



/** \brief Calcula el promedio de los empleados.
 *
 * \param eEmpleado[]
 * \param int
 * \return float Retorna el promedio de los sueldos.
 *
 */
float CalculaPromedioSalarial(eEmpleado[],int );




//--------Funciones Especiales.

/** \brief Inicializa isEmpty en 1.
 *
 * \param
 * \param
 * \return
 *
 */

int InicializadorEstados(eEmpleado[],int );


/** \brief Busca lugar libre para la carga de empleados.
 *
 * \param
 * \param
 * \return  retorna indice libre o -1 si no hay indice libre
 *
 */

int BuscarLibre(eEmpleado[], int);//


