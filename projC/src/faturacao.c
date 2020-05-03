/**
 * @file faturacao.c
 * @brief Ficheiro que contém a API relativa à implementação da faturação.
 */

#include "../include/faturacao.h"

struct catalogo_faturacao{
  Catalogo catalogo;
};

struct fat_info{
  /*Modo -> N = 0 & P = 1*/
  double fat[MODO][FILIAL][MESES]; /*Faturação por mes/filial/modo*/
  int qtd[MODO][FILIAL][MESES]; /*Quantidade por mes/filial/modo*/
  int n_vendas[MODO][FILIAL][MESES]; /*Quantidade total de vendas registadas por mes/filial/modo*/
  int qtd_total[FILIAL];
};

/**
 * @brief Função que cria um catálogo da faturação, inserindo informação no mesmo.
 * @param cat Faturacao_catalog Catálogo da faturação que vai ser criado e onde se vai inserir a informação.
 * @param p Produto a ser inserido.
 * @param mes int, utilizado na matriz tridimensional, onde vai ser inserida a informação.
 * @param filial int, utilizado na matriz tridimensional, onde vai ser inserida a informação.
 * @param modo char, que indica se a venda foi efetuada em regime normal ou promocional.
 * @param preco double, que vai ser inserido na faturação.
 * @param qtd int, que vai ser inserida na faturação.
 * @return novo catálogo da faturação criado.
 */
Faturacao_Catalog cria_Faturacao(Faturacao_Catalog cat, Produto p, int mes,int filial, char modo, double preco,int qtd){
  f_info f = init_Info_Faturacao();
  int m=0;
  if(modo == 'P') m=1;
  f->fat[m][filial-1][mes-1] += qtd * preco;
  f->qtd[m][filial-1][mes-1] += qtd;
  f->n_vendas[m][filial-1][mes-1]++;
  f->qtd_total[filial-1] += qtd;
  cat = insere_faturacao(cat,p,f);
  return cat;
}

/**
 * @brief Função que altera o catálogo da faturação.
 * @param cat Faturacao_catalog Catálogo da faturação que vai ser alterado e onde vão se vai inserir a nova informação.
 * @param p Produto a ser inserido.
 * @param mes int, utilizado na matriz tridimensional, onde vai ser alterada a informação.
 * @param filial int, utilizado na matriz tridimensional, onde vai ser alterada a informação.
 * @param modo char, que indica se a venda foi efetuada em regime normal ou promocional.
 * @param preco double, que vai ser inserido na faturação.
 * @param qtd int, que vai ser inserida na faturação.
 * @return novo catálogo da faturação alterado.
 */
Faturacao_Catalog altera_Faturacao(Faturacao_Catalog cat,Produto p,int mes,int filial, char modo, double preco,int qtd){
  char *aux = getProdutoCode(p);
  f_info f = get_Cat_struct(cat->catalogo,aux);
  if (f == NULL) f = init_Info_Faturacao();
  int m=0;
  if(modo == 'P') m=1;
  f->fat[m][filial-1][mes-1] += qtd * preco;
  f->qtd[m][filial-1][mes-1] += qtd;
  f->n_vendas[m][filial-1][mes-1]++;
  f->qtd_total[filial-1] += qtd;
  cat->catalogo = altera_Catalogo(cat->catalogo,aux,f);
  free(aux);
  return cat;
}

/**
 * @brief Função que devolve a estrutura associada a um produto de um catálogo que lhe é passado como argumento.
 * @param cat Faturacao_Catalog de onde será devolvida a estrutura.
 * @param p Produto indicando o produto a procurar onde estará associada a estrutura.
 * @return Estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_Fat_struct(Faturacao_Catalog cat, Produto p){
  char *aux = getProdutoCode(p);
  Estrutura a = get_Cat_struct(cat->catalogo,aux);
  free(aux);
  return a;
}

/**
 * @brief Função que inicializa a informação da faturação.
 * @return f_info inicializada.
 */
f_info init_Info_Faturacao(){
  f_info f = (f_info) malloc((sizeof(struct fat_info)));
  int i,j,k;
  for(i=0 ; i<MODO ; i++)
    for(j=0 ; j<FILIAL ; j++){
        f->qtd_total[j] = 0;
        for(k=0 ; k<MESES ; k++){
          f->fat[i][j][k] = 0;
          f->qtd[i][j][k] = 0;
          f->n_vendas[i][j][k] = 0;
        }
    }
  return f;
}

