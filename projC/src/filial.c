/**
 * @file filial.c
 * @brief Ficheiro que contém a API relativa à implementação das filiais.
 */

#include "../include/filial.h"

/*FILIAL_clientes*/
struct filial_c{
  Filial_Catalogo_Clientes f_clientes[FILIAL];
};

/*Filial_Catalogo_Clientes*/
struct filial_cat_clientes{
  Catalogo catalogo;
};

/*f_info_c*/
struct filial_info_cliente{
  AVL produtos_comprados[MESES];
  int qtd_total_compras[MESES];
};

/*info_c*/
struct info_cliente{
  int qtd;
  double faturacao;
};


/*------------------------------------------------------------CLIENTES------------------------------------------------------------*/

/**
 * @brief Função que cria uma filial de clientes, inserindo informação na mesma.
 * @param f FILIAL_clientes que vai ser criada e onde se vai inserir a informação.
 * @param c Cliente, que vai ser inserido.
 * @return nova FILIAL_clientes criada.
 */
FILIAL_clientes cria_Filial_Clientes(FILIAL_clientes f, Cliente c){
  int i;
  Filial_Catalogo_Clientes cat;
  for(i= 0; i < FILIAL; i++){
    cat = f->f_clientes[i];
    cat = insere_info_cliente(cat,c,NULL);
  }
  return f;
}

/**
 * @brief Função que altera a informação de um cliente.
 * @param f f_info_c que vai ser alterado e onde se vai inserir a nova informação.
 * @param p Produto a ser inserido.
 * @param mes int onde vai ser alterada a informação.
 * @param preco double, que vai ser inserido na informação do cliente.
 * @param qtd int, que vai ser inserida na informação do cliente.
 * @return novo f_info_c alterado.
 */
f_info_c altera_info_cliente(f_info_c f, Produto p, int mes, int qtd, double preco){
  char *aux = getProdutoCode(p);
  info_c new = avl_getEstrutura(f->produtos_comprados[mes-1],aux);
  if (new==NULL) new = init_Info_Cliente();
  new->qtd += qtd;
  new->faturacao += qtd*preco;
  f->qtd_total_compras[mes-1] += qtd;
  f->produtos_comprados[mes-1] = avl_insert(f->produtos_comprados[mes-1],aux,new);
  free(aux);
  return f;
}

/**
 * @brief Função que altera a informação de uma filial de clientes.
 * @param f FILIAL_clientes que vai ser alterada e onde se vai inserir a nova informação.
 * @param c Cliente que vai ser alterado.
 * @param p Produto a ser inserido.
 * @param mes int onde vai ser alterada a informação.
 * @param qtd int, que vai ser inserida na informação do cliente.
 * @param preco double, que vai ser inserido na informação do cliente.
 * @return nova FILIAL_clientes alterada.
 */
FILIAL_clientes altera_Filial_Cliente(FILIAL_clientes f, Cliente c, Produto p, int mes, int qtd, double preco, int filial){
  char *aux = getClienteCode(c);
  Filial_Catalogo_Clientes cat = f->f_clientes[filial-1];
  f_info_c cliente_info = get_Filial_Cliente_struct(cat,c);
  if (cliente_info == NULL) cliente_info = init_Filial_Info_Cliente();
  cliente_info = altera_info_cliente(cliente_info,p,mes,qtd,preco);
  cat->catalogo = altera_Catalogo(cat->catalogo,aux,cliente_info);
  free(aux);
  return f;
}

/**
 * @brief Função que inicializa a informação de um produto do cliente.
 * @return info_c inicializada.
 */
info_c init_Info_Cliente(){
  info_c new = (info_c) malloc(sizeof(struct info_cliente));
  new->qtd = 0;
  new->faturacao = 0;
  return new;
}

/**
 * @brief Função que inicializa a informação de todos os produtos comprados pelo cliente.
 * @return f_info_c inicializada.
 */
