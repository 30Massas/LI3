/**
 * @file estruturas.c
 * @brief Ficheiro que contém a API relativa à implementação das estruturas.
 */

#include "../include/estruturas.h"

struct querie2{
    int num_total;
    char **lista_produtos;
};

/**
 * @brief Função que inicializa a estrutura Q2.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q2 init_Q2(int n){
    Q2 q = (Q2) malloc(sizeof(struct querie2));
    q->num_total = 0;
    q->lista_produtos = malloc(n * sizeof(char*));
    return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q2.
 * @param q Q2 que é estrutura a ser libertada.
 */
void freeQ2(Q2 q){
    if(q->lista_produtos){
        int i;
        for(i = 0; i< q->num_total; i++) free(q->lista_produtos[i]);
        free(q->lista_produtos);
    }
    free(q);
}

/**
 * @brief Função que devolve a lista de produtos presente na estrutura.
 * @param q Q2 que é estrutura onde se vai buscar a lista de strings.
 * @return char** que é a lista de strings presente na estrutura.
 */
char** getLista_ProdsQ2(Q2 q){
    return q->lista_produtos;
}

/**
 * @brief Função que devolve o número total de elementos em Q2.
 * @param q Q2 que é estrutura onde se vai buscar o número total de elementos.
 * @return int que é o número total de elementos.
 */
int getNum_TotalQ2(Q2 q){
    return q->num_total;
}

/**
 * @brief Função que estabelece a lista de produtos da estrutura Q2. Caso exista uma previamente, é libertada e substituída.
 * @param a char** que é nova lista da estrutura Q2.
 * @param q Q2 que é estrutura onde será estabelecida a lista de string.
 */
void setLista_ProdsQ2(char** a, Q2 q){
    if(q->lista_produtos){
        int i = 0;
        while (q->lista_produtos){
            free(q->lista_produtos[i++]);
        }
    }
    q->lista_produtos = a;
}

/**
 * @brief Função que fixa o número total de elementos dentro da estrutura.
 * @param n int que é o número total de elementos.
 * @param q Q2 que é estrutura onde será fixado o número total de elementos.
 */
void setNum_totalQ2(int n, Q2 q){
    q->num_total = n;
}

/**
 * @brief Função que insere na estrutura um código de produto.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param q Q2 que é estrutura onde será inserida a key dada.
 */
void insere_ProdQ2(char * key, Q2 q){
    q->lista_produtos[q->num_total] = malloc((strlen(key) +1) * sizeof(char));
    strcpy(q->lista_produtos[q->num_total++],key);
}

/**
 * @brief Função que retorna um produto numa dada posição.
 * @param i int que é a posição a procurar.
 * @param q Q2 que é estrutura onde será procurada a string na posição referida.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdQ2(Q2 q, int i){
    return (q->lista_produtos[i]);
}

/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE3---------------------------------*/

struct querie3{
  int qt_total_N, qt_total_P;
  double fat_total_N, fat_total_P;
};

/**
 * @brief Função que inicializa a estrutura Q3.
 * @return q que é a estrutura inicializada.
 */
Q3 init_Q3(){
    Q3 q = (Q3) malloc(sizeof(struct querie3));
    q->qt_total_N = 0;
    q->qt_total_P = 0;
    q->fat_total_N = 0;
    q->fat_total_P = 0;
    return q;
}

/**
 * @brief Função que retorna a quantidade total de vendas registas em modo Normal.
 * @param q Q3 que é a estrutura onde será procurado.
 * @return int que é o total de vendas registadas em modo normal.
 */
int getQt_NQ3(Q3 q){
    return q->qt_total_N;
}

/**
 * @brief Função que estabelece a quantidade total de vendas registas em modo Normal.
 * @param n int que é a quantidade total de vendas registadas.
 * @param q Q3 que é a estrutura onde será inserido.
 */
void setQt_NQ3(int n, Q3 q){
    q->qt_total_N = n;
}

/**
 * @brief Função que retorna a quantidade total de vendas registas em modo Promocional.
 * @param q Q3 que é a estrutura onde será procurado.
 * @return int que é o total de vendas registadas em modo promocional.
 */
int getQt_PQ3(Q3 q){
    return q->qt_total_P;
}

/**
 * @brief Função que estabelece a quantidade total de vendas registas em modo promocional.
 * @param n int que é a quantidade total de vendas registadas.
 * @param q Q3 que é a estrutura onde será inserido.
 */
