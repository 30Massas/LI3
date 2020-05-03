/*#ifndef _catalogo_h_*/
/*#define _catalogo_h_*/
#include "avl.h"
#include "headers.h"

typedef struct catalogo *Catalogo;

Catalogo init_Catalogo();

Boolean existe_Catalogo(Catalogo catalogo, char* key);

Estrutura get_Cat_struct(Catalogo c, char* key);

Catalogo insere_Catalogo(Catalogo c, char* key, void * estrutura);

Catalogo altera_Catalogo(Catalogo c, char* key, void* estrutura);

void free_Catalogo(Catalogo cat, Funcao f);

void imprime_Catalogo(Catalogo cat);

AVL catalogo_getAVL(Catalogo cat, int index);