f_info_c init_Filial_Info_Cliente(){
  f_info_c new = (f_info_c) malloc(sizeof(struct filial_info_cliente));
  int i;
  for(i=0; i<MESES; i++){
    new->produtos_comprados[i] = initAVL();
    new->qtd_total_compras[i] = 0;
  }
  return new;
}

/**
 * @brief Função que inicializa o catálogo da filial de clientes.
 * @return Filial_Catalogo_Clientes inicializada.
 */
Filial_Catalogo_Clientes init_Filial_Catalogo_Clientes(){
  Filial_Catalogo_Clientes new = (Filial_Catalogo_Clientes) malloc (sizeof(struct filial_cat_clientes));
  new->catalogo = init_Catalogo();
  return new;
}

/**
 * @brief Função que inicializa a informação das filiais dos clientes.
 * @return FILIAL_clientes inicializada.
 */
FILIAL_clientes init_filial_clientes(){
  FILIAL_clientes new = malloc(sizeof(struct filial_c));
  int i;
  for(i=0; i<FILIAL;i++){
    new->f_clientes[i] = init_Filial_Catalogo_Clientes();
  }
  return new;
}

/**
 * @brief Função que insere num cliente de um catálogo uma estrutura.
 * @param cat Filial_Catalogo_Clientes onde vai ser inserida a informação.
 * @param c Cliente onde vai ser inserido.
 * @param estrutura *void a ser inserida
 * @return Filial_Catalogo_Clientes com a estrutura inserida.
 */
Filial_Catalogo_Clientes insere_info_cliente(Filial_Catalogo_Clientes cat, Cliente c, void * estrutura){
  char *aux = getClienteCode(c);
  cat->catalogo = insere_Catalogo(cat->catalogo,aux,estrutura);
  free(aux);
  return cat;
}

/**
 * @brief Função que devolve a estrutura associada a um cliente de um catálogo que lhe é passado como argumento.
 * @param f Filial_Catalogo_Clientes de onde será devolvida a estrutura.
 * @param c Cliente indicando o cliente a procurar onde estará associada a estrutura.
 * @return Estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_Filial_Cliente_struct(Filial_Catalogo_Clientes f, Cliente c){
  char *aux = getClienteCode(c);
  Estrutura a = get_Cat_struct(f->catalogo,aux);
  free(aux);
  return a;
}

/**
 * @brief Função que liberta da memória o espaço ocupado pela informação de um produto comprado pelo cliente.
 * @param f void* a ser limpo da memória.
 */
static void free_struct_filial_clientes_info(void *f){
  info_c aux = (info_c) f;
  free(aux);
}

/**
 * @brief Função que liberta da memória o espaço ocupado pela informação dos produtos comprados pelo cliente.
 * @param f void* a ser limpo da memória.
 */
static void free_struct_filial_clientes(void *f){
  f_info_c aux = (f_info_c) f;
  int i;
  for(i =0; i<MESES ; i++){
    avl_free(aux->produtos_comprados[i],free_struct_filial_clientes_info);
  }
  free(aux);
}

/**
 * @brief Função que liberta da memória o espaço ocupado pelo catálogo das filiais dos clientes.
 * @param c Filial_Catalogo_Clientes a ser limpo da memória.
 */
void free_Filial_Catalogo_Clientes(Filial_Catalogo_Clientes c){
  Filial_Catalogo_Clientes aux = (Filial_Catalogo_Clientes) c;
  free_Catalogo(aux->catalogo,free_struct_filial_clientes);
  free(aux);
}

/**
 * @brief Função que liberta da memória o espaço ocupado pelo array que contém a informação de cada filial de clientes.
 * @param f FILIAL_clientes a ser limpo da memória.
 */
void free_Filial_Clientes(FILIAL_clientes f){
  int i;
  for(i = 0; i<FILIAL; i++) free_Filial_Catalogo_Clientes(f->f_clientes[i]);
  free(f);
}

/**
 * @brief Função que verifica se existe um determinado cliente numa filial.
 * @param f FILIAL_clientes onde se vai procurar.
 * @param c Cliente a ser procurado.
 * @param filial int onde se vai procurar.
 * @return Boolean com o resultado.
 */