void setQt_PQ3(int n, Q3 q){
    q->qt_total_P = n;
}

/**
 * @brief Função que retorna o total faturado em modo Normal.
 * @param q Q3 que é a estrutura onde será procurado.
 * @return double que é o total faturado em modo normal.
 */
double getFat_NQ3(Q3 q){
    return q->fat_total_N;
}

/**
 * @brief Função que estabelece o total faturado em modo normal.
 * @param n double que é o total faturado.
 * @param q Q3 que é a estrutura onde será inserido.
 */
void setFat_NQ3(double n, Q3 q){
    q->fat_total_N = n;
}

/**
 * @brief Função que retorna o total faturado em modo promocional.
 * @param q Q3 que é a estrutura onde será procurado.
 * @return double que é o total de vendas registadas em modo normal.
 */
double getFat_PQ3(Q3 q){
    return q->fat_total_P;
}

/**
 * @brief Função que estabelece o total faturado em modo promocional.
* @param n double que é o total faturado.
 * @param q Q3 que é a estrutura onde será inserido.
 */
void setFat_PQ3(double n, Q3 q){
    q->fat_total_P = n;
}


/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE4---------------------------------*/

                /*THIS QUERIE USES THE SAME STRUCT AS QUERIE2*/

/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE5---------------------------------*/

struct querie5{
  int num_total;
  char **lista_clientes;
};

/**
 * @brief Função que inicializa a estrutura Q5.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q5 init_Q5(int n){
  Q5 q = (Q5) malloc(sizeof(struct querie5));
  q->lista_clientes = malloc(n * sizeof(char*));
  q->num_total = 0;
  return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q5.
 * @param q Q5 que é estrutura a ser libertada.
 */
void freeQ5(Q5 q){
    if(q->lista_clientes){
        int i = 0;
        for(i=0; i<q->num_total;i++) free(q->lista_clientes[i]);
        free(q->lista_clientes);
    }
    free(q);
}

/**
 * @brief Função que devolve a lista de clientes presente na estrutura.
 * @param q Q5 que é estrutura onde se vai buscar a lista de strings.
 * @return char** que é a lista de strings presente na estrutura.
 */
char** getLista_ClientesQ5(Q5 q){
    return q->lista_clientes;
}

/**
 * @brief Função que estabelece a lista de clientes da estrutura Q5. Caso exista uma previamente, é libertada e substituída.
 * @param a char** que é nova lista da estrutura Q5.
 * @param q Q5 que é estrutura onde será estabelecida a lista de string.
 */
void setLista_ClientesQ5(char** a, Q5 q){
    if(q->lista_clientes){
        int i = 0;
        while (q->lista_clientes){
            free(q->lista_clientes[i++]);
        }
    }
    q->lista_clientes = a;
}

/**
 * @brief Função que insere na estrutura um código de cliente.
 * @param key char* que é o código do cliente a inserir na estrutura.
 * @param q Q5 que é estrutura onde será inserida a key dada.
 */
void insere_ClienteQ5(char * key, Q5 q){
    q->lista_clientes[q->num_total] = malloc((strlen(key) +1) * sizeof(char));
    strcpy(q->lista_clientes[q->num_total++],key);
}

/**
 * @brief Função que retorna um cliente numa dada posição.
 * @param q Q5 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getClienteQ5(Q5 q, int i){
    return (q->lista_clientes[i]);
}

/**
 * @brief Função que devolve o número total de elementos em Q5.
 * @param q Q5 que é estrutura onde se vai buscar o número total de elementos.
 * @return int que é o número total de elementos.
 */
int getNum_TotalQ5(Q5 q){
  return q->num_total;
}

/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE6---------------------------------*/

struct querie6{
  int nprodutos;
  int nclientes;
};

/**
 * @brief Função que inicializa a estrutura Q6.
 * @return q que é a estrutura inicializada.
 */
Q6 init_Q6(){
  Q6 q = (Q6) malloc(sizeof(struct querie6));
  q->nprodutos = 0;
  q->nclientes = 0;
  return q;
}

/**
 * @brief Função que retorna a quantidade de produtos.
 * @param q Q6 que é a estrutura onde será procurado.
 * @return int que é a quantidade de produtos.
 */
int getNumProdsQ6(Q6 q){
  return q->nprodutos;
}

/**
 * @brief Função que retorna a quantidade de clientes.
 * @param q Q6 que é a estrutura onde será procurado.
 * @return int que é a quantidade de clientes.
 */