/**
 * @brief Função que inicializa o catálogo da faturação.
 * @return Faturacao_Catalog inicializado.
 */
Faturacao_Catalog init_faturacao_catalogo(){
  Faturacao_Catalog new = malloc(sizeof(struct catalogo_faturacao));
  new->catalogo = init_Catalogo();
  return new;
}

/**
 * @brief Função que verifica se existe, dado um produto, uma certa faturação a ele associada.
 * @param cat Faturacao_Catalog onde se procura.
 * @param p Produto utilizado como referência de procura.
 * @return Boolean com o resultado.
 */
Boolean existe_faturacao(Faturacao_Catalog cat, Produto p){
  char *aux = getProdutoCode(p);
  Boolean a = existe_Catalogo(cat->catalogo,aux);
  free(aux);
  return a;
}

/**
 * @brief Função que insere no produto de um catálogo uma estrutura.
 * @param cat Faturacao_Catalog onde se vai inserir.
 * @param p Produto onde se vai inserir.
 * @param estrutura void* a ser inserida.
 * @return Faturacao_Catalog com a estrutura inserida.
 */
Faturacao_Catalog insere_faturacao(Faturacao_Catalog cat,Produto p, void * estrutura){
  char *aux = getProdutoCode(p);
  cat->catalogo = insere_Catalogo(cat->catalogo,aux,estrutura);
  free(aux);
  return cat;
}

/**
 * @brief Função que liberta da memória o espaço ocupado por um catálogo da faturação.
 * @param cat Faturacao_Catalog a ser limpo da memória.
 */

void free_Faturacao(Faturacao_Catalog cat){
  free_Catalogo(cat->catalogo,free);
  free(cat);
}

/**
 * @brief Função que imprime a faturação.
 * @param cat Faturacao_Catalog onde se encontram os produtos a ser impressos.
 */
void imprime_Faturacao(Faturacao_Catalog cat){
  imprime_Catalogo(cat->catalogo);
}

/**
 * @brief Função que retorna a quantidade total de produtos por filial.
 * @param f f_info onde se acede à informação.
 * @param filial int da qual queremos obter a quantidade total.
 * @return int com a quantidade total.
 */
int getQtTotalFat(f_info f, int filial){
  int a = f->qtd_total[filial];
  return a;
}


/*----------------------------------QUERIE3----------------------------------*/

/**
 * @brief Função insere numa estrutura o número de vendas de um certo produto realizadas num dado mês.
 * @param f Faturacao_Catalog que é onde será consultada a informação do produto.
 * @param product char* que é o código do produto a avaliar.
 * @param month int que é o mês a investigar.
 * @param q Q3 que é a estrutura onde será inserida a informação.
 */
void get_NVendas_Mes_Faturacao(Faturacao_Catalog f, char* product, int month, Q3 q){
  int i,aux1=0,aux2=0;
  f_info fat = get_Cat_struct(f->catalogo,product);
  for(i=0;i<FILIAL;i++){
    aux1 += fat->n_vendas[0][i][month-1];
    aux2 += fat->n_vendas[1][i][month-1];
  }
  setQt_NQ3(aux1,q);
  setQt_PQ3(aux2,q);
}

/**
 * @brief Função insere numa estrutura o total faturado de um certo produto realizadas num dado mês.
 * @param f Faturacao_Catalog que é onde será consultada a informação do produto.
 * @param product char* que é o código do produto a avaliar.
 * @param month int que é o mês a investigar.
 * @param q Q3 que é a estrutura onde será inserida a informação.
 */
void get_Fat_Mes_Faturacao(Faturacao_Catalog f, char* product, int month, Q3 q){
  double aux1=0,aux2=0;
  f_info fat = get_Cat_struct(f->catalogo,product);
  int i;
  for(i=0;i<FILIAL;i++){
    aux1 += fat->fat[0][i][month-1];
    aux2 += fat->fat[1][i][month-1];
  }
  setFat_NQ3(aux1,q);
  setFat_PQ3(aux2,q);
}