Boolean existe_Cliente_Filial(FILIAL_clientes f, Cliente c, int filial){
  char *aux = getClienteCode(c);
  Filial_Catalogo_Clientes cat = f->f_clientes[filial-1];
  Boolean a = existe_Catalogo(cat->catalogo,aux);
  free(aux);
  return a;
}

/**
 * @brief Função que imprime uma filial de clientes.
 * @param f FILIAL_clientes de onde se vai imprimir uma das filiais.
 * @param filial int que vai ser impressa.
 */
void imprime_Filial_Clientes(FILIAL_clientes f, int filial){
  Filial_Catalogo_Clientes cat = f->f_clientes[filial-1];
  imprime_Catalogo(cat->catalogo);
}

/**
 * @brief Função que verifica se um cliente efetuou compras.
 * @param f f_info_c onde se vai verificar.
 * @return Boolean com o resultado.
 */
Boolean cliente_Fez_Compras(f_info_c f){
  if(f==NULL) return 0;
  return 1;
}

/**
 * @brief Função que verifica se um cliente comprou em todas as filiais.
 * @param f FILIAL_clientes onde se vai procurar.
 * @param key char* que serve de referência para procurar o cliente pretendido.
 * @return Boolean com o resultado.
 */
Boolean cliente_comprou_todas_filiais(FILIAL_clientes f, char *key){
    int i,counter=0;
    Filial_Catalogo_Clientes fc;
    f_info_c infoc;
    for(i=0;i<FILIAL;i++){
      fc = f->f_clientes[i];
      infoc = get_Cat_struct(fc->catalogo,key);
      if(infoc != NULL) counter++;
    }
    if(counter == 3) return 1;
    return 0;
}

/*------------------------------------------------------------QUERIE5------------------------------------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrida.
 * @param f FILIAL_clientes onde serão consultados os clientes.
 * @param q Q5 onde serão inseridos os códigos dos clientes.
 */