int getNumClientessQ6(Q6 q){
  return q->nclientes;
}

/**
 * @brief Função que estabelece o número de produtos.
 * @param q Q6 que é a estrutura onde será inserido.
 * @param n int que é o número de produtos.
 */
void setNumProdsQ6(Q6 q, int n){
  q->nprodutos = n;
}

/**
 * @brief Função que estabelece o número de produtos.
 * @param q Q6 que é a estrutura onde será inserido.
 * @param n int que é o número de clientes.
 */
void setNumClientesQ6(Q6 q, int n){
  q->nclientes = n;
}

/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE7---------------------------------*/

struct querie7{
  int qtd_total[FILIAL][MESES];
};

/**
 * @brief Função que inicializa a estrutura Q7.
 * @return q que é a estrutura inicializada.
 */
Q7 init_Q7(){
  Q7 q = (Q7) malloc(sizeof(struct querie7));
  int i,j;
  for(i=0;i<FILIAL;i++){
    for(j=0;j<MESES;j++){
      q->qtd_total[i][j]=0;
    }
  }
  return q;
}

/**
 * @brief Função que retorna a quantidade total comprada numa dada filial, num dado mês.
 * @param q Q7 que é a estrutura onde será procurado.
 * @param i int que é a filial a averiguar.
 * @param j int que é o mês a averiguar.
 * @return int que é a quantidade total.
 */
int getQt_FilialQ7(Q7 q, int i, int j){
  return q->qtd_total[i][j];
}

/**
 * @brief Função que estabelece a quantidade total comprada numa dada filial, num dado mês.
 * @param q Q7 que é a estrutura onde será estabelecido.
 * @param n int que é a quantidade total.
 * @param i int que é a filial.
 * @param j int que é o mês.
 */
void setQt_FilialQ7(Q7 q, int n, int i, int j){
  q->qtd_total[i][j] = n;
}

/*-------------------------------------------------------------------------*/


/*---------------------------------QUERIE8---------------------------------*/

struct querie8{
  int nvendas_total;
  double fat_total;
};

/**
 * @brief Função que inicializa a estrutura Q8.
 * @return q que é a estrutura inicializada.
 */
Q8 init_Q8(){
    Q8 q = (Q8) malloc(sizeof(struct querie8));
    q->nvendas_total = 0;
    q->fat_total = 0;
    return q;
}

/**
 * @brief Função que retorna a quantidade total de vendas registadas.
 * @param q Q8 que é a estrutura onde será procurado.
 * @return int que é a quantidade de vendas registadas.
 */
int getNVendas_Q8(Q8 q){
    return q->nvendas_total;
}

/**
 * @brief Função que estabelece a quantidade total de vendas registadas.
 * @param n int que é a quantidade total.
 * @param q Q8 que é a estrutura onde será estabelecido.
 */
void setNVendas_Q8(int n, Q8 q){
    q->nvendas_total = n;
}

/**
 * @brief Função que retorna o total faturado.
 * @param q Q8 que é a estrutura onde será procurado.
 * @return double que é o total faturado.
 */
double getFat_Q8(Q8 q){
    return q->fat_total;
}

/**
 * @brief Função que estabelece o total faturado.
 * @param n double que é o total faturado.
 * @param q Q8 que é a estrutura onde será estabelecido.
 */
void setFat_Q8(double n, Q8 q){
    q->fat_total = n;
}

/*-------------------------------------------------------------------------*/

/*---------------------------------QUERIE9---------------------------------*/

struct querie9{
  int totalN;
  int totalP;
  char **lista_clientesN;
  char **lista_clientesP;
};

/**
 * @brief Função que inicializa a estrutura Q9.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q9 init_Q9(int n){
  Q9 q = (Q9) malloc(sizeof(struct querie9));
  q->totalN = 0;
  q->totalP = 0;
  q->lista_clientesN = malloc(n*sizeof(char*));
  q->lista_clientesP = malloc(n*sizeof(char*));
  return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q9.
 * @param q Q9 que é estrutura a ser libertada.
 */
void freeQ9(Q9 q){
  int i;
  for(i=0;i<q->totalN;i++){
    free(q->lista_clientesN[i]);
  }
  free(q->lista_clientesN);
  for(i=0;i<q->totalP;i++){
    free(q->lista_clientesP[i]);
  }
  free(q->lista_clientesP);
  free(q);
}

/**
 * @brief Função que retorna a quantidade total clientes que compraram em modo Normal.
 * @param q Q9 que é a estrutura onde será procurado.
 * @return int que é a quantidade de clientes.
 */
