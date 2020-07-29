
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "bicicletas.h"
#include "validacion.h"


//#include <ctype.h>


eBicicleta* bicicleta_new()
{

    eBicicleta* newBicicleta = (eBicicleta*) malloc(sizeof(eBicicleta));

    if (newBicicleta != NULL)
    {
        newBicicleta->id = 0;
        strcpy(newBicicleta->nombre," ");

        strcpy(newBicicleta->tipo," ");
        newBicicleta->tiempo = 0;


    }

    return newBicicleta;

}


/** \brief recibe datos como string, los convierte y carga los carga en una nueva eBicicleta
 *
 * \param dniStr char* dni
 * \param apellidoStr char*
 * \param char* tarjetaStr
 * \param char* cuotasStr
 * \return eBicicleta* puntero al nuevo bicicleta
 *
 */

eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* IipoStr,char* tiempoStr)
{


    eBicicleta* nuevo = bicicleta_new();

    if (nuevo != NULL)
    {
        bicicleta_setId(nuevo, atoi(idStr));
        bicicleta_setNombre(nuevo, nombreStr);
        bicicleta_setTipo(nuevo, IipoStr);
        bicicleta_setTiempo(nuevo, atoi(tiempoStr));


    }

    return nuevo;
}

void bicicleta_delete(eBicicleta* unaBicicleta)
{

    if(unaBicicleta!=NULL)
    {

        free(unaBicicleta);
        unaBicicleta=NULL;
    }

}


int bicicleta_getId(eBicicleta* this, int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 0;
    }

    return todoOk;
}

int bicicleta_getNombre(eBicicleta* this, char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, 128);
        todoOk = 0;
    }

    return todoOk;
}





int bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int todoOk = 1;

    if(this != NULL && tipo != NULL)
    {
        strncpy(tipo, this->tipo, 128);
        todoOk = 0;
    }

    return todoOk;
}



int bicicleta_getTiempo(eBicicleta* this, int* tiempo)
{
    int todoOk = 1;

    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        todoOk = 0;
    }

    return todoOk;
}

int bicicleta_setId(eBicicleta* this,int id)
{
    int todoOk = 1;

    if (this != NULL)
    {
        this->id = id;
        todoOk = 0;
    }

    return todoOk;

}

int bicicleta_setNombre(eBicicleta* this,char* nombre)
{

    int todoOk = 1;

    if (this != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 0;
    }

    return todoOk;

}









int bicicleta_setTipo(eBicicleta* this,char* tipo)
{

    int todoOk = 1;

    if (this != NULL)
    {
        strcpy(this->tipo, tipo);
        todoOk = 0;
    }

    return todoOk;

}


int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int todoOk = 1;

    if (this != NULL)
    {
        this->tiempo = tiempo;
        todoOk = 0;
    }

    return todoOk;

}





int parser(FILE* pFile, LinkedList* pBicicletas)
{
    int todoOk = 1;
    eBicicleta* pBicicleta;
    char id[200];
    char nombre[200];
    char tipo[200];
    char tiempo[200];


    if(pFile != NULL && pBicicletas != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo) == 4)
            {
                pBicicleta = bicicleta_newParametros(id, nombre, tipo, tiempo);

                if(pBicicleta != NULL)//osea si pudo cargar
                {
                    ll_add(pBicicletas, pBicicleta);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }

        }
        while(feof(pFile) == 0);
    }

    return todoOk;
}

