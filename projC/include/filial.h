#include "headers.h"
#include "produtos.h"
#include "clientes.h"
#include "catalogo.h"
#include "avl.h"
#include "estruturas.h"



/*Filial organizada por clientes*/
typedef struct filial_c *FILIAL_clientes;
typedef struct filial_cat_clientes *Filial_Catalogo_Clientes;
typedef struct filial_info_cliente *f_info_c;
typedef struct info_cliente *info_c;


FILIAL_clientes cria_Filial_Clientes(FILIAL_clientes f,Cliente c);

f_info_c altera_info_cliente(f_info_c f, Produto p, int mes, int qtd, double preco);

FILIAL_clientes altera_Filial_Cliente(FILIAL_clientes f, Cliente c, Produto p, int mes, int qtd, double preco, int filial);

info_c init_Info_Cliente();

f_info_c init_Filial_Info_Cliente();

Filial_Catalogo_Clientes init_Filial_Catalogo_Clientes();

FILIAL_clientes init_filial_clientes();

Filial_Catalogo_Clientes insere_info_cliente(Filial_Catalogo_Clientes cat, Cliente c, void * estrutura);

Estrutura get_Filial_Cliente_struct(Filial_Catalogo_Clientes f, Cliente c);

/*static void free_struct_filial_clientes(void *f);
static void free_struct_filial_clientes_info(void *f);*/
void free_Filial_Catalogo_Clientes(Filial_Catalogo_Clientes c);
void free_Filial_Clientes(FILIAL_clientes f);

Boolean existe_Cliente_Filial(FILIAL_clientes f, Cliente c, int filial);
void imprime_Filial_Clientes(FILIAL_clientes f, int filial);
Boolean cliente_Fez_Compras(f_info_c f);
Boolean cliente_comprou_todas_filiais(FILIAL_clientes f, char *key);

/*-----------------------------------------QUERIE5-----------------------------------------*/

void percorre_NODO_Filial_Q5(NODO tree, FILIAL_clientes f, Q5 q);
void percorre_AVL_Filial_Q5(AVL tree, FILIAL_clientes f, Q5 q);

void clientes_todas_filiais(FILIAL_clientes f, Q5 q);

/*-----------------------------------------QUERIE6-----------------------------------------*/

void percorre_NODO_Filial_Q6(NODO tree, int *aux);
void percorre_AVL_Filial_Q6(AVL tree, int *aux);

void produtos_nao_comprados_num_filial(FILIAL_clientes f,Q6 q);


/*-----------------------------------------QUERIE7-----------------------------------------*/

void quantidade_compras_cliente(FILIAL_clientes f,char* key,Q7 q);

/*-----------------------------------------QUERIE10-----------------------------------------*/

void percorre_NODO_Filial_Q10(NODO tree, Q10 q);
void percorre_AVL_Filial_Q10(AVL tree, Q10 q);

void produtos_favoritos_cliente(FILIAL_clientes f, char* cliente, int m, Q10 q);

/*-----------------------------------------QUERIE12-----------------------------------------*/

void percorre_NODO_Filial_Q12(NODO tree, Q12 q);
void percorre_AVL_Filial_Q12(AVL tree, Q12 q);

void produtosMaisCarosQ12(FILIAL_clientes f, char* cliente, Q12 q);

/*-----------------------------------------------------------------------------------------*/


/*Filial organizada por produtos*/
typedef struct filial_p *FILIAL_produtos;
typedef struct filial_cat_produtos *Filial_Catalogo_Produtos;
typedef struct filial_info_produtos *f_info_p;
typedef struct info_produto *info_p;



FILIAL_produtos cria_Filial_Produtos(FILIAL_produtos f, Produto p);


f_info_p altera_info_produto(f_info_p f, Cliente c, int mes, int qtd, double preco,char modo);
FILIAL_produtos altera_Filial_Produto(FILIAL_produtos f, Cliente c, Produto p, int mes, int qtd, double preco, int filial, char modo);


info_p init_Info_Produto(char modo);
f_info_p init_Filial_Info_Produto();
Filial_Catalogo_Produtos init_Filial_Catalogo_Produtos();
FILIAL_produtos init_filial_produtos();


Estrutura get_Filial_Produto_struct(Filial_Catalogo_Produtos f, Produto p);

Filial_Catalogo_Produtos insere_info_produto(Filial_Catalogo_Produtos cat, Produto p, void * estrutura);
Boolean existe_Produto_Filial(FILIAL_produtos f, Produto p, int filial);


/*static void free_struct_filial_produtos_info(void *f);
static void free_struct_filial_produtos(void *f);*/
void free_Filial_Catalogo_Produtos(Filial_Catalogo_Produtos c);
void free_Filial_Produtos(FILIAL_produtos f);

void imprime_Filial_Produtos(FILIAL_produtos f, int filial);

Boolean produto_Foi_Comprado(f_info_p f);

/*-----------------------------------------QUERIE4-----------------------------------------*/

void percorre_NODO_Filial_Q4(NODO tree, Q2 q, int *aux);
void percorre_AVL_Filial_Q4(AVL tree, Q2 q, int *aux);

void produtos_nao_comprados_filial(FILIAL_produtos f, int filial, Q2 q);

/*-----------------------------------------QUERIE9-----------------------------------------*/

void percorre_NODO_Filial_Q9(NODO tree, Q9 q, int *aux1, int *aux2);
void percorre_AVL_Filial_Q9(AVL tree, Q9 q, int *aux1, int *aux2);

void lista_produtos_comprados_filial(Q9 q,FILIAL_produtos f, char* key, int filial);

/*-----------------------------------------QUERIE11-----------------------------------------*/

void defineNClientes(FILIAL_produtos f, Q11 q, int limit);