int getTotalNQ9(Q9 q){
  return q->totalN;
}

/**
 * @brief Função que estabelece a quantidade total clientes que compraram em modo Normal.
 * @param n int que é a quantidade total.
 * @param q Q9 que é a estrutura onde será estabelecido.
 */
void setTotalNQ9(Q9 q, int n){
  q->totalN = n;
}

/**
 * @brief Função que devolve a lista de produtos que foram comprados em modo Normal presente na estrutura.
 * @param q Q9 que é estrutura onde se vai buscar a lista de strings.
 * @return char** que é a lista de strings presente na estrutura.
 */
char** getLista_ProdsNQ9(Q9 q){
    return q->lista_clientesN;
}

/**
 * @brief Função que estabelece a lista de produtos comprados em modo Normal da estrutura Q9. Caso exista uma previamente, é libertada e substituída.
 * @param a char** que é nova lista da estrutura Q9.
 * @param q Q9 que é estrutura onde será estabelecida a lista de string.
 */
void setLista_ProdsNQ9(char** a, Q9 q){
    if(q->lista_clientesN){
        int i = 0;
        while (q->lista_clientesN){
            free(q->lista_clientesN[i++]);
        }
    }
    q->lista_clientesN = a;
}

/**
 * @brief Função que insere na estrutura um código produto comprado em modo Normal.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param q Q9 que é estrutura onde será inserida a key dada.
 */
void insere_ProdNQ9(char * key, Q9 q){
    q->lista_clientesN[q->totalN] = malloc((strlen(key) +1) * sizeof(char));
    strcpy(q->lista_clientesN[q->totalN++],key);
}

/**
 * @brief Função que retorna um produto comprado em modo Normal numa dada posição.
 * @param q Q9 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdNQ9(Q9 q, int i){
    return (q->lista_clientesN[i]);
}

/**
 * @brief Função que retorna a quantidade total clientes que compraram em modo Promocional.
 * @param q Q9 que é a estrutura onde será procurado.
 * @return int que é a quantidade de clientes.
 */
int getTotalPQ9(Q9 q){
  return q->totalP;
}

/**
 * @brief Função que estabelece a quantidade total clientes que compraram em modo Promocional.
 * @param n int que é a quantidade total.
 * @param q Q9 que é a estrutura onde será estabelecido.
 */
void setTotalPQ9(Q9 q, int n){
  q->totalP = n;
}

/**
 * @brief Função que devolve a lista de produtos que foram comprados em modo Promocional presente na estrutura.
 * @param q Q9 que é estrutura onde se vai buscar a lista de strings.
 * @return char** que é a lista de strings presente na estrutura.
 */
char** getLista_ProdsPQ9(Q9 q){
    return q->lista_clientesP;
}

/**
 * @brief Função que estabelece a lista de produtos comprados em modo Promocional da estrutura Q9. Caso exista uma previamente, é libertada e substituída.
 * @param a char** que é nova lista da estrutura Q9.
 * @param q Q9 que é estrutura onde será estabelecida a lista de string.
 */
void setLista_ProdsPQ9(char** a, Q9 q){
    if(q->lista_clientesP){
        int i = 0;
        while (q->lista_clientesP){
            free(q->lista_clientesP[i++]);
        }
    }
    q->lista_clientesP = a;
}

/**
 * @brief Função que insere na estrutura um código produto comprado em modo Promocional.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param q Q9 que é estrutura onde será inserida a key dada.
 */
void insere_ProdPQ9(char * key, Q9 q){
    q->lista_clientesP[q->totalP] = malloc((strlen(key) +1) * sizeof(char));
    strcpy(q->lista_clientesP[q->totalP++],key);
}

/**
 * @brief Função que retorna um produto comprado em modo Promocional numa dada posição.
 * @param q Q9 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdPQ9(Q9 q, int i){
    return (q->lista_clientesP[i]);
}

/*-------------------------------------------------------------------------*/

/*---------------------------------QUERIE10---------------------------------*/

typedef struct querie10aux{
  char* key;
  int quantidade;
}*Q10Aux;

struct querie10{
  int num_total;
  Q10Aux *ordenado;
};


/**
 * @brief Função que inicializa a estrutura Q10Aux.
 * @param p char* que indica o tamanho do espaço necessário alocar para a key.
 * @return q que é a estrutura inicializada.
 */
