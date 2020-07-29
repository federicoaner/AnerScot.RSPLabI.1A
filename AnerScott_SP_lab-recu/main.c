#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include <time.h>

//#include <ctype.h>


int menu();


int main()

{

    //int flagTexto=0;
    char seguir='s';
    char confirma;
    srand (time(NULL));


   LinkedList* listaBicis = ll_newLinkedList();
   LinkedList* listafiltrada=ll_newLinkedList();
   //LinkedList* listaTipos=ll_newLinkedList();
   //LinkedList* listaTiempos=ll_newLinkedList();



/*

       if(!loadFromText("data.csv", listaBicis))
    {
        printf("Autos cargados desde CSV\n");
        flagTexto = 1;
    }

    if(flagTexto == 1)
    {
        mostrarBicicletas(listaBicis);
    }
    else
    {
        printf("Error. No hay archivos registrados.\n");
    }*/


     do
    {
        switch(menu())
        {
        case 1:
            if( !loadFromText("bicicletas.csv",listaBicis))
            {
                printf("Bicicletas cargadas con exito\n");
            }
            else
            {
                printf("Problema para cargar el archivo\n");
            }
            break;


        case 2:

                mostrarBicicletas(listaBicis);

            break;

        case 3:


            bicicleta_setCampos(listaBicis);

            break;

        case 4:

            listafiltrada=ll_filter(listaBicis,filtrarBmx);
            mostrarBicicletas(listafiltrada);
            break;

        case 5:

            ll_sort(listaBicis,ordenarBicicletasTipoyTiempo,1);

           mostrarBicicletas(listaBicis);



            break;


        case 6:
            guardarTexto("datos.csv",listaBicis);
            break;
           // system("pause");


        case 7:

            break;

        case 8:
            //controller_saveAsText("data.csv",listaEmpleados);
            break;

        case 9:
           // controller_saveAsBinary("data.bin",listaEmpleados);
            break;


        case 10:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma =='s')
            {
                seguir='n';
            }

            break;
        }
        system("pause");

    }
    while(seguir=='s');


    return 0;
}



int menu()
{
    int opcion;
    system("cls");
    printf("-------------------------\n");
    printf("-------------------------\n");
    printf("1. Cargar archivo csv\n");
    printf("2. Mostrar Bicicletas\n");
    printf("3. Asignar tiempos\n");
    printf("4. filtrar bicicletas Bmx\n");
    printf("5. Ordenar por tipo y tiempo\n");
    printf("6. Guardar Archivo de Texto\n");

    printf("10. Salir\n");
    printf("-------------------------\n");
    printf("-------------------------\n\n\n");


    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}

