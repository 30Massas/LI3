/**
 * @file clientes.c
 * @brief Ficheiro que contém a API relativa à implementação dos clientes.
 */

#include "../include/clientes.h"

struct cliente {
  char *n_cliente;
};

struct catalogo_clientes {
  Catalogo catalogo;
};

/**
 * @brief Função que cria um novo cliente.
 * @return novo cliente nulo.
 */
Cliente cria_Cliente(){
    Cliente c = (Cliente) malloc(sizeof(struct cliente));
    c->n_cliente = NULL;
    return c;
}

/**
 * @brief Função que limpa da memória o espaço ocupado por um dado cliente.
 * @param c Cliente a limpar da memória.
 */
void free_c(Cliente c){
    if(c){
        if(c->n_cliente)
            free(c->n_cliente);
        free(c);
    }
}

/**
 * @brief Função que altera o código de um determinado cliente.
 * @param c Cliente que vai ser alterado.
 * @param e char* apontador para o novo código do cliente.
 * @return Cliente alterado.
 */
Cliente altera_Cliente(Cliente c, char* e){
    if(c->n_cliente){
        free(c->n_cliente);
    }
    c->n_cliente = malloc((strlen(e) + 1) * sizeof(char));
    strcpy(c->n_cliente,e);
    return c;
}

/**
 * @brief Função que inicia um novo catálogo de clientes.
 * @return Novo catalogo de clientes nulo.
 */
Clientes_Catalog init_clientes_catalog(){
    Clientes_Catalog new = malloc(sizeof(struct catalogo_clientes));
    new->catalogo = init_Catalogo();
    return new;
}

/**
 * @brief Função que verifica se existe um cliente.
 * @param cat Clientes_Catalog onde se vai procurar.
 * @param char *key a procurar.
 * @return Boolean com o resultado.
 */
Boolean existe_cliente(Clientes_Catalog cat, char *key){
    return existe_Catalogo(cat->catalogo,key);
}

/**
 * @brief Função que insere um cliente num catálogo.
 * @param cat Clientes_Catalog onde se vai inserir o cliente.
 * @param e Cliente a ser inserido no catálogo de clientes.
 * @return Clientes_Catalog com o cliente inserido.
 */
Clientes_Catalog insere_cliente(Clientes_Catalog cat, Cliente e){
    char *aux = getClienteCode(e);
    cat->catalogo = insere_Catalogo(cat->catalogo,aux,NULL);
    free(aux);
    return cat;
}

/**
 * @brief Função que insere no catálogo de clientes um cliente juntamente com uma estrutura.
 * @param cat CLientes_Catalog onde insere o cliente e a estrutura.
 * @param e Cliente a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return Clientes_Catalog com o cliente e a estrutura inseridos.
 */
Clientes_Catalog insere_Clientes_Catalogo (Clientes_Catalog cat, Cliente e, void* Estrutura) {
    char *aux = getClienteCode(e);
    cat->catalogo = insere_Catalogo(cat->catalogo,aux, Estrutura);
    free(aux);
    return cat;
}

/**
 * @brief Função com o objetivo de limpar da memória um dado catálogo de clientes.
 * @param cat Clientes_Catalog a limpar da memória.
 * @param f Funcao que liberta a memória da estrutura associada.
 */

void free_Clientes(Clientes_Catalog cat, Funcao f){
    free_Catalogo(cat->catalogo,f);
    free(cat);
}

/**
 * @brief Função que imprime os clientes do catálogo de clientes.
 * @param cat Clientes_Catalog onde estão os clientes.
 */
void imprime_Clientes(Clientes_Catalog cat){
    imprime_Catalogo(cat->catalogo);
}

/**
 * @brief Função que obtém o código do cliente.
 * @param e Cliente do qual se pretende obter o código.
 * return apontador para um char com o código do clientes
 */
char* getClienteCode(Cliente e){
  char *aux = malloc(sizeof(char)*(strlen(e->n_cliente)+1));
  strcpy(aux,e->n_cliente);
  return aux;
}

/**
 * @brief Função que devolve a estrutura associada a um catálogo e a um cliente que lhe são passados como argumento.
 * @param cat Clientes_Catalog de onde será devolvida a estrutura.
 * @param c Cliente que indica onde está a estrutura que se pretende obter.
 * @return void* com apontador para a estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_cliente_struct (Clientes_Catalog cat, Cliente c) {
    char *aux = getClienteCode(c);
    Estrutura a = get_Cat_struct (cat->catalogo, aux);
    free(aux);
    return a;
}

/**
 * @brief Função que altera no catálogo de clientes um cliente juntamente com a estrutura.
 * @param cat Clientes_Catalog onde se vai efetuar a alteração.
 * @param e Cliente que vai alterar o existente.
 * @param estrutura Conteúdo/Estrutura que vai alterar a existente.
 * @return Clientes_Catalog atualizado.
 */
Clientes_Catalog altera_Catalogo_Clientes(Clientes_Catalog cat , Cliente e, void * Estrutura){
  char *aux = getClienteCode(e);
  cat->catalogo = altera_Catalogo(cat->catalogo,aux,Estrutura);
  free(aux);
  return cat;
}