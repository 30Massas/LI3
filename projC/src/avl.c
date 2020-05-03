/**
 * @file avl.c
 * @brief Ficheiro que contém a API relativa à implementação de AVL's.
 */

#include "../include/avl.h"

struct nodeAVL {
    char* string;
    void *cont;
    int height;
    struct nodeAVL *left;
    struct nodeAVL *right;
};

struct avl {
    NODO arvore;
    int avl_tamanho;
};


static int height(NODO n);
static int max(int a, int b);
static int getBalance(NODO N);
static Boolean node_lookUp(NODO node, Valor value);
static NODO newNode(NODO node, Valor info, void *estrutura);
static NODO rightRotate(NODO y);
static NODO leftRotate(NODO x);
static NODO atualiza_node(NODO node, char* value, void* estrutura);
static NODO node_insert(NODO node, Valor string, Estrutura estrutura);
static NODO tree_clone(NODO node, NODO novo);
static Estrutura node_getEstrutura(NODO node, Valor value);
static void tree_free(NODO node, Funcao f);

/**
 * @brief Função que inicializa uma nova AVL.
 * @return Nova AVL nula
 */
AVL initAVL() {
    AVL tree = malloc(sizeof(struct avl));
    tree->arvore = NULL;
    tree->avl_tamanho = 0;
    return tree;
}

/**
 * @brief Função que insere uma nova estrutura na arvore tree tendo como referência de posicionamento um char* value.
 * @param tree AVL onde insere.
 * @param value char* a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return AVL atualizada.
 */
AVL atualiza_avl(AVL tree, char* value, Estrutura estrutura) {
    tree->arvore = atualiza_node(tree->arvore,value,estrutura);
    return tree;
}

/**
 * @brief Função que insere na arvore tree tendo como referência de posicionamento um char*.
 * @param tree AVL onde insere.
 * @param key char* a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return AVL com o novo nodo adicionado.
 */
AVL avl_insert(AVL tree, Valor key, Estrutura estrutura) {
    tree->arvore = node_insert(tree->arvore,key,estrutura);
    tree->avl_tamanho ++;
    return tree;
}

/**
 * @brief Função que devolve um Boolean referente a ter encontrado ou não na AVL o Valor value.
 * @param tree AVL onde é efectuada a procura.
 * @param value valor a procurar na AVL.
 * @return Boolean com o resultado.
 */
Boolean avl_lookUp(AVL tree, Valor value) {
    if(tree==NULL) return false;
    return node_lookUp(tree->arvore,value);
}

/**
 * @brief Função que devolve o tamanho (quantidade de nodos) de uma AVL passada como argumento.
 * @param tree AVL da qual se pretende o tamanho.
 * @return Int com tamanho da AVL.
 */
int avl_count(AVL tree) {
    return tree->avl_tamanho;
}

/**
 * @brief Função que executa um clone de uma dada AVL.
 * @param node AVL a clonar.
 * @param novo AVL onde colocar o clone.
 * @return AVL nova, clonada da anterior.
 */
AVL avl_clone(AVL node, AVL novo) {
    novo = (AVL) malloc(sizeof(struct avl));
    novo->arvore = tree_clone(node->arvore,novo->arvore);
    novo->avl_tamanho = node->avl_tamanho;
    return novo;
}

/**
 * @brief Função que devolve a estrutura associada a um nodo de uma AVL passada como argumento.
 * @param node AVL de onde será devolvida a estrutura.
 * @param value char* indicando o nodo a procurar onde estará a estrutura associada.
 * @return void* com apontador para a estrutura ou NULL caso a mesma nao se encontre lá.
 */
Estrutura avl_getEstrutura(AVL node, Valor value) {
    return node_getEstrutura(node->arvore,value);
}

 /**
 * @brief Função que devolve o tamanho de uma AVL.
 * @param tree AVL da qual se calcula o tamanho.
 * @return int com o tamanho da AVL.
 */
int avl_getTamanho(AVL tree){
  return tree->avl_tamanho;
}

/**
 * @brief Função que dada uma AVL retorna o nodo da sua raiz.
 * @param a AVL de onde se pretende o nodo.
 * @return NODO.
 */
