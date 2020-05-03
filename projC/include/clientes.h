/*#ifndef _clientes_h_*/
/*#define _clientes_h_*/
#include "catalogo.h"
#include "headers.h"

typedef struct catalogo_clientes *Clientes_Catalog;
typedef struct cliente *Cliente;

Cliente cria_Cliente();

void free_c(Cliente c);

Cliente altera_Cliente(Cliente c, char* e);

Boolean existe_cliente(Clientes_Catalog cat, char *key);

Clientes_Catalog init_clientes_catalog();

Clientes_Catalog insere_cliente(Clientes_Catalog cat, Cliente e);

Clientes_Catalog insere_Clientes_Catalogo (Clientes_Catalog cat, Cliente e, void* Estrutura);

void free_Clientes(Clientes_Catalog cat, Funcao f);

void imprime_Clientes(Clientes_Catalog cat);

char* getClienteCode(Cliente e);

Estrutura get_cliente_struct (Clientes_Catalog cat, Cliente c);

Clientes_Catalog altera_Catalogo_Clientes(Clientes_Catalog cat , Cliente e, void * Estrutura);