/*----------------------------------QUERIE4----------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param q Q2 onde serão inseridos os códigos dos produtos.
 * @param aux int* que serve como contador recursivo do número de produtos que não foram comprados.
 */
void percorre_NODO_Fat_Q4(NODO tree, Q2 q, int *aux){
  if (tree == NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Fat_Q4(esq,q,aux);
  free_Nodo(esq);
  f_info f = (f_info) getCont(tree);
  char* prod = getString(tree);
  if(f==NULL){
    insere_ProdQ2(prod,q);
    (*aux)++;
  }
  free(prod);
  NODO dir;
  dir = getNodoDir(tree);
  percorre_NODO_Fat_Q4(dir,q,aux);
  free_Nodo(dir);

}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q2 onde serão inseridos os códigos dos produtos.
 * @param aux int* que serve como contador recursivo do número de produtos que não foram comprados.
 */
void percorre_AVL_Fat_Q4(AVL tree, Q2 q, int *aux){
  NODO f = getNodo(tree);
  percorre_NODO_Fat_Q4(f,q,aux);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o total e o código dos produtos que não foram comprados globalmente.
 * @param f Faturacao_catalog onde serão consultados os produtos.
 * @param q Q2 onde serão inseridas essas informações.
 */
void produtos_nao_comprados(Faturacao_Catalog f, Q2 q){
  int k,aux=0;
  AVL auxiliar;
  for(k=0;k<NR_LETRAS;k++){
    auxiliar = catalogo_getAVL(f->catalogo,k);
    percorre_AVL_Fat_Q4(auxiliar,q,&aux);
  }
  setNum_totalQ2(aux,q);
}

/*----------------------------------QUERIE6----------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param q Q6 onde serão inseridos os códigos dos produtos.
 * @param aux int* que serve como contador recursivo do número de produtos que não foram comprados.
 */
void percorre_NODO_Fat_Q6(NODO tree, Q6 q, int *aux){
  if (tree == NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Fat_Q6(esq,q,aux);
  free_Nodo(esq);

  NODO dir;
  dir = getNodoDir(tree);
  percorre_NODO_Fat_Q6(dir,q,aux);
  free_Nodo(dir);

  f_info f = (f_info) getCont(tree);
  if(f==NULL) (*aux)++;
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q6 onde serão inseridos os códigos dos produtos.
 * @param aux int* que serve como contador recursivo do número de produtos que não foram comprados.
 */
void percorre_AVL_Fat_Q6(AVL tree, Q6 q, int *aux){
  NODO f = getNodo(tree);
  percorre_NODO_Fat_Q6(f,q,aux);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o total de produtos que não foram comprados.
 * @param f Faturacao_catalog onde serão consultados os produtos.
 * @param q Q6 onde será inserido esse valor.
 */
void produtos_nao_comprados_num(Faturacao_Catalog f, Q6 q){
  int k,aux=0;
  AVL auxiliar;
  for(k=0;k<NR_LETRAS;k++){
    auxiliar = catalogo_getAVL(f->catalogo,k);
    percorre_AVL_Fat_Q6(auxiliar,q,&aux);
  }
  setNumProdsQ6(q,aux);
}

/*----------------------------------QUERIE8----------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param total int* que serve como contador recursivo do total de vendas realizadas.
 * @param q Q8 onde serão inseridos os códigos dos produtos.
 */
void percorre_NODO_NVendas_Q8(NODO tree,int m1, int m2, int *total, Q8 q) {
    int j, k, i;
    if (tree == NULL) return;
    NODO esq = getNodoEsq(tree);
    percorre_NODO_NVendas_Q8(esq, m1, m2, total,q);
    free_Nodo(esq);
    NODO dir;
    dir = getNodoDir(tree);
    percorre_NODO_NVendas_Q8(dir, m1, m2, total,q);
    free_Nodo(dir);
    f_info f = (f_info) getCont(tree);
    if (f == NULL) return;

    for (i = 0; i < MODO; i++) {
        for (j = 0; j < FILIAL; j++) {
            for (k = m1-1; k < m2; k++) {
                *total += f->n_vendas[i][j][k];
            }
        }
    }

}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param total int* que serve como contador recursivo do total de vendas realizadas.
 * @param q Q8 onde serão inseridos os códigos dos produtos.
 */
void percorre_AVL_NVendas_Q8(AVL auxiliar,int m1,int m2,int *total, Q8 q){
  NODO f = getNodo(auxiliar);
  percorre_NODO_NVendas_Q8(f,m1,m2,total,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o total de vendas registadas num intervalo de meses.
 * @param f Faturacao_catalog onde serão consultados os produtos.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param q Q8 onde serão inseridos os códigos dos produtos.
 */
void get_NVendas_Faturacao_EntreMeses(Faturacao_Catalog f, int m1, int m2, Q8 q){
  int k;
  int total=0;
  AVL auxiliar;
  for(k=0;k<NR_LETRAS;k++){
    auxiliar = catalogo_getAVL(f->catalogo,k);
    percorre_AVL_NVendas_Q8(auxiliar,m1,m2,&total,q);
  }
  setNVendas_Q8(total,q);
}


/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param total int* que serve como contador recursivo do total faturado.
 * @param q Q8 onde será inserido esse valor.
 */
void percorre_NODO_Fat_Q8(NODO tree,int m1, int m2, double *total, Q8 q){
  int i,j,k;
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Fat_Q8(esq,m1,m2,total,q);
  free_Nodo(esq);
  NODO dir;
  dir = getNodoDir(tree);
  percorre_NODO_Fat_Q8(dir,m1,m2,total,q);
  free_Nodo(dir);
  f_info f = (f_info) getCont(tree);
  if(f==NULL) return;

  for(i=0;i<MODO;i++){
    for(j=0;j<FILIAL;j++){
      for(k=m1-1;k<m2;k++){
        *total += f->fat[i][j][k];
      }
    }
  }
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param total int* que serve como contador recursivo do total faturado.
 * @param q Q8 onde serão inseridos os códigos dos produtos.
 */
void percorre_AVL_Fat_Q8(AVL auxiliar,int m1, int m2,double *total, Q8 q){
  NODO f = getNodo(auxiliar);
  percorre_NODO_Fat_Q8(f,m1,m2,total,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o total faturado num intervalo de meses.
 * @param f Faturacao_catalog onde serão consultados os produtos.
 * @param m1 int que é o limite inferior do intervalo de meses.
 * @param m2 int que é o limite superior do intervalo de meses
 * @param q Q8 onde será inserido esse valor.
 */
void get_Fat_Faturacao_EntreMeses(Faturacao_Catalog f, int m1, int m2, Q8 q){
  int k;
  double total=0;
  AVL auxiliar;
  for(k=0;k<NR_LETRAS;k++){
    auxiliar = catalogo_getAVL(f->catalogo,k);
    percorre_AVL_Fat_Q8(auxiliar,m1,m2,&total,q);
  }
  setFat_Q8(total,q);
}


/*----------------------------------QUERIE11----------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param q Q8 onde serão inseridas essas informações.
 */
void percorre_NODO_Fat_Q11(NODO tree, Q11 q){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Fat_Q11(esq,q);
  free_Nodo(esq);

  f_info aux = getCont(tree);
  char* produto;
  if(aux==NULL);
  else{
    produto = getString(tree);
    int i;
    int qt[FILIAL];
    for(i=0;i<FILIAL;i++){
      qt[i] = getQtTotalFat(aux,i);
    }
    insere_ProdInfoQ11(q,produto,qt);
    free(produto);
  }

  NODO dir = getNodoDir(tree);
  percorre_NODO_Fat_Q11(dir,q);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q8 onde serão inseridas essas informações.
 */
void percorre_AVL_Fat_Q11(AVL tree, Q11 q){
  NODO f = getNodo(tree);
  percorre_NODO_Fat_Q11(f,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o código dos produtos bem como a sua quantidade comprada.
 * @param f Faturacao_catalog onde serão consultados os produtos.
 * @param q Q11 onde serão inseridas essas informações.
 */
void produtosMaisCompradosQ11(Faturacao_Catalog f, Q11 q){
  int j;
  AVL auxiliar;
  for(j=0;j<NR_LETRAS;j++){
    auxiliar = catalogo_getAVL(f->catalogo,j);
    percorre_AVL_Fat_Q11(auxiliar,q);
  }
}
