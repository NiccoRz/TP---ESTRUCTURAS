#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char genero;
    int matricula;
} ALUMNO;

int main()
{
    int op;
    do
    {
        system("cls");
        printf("RUIZ NICOLAS - TP ESTRUCTURAS\n\n");
        for(int i=1; i<=9; i++)
        {
            printf("- Ejercicio %d\n",i);
        }
        printf("\nSi desea salir digite 0 (cero)...");
        printf("\n\nDigite un ejercicio: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            system("cls");
            Ejercicio1();
            printf("\n\n");
            system("PAUSE");
            break;
        case 2:
            system("cls");
            Ejercicio2();
            printf("\n\n");
            system("PAUSE");
            break;
        case 3:
            system("cls");
            Ejercicio3();
            printf("\n\n");
            system("PAUSE");
            break;
        case 4:
            system("cls");
            Ejercicio4();
            printf("\n\n");
            system("PAUSE");
            break;
        case 5:
            system("cls");
            Ejercicio5();
            printf("\n\n");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            Ejercicio6();
            printf("\n\n");
            system("PAUSE");
            break;
        case 7:
            system("cls");
            Ejercicio7();
            printf("\n\n");
            system("PAUSE");
            break;
        case 8:
            system("cls");
            Ejercicio8();
            printf("\n\n");
            system("PAUSE");
            break;
        case 0:
            break;
        default:
            system("cls");
            printf("El ejercicio elegido no existe...");
            printf("\n\n");
            system("PAUSE");
            break;
        }
    }
    while(op!=0);

    return 0;
}


int cargarArreglo(ALUMNO A[],int dim)
{
    int i=0;
    char op='s';
    while(i<dim && op=='s')
    {
        printf("Ingrese nombre del alumno: ");
        fflush(stdin);
        gets(A[i].nombre);

        printf("Ingrese genero (f/m): ");
        fflush(stdin);
        scanf("%c",&A[i].genero);
        while(A[i].genero!='m' && A[i].genero!='f')
        {
            printf("Ingrese nuevamente el genero (f/m): ");
            fflush(stdin);
            scanf("%c",&A[i].genero);
        }

        printf("Ingrese matricula: ");
        scanf("%d",&A[i].matricula);

        printf("Desea continuar? Presione 's' o 'n': ");
        fflush(stdin);
        scanf("%c",&op);
        printf("\n");
    }
    return i;
}
void mostrarPersona(ALUMNO A[],int i)
{
    char genero[1][30];
    printf("\nNombre: %s",A[i].nombre);
        if(A[i].genero=='m')
            strcpy(genero[0],"Masculino");
        else
            strcpy(genero[0],"Femenino");
        printf("\nGenero: %s",genero[0]);
        printf("\nMatricula: %d",A[i].matricula);
}
void mostrarArreglo(ALUMNO A[],int val)
{
    char genero[1][30];
    for(int i=0;i<val;i++)
    {
        mostrarPersona(A,i);
        printf("\n-------------------------\n");
    }
}
int busquedaMatricula(ALUMNO A[],int val,int dato)
{
    int flag=-1;
    int i=0;
    while(i<val && A[i].matricula!=dato)
    {
        i++;
    }

    if(A[i].matricula==dato)
        flag=i;

    return flag;
}
void ordSeleccion(ALUMNO A[],int val)
{
    ALUMNO aux;
    int min;
    for(int i=0;i<val;i++)
    {
        min = i;
        for(int j=i+1;j<val;j++)
        {
            if(A[j].matricula<A[min].matricula)
                min=j;
        }
        aux = A[i];
        A[i]= A[min];
        A[min] = aux;
    }
}
void mostrarXGenero(ALUMNO A[],int val,char gr)
{
    if(gr=='m')
    {
        printf("\nAlumnos Masculinos: \n");
    }else{
        printf("\nAlumnos Femeninos: \n");
    }
    for(int i=0;i<val;i++)
    {
        if(A[i].genero==gr)
        {
          mostrarPersona(A,i);
          printf("\n-----------------\n");
        }
    }
}
ALUMNO cargarAlumno(ALUMNO B)
{
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(B.nombre);

    printf("Ingrese genero (f/m): ");
        fflush(stdin);
        scanf("%c",&B.genero);
        while(B.genero!='m' && B.genero!='f')
        {
            printf("Ingrese nuevamente el genero (f/m): ");
            fflush(stdin);
            scanf("%c",&B.genero);
        }

    printf("Ingrese matricula: ");
    scanf("%d",&B.matricula);

    return B;
}
int insertarOrdenado(ALUMNO A[],int validos,ALUMNO B)
{
    int ult = validos -1;
    while(ult>=0 && B.matricula < A[ult].matricula)
    {
        A[ult+1]=A[ult];
        ult--;
    }
    A[ult+1]=B;

    return validos+1;
}
void ordIncersion(ALUMNO A[],int val)
{
 int pos;
 ALUMNO aux;
 for(int i=0;i<val;i++)
 {
     pos = i;
     aux = A[i];
     while(pos>0 && strcmpi(A[pos-1].nombre,aux.nombre)>0)
     {
        A[pos]=A[pos-1];
        pos--;
     }
     A[pos]=aux;
 }
}
int cantGenero(ALUMNO A[],int val,char gnro)
{
    int cantG = 0;

    for(int i=0;i<val;i++)
    {
        if(A[i].genero==gnro)
            cantG++;
    }

    return cantG;
}