Q10Aux init_Q10Aux(char* p){
  Q10Aux qaux = (Q10Aux) malloc(sizeof(struct querie10aux));
  qaux->key = malloc((strlen(p)+1)*sizeof(char));
  qaux->quantidade = 0;
  return qaux;
}

/**
 * @brief Função que inicializa a estrutura Q10.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q10 init_Q10(int n){
  Q10 q = (Q10) malloc(sizeof(struct querie10));
  q->ordenado = malloc(n * sizeof(Q10Aux));
  q->num_total = 0;
  return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q10.
 * @param q Q10 que é estrutura a ser libertada.
 */
void freeQ10(Q10 q){
  if(q->ordenado){
    int i;
    for(i=0;i<q->num_total;i++){
      free(q->ordenado[i]->key);
      free(q->ordenado[i]);
    }
    free(q->ordenado);
  }
  free(q);
}

/**
 * @brief Função que estabelece a key e a quantidade de uma estrutura.
 * @param q Q10Aux que é estrutura onde serão inseridos estes parâmetros.
 * @param p char* que é o código do produto a ser inserido.
 * @param qtd int que é a quantidade total desse produto.
 */
void setQ10Aux(Q10Aux q, char* p, int qtd){
  strcpy(q->key,p);
  q->quantidade = qtd;
}

/**
 * @brief Função que insere na estrutura um código produto e a quantidade total comprada desse produto.
 * @param q Q10 que é estrutura onde será inserida a key dada.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param qtd int que é a quantidade comprada do produto.
 */
void insere_ProdInfoQ10(Q10 q, char* p , int qtd){
  int i;
  for(i=0;i<q->num_total;i++){
    if(strcmp(q->ordenado[i]->key,p) == 0){
      q->ordenado[i]->quantidade += qtd;
      return;
    }
  }
  q->ordenado[q->num_total] = init_Q10Aux(p);
  setQ10Aux(q->ordenado[q->num_total++],p,qtd);
}

/**
 * @brief Função que retorna o código de produto numa dada posição.
 * @param q Q10 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdutoQ10(Q10 q,int i){
  Q10Aux qaux = q->ordenado[i];
  return qaux->key;
}

/**
 * @brief Função que retorna a quantidade total comprada de um produto.
 * @param q Q10 que é a estrutura onde será procurado.
 * @param i int que é a posição do produto na lista.
 * @return int que é a quantidade total.
 */
int getQ10QtdProduto(Q10 q, int i){
  return q->ordenado[i]->quantidade;
}

/**
 * @brief Função que retorna o total de elementos na estrutura.
 * @param q Q10 que é a estrutura onde será procurado.
 * @return int que é a quantidade de clientes.
 */
int getNum_TotalQ10(Q10 q){
  return q->num_total;
}

/**
 * @brief Função que compara duas estruturas Q10Aux pela quantidade.
 * @param a const void* que é o primeiro elemento da comparação.
 * @param b const void* que é o segundo elemento da comparação.
 * @return int que é o resultado da comparação.
 */
int compare(const void * a, const void * b){
  Q10Aux a1 = *((Q10Aux *) a);
  Q10Aux b1 = *((Q10Aux *) b);
  return (b1->quantidade - a1->quantidade);
}

/**
 * @brief Função que ordena uma estrutura.
 * @param q Q10 que é a estrutura a ser ordenada.
 */
void sortAndGetQ10(Q10 q){
  qsort(q->ordenado,q->num_total,sizeof(q->ordenado[0]),compare);
}

/*-------------------------------------------------------------------------*/

/*---------------------------------QUERIE11---------------------------------*/

typedef struct querie11aux{
  char* key;
  int quantidade;
  int nclientes;
  int *nc;
  int *qtd;
}*Q11Aux;

struct querie11{
  Q11Aux *ordenado;
  int num_total;
};

/**
 * @brief Função que inicializa a estrutura Q11Aux.
 * @param p char* que indica o tamanho do espaço necessário alocar para a key.
 * @return q que é a estrutura inicializada.
 */
Q11Aux init_Q11Aux(char* p){
  Q11Aux qaux = (Q11Aux) malloc(sizeof(struct querie11aux));
  qaux->key = malloc((strlen(p)+1)*sizeof(char));
  qaux->quantidade = 0;
  qaux->nclientes = 0;
  qaux->nc = malloc(FILIAL * sizeof(int));
  qaux->qtd = malloc(FILIAL * sizeof(int));
  int i;
  for(i=0;i<FILIAL;i++){
    qaux->nc[i] = 0;
    qaux->qtd[i] = 0;
  }
  return qaux;
}