void percorre_NODO_Filial_Q5(NODO tree, FILIAL_clientes f, Q5 q){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q5(esq,f,q);
  free_Nodo(esq);

  char *cliente = getString(tree);
  if(cliente_comprou_todas_filiais(f,cliente)){
    insere_ClienteQ5(cliente,q);
  }
  free(cliente);

  NODO dir = getNodoDir(tree);
  percorre_NODO_Filial_Q5(dir,f,q);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param f FILIAL_clientes onde serão consultados os clientes.
 * @param q Q5 onde serão inseridos os códigos dos clientes.
 */
void percorre_AVL_Filial_Q5(AVL tree, FILIAL_clientes f, Q5 q){
  NODO aux = getNodo(tree);
  percorre_NODO_Filial_Q5(aux,f,q);
  free_Nodo(aux);
}

/**
 * @brief Função que insere numa estrutura os clientes que compraram em todas as filiais.
 * @param f FILIAL_clientes onde serão consultados os clientes.
 * @param q Q5 onde serão inseridos os códigos dos clientes.
 */
void clientes_todas_filiais(FILIAL_clientes f, Q5 q){
  Filial_Catalogo_Clientes fc;
  AVL auxiliar;
  int j;
  fc = f->f_clientes[0];
  for(j=0;j<NR_LETRAS;j++){
    auxiliar = catalogo_getAVL(fc->catalogo,j);
    percorre_AVL_Filial_Q5(auxiliar,f,q);
  }
}


/*------------------------------------------------------------QUERIE6------------------------------------------------------------*/

/**
 * @brief Função que percorre os nodos da AVL.
 * @param tree NODO que será percorrido.
 * @param aux int* que será o contador recursivo dos clientes que nao fizeram compras em nenhuma filial.
 */
void percorre_NODO_Filial_Q6(NODO tree, int *aux){
  if (tree == NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q6(esq,aux);
  free_Nodo(esq);

  f_info_c f = (f_info_c) getCont(tree);
  if(!cliente_Fez_Compras(f)){
    (*aux)++;
  }
  NODO dir;
  dir = getNodoDir(tree);
  percorre_NODO_Filial_Q6(dir,aux);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param aux int* que será o contador recursivo dos clientes que nao fizeram compras em nenhuma filial.
 */
void percorre_AVL_Filial_Q6(AVL tree, int *aux){
  NODO f = getNodo(tree);
  percorre_NODO_Filial_Q6(f,aux);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura a quantidade de clientes que não compraram em nenhuma filial.
 * @param f FILIAL_clientes onde serão consultados os clientes.
 * @param q Q6 onde será inserida a quantidade.
 */
void produtos_nao_comprados_num_filial(FILIAL_clientes f,Q6 q){
  int i,j,aux=0;
  Filial_Catalogo_Clientes fc;
  AVL auxiliar;
  for(i=0; i < FILIAL; i++){
    fc = f->f_clientes[i];
    for(j=0;j<NR_LETRAS;j++){
      auxiliar = catalogo_getAVL(fc->catalogo,j);
      percorre_AVL_Filial_Q6(auxiliar,&aux);
    }
  }
  setNumClientesQ6(q,aux);
}

/*------------------------------------------------------------QUERIE7------------------------------------------------------------*/

/**
 * @brief Função que insere numa estrutura a quantidade de compras que um dado cliente fez em cada filial, por mês.
 * @param f FILIAL_clientes onde será consultada a informação do cliente.
 * @param key char* código do cliente.
 * @param q Q7 onde será inserida a quantidade por filial, por mês.
 */
void quantidade_compras_cliente(FILIAL_clientes f,char* key,Q7 q){
  int i,j;
  Filial_Catalogo_Clientes fc;
  f_info_c auxiliar;
  for(i=0; i < FILIAL; i++){
    fc = f->f_clientes[i];
    auxiliar = get_Cat_struct(fc->catalogo,key);
    if(auxiliar != NULL)
      for(j=0;j<MESES;j++){
        setQt_FilialQ7(q,auxiliar->qtd_total_compras[j],i,j);
      }
  }
}

/*------------------------------------------------------------QUERIE10------------------------------------------------------------*/

/**
 * @brief Função que percorre os nodos de uma AVL.
 * @param tree NODO que será percorrido.
 * @param q Q10 que é a estrutura onde será inserida a informação.
 */
void percorre_NODO_Filial_Q10(NODO tree, Q10 q){
  if(tree == NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q10(esq,q);
  free_Nodo(esq);

  char* prod = getString(tree);
  info_c f = getCont(tree);
  insere_ProdInfoQ10(q,prod,f->qtd);
  free(prod);

  NODO dir = getNodoDir(tree);
  percorre_NODO_Filial_Q10(dir,q);
  free_Nodo(dir);

}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q10 que é a estrutura onde será inserida a informação.
 */
void percorre_AVL_Filial_Q10(AVL tree, Q10 q){
  NODO f = getNodo(tree);
  percorre_NODO_Filial_Q10(f,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o código e a quantidade dos produtos que um certo cliente comprou.
 * @param f FILIAL_clientes onde será consultada a informação do cliente.
 * @param cliente char* que é o código de cliente.
 * @param q Q10 onde será inserida a informação.
 */
void produtos_favoritos_cliente(FILIAL_clientes f, char* cliente, int m, Q10 q){
  Filial_Catalogo_Clientes fc;
  f_info_c aux;
  AVL aux2;
  int i;
  for(i=0;i<FILIAL;i++){
    fc = f->f_clientes[i];
    aux = get_Cat_struct(fc->catalogo,cliente);
    aux2 = aux->produtos_comprados[m-1];
    percorre_AVL_Filial_Q10(aux2,q);
  }
}

/*------------------------------------------------------------QUERIE12------------------------------------------------------------*/


/**
 * @brief Função que percorre os nodos de uma AVL.
 * @param tree NODO que será percorrido.
 * @param q Q12 que é a estrutura onde será inserida a informação.
 */
void percorre_NODO_Filial_Q12(NODO tree, Q12 q){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q12(esq,q);
  free_Nodo(esq);

  info_c aux = getCont(tree);
  char* prod = getString(tree);
  insere_ProdInfoQ12(q,prod,aux->faturacao);
  free(prod);

  NODO dir = getNodoDir(tree);
  percorre_NODO_Filial_Q12(dir,q);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q12 que é a estrutura onde será inserida a informação.
 */
void percorre_AVL_Filial_Q12(AVL tree, Q12 q){
  NODO f = getNodo(tree);
  percorre_NODO_Filial_Q12(f,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o código e o total faturado dos produtos que um certo cliente comprou.
 * @param f FILIAL_clientes onde será consultada a informação do cliente.
 * @param cliente char* que é o código de cliente.
 * @param q Q12 onde será inserida a informação.
 */
void produtosMaisCarosQ12(FILIAL_clientes f, char* cliente, Q12 q){
  int i,k;
  Filial_Catalogo_Clientes fc;
  f_info_c aux;
  for(i=0;i<FILIAL;i++){
    fc = f->f_clientes[i];
    aux = get_Cat_struct(fc->catalogo,cliente);
    if(aux!=NULL)
      for(k=0;k<MESES;k++)
        percorre_AVL_Filial_Q12(aux->produtos_comprados[k],q);
  }
}

/*------------------------------------------------------------PRODUTOS------------------------------------------------------------*/



/*FILIAL_produtos*/
struct filial_p{
  Filial_Catalogo_Produtos f_produtos[FILIAL];
};

/*Filial_Catalogo_Produtos*/
struct filial_cat_produtos{
  Catalogo catalogo;
};

/*f_info_p*/
struct filial_info_produtos{
  AVL clientes_compradores[MESES];
  int qtd_total_comprada[MESES];
  double faturacao_total_mes[MESES];
};

/*info_p*/
struct info_produto{
  int tipo_compra; /* 'N' = 0 & 'P = 1' & 'N+P' = 2*/
};


/**
 * @brief Função que cria uma filial de produtos, inserindo informação na mesma.
 * @param f FILIAL_produtos que vai ser criada e onde se vai inserir a informação.
 * @param p Produto, que vai ser inserido.
 * @return nova FILIAL_produtos criada.
 */
FILIAL_produtos cria_Filial_Produtos(FILIAL_produtos f, Produto p){
  int i;
  Filial_Catalogo_Produtos cat;
  for(i = 0; i < FILIAL; i++){
    cat = f->f_produtos[i];
    cat = insere_info_produto(cat,p,NULL);
  }
  return f;
}

/**
 * @brief Função que altera a informação de um produto.
 * @param f f_info_p que vai ser alterado e onde se vai inserir a nova informação.
 * @param c Client a ser inserido.
 * @param mes int onde vai ser alterada a informação.
 * @param qtd int, que vai ser inserida na informação do cliente.
 * @param preco double, que vai ser inserido na informação do produto.
 * @param qtd int, que vai ser inserida na informação do produto.
 * @return novo f_info_p alterado.
 */
f_info_p altera_info_produto(f_info_p f, Cliente c, int mes, int qtd, double preco,char modo){
  char *aux = getClienteCode(c);
  info_p new = avl_getEstrutura(f->clientes_compradores[mes-1],aux);
  if (new==NULL) new = init_Info_Produto(modo);
  else{
    if( (new->tipo_compra == 0 && modo == 'P') || (new->tipo_compra == 1 && modo == 'N')) new->tipo_compra = 2;
    else if(modo == 'N') new->tipo_compra = 0;
    else new->tipo_compra = 1;
  }
  f->qtd_total_comprada[mes-1] += qtd;
  f->faturacao_total_mes[mes-1] += qtd*preco;
  f->clientes_compradores[mes-1] = avl_insert(f->clientes_compradores[mes-1],aux,new);
  free(aux);
  return f;
}

/**
 * @brief Função que altera a informação de uma filial de produtos.
 * @param f FILIAL_produtos que vai ser alterada e onde se vai inserir a nova informação.
 * @param p Produto que vai ser alterado.
 * @param c Cliente a ser inserido.
 * @param mes int onde vai ser alterada a informação.
 * @param qtd int, que vai ser inserida na informação do produto.
 * @param preco double, que vai ser inserido na informação do produto.
 * @return nova FILIAL_produtos alterada.
 */
FILIAL_produtos altera_Filial_Produto(FILIAL_produtos f, Cliente c, Produto p, int mes, int qtd, double preco, int filial, char modo){
  char* aux = getProdutoCode(p);
  Filial_Catalogo_Produtos cat = f->f_produtos[filial-1];
  f_info_p product_info = get_Filial_Produto_struct(cat,p);
  if(product_info == NULL) product_info = init_Filial_Info_Produto();
  product_info = altera_info_produto(product_info,c,mes,qtd,preco,modo);
  cat->catalogo = altera_Catalogo(cat->catalogo,aux,product_info);
  free(aux);
  return f;
}

/**
 * @brief Função que inicializa o tipo de compra de um produto.
 * @return info_p inicializada.
 */
info_p init_Info_Produto(char modo){
  info_p new = (info_p) malloc(sizeof(struct info_produto));
  if(modo == 'N') new->tipo_compra = 0;
  else new->tipo_compra = 1;
  return new;
}

/**
 * @brief Função que inicializa a informação de um produto.
 * @return f_info_p inicializada.
 */
f_info_p init_Filial_Info_Produto(){
  f_info_p new = (f_info_p) malloc(sizeof(struct filial_info_produtos));
  int i;
  for(i=0; i<MESES; i++){
    new->clientes_compradores[i] = initAVL();
    new->qtd_total_comprada[i] = 0;
    new->faturacao_total_mes[i] = 0;
  }
  return new;
}

/**
 * @brief Função que inicializa o catálogo da filial de produtos.
 * @return Filial_Catalogo_Produtos inicializada.
 */
Filial_Catalogo_Produtos init_Filial_Catalogo_Produtos(){
  Filial_Catalogo_Produtos new = (Filial_Catalogo_Produtos) malloc (sizeof(struct filial_cat_produtos));
  new->catalogo = init_Catalogo();
  return new;
}

/**
 * @brief Função que inicializa a informação das filiais dos produtos.
 * @return FILIAL_produtos inicializada.
 */
FILIAL_produtos init_filial_produtos(){
  FILIAL_produtos new = malloc(sizeof(struct filial_p));
  int i;
  for(i=0; i<FILIAL;i++){
    new->f_produtos[i] = init_Filial_Catalogo_Produtos();
  }
  return new;
}

/**
 * @brief Função que devolve a estrutura associada a um produto de um catálogo que lhe é passado como argumento.
 * @param f Filial_Catalogo_Produtos de onde será devolvida a estrutura.
 * @param p Produto indicando o produto a procurar onde estará associada a estrutura.
 * @return Estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_Filial_Produto_struct(Filial_Catalogo_Produtos f, Produto p){
  char* aux = getProdutoCode(p);
  Estrutura a = get_Cat_struct(f->catalogo,aux);
  free(aux);
  return a;
}

/**
 * @brief Função que insere num produto de um catálogo uma estrutura.
 * @param cat Filial_Catalogo_Produtos onde vai ser inserida a informação.
 * @param p Produto onde vai ser inserido.
 * @param estrutura *void a ser inserida
 * @return Filial_Catalogo_Produtos com a estrutura inserida.
 */
Filial_Catalogo_Produtos insere_info_produto(Filial_Catalogo_Produtos cat, Produto p, void * Estrutura){
  char* aux = getProdutoCode(p);
  cat->catalogo = insere_Catalogo(cat->catalogo,aux,Estrutura);
  free(aux);
  return cat;
}

/**
 * @brief Função que verifica se existe um determinado produto numa filial.
 * @param f FILIAL_produtos onde se vai procurar.
 * @param p Produto a ser procurado.
 * @param filial int onde se vai procurar.
 * @return Boolean com o resultado.
 */
Boolean existe_Produto_Filial(FILIAL_produtos f, Produto p, int filial){
  char *aux = getProdutoCode(p);
  Filial_Catalogo_Produtos cat = f->f_produtos[filial-1];
  Boolean a = existe_Catalogo(cat->catalogo,aux);
  free(aux);
  return a;

}

/**
 * @brief Função que liberta da memória o espaço ocupado pela informação do tipo de compra efetuado pelo cliente.
 * @param f void* a ser limpo da memória.
 */
static void free_struct_filial_produtos_info(void *f){
  info_p aux = (info_p) f;
  free(aux);

}

/**
 * @brief Função que liberta da memória o espaço ocupado pela informação de um produto.
 * @param f void* a ser limpo da memória.
 */
static void free_struct_filial_produtos(void *f){
  f_info_p aux = (f_info_p) f;
  int i;
  for(i =0; i<MESES ; i++){
    avl_free(aux->clientes_compradores[i],free_struct_filial_produtos_info);
  }
  free(aux);
}

/**
 * @brief Função que liberta da memória o espaço ocupado pelo catálogo das filiais dos produtos.
 * @param c Filial_Catalogo_Clientes a ser limpo da memória.
 */
void free_Filial_Catalogo_Produtos(Filial_Catalogo_Produtos c){
  Filial_Catalogo_Produtos aux = (Filial_Catalogo_Produtos) c;
  free_Catalogo(aux->catalogo,free_struct_filial_produtos);
  free(aux);
}

/**
 * @brief Função que liberta da memória o espaço ocupado pelo array que contém a informação de cada filial de produtos.
 * @param f FILIAL_clientes a ser limpo da memória.
 */
void free_Filial_Produtos(FILIAL_produtos f){
  int i;
  for(i = 0; i<FILIAL; i++) free_Filial_Catalogo_Produtos(f->f_produtos[i]);
  free(f);
}

/**
 * @brief Função que imprime uma filial de produtos.
 * @param f FILIAL_produtos de onde se vai imprimir uma das filiais.
 * @param filial int que vai ser impressa.
 */
void imprime_Filial_Produtos(FILIAL_produtos f, int filial){
  Filial_Catalogo_Produtos cat = f->f_produtos[filial-1];
  imprime_Catalogo(cat->catalogo);
}

/**
 * @brief Função que verifica se um produto foi comprado.
 * @param f f_info_p onde se vai verificar.
 * @return Boolean com o resultado.
 */
Boolean produto_Foi_Comprado(f_info_p f){
  if (f == NULL) return 0;
  return 1;
}



/*-----------------------------------------QUERIE4-----------------------------------------*/


/**
 * @brief Função que percorre os nodos de uma AVL.
 * @param tree NODO que será percorrido.
 * @param q Q2 que é a estrutura onde será inserida a informação.
 * @param aux int* que serve como contador recursivo dos produtos não comprados.
 */
void percorre_NODO_Filial_Q4(NODO tree, Q2 q, int *aux){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q4(esq,q,aux);
  free_Nodo(esq);

  f_info_p f = (f_info_p) getCont(tree);
  char* produto = getString(tree);
  if(!produto_Foi_Comprado(f)){
    insere_ProdQ2(produto,q);
    (*aux)++;
  }
  free(produto);

  NODO dir = getNodoDir(tree);
  percorre_NODO_Filial_Q4(dir,q,aux);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q2 que é a estrutura onde será inserida a informação.
 * @param aux int* que serve como contador recursivo dos produtos não comprados.
 */
void percorre_AVL_Filial_Q4(AVL tree, Q2 q, int *aux){
  NODO f = getNodo(tree);
  percorre_NODO_Filial_Q4(f,q,aux);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o código e a quantidade total de produtos que ninguém comprou, numa dada filial.
 * @param f FILIAL_produtos onde será consultada a informação do cliente.
 * @param filial int que é a filial a averiguar.
 * @param q Q2 onde será inserida a informação.
 */
void produtos_nao_comprados_filial(FILIAL_produtos f, int filial, Q2 q){
  Filial_Catalogo_Produtos cat = f->f_produtos[filial-1];
  int i,aux=0;
  AVL auxiliar;
  for(i=0;i<NR_LETRAS;i++){
    auxiliar = catalogo_getAVL(cat->catalogo,i);
    percorre_AVL_Filial_Q4(auxiliar,q,&aux);
  }
  setNum_totalQ2(aux,q);
}

/*-----------------------------------------QUERIE9-----------------------------------------*/

/**
 * @brief Função que percorre os nodos de uma AVL.
 * @param tree NODO que será percorrido.
 * @param q Q9 que é a estrutura onde será inserida a informação.
 * @param aux1 int* que serve como contador recursivo dos clientes que compraram em modo normal.
 * @param aux1 int* que serve como contador recursivo dos clientes que compraram em modo promocional.
 */
void percorre_NODO_Filial_Q9(NODO tree, Q9 q, int *aux1, int *aux2){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_NODO_Filial_Q9(esq,q,aux1,aux2);
  free_Nodo(esq);

  info_p f = (info_p) getCont(tree);
  char* cliente = getString(tree);
  if(f->tipo_compra == 0){
    insere_ProdNQ9(cliente,q);
    (*aux1)++;
  }
  else if(f->tipo_compra == 1){
    insere_ProdPQ9(cliente,q);
    (*aux2)++;
  }
  else if(f->tipo_compra == 2){
    insere_ProdNQ9(cliente,q);
    insere_ProdPQ9(cliente,q);
    (*aux1)++;
    (*aux2)++;
  }
  free(cliente);

  NODO dir = getNodoDir(tree);
  percorre_NODO_Filial_Q9(dir,q,aux1,aux2);
  free_Nodo(dir);


}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que será percorrida.
 * @param q Q9 que é a estrutura onde será inserida a informação.
 * @param aux1 int* que serve como contador recursivo dos clientes que compraram em modo normal.
 * @param aux1 int* que serve como contador recursivo dos clientes que compraram em modo promocional.
 */
void percorre_AVL_Filial_Q9(AVL tree, Q9 q, int *aux1, int *aux2){
  NODO f = getNodo(tree);
  percorre_NODO_Filial_Q9(f,q,aux1,aux2);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura o código dos clientes que compraram um dado produto numa dada filial.
 * @param q Q9 onde serão inseridos os códigos dos clientes.
 * @param f FILIAL_produtos onde será consultada a informação do produto.
 * @param filial int que é a filial a averiguar.
 */
void lista_produtos_comprados_filial(Q9 q,FILIAL_produtos f, char* key, int filial){
  Filial_Catalogo_Produtos fc = f->f_produtos[filial-1];
  f_info_p info = get_Cat_struct(fc->catalogo,key);
  int i,aux1=0,aux2=0;
  if (info != NULL)
    for(i=0;i<MESES;i++){
        percorre_AVL_Filial_Q9(info->clientes_compradores[i],q,&aux1,&aux2);
    }
  setTotalNQ9(q,aux1);
  setTotalPQ9(q,aux2);
}

/*-----------------------------------------QUERIE11-----------------------------------------*/


/**
 * @brief Função que altera numa estrutura o número de clientes que compraram dado produto.
 * @param f FILIAL_produtos onde será consultada a informação do produto.
 * @param q Q11 onde será alterado o número de clientes.
 * @param limit int que é o número de produtos a averiguar o número de clientes que os compraram.
 */
void defineNClientes(FILIAL_produtos f, Q11 q, int limit){
  int i,j,k,nc;
  int l2 = getNum_TotalQ11(q);
  Filial_Catalogo_Produtos fc;
  f_info_p aux;
  char* prod;
  for(i=0;i<FILIAL;i++){
    fc = f->f_produtos[i];
    for(j=0;j<l2 && j<limit;j++){
      prod = getProdutoQ11(q,j);
      aux = get_Cat_struct(fc->catalogo,prod);
      if(aux != NULL)
      for(k=0;k<MESES;k++){
        nc = avl_getTamanho(aux->clientes_compradores[k]);
        alteraNClientesQ11(q,j,nc,i);
      }
    }
  }
}