NODO getNodo(AVL a) {
    NODO novo;
    if(a->arvore) {
        novo = (NODO) malloc(sizeof(struct nodeAVL));
        novo->string = malloc((strlen(a->arvore->string)+1)*sizeof(char));
        strcpy(novo->string,a->arvore->string);
        novo->cont = a->arvore->cont;
        novo->left = a->arvore->left;
        novo->right = a->arvore->right;
    }else {
        novo = NULL;
    }

    return novo;
}

/**
 * @brief Função que dado um NODO retorna o nodo á sua esquerda.
 * @param n NODO.
 * @return NODO à esquerda.
 */
NODO getNodoEsq(NODO n) {
    NODO novo;
    if(n->left) {
        novo = (NODO) malloc(sizeof(struct nodeAVL));
        novo->string = malloc((strlen(n->left->string)+1)*sizeof(char));
        strcpy(novo->string,n->left->string);
        novo->cont = n->left->cont;
        novo->left = n->left->left;
        novo->right = n->left->right;
    }else {
        novo = NULL;
    }
    return novo;
}

/**
 * @brief Função que dado um NODO retorna o nodo á sua direita.
 * @param n NODO.
 * @return NODO à direita.
 */
NODO getNodoDir(NODO n) {
    NODO novo;
    if(n->right) {
        novo = (NODO) malloc(sizeof(struct nodeAVL));
        novo->string = malloc((strlen(n->right->string)+1)*sizeof(char));
        strcpy(novo->string,n->right->string);
        novo->cont = n->right->cont;
        novo->left = n->right->left;
        novo->right = n->right->right;
    }else {
        novo = NULL;
    }
    return novo;
}

/**
 * @brief Função que dado um NODO retorna uma copia da sua string.
 * @param n NODO.
 * @return char* com a cópia.
 */
char* getString(NODO n) {
    char* novo;
    novo = malloc((strlen(n->string)+1)*sizeof(char));
    strcpy(novo,n->string);
    return novo;
}

/**
 * @brief Função que dado um NODO retorna o seu contéudo.
 * @param n NODO.
 * @return void*.
 */
void* getCont(NODO n) {
    return n->cont;
}

/**
 * @brief Função com o objetivo de limpar da memória uma dada AVL.
 * @param nodo AVL a limpar da memória.
 * @param f Funcao que liberta a memória da estrutura associada.
 */
void avl_free(AVL nodo, Funcao f) {
    tree_free(nodo->arvore,f);
    free(nodo);
}

/**
 * @brief Função que dado um NODO retorna a sua altura.
 * @param n NODO.
 * @return int altura.
 */
static int height(NODO n) {
    if (n == NULL)
        return 0;
    return n->height;
}

/**
 * @brief Função que calcula qual o maior de dois inteiros.
 * @param int a.
 * @param int b.
 * @return int max.
 */
static int max(int a, int b) {
    return (a > b)? a : b;
}

/**
 * @brief Função que cria um novo nodo.
 * @param node NODO.
 * @param info Valor.
 * @param estrutura void*.
 * @return novo NODO.
 */
static NODO newNode(NODO node, Valor info, void *estrutura) {
    node = (NODO) malloc(sizeof(struct nodeAVL));
    node->string = malloc((strlen(info)+1)*sizeof(char));
    strcpy(node->string,info);
    node->cont = estrutura;
    node->height = 1;
    node->left   = NULL;
    node->right  = NULL;
    return node;
}

/**
 * @brief Função que dado um NODO roda para a direita.
 * @param y NODO.
 * @return NODO depois de uma rotação à direita.
 */
