/*
 ============================================================================
 Name        : FigueroaDamian-TP2.c
 Author      : Figueroa Damian
 ============================================================================
 */
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/** \brief menu que se despliega y muestra opciones
 *
 * \return retorna un entero segun la opcion elegida.
 */
int menu();

/** \brief indica que todas las posiciones del array esten vacias
 * poniendo la bandera isEmpty en TRUE en todas las posiciones
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \return retorna un int (-1) si hubo error [Longitud invalida o puntero NULL] o (0) si esta todo OK.
 *
 */
int initEmployees(eEmployee* lista, int len);

/** \brief encuentra un empleado por ID y devuelve el indice en el array
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \param id, entero que se usa para comparar con el id del empleado
 * \return
 *
 */
int findEmployeeById(eEmployee* lista, int len, int id);


/** \brief devuelve el indice del que esta vacio en vector lista
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \return devuelve el indice del siguiente lugar libre en el vector o -1 si no hay lugar libre
 *
 */
int findFreeIndex(eEmployee* lista, int len);

/** \brief pide los datos que luego le pasa a la funcion addEmployee
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \param nextId, puntero del entero que contiene el id.
 * \param flagFirstEntry, puntero de la bandera del primer ingreso
 * \return 0 si todoOk o -1 si array null o longitud invalida
 *
 */
int employeeRegistration(eEmployee* lista , int len, int* nextId, int* flagFirstEntry);

/** \brief imprime por pantalla el array en forma encolumnada
 *
 * \param lista, puntero del array de empleados
 * \param length, longitud del array
 * \return 0 si todoOk o -1 si array null o longitud invalida
 *
 */
int printEmployees(eEmployee* lista, int length);

/** \brief muestra los datos del array de empelados que le llega a traves de la funcion printEmployee
 *
 * \param empleado, una entidad del tipo eEmployee
 * \return void
 *
 */
void showEmployeeInfo(eEmployee employee);

/** \brief agrega en un array de empleados existente los valores recibidos como parametro en la
 *         primera posicion libre
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \param id, id del empleado
 * \param name, nombre del empleado
 * \param lastName, apellido del empleado
 * \param salary, salario del empleado
 * \param sector, sector del empleado
 * \return -1 si hubo error en la longitud del array o puntero nullo o sin espacio, o 0 si todo Ok
 *
 */
int addEmployee(eEmployee* lista, int len, int id, char name[],char lastname[],float salary, int sector);

/** \brief elimina de manera logica (isEmpty en 1) un empleado recibiendo como parametro su ID.
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \param id, id del empleado
 * \return -1 si hubo error de longitud o puntero nullo o si no pudo encontrar al empleado O 0 si todo OK
 *
 */
int removeEmployee(eEmployee* lista, int len, int id);

/** \brief despliega un menu con opciones de informes
 *
 * \return devuelve un entero segun la opcion elegida
 *
 */
int subMenuOrder();

/** \brief despliega un menu para elegir el tipo de orden ASC o DES
 *
 * \return retora un entero segun la opcion elegida
 *
 */
int menuOpcionOrder();

/** \brief Ordena el array de empleados por apellido y sector
 *         de manera ascendente o descendente
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \param orden, entero  (1) que indica orden ascendente, entero (0) orden descendente
 * \return devuelve -1 si hubo error de longitud o puntero null, o 0 si todo OK
 *
 */
int sortEmployees(eEmployee* lista, int len, int order);


/** \brief engloba el funcionamiento de la cuarta opcion del menu principal
 *
 * \return void
 *
 */
void reports(eEmployee* lista, int len);

/** \brief funcion que se calcula el salario total y el promedio.
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \return void
 *
 */
void reportTotalSalary(eEmployee* lista,int tam);

/** \brief permite modificar los datos de un empleado.
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \return devuelve -1 si hubo error de longitud o puntero null, o 0 si todo OK
 *
 */
int updateEmployee(eEmployee* lista, int len);

/** \brief menu que te deja elegir que parametro modificar y devuelve un entero
 *
 * \return devuelva la opcion en entero.
 *
 */
int subMenuUpdates();

/** \brief verifica que el array este vacio
 *
 * \param lista, puntero del array de empleados
 * \param len, longitud del array
 * \return devuelve entero 0 si el array esta vacio, -1 si no lo esta
 *
 */
int verifyIfArrayIsEmpty(eEmployee* lista,int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
