#include "headers.h"
#include "catalogo.h"

typedef struct catalogo_produtos *Produtos_Catalog;

typedef struct produto *Produto;

Produtos_Catalog init_produtos_catalog();

Produto cria_Produto();

Produto altera_Produto(Produto p, char* e);

Boolean existe_produto(Produtos_Catalog c, char *key);

Produtos_Catalog insere_produto(Produtos_Catalog cat, Produto p);

Produtos_Catalog insere_Produtos_Catalogo (Produtos_Catalog cat, Produto p, void* Estrutura);

void free_Produtos(Produtos_Catalog cat, Funcao f);

void imprime_Produtos(Produtos_Catalog cat);

char* getProdutoCode(Produto p);

Estrutura get_product_struct (Produtos_Catalog cat, Produto p);

Produtos_Catalog altera_Catalogo_Produtos(Produtos_Catalog cat , Produto p, void * Estrutura);

void free_p(Produto p);

/*--------------------------QUERIE2--------------------------*/

void percorre_Nodo_Produtos_Q2(NODO tree, Q2 q);
void percorre_AVL_Produtos_Q2(AVL tree, Q2 q);

void imprime_produtos_letra(Produtos_Catalog cat, char letra, Q2 q);