static NODO rightRotate(NODO y) {

    NODO x = y->left;
    NODO T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

/**
 * @brief Função que dado um NODO roda para a esquerda.
 * @param x NODO.
 * @return NODO depois de uma rotação à esquerda.
 */
static NODO leftRotate(NODO x) {

    NODO y = x->right;
    NODO T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

/**
 * @brief Função que verifica se o nodo está balanceado e, consequentemente, a árvore.
 * @param N NODO.
 * @return int como Boolean.
 */
static int getBalance(NODO N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/**
 * @brief Função que insere um node NODO com um info Valor e uma estrutura Estrutura.
 * @param node NODO a inserir.
 * @param info Valor a inserir.
 * @param estrutura Conteúdo/Estrutura a inserir.
 * @return novo NODO inserido.
 */
static NODO node_insert(NODO node, Valor info, Estrutura estrutura) {
    int balance;

    if(node != NULL) {

    if (strcmp(info,node->string) < 0)
        node->left  = node_insert(node->left, info, estrutura);
    else if(strcmp(info,node->string) > 0)
        node->right = node_insert(node->right, info, estrutura);
    else node->cont = estrutura;

    /* Atualiza os pesos */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* Varifica o balanceamento */
    balance = getBalance(node);

    /* Left Left Case */
    if (balance > 1 && strcmp(info,node->left->string) < 0) return rightRotate(node);

    /* Right Right Case */
    if (balance < -1 && strcmp(info,node->right->string) > 0) return leftRotate(node);

    /* Left Right Case */
    if (balance > 1 && strcmp(info,node->left->string) > 0) {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
     /* Right Left Case */
    if (balance < -1 && strcmp(info, node->right->string) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    } else node = newNode(node,info,estrutura);

   return node;
}

/**
 * @brief Função que verifica se existe um nodo com um certo valor.
 * @param node NODO a procurar.
 * @param value Valor a procurar.
 * @return Boolean com o resultado.
 */
static Boolean node_lookUp(NODO node, Valor value) {
    int r;
    if(node == NULL) return false;
    else {
        r = strcmp(value,node->string);
        if(r == 0) return true;
        else if(r < 0) return node_lookUp(node->left, value);
        else return node_lookUp(node->right,value);
    }
}

/**
 * @brief Função que clona um nodo para outro nodo.
 * @param node NODO a ser clonado.
 * @param novo NODO clone.
 * @return o novo NODO clone.
 */
static NODO tree_clone(NODO node, NODO novo) {

    if(node) {
        novo = malloc(sizeof(struct nodeAVL));
        novo->string = malloc((strlen(node->string)+1)*sizeof(char));
        strcpy(novo->string,node->string);
        novo->height = node->height;
        novo->cont = NULL;
        novo->left = tree_clone(node->left,novo->left);
        novo->right = tree_clone(node->right,novo->right);
    }
    else novo = NULL;

    return novo;
}

/**
 * @brief Função que atualiza um nodo.
 * @param node NODO atualizado
 * @param value char* utilizado como comparação para saber onde atualizar.
 * @param estrutura Conteúdo/Estrutura a inserir quando atualizar.
 * @return node NODO atualizado.
 */
static NODO atualiza_node(NODO node, char* value, Estrutura estrutura) {
    int r;
    r = strcmp(value,node->string);
    if(r == 0) {
        node->cont = estrutura;
        return node;
    }
    else if(r < 0) atualiza_node(node->left, value,estrutura);
    else atualiza_node(node->right,value,estrutura);

    return node;
}

/**
 * @brief Função que devolve a estrutura associada a um nodo que lhe é passado como argumento.
 * @param node NODO de onde será devolvida a estrutura.
 * @param value Valor utilizado como referência de procura.
 * @return Estrutura ou NULL caso a mesma nao se encontre lá.
 */
static Estrutura node_getEstrutura(NODO node, Valor value) {
    int r;
    if(node == NULL) return NULL;
    else {
        r = strcmp(value,node->string);
        if(r == 0) return node->cont;
        else if(r < 0) return node_getEstrutura(node->left, value);
        else return node_getEstrutura(node->right,value);
    }
}

/**
 * @brief Função que limpa o espaço de memória ocupado por uma árvore.
 * @param node NODO a libertar.
 * @param f Funcao que liberta a memória da estrutura associada.
 */
static void tree_free(NODO node, Funcao f) {
    if(node != NULL) {
        tree_free(node->left,f);
        tree_free(node->right,f);
        if(node->cont != NULL) {
            f(node->cont);
        }
        free(node->string);
        free(node);
    }
}

/**
 * @brief Função que limpa da memória um dado NODO.
 * @param node NODO a remover.
 */
void free_Nodo(NODO node) {
    if(node != NULL) {
        free(node->string);
        free(node);
    }
}

/**
 * @brief Função que imprime os nodos da AVL.
 * @param tree NODO a imprimir.
 */
void imprime_Conteudo_AVL(NODO tree){
    if (tree == NULL) return;
    imprime_Conteudo_AVL(tree->left);
    printf("%s\n",tree->string);
    imprime_Conteudo_AVL(tree->right);
}

/**
 * @brief Função que imprime todas as Strings da AVL
 * @param tree AVL a imprimir
 */
void imprime_AVL_String(AVL tree){
    imprime_Conteudo_AVL(tree->arvore);
}
