/**
 * @file produtos.c
 * @brief Ficheiro que contém a API relativa à implementação dos produtos.
 */

#include "../include/produtos.h"


struct produto {
  char* n_produto;
};

struct catalogo_produtos{
  Catalogo catalogo;
};

/**
 * @brief Função que cria um produto.
 * @return novo produto criado.
 */
Produto cria_Produto() {
	Produto p = (Produto) malloc(sizeof(struct produto));
	p->n_produto = NULL;
	return p;
}

/**
 * @brief Função que altera um produto.
 * @param p Produto a ser alterado.
 * @param e char* novo código do produto.
 * @return novo produto criado.
 */
Produto altera_Produto(Produto p, char* e){
    if(p->n_produto){
        free(p->n_produto);
    }
    p->n_produto = malloc((strlen(e) + 1) * sizeof(char));
    strcpy(p->n_produto,e);
    return p;
}

/**
 * @brief Função que inicializa um catálogo de produtos.
 * @return Produtos_Catalog inicializado.
 */
Produtos_Catalog init_produtos_catalog(){
    Produtos_Catalog new = malloc(sizeof(struct catalogo_produtos));
    new->catalogo = init_Catalogo();
    return new;
}

/**
 * @brief Função que verifica se um produto existe.
 * @param c Produtos_Catalog onde procura.
 * @param key char* utilizado como referência de procura.
 * @return Boolean com o resultado.
 */
Boolean existe_produto(Produtos_Catalog c, char *key){
    return existe_Catalogo(c->catalogo,key);
}

/**
 * @brief Função que insere um produto num catálogos de produto.
 * @param cat Produtos_Catalog onde vai inserir o produto.
 * @param p Produto a ser inserido.
 * @return Produtos_Catalog com o produto inserido.
 */
Produtos_Catalog insere_produto(Produtos_Catalog cat, Produto p){
    char *aux = getProdutoCode(p);
    cat->catalogo = insere_Catalogo(cat->catalogo,aux,NULL);
    free(aux);
    return cat;
}

/**
 * @brief Função que insere no produto de um catálogo uma estrutura.
 * @param cat Produtos_Catalog onde se vai inserir.
 * @param p Produto onde se vai inserir.
 * @param Estrutura void* a ser inserida.
 * @return Produtos_Catalog com a estrutura inserida.
 */
Produtos_Catalog insere_Produtos_Catalogo(Produtos_Catalog cat, Produto p, void* Estrutura) {
    char *aux = getProdutoCode(p);
    cat->catalogo = insere_Catalogo(cat->catalogo,aux, Estrutura);
    free(aux);
    return cat;
}

/**
 * @brief Função que liberta da memória o espaço ocupado por um catálogo de produtos.
 * @param cat Produtos_Catalog a ser limpo da memória.
 * @param f Funcao que liberta a memória da estrutura associada.
 */
void free_Produtos(Produtos_Catalog cat, Funcao f){
    free_Catalogo(cat->catalogo,f);
    free(cat);
}

/**
 * @brief Função que imprime os produtos.
 * @param cat Produtos_Catalog onde se encontram os produtos a ser impressos.
 */
void imprime_Produtos(Produtos_Catalog cat){
    imprime_Catalogo(cat->catalogo);
}

/**
 * @brief Função que retorna o código de um produto.
 * @param p Produto do qual se pretende obter o código.
 * @return char* com o código do produto.
 */
char* getProdutoCode(Produto p){
  char *aux = malloc(sizeof(char)*(strlen(p->n_produto)+1));
  strcpy(aux,p->n_produto);
  return aux;
}

/**
 * @brief Função que devolve a estrutura associada a um produto de um catálogo que lhe é passado como argumento.
 * @param cat Produtos_Catalog de onde será devolvida a estrutura.
 * @param p Produto indicando o produto a procurar onde estará associada a estrutura.
 * @return Estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_product_struct (Produtos_Catalog cat, Produto p) {
    char *aux = getProdutoCode(p);
    Estrutura a = get_Cat_struct (cat->catalogo, aux);
    free(aux);
    return a;
}

/**
 * @brief Função que altera uma determinada estrutura dando um catálogo de produtos e um produto como argumentos.
 * @param cat Produtos_Catalog onde se vai alterar.
 * @param p Produto onde se vai alterar.
 * @param Estrutura void* que vai ser introduzida
 * @return Produtos_Catalogo com a estrutra do produto alterada.
 */
Produtos_Catalog altera_Catalogo_Produtos(Produtos_Catalog cat , Produto p, void * Estrutura){
  char *aux = getProdutoCode(p);
  cat->catalogo = altera_Catalogo(cat->catalogo,aux,Estrutura);
  free(aux);
  return cat;
}

/**
 * @brief Função que liberta da memória o espaço ocupado por um produto.
 * @param p Produto a ser libertado.
 */
void free_p(Produto p){
    if(p){
        if(p->n_produto)
            free(p->n_produto);
        free(p);
    }
}

/*-----------------------------------QUERIE2-----------------------------------*/

/**
 * @brief Função que percorre o nodo de cada árvore, de forma inorder, obtendo a string que lá está inserida e colocando-a na estrutura auxiliar Q2.
 * @param tree NODO a percorrer.
 * @param q Q2 onde se vai inserir as strings.
 */
void percorre_Nodo_Produtos_Q2(NODO tree, Q2 q){
  if(tree==NULL) return;
  NODO esq = getNodoEsq(tree);
  percorre_Nodo_Produtos_Q2(esq,q);
  free_Nodo(esq);

  char* prod = getString(tree);
  insere_ProdQ2(prod,q);
  free(prod);

  NODO dir = getNodoDir(tree);
  percorre_Nodo_Produtos_Q2(dir,q);
  free_Nodo(dir);
}

/**
 * @brief Função que percorre uma AVL.
 * @param tree AVL que é percorrida.
 * @param q Q2 onde inserimos a informação.
 */
void percorre_AVL_Produtos_Q2(AVL tree, Q2 q){
  NODO f = getNodo(tree);
  percorre_Nodo_Produtos_Q2(f,q);
  free_Nodo(f);
}

/**
 * @brief Função que insere numa estrutura auxiliar Q2 as strings dos produtos e o número total dos produtos começados pela letra dada.
 * @param cat Produtos_Catalog que contém os produtos.
 * @param letra char pela qual são iniciados os produtos que se pretende imprimir.
 * @param q Q2 de onde obtemos as informações.
 */
void imprime_produtos_letra(Produtos_Catalog cat, char letra, Q2 q){
  AVL auxiliar;
  int index = letra - 'A';
  auxiliar = catalogo_getAVL(cat->catalogo,index);
  percorre_AVL_Produtos_Q2(auxiliar,q);
  int aux = avl_getTamanho(auxiliar);
  setNum_totalQ2(aux,q);
}