int loadFromText(char* path, LinkedList* pBicicletas)
{
    FILE* pFile;
    int todoOk = 1;

    pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

    if(pFile != NULL)
    {
        if(parser(pFile, pBicicletas) == 0)
        {

            todoOk = 0;

        }
        else
        {
            printf("Error No se pudo abrir el archivo\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    fclose(pFile);



    return todoOk;
}


void listarBicicleta(LinkedList* lista, int index)
{
    eBicicleta* auxBicicleta = (eBicicleta*) bicicleta_new();
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;





    if(lista != NULL && index >=0)
    {
    auxBicicleta = ll_get(lista, index);
    bicicleta_getId(auxBicicleta,&id);
   bicicleta_getNombre(auxBicicleta,nombre);
    bicicleta_getTipo(auxBicicleta,tipo);
    bicicleta_getTiempo(auxBicicleta,&tiempo);


    printf("%2d        %-12s        %-12s     %d         \n", id, nombre, tipo, tiempo);

    }

}

int mostrarBicicletas(LinkedList* pBicicletas)
{
    int todoOk = 1;

    eBicicleta* pBicicleta;


    if(pBicicletas != NULL)
    {
        system("cls");
        printf("\n  ID      Nombre        Tipo              Tiempo   \n\n");
        for(int i = 0; i < ll_len(pBicicletas); i++)
        {
            pBicicleta = ll_get(pBicicletas, i);
            if(pBicicleta != NULL)
            {
                 listarBicicleta(pBicicletas, i);
                todoOk = 0;
            }
        }
    }
    else if(todoOk == 1)
    {
        printf("No hay Bicicletass cargadas en la lista.\n");
    }

    return todoOk;
}



int filtrarBmx( void* unaBicicleta){

    int auxReturn=0;
    eBicicleta* x;

    if(unaBicicleta!=NULL){

       x=(eBicicleta*) unaBicicleta;
    if(strcmp(x->tipo,"BMX")==0){

        auxReturn=1;
    }


}
 return auxReturn;

}


int getRandomTiempo()
{
    int tiempo;

    tiempo = rand()% (71)+50 ;

    return tiempo;
}

void* asignarTiempos(void* pElement)
{
    eBicicleta* auxBicicleta;
    auxBicicleta = (eBicicleta*) pElement;

    settearTiempos(auxBicicleta);

    return auxBicicleta;
}

int bicicleta_setCampos(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaAsignada;

    if(lista != NULL)
    {
        listaAsignada = ll_map(lista,asignarTiempos);
        if(listaAsignada != NULL)
        {
            todoOk = 0;
            printf("Se asignaron los tiempos\n");
        }
        else
        {
            printf("No se pudieron asignar los tiempos\n");
        }
    }
    return todoOk;
}


void settearTiempos(void* element)
{
    eBicicleta* tiempos = NULL;

    if(element!=NULL)
    {
        tiempos = (eBicicleta*) element;
        bicicleta_setTiempo(tiempos, getRandomTiempo());

    }

}

int guardarTexto(char* path, LinkedList* pArrayList)
{
    int todoOk=-1;
    FILE* f=fopen(path,"w");
    int id;
	char nombre[128];
    char tipo[128];
    int tiempo;



    eBicicleta* auxBicicleta;



    if(f!=NULL && pArrayList != NULL)
    {
        fprintf(f,"id,nombre,tipo,tiempo\n");

        for (int i=0; i<ll_len(pArrayList) ; i++ )
        {

            auxBicicleta = ll_get(pArrayList,i);

            bicicleta_getId(auxBicicleta, &id);
            bicicleta_getNombre(auxBicicleta, nombre);
            bicicleta_getTipo(auxBicicleta, tipo);
            bicicleta_getTiempo(auxBicicleta, &tiempo);



            fprintf(f,"%d,%s,%s,%d\n",id,nombre,tipo,tiempo );
            todoOk=1;

        }

        printf("\nArchivo guardado con exito!!!\n");

    }

    else
    {
        printf("error al guardar");
    }

    fclose(f);


    return todoOk;
}


int ordenarTiempo(void* a, void* b)
{
    int returnAux=0;
    eBicicleta* p1;
    eBicicleta* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eBicicleta*)a;
        p2 = (eBicicleta*)b;

        if(p1->tiempo < p2->tiempo)
        {
            returnAux=1;
        }

    }
    return returnAux;
}


/*int ordenarTipos(void* a, void* b) //sort
{
    int retorno;
    eBicicleta* b1;
    eBicicleta* b2;

    if(a != NULL && b != NULL)
    {
        b1 =(eBicicleta*) a;
        b2 =(eBicicleta*) b;

        retorno=strcmp(b1->tipo,b2->tipo);
    }

    return retorno;
}*/


int ordenarBicicletasTipoyTiempo(void * a, void* b)
{
    int retorno = 0;
    eBicicleta* b1;
    eBicicleta* b2;

    if(a != NULL && b != NULL)
    {
        b1 = (eBicicleta*) a;
        b2 = (eBicicleta*) b;

        retorno = strcmp(b1->tipo,b2->tipo);

        if(!strcmp(b1->tipo,b2->tipo))
        {
            retorno = ordenarTiempo(b1,b2);
        }

    }

    return retorno;
}