/**
 * @brief Função que inicializa a estrutura Q11.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q11 init_Q11(int n){
  Q11 q = (Q11) malloc(sizeof(struct querie11));
  q->ordenado = malloc(n* sizeof(Q11Aux));
  q->num_total = 0;
  return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q11.
 * @param q Q11 que é estrutura a ser libertada.
 */
void freeQ11(Q11 q){
  if(q->ordenado){
    int i;
    for(i=0;i<q->num_total;i++){
      free(q->ordenado[i]->key);
      free(q->ordenado[i]->nc);
      free(q->ordenado[i]->qtd);
      free(q->ordenado[i]);
    }
    free(q->ordenado);
  }
  free(q);
}

/**
 * @brief Função que estabelece a key e a quantidade, total e por filial, de uma estrutura.
 * @param q Q11Aux que é estrutura onde serão inseridos estes parâmetros.
 * @param p char* que é o código do produto a ser inserido.
 * @param qtd int[] que é o array com a quantidade total por filial desse produto.
 */
void setQ11Aux(Q11Aux q, char* p, int qt[]){
  strcpy(q->key,p);
  int i;
  for(i=0;i<FILIAL;i++){
    q->quantidade += qt[i];
    q->qtd[i] = qt[i];
  }
}

/**
 * @brief Função que insere na estrutura um código produto e a quantidade total comprada desse produto.
 * @param q Q11 que é estrutura onde será inserida a key dada.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param qtd int[] que é o array com a quantidade total por filial desse produto.
 */
void insere_ProdInfoQ11(Q11 q, char* p , int qt[]){
  q->ordenado[q->num_total] = init_Q11Aux(p);
  setQ11Aux(q->ordenado[q->num_total],p,qt);
  q->num_total++;
}

/**
 * @brief Função que retorna o código de produto numa dada posição.
 * @param q Q11 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdutoQ11(Q11 q,int i){
  return q->ordenado[i]->key;
}

/**
 * @brief Função que retorna a quantidade total comprada de um produto.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param i int que é a posição do produto na lista.
 * @return int que é a quantidade total.
 */
int getQ11QtdProduto(Q11 q, int i){
  return q->ordenado[i]->quantidade;
}

/**
 * @brief Função que retorna a quantidade total de clientes que compraram um produto.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param i int que é a posição do produto na lista.
 * @return int que é a quantidade total.
 */
int getQ11NClientes(Q11 q, int i){
  return q->ordenado[i]->nclientes;
}

/**
 * @brief Função que retorna a quantidade total de elementos numa estrutura.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param i int que é a posição do produto na lista.
 * @return int que é a quantidade total.
 */
int getNum_TotalQ11(Q11 q){
  return q->num_total;
}

/**
 * @brief Função que retorna a quantidade total comprada de um produto numa dada filial.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param pos int que é a posição do produto na lista.
 * @param filian int que é a filial a ser procurada.
 * @return int que é a quantidade total.
 */
int getQtdFilialQ11(Q11 q,int pos, int filial){
  return q->ordenado[pos]->qtd[filial];
}

/**
 * @brief Função que retorna a quantidade total de clientes que compraram um produto numa dada filial.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param pos int que é a posição do produto na lista.
 * @param filian int que é a filial a ser procurada.
 * @return int que é a quantidade total.
 */
int getNClientesFilialQ11(Q11 q, int pos, int filial){
  return q->ordenado[pos]->nc[filial];
}

/**
 * @brief Função que altera o total de clientes que comprou um certo produto, bem como por filial.
 * @param q Q11 que é a estrutura onde será procurado.
 * @param j int que é a posição do produto na lista.
 * @param nc int que é o número de clientes.
 * @param filian int que é a filial a ser procurada.
 * @return int que é a quantidade total.
 */
void alteraNClientesQ11(Q11 q, int j, int nc, int filial){
  q->ordenado[j]->nclientes += nc;
  q->ordenado[j]->nc[filial] = nc;
}

/**
 * @brief Função que compara duas estruturas Q11Aux pela quantidade.
 * @param a const void* que é o primeiro elemento da comparação.
 * @param b const void* que é o segundo elemento da comparação.
 * @return int que é o resultado da comparação.
 */
int compareQ11(const void * a, const void * b){
  Q11Aux a1 = *((Q11Aux *) a);
  Q11Aux b1 = *((Q11Aux *) b);
  return (b1->quantidade - a1->quantidade);
}

