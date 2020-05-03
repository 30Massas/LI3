/**
 * @file catalogo.c
 * @brief Ficheiro que contém a API relativa à implementação de catálogos.
 */

#include "../include/catalogo.h"

/* Estrutura que contém um array em que cada indíce é um apontador para uma AVL.*/
struct catalogo {
   AVL indice[NR_LETRAS];
};

/**
 * @brief Função que inicializa um novo catálogo.
 * @return Novo catálogo nulo.
 */
Catalogo init_Catalogo() {
  Catalogo cat = (Catalogo) malloc(sizeof(struct catalogo));
  int i;
  for(i = 0; i < NR_LETRAS; i++) {
      cat->indice[i] = initAVL();
  }
  return cat;
}

/**
 * @brief Função que verifica se existe uma key num catálogo.
 * @param catalogo Catalogo onde a existência é verificada.
 * @param key *char a procurar no array.
 * @return Boolean com o resultado.
 */
Boolean existe_Catalogo(Catalogo catalogo, char* key) {
   int index = key[0] - 'A';
   Boolean existe = avl_lookUp(catalogo->indice[index],key);
   return existe;
}

/**
 * @brief Função que devolve a estrutura associada a uma key de um catálogo que lhe é passada como argumento.
 * @param c Catalogo de onde será devolvida a estrutura.
 * @param key *char indicando o valor a procurar onde estará associada a estrutura.
 * @return void* com apontador para a estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura get_Cat_struct(Catalogo c, char* key){
   int index = key[0] - 'A';
   return avl_getEstrutura(c->indice[index],key);
}

/**
 * @brief Função que insere no catálogo tendo como referência de posicionamento um char* key.
 * @param c Catalogo onde insere.
 * @param key char* que indica o local onde inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return catálogo com a nova estrutura adicionada.
 */
Catalogo insere_Catalogo(Catalogo c, char* key, void * estrutura){
   int i = key[0] - 'A';
   c->indice[i] = avl_insert(c->indice[i],key,estrutura);
   return c;
}

/**
 * @brief Função que altera uma estrutura no catálogo tendo como referência de posicionamento um char* key.
 * @param c Catalogo que vai ser alterado.
 * @param key char* que indica o local onde altera.
 * @param estrutura Conteúdo/Estrutura que vai alterar a existente.
 * @return catálogo atualizado.
 */
Catalogo altera_Catalogo(Catalogo c, char* key, void* estrutura){
   int i = key[0] - 'A';
   c->indice[i] = atualiza_avl(c->indice[i],key,estrutura);
   return c;
}

/**
 * @brief Função com o objetivo de limpar da memória um dado catálogo.
 * @param cat Catalogo a limpar da memória.
 * @param f Funcao que liberta a memória da estrutura associada.
 */
void free_Catalogo(Catalogo cat, Funcao f){
   int i;
   for(i = 0;i<NR_LETRAS;i++)
      avl_free(cat->indice[i],f);
   free(cat);
}

/**
 * @brief Função que imprime um catálogo.
 * @param cat Catalogo a imprimir.
 */
void imprime_Catalogo(Catalogo cat){
   int i;
   for(i = 0; i<NR_LETRAS;i++)
      imprime_AVL_String(cat->indice[i]);
}

/**
 * @brief Função que devolve a AVL que se encontra numa determinada posição do array.
 * @param cat Catalogo onde se procura.
 * @param index int que determina a posição do array.
 * @return AVL que se encontra nessa posição do array.
 */
AVL catalogo_getAVL(Catalogo cat, int index){
  return cat->indice[index];
}
