#ifndef _avl_h_
#define _avl_h_

#include "headers.h"
#include "estruturas.h"

typedef struct avl* AVL;
typedef struct nodeAVL *NODO;

typedef void* Estrutura;
typedef char* Valor;

typedef void(*Funcao)(void*);

AVL initAVL();

AVL atualiza_avl(AVL tree, Valor value, Estrutura estrutura);

AVL avl_insert(AVL arvore, Valor key, Estrutura estrutura);

Boolean avl_lookUp(AVL tree, Valor value);

int avl_count(AVL tree);

AVL avl_clone(AVL node, AVL novo);

Estrutura avl_getEstrutura(AVL node, Valor value);

int avl_getTamanho(AVL tree);

NODO getNodo(AVL a);

NODO getNodoEsq(NODO n);

NODO getNodoDir(NODO n);

char* getString(NODO n);

void* getCont(NODO n);

void avl_free(AVL node, Funcao f);

void free_Nodo(NODO node);

void imprime_Conteudo_AVL(NODO tree);

void imprime_AVL_String(AVL tree);

#endif /* _avl_h_ */