/**
 * @brief Função que ordena uma estrutura.
 * @param q Q11 que é a estrutura a ser ordenada.
 */
void sortAndGetQ11(Q11 q){
  qsort(q->ordenado,q->num_total,sizeof(q->ordenado[0]),compareQ11);
}


/*--------------------------------------------------------------------------*/

/*---------------------------------QUERIE12---------------------------------*/

typedef struct querie12aux{
  char* key;
  double fat;
}*Q12Aux;

struct querie12{
  int num_total;
  Q12Aux *ordenado;
};


/**
 * @brief Função que inicializa a estrutura Q12Aux.
 * @param p char* que indica o tamanho do espaço necessário alocar para a key.
 * @return q que é a estrutura inicializada.
 */
Q12Aux init_Q12Aux(char* p){
  Q12Aux qaux = (Q12Aux) malloc(sizeof(struct querie12aux));
  qaux->key = malloc((strlen(p)+1)*sizeof(char));
  qaux->fat = 0;
  return qaux;
}

/**
 * @brief Função que inicializa a estrutura Q12.
 * @param n int que contém o tamanho do espaço necessário alocar.
 * @return q que é a estrutura inicializada.
 */
Q12 init_Q12(int n){
  Q12 q = (Q12) malloc(sizeof(struct querie10));
  q->ordenado = malloc(n * sizeof(Q12Aux));
  q->num_total = 0;
  return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q12.
 * @param q Q12 que é estrutura a ser libertada.
 */
void freeQ12(Q12 q){
  if(q->ordenado){
    int i;
    for(i=0;i<q->num_total;i++){
      free(q->ordenado[i]->key);
      free(q->ordenado[i]);
    }
    free(q->ordenado);
  }
  free(q);
}

/**
 * @brief Função que estabelece a key e o total faturado de uma estrutura.
 * @param q Q12Aux que é estrutura onde serão inseridos estes parâmetros.
 * @param p char* que é o código do produto a ser inserido.
 * @param faturado double que é o total faturado desse produto.
 */
void setQ12Aux(Q12Aux q, char* p, double faturado){
  strcpy(q->key,p);
  q->fat = faturado;
}

/**
 * @brief Função que insere na estrutura um código produto e o total faturado desse produto.
 * @param q Q12 que é estrutura onde será inserida a key dada.
 * @param key char* que é o código do produto a inserir na estrutura.
 * @param faturado double que é o total faturado desse produto.
 */
void insere_ProdInfoQ12(Q12 q, char* p , double faturado){
  int i;
  for(i=0;i<q->num_total;i++){
    if(strcmp(q->ordenado[i]->key,p) == 0){
      q->ordenado[i]->fat += faturado;
      return;
    }
  }
  q->ordenado[q->num_total] = init_Q12Aux(p);
  setQ12Aux(q->ordenado[q->num_total++],p,faturado);
}

/**
 * @brief Função que retorna o código de produto numa dada posição.
 * @param q Q12 que é estrutura onde será procurada a string na posição referida.
 * @param i int que é a posição a procurar.
 * @return char* que é a string na posição dada da lista.
 */
char* getProdutoQ12(Q12 q,int i){
  Q12Aux qaux = q->ordenado[i];
  return qaux->key;
}

/**
 * @brief Função que retorna o total faturado de um dado produto.
 * @param q Q12 que é a estrutura onde será procurado.
 * @param i int que é a posição do produto na lista.
 * @return double que é o total faturado.
 */
double getQ12Faturado(Q12 q, int i){
  return q->ordenado[i]->fat;
}

/**
 * @brief Função que retorna a quantidade total de elementos na estrutura.
 * @param q Q12 que é a estrutura onde será procurado.
 * @return int que é a quantidade total.
 */
int getNum_TotalQ12(Q12 q){
  return q->num_total;
}

/**
 * @brief Função que compara duas estruturas Q12Aux pelo total faturado.
 * @param a const void* que é o primeiro elemento da comparação.
 * @param b const void* que é o segundo elemento da comparação.
 * @return int que é o resultado da comparação.
 */
int compareQ12(const void * a, const void * b){
  Q12Aux a1 = *((Q12Aux *) a);
  Q12Aux b1 = *((Q12Aux *) b);
  if(b1->fat > a1->fat) return 1;
  else if(b1->fat < a1->fat) return -1;
  else return 0;
}

/**
 * @brief Função que ordena uma estrutura.
 * @param q Q12 que é a estrutura a ser ordenada.
 */
void sortAndGetQ12(Q12 q){
  qsort(q->ordenado,q->num_total,sizeof(q->ordenado[0]),compareQ12);
}

/*---------------------------------QUERIE13---------------------------------*/

struct querie13{
    int q_clientes; /* Quantidade total de clientes*/
    int q_produtos; /* Quantidade total de produtos*/
    int vendas_validas; /* Quantidade total de vendas válidas*/
    int vendas_totais; /* Quantidade total de vendas lidas*/
    char *clients_File_Path; /* Diretoria do ficheiro que contém os clientes*/
    char *products_File_Path; /* Diretoria do ficheiro que contém os produtos*/
    char *sales_File_Path; /* Diretoria do ficheiro que contém as vendas*/
};

/**
 * @brief Função que inicializa a estrutura Q13.
 * @return q que é a estrutura inicializada.
 */
Q13 init_Q13(){
    Q13 q = malloc(sizeof(struct querie13));
    return q;
}

/**
 * @brief Função que liberta o espaço alocado por uma estrutura Q13.
 * @param q Q13 que é estrutura a ser libertada.
 */
void free_Q13(Q13 q){
    if(q){
        free(q->clients_File_Path);
        free(q->products_File_Path);
        free(q->sales_File_Path);
        free(q);
    }
}

/**
 * @brief Função que retorna a quantidade total de clientes.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return int que é a quantidade total.
 */
int getQ_Clientes13(Q13 q){
    return q->q_clientes;
}

/**
 * @brief Função que retorna a quantidade total de produtos.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return int que é a quantidade total.
 */
int getQ_Produtos13(Q13 q){
    return q->q_produtos;
}

/**
 * @brief Função que retorna a quantidade total de vendas válidas.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return int que é a quantidade total.
 */
int getV_Validas13(Q13 q){
    return q->vendas_validas;
}

/**
 * @brief Função que retorna a quantidade total de linhas de venda lidas.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return int que é a quantidade total.
 */
int getV_Totais13(Q13 q){
    return q->vendas_totais;
}

/**
 * @brief Função que retorna uma string com o caminho para o ficheiro de clientes.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return char* que é a a string com o caminho para o ficheiro.
 */
char* getClients_Path13(Q13 q){
    return q->clients_File_Path;
}

/**
 * @brief Função que retorna uma string com o caminho para o ficheiro de produtos.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return char* que é a a string com o caminho para o ficheiro.
 */
char* getProducts_Path13(Q13 q){
    return q->products_File_Path;
}

/**
 * @brief Função que retorna uma string com o caminho para o ficheiro de vendas.
 * @param q Q13 que é a estrutura onde será procurado.
 * @return char* que é a a string com o caminho para o ficheiro.
 */
char* getSales_Path13(Q13 q){
    return q->sales_File_Path;
}

/**
 * @brief Função que estabelece a quantidade total de clientes.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param n int que é a quantidade total.
 */
void setQ_Clientes13(Q13 q, int n){
    q->q_clientes = n;
}

/**
 * @brief Função que estabelece a quantidade total de produtos.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param n int que é a quantidade total.
 */
void setQ_Produtos13(Q13 q, int n){
    q->q_produtos = n;
}

/**
 * @brief Função que estabelece a quantidade total de vendas válidas.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param n int que é a quantidade total.
 */
void setV_Validas13(Q13 q, int n){
    q->vendas_validas = n;
}

/**
 * @brief Função que estabelece a quantidade total de linhas de venda lidas.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param n int que é a quantidade total.
 */
void setV_Totais13(Q13 q, int n){
    q->vendas_totais = n;
}

/**
 * @brief Função que estabelece a quantidade total de vendas válidas.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param file char* que é o caminho para o ficheiro dos clientes.
 */
void setClients_Path13(Q13 q, char *file){
    q->clients_File_Path = file;
}

/**
 * @brief Função que estabelece a quantidade total de vendas válidas.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param file char* que é o caminho para o ficheiro dos produtos.
 */
void setProducts_Path13(Q13 q, char *file){
    q->products_File_Path = file;
}

/**
 * @brief Função que estabelece a quantidade total de vendas válidas.
 * @param q Q13 que é a estrutura onde será estabelecido.
 * @param file char* que é o caminho para o ficheiro das vendas.
 */
void setSales_Path13(Q13 q, char *file){
    q->sales_File_Path = file;
}
/*-------------------------------------------------------------------------*/
