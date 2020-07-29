#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED


#endif // BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;




} eBicicleta;



eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* IipoStr,char* tiempoStr);
void bicicleta_delete(eBicicleta* unaBicicleta);
int bicicleta_getId(eBicicleta* this, int* id);
int bicicleta_getNombre(eBicicleta* this, char* nombre);
int bicicleta_getIdTipo(eBicicleta* this, int* tipo);
int bicicleta_getTiempo(eBicicleta* this, int* tiempo);
int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int parser(FILE* pFile, LinkedList* pBicicletas);
int loadFromText(char* path, LinkedList* pBicicletas);
void listarBicileta(LinkedList* lista, int index);
int mostrarBicicletas(LinkedList* pBicicletas);
int filtrarBmx( void* unaBicicleta);
int getRandomTiempo();
void* asignarTiempos(void* pElement);
int bicicleta_setCampos(LinkedList* lista);
void settearTiempos(void* element);
int guardarTexto(char* path, LinkedList* pArrayList);
int ordenarTipos(void* a, void* b);
int ordenarBicicletasTipoyTiempo(void * a, void* b);
int ordenarTiempo(void* a, void* b);






