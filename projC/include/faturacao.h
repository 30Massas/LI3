#include "avl.h"
#include "headers.h"
#include "catalogo.h"
#include "produtos.h"
#include "estruturas.h"

typedef struct fat_info *f_info;
typedef struct catalogo_faturacao *Faturacao_Catalog;


Faturacao_Catalog cria_Faturacao(Faturacao_Catalog cat, Produto p, int mes,int filial, char modo, double preco,int qtd);

f_info init_Info_Faturacao();
Faturacao_Catalog init_faturacao_catalogo();

Boolean existe_faturacao(Faturacao_Catalog cat, Produto p);

Faturacao_Catalog insere_faturacao(Faturacao_Catalog cat,Produto p, void * estrutura);

Faturacao_Catalog altera_Faturacao(Faturacao_Catalog cat,Produto p,int mes,int filial, char modo, double preco,int qtd);

void free_Faturacao(Faturacao_Catalog cat);

void imprime_Faturacao(Faturacao_Catalog cat);

Estrutura get_Fat_struct(Faturacao_Catalog cat, Produto p);

int getQtTotalFat(f_info f, int filial);
/*-----------------------------------QUERIE3-----------------------------------*/

void get_NVendas_Mes_Faturacao(Faturacao_Catalog f, char* product, int month, Q3 q);
void get_Fat_Mes_Faturacao(Faturacao_Catalog f, char* product, int month, Q3 q);

/*-----------------------------------QUERIE4-----------------------------------*/

void percorre_NODO_Fat_Q4(NODO tree, Q2 q, int *aux);
void percorre_AVL_Fat_Q4(AVL tree, Q2 q, int *aux);

void produtos_nao_comprados(Faturacao_Catalog f, Q2 q);

/*-----------------------------------QUERIE6-----------------------------------*/

void percorre_NODO_Fat_Q6(NODO tree, Q6 q, int *aux);
void percorre_AVL_Fat_Q6(AVL tree, Q6 q, int *aux);

void produtos_nao_comprados_num(Faturacao_Catalog f, Q6 q);

/*-----------------------------------QUERIE8-----------------------------------*/

void percorre_NODO_NVendas_Q8(NODO tree,int m1, int m2, int *total,Q8 q);
void percorre_AVL_NVendas_Q8(AVL auxiliar,int m1, int m2,int *total,Q8 q);

void get_NVendas_Faturacao_EntreMeses(Faturacao_Catalog f, int m1, int m2,Q8 q);


void percorre_NODO_Fat_Q8(NODO tree,int m1, int m2, double *total,Q8 q);
void percorre_AVL_Fat_Q8(AVL auxiliar,int m1, int m2,double *total,Q8 q);

void get_Fat_Faturacao_EntreMeses(Faturacao_Catalog f, int m1, int m2,Q8 q);


/*-----------------------------------QUERIE11-----------------------------------*/

void percorre_NODO_Fat_Q11(NODO tree, Q11 q);
void percorre_AVL_Fat_Q11(AVL tree, Q11 q);
void produtosMaisCompradosQ11(Faturacao_Catalog f, Q11 q);