int Ejercicio1()
{
    printf("EJERCICIO 1 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.\n\n");
    ALUMNO A[100];
    int val = cargarArreglo(A,100);
}

int Ejercicio2()
{
    printf("EJERCICIO 2 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que muestre un arreglo de alumnos por pantalla. Modularizar.\n\n");
    ALUMNO A[100];
    int val = cargarArreglo(A,100);
    mostrarArreglo(A,val);
}

int Ejercicio3()
{
    printf("EJERCICIO 3 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula. Modularizar. \n\n");
    ALUMNO A[100];
    int dato;
    int val=cargarArreglo(A,100);
    printf("\nIngrese matricula a buscar: ");
    scanf("%d",&dato);
    int flag = busquedaMatricula(A,val,dato);
    if(flag==-1)
    {
        printf("\nNo se encuentra la matricula ingresada...");
    }else
    {
        mostrarPersona(A,flag);
    }
}

int Ejercicio4()
{
    printf("EJERCICIO 4 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion. El criterio de ordenacion es el numero de matricula.\n\n");
    ALUMNO A[100];
    int val=cargarArreglo(A,100);
    printf("\n\nEstudiantes: ");
    mostrarArreglo(A,val);
    printf("\n\nEstudiantes Ordenados: ");
    ordSeleccion(A,val);
    mostrarArreglo(A,val);
}

int Ejercicio5()
{
    printf("EJERCICIO 5 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro). Modularizar.\n\n");
    ALUMNO A[100];
    int val = cargarArreglo(A,100);
    char gr;
    printf("Elija genero a buscar (f/m): ");
    fflush(stdin);
    scanf("%c",&gr);

    while(gr!='m'&& gr!='f')
    {
        printf("GENERO INEXISTENTE...Introduzca nuevamente el genero (f/m): ");
        fflush(stdin);
        scanf("%c",&gr);
    }
    mostrarXGenero(A,val,gr);
}

int Ejercicio6()
{
    printf("EJERCICIO 6 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato, conservando el orden. \n\n");
    ALUMNO A[6]=
    {
    {"Carmen",'f',1},
    {"Nestor",'m',4},
    {"Julio",'m',6},
    {"Camila",'f',9},
    {"Aldana",'f',15}
    };
    printf("\nAlumnos: \n");
    mostrarArreglo(A,5);

    ALUMNO B;
    ALUMNO alB = cargarAlumno(B);
    int val= insertarOrdenado(A,5,alB);
    printf("\nAlumnos + el nuevo alumno: \n");
    mostrarArreglo(A,val);
}

int Ejercicio7()
{
    printf("EJERCICIO 7 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de insercion. El criterio de ordenacion es el nombre.\n\n");
    ALUMNO A[100];
    int val = cargarArreglo(A,100);
    printf("\nALUMNOS: \n");
    mostrarArreglo(A,val);
    printf("\nALUMNOS INCERSION: \n");
    ordIncersion(A,val);
    mostrarArreglo(A,val);
}

int Ejercicio8()
{
    printf("EJERCICIO 8 - TP ESTRUCTURAS\n\n");
    printf("Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado (se envia por parametro) que tiene un arreglo de alumnos.\n\n");
    ALUMNO A[100];
    int val = cargarArreglo(A,100);

    char gnro;
    printf("\nIngrese genero a buscar (f/m): ");
    fflush(stdin);
    scanf("%c",&gnro);

    int cant = cantGenero(A,val,gnro);

    if(gnro=='m')
        printf("\nLa cantidad de Masculinos es de: %d",cant);
    else if(gnro=='f')
        printf("\La cantidad de Femeninas es de: %d",cant);
        else
            printf("El genero ingresado no existe...");
}
