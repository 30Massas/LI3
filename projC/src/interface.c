/**
 * @file interface.c
 * @brief Ficheiro que contém a API relativa à implementação da interface.
 */

#include "../include/interface.h"

struct sgv{
    int valido;
    int quantidade_clientes; /* Quantidade total de clientes*/
    int quantidade_produtos; /* Quantidade total de produtos*/
    int vendas_validas; /* Quantidade total de vendas válidas*/
    int vendas_totais; /* Quantidade total de vendas lidas*/
    char clients_File_Path[BUFFER]; /* Diretoria do ficheiro que contém os clientes*/
    char products_File_Path[BUFFER]; /* Diretoria do ficheiro que contém os produtos*/
    char sales_File_Path[BUFFER]; /* Diretoria do ficheiro que contém as vendas*/
    Clientes_Catalog clientes; /*Catálogo de clientes*/
    Produtos_Catalog produtos; /*Catálogo de produtos*/
    Faturacao_Catalog faturacao; /*Catálogo de faturação*/
    FILIAL_clientes f_clientes; /* Catálogo de filial ordenada por clientes*/
    FILIAL_produtos f_produtos; /* Catálogo de filial ordenada por produtos*/
};

/**
 * @brief Função que inicializa o SGV.
 * @return SGV inicializado.
 */
SGV initSGV(){
    SGV sgv = malloc(sizeof(struct sgv));
    sgv->clientes = init_clientes_catalog();
    sgv->produtos = init_produtos_catalog();
    sgv->faturacao = init_faturacao_catalogo();
    sgv->f_clientes = init_filial_clientes();
    sgv->f_produtos = init_filial_produtos();
    sgv->valido = 0;
    return sgv;
}

/**
 * @brief Função que destrói o SGV, libertando o espaço da memória por ele ocupado.
 * @param sgv SGV que contém a informação dos módulos.
 */
void destroySGV(SGV sgv){
    free_Clientes(sgv->clientes,NULL);
    free_Produtos(sgv->produtos,NULL);
    free_Faturacao(sgv->faturacao);
    free_Filial_Clientes(sgv->f_clientes);
    free_Filial_Produtos(sgv->f_produtos);
    free(sgv);
}

/**
 * @brief Função que verifica se o SGV é válido.
 * @param sgv SGV que contém a informação dos módulos.
 * @param Boolean com o resultado.
 */
Boolean isSGVvalid(SGV sgv){
  if(sgv) return sgv->valido;
  return false;
}

/*--------------------------------------------------QUERIE1--------------------------------------------------*/

/**
 * @brief Função que carrega o conteúdo dos ficheiros para os respetivos catálogos.
 * @param sgv SGV que contém a informação dos módulos.
 * @param clientsFilePath char * que contém o caminho para o ficheiro dos clientes.
 * @param produtcsFilePath char * que contém o caminho para o ficheiro dos produtos.
 * @param salesFilePath char * que contém o caminho para o ficheiro das vendas.
 * @param f FILE* onde se vai escrever a informação do ficheiro dos clientes.
 * @param g FILE* onde se vai escrever a informação do ficheiro dos produtos.
 * @param h FILE* onde se vai escrever a informação do ficheiro das vendas.
 * @return SGV com o conteúdo dos ficheiros carregado.
 */
SGV loadSGVFromFiles(SGV sgv,char* clientsFilePath,char* productsFilePath,char* salesFilePath,FILE *f, FILE *g, FILE *h){
    if (sgv->valido) {
      destroySGV(sgv);
      sgv = initSGV(sgv);
    }
    int i=0, j=0, k=0 , count = 0;
    Produto prod;
    Cliente e;

    strcpy(sgv->clients_File_Path,clientsFilePath);
    strcpy(sgv->products_File_Path,productsFilePath);
    strcpy(sgv->sales_File_Path,salesFilePath);

    /*Inicialização do catálogo dos clientes*/

        e = cria_Cliente();
        char cli_code[8];
        char *token;
        while(fgets(cli_code,8,f)){
            token = strtok(cli_code,"\r\n");
            if(isalpha(token[0]) && isdigit(token[1]) && isdigit(token[2]) && isdigit(token[3]) && isdigit(token[4])){
            e = altera_Cliente(e,token);
            sgv->clientes = insere_cliente(sgv->clientes,e);
            sgv->f_clientes = cria_Filial_Clientes(sgv->f_clientes, e);
            i++;
          }
        }
        sgv->quantidade_clientes = i;

        /*Fecho dos ficheiro previamente lido*/

        free_c(e);
        fclose(f);


    /*Inicialização do catálogo dos produtos*/

        prod = cria_Produto();
        char prod_code[9];
        char *token2;

        while(fgets(prod_code,9,g)){
            token2 = strtok(prod_code,"\r\n");
            if(isalpha(token2[0]) && isalpha(token2[1]) && isdigit(token2[2]) && isdigit(token2[3]) && isdigit(token2[4]) && isdigit(token2[5])){
            prod = altera_Produto(prod,token2);
            sgv->produtos = insere_produto(sgv->produtos,prod);
            sgv->faturacao = insere_faturacao(sgv->faturacao,prod,NULL);
            sgv->f_produtos = cria_Filial_Produtos(sgv->f_produtos,prod);
            j++;
            }
        }
        sgv->quantidade_produtos = j;

        /*Fecho dos ficheiro previamente lido*/
        free_p(prod);
        fclose(g);


    /*Inicialização do catálogo de faturação*/


        char *p; /*Código do produto*/
        double preco; /*Preço da venda*/
        int qt; /*Quantidade da venda*/
        char *tipo_compra; /*Tipo da compra, Normal(N) ou Promoção(P)*/
        char *c; /*Código do cliente*/
        int mes; /*Mês da venda*/
        int filial; /*Filial responsável pela venda*/
        char *string, *string2; /*Guarda a linha da venda*/
        char token3[BUFFER];
        e = cria_Cliente();
        prod = cria_Produto();

        while (fgets(token3, BUFFER, h)) {
            string2 = string = strdup(token3);

            p = strsep(&string," ");
            prod = altera_Produto(prod,p);


            preco = (double)atof(strsep(&string," "));


            qt = atoi(strsep(&string," "));


            tipo_compra = strsep(&string," ");


            c = strsep(&string," ");
            e = altera_Cliente(e,c);


            mes = atoi(strsep(&string," "));


            filial = atoi(strsep(&string,"\n"));


            /*Validação das vendas, caso encontre o código de cliente e o código de produto*/
            if(existe_cliente(sgv->clientes,c) && existe_produto(sgv->produtos,p)){

              /*Insere na estrutura de filial organizada por clientes*/
              sgv->f_clientes = altera_Filial_Cliente(sgv->f_clientes, e, prod, mes, qt, preco, filial);


              /*/Insere na estrutura filial organizada por produtos*/
              sgv->f_produtos = altera_Filial_Produto(sgv->f_produtos, e, prod, mes, qt, preco, filial, tipo_compra[0]);


              /*Insere na estrutura todas as informações na linha da venda previamente copiadas*/


              sgv->faturacao = altera_Faturacao(sgv->faturacao,prod,mes,filial,tipo_compra[0],preco,qt);
              count++;


            }
            free(string2);
            k++;
        }



        sgv->vendas_validas = count;
        sgv->vendas_totais = k;

        /*Fecho dos ficheiro previamente lido*/
        free_c(e);
        free_p(prod);
        fclose(h);
        sgv->valido = 1;

    return sgv;
}

/**
 * @brief Função que retorna o a quantidade total de produtos do SGV.
 * @param sgv SGV que contém a informação dos módulos.
 * @return int com o número total de produtos.
 */
int getTotalProdSGV(SGV sgv){
  return sgv->quantidade_produtos;
}

/**
 * @brief Função que verifica se um dado cliente existe no SGV.
 * @param sgv SGV que contém a informação dos módulos.
 * @param cliente char* a ser procurado.
 * @return Boolean com o resultado.
 */
Boolean existeSGVCliente(SGV sgv, char* cliente){
  return existe_cliente(sgv->clientes,cliente);
}

/**
 * @brief Função que verifica se um dado produto existe no SGV.
 * @param sgv SGV que contém a informação dos módulos.
 * @param produto char* a ser procurado
 * @return Boolean com o resultado.
 */
Boolean existeSGVProduto(SGV sgv, char* produto){
  return existe_produto(sgv->produtos,produto);
}
/*--------------------------------------------------QUERIE2--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os produtos começados por uma certa letra.
 * @param sgv SGV que contém a informação dos módulos.
 * @param letter char pela qual os produtos devem começar.
 * @return q Q2 estrutura com os produtos.
 */
Q2 getProductsStartedByLetter(SGV sgv, char letter){
    Q2 q = init_Q2(getTotalProdSGV(sgv));
    imprime_produtos_letra(sgv->produtos, letter, q);
    return q;
}

/*--------------------------------------------------QUERIE3--------------------------------------------------*/

/**
 * @brief Função que retorna o número de vendas e a faturação de um determinado produto num determinado mês.
 * @param sgv SGV que contém a informação dos módulos.
 * @param product char* do qual se pretende obter a informação.
 * @param month int do qual se pretende obter a informação.
 * @return q Q3 estrutura com os resultados pretendidos.
 */
Q3 getProductSalesAndProfit(SGV sgv, char* product, int month){
  Q3 q = init_Q3();
  if(existe_produto(sgv->produtos,product)){
    get_NVendas_Mes_Faturacao(sgv->faturacao,product,month,q);
    get_Fat_Mes_Faturacao(sgv->faturacao,product,month,q);
  }
  return q;
}

/*--------------------------------------------------QUERIE4--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os produtos de uma certa filial que nunca foram comprados.
 * @param sgv SGV que contém a informação dos módulos.
 * @param branchID int que indica a filial.
 * @return q Q2 estrutura com os resultados obtidos.
 */
Q2 getProductsNeverBought(SGV sgv, int branchID){
  Q2 q = init_Q2(getTotalProdSGV(sgv));
  if(branchID == 0) produtos_nao_comprados(sgv->faturacao,q);
  else produtos_nao_comprados_filial(sgv->f_produtos,branchID,q);
  return q;
}

/*--------------------------------------------------QUERIE5--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os clientes que realizaram compras em todas as filiais.
 * @param sgv SGV que contém a informação dos módulos.
 * @return q Q5 estrutura com os clientes pretendidos.
 */
Q5 getClientsOffAllBranches(SGV sgv){
  Q5 q = init_Q5(getTotalProdSGV(sgv));
  clientes_todas_filiais(sgv->f_clientes,q);
  return q;
}

/*--------------------------------------------------QUERIE6--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com o número de clientes que não efetuaram compras e o número de produtos não comprados.
 * @param sgv SGV que contém a informação dos módulos.
 * @return q Q6 estrutura com os resultados obtidos.
 */
Q6 getClientsAndProductsNeverBoughtCount(SGV sgv){
  Q6 q = init_Q6();
  produtos_nao_comprados_num(sgv->faturacao,q);
  produtos_nao_comprados_num_filial(sgv->f_clientes,q);
  return q;
}

/*--------------------------------------------------QUERIE7--------------------------------------------------*/

/**
 * @brief Função que retorna o número total de produtos comprados por um determinado cliente.
 * @param sgv SGV que contém a informação dos módulos.
 * @param clientID char* do qual se pretende obter a informação.
 * @return q Q7 estrutura com o número total de produtos.
 */
Q7 getProductsBoughtByClient(SGV sgv, char* clientID){
  Q7 q = init_Q7();
  quantidade_compras_cliente(sgv->f_clientes,clientID,q);
  return q;
}

/*--------------------------------------------------QUERIE8--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com o número total de vendas e o total faturado num intervalo fechado de meses.
 * @param sgv SGV que contém a informação dos módulos.
 * @param int minMonth primeiro mês do intervalo.
 * @param int maxMonth último mês do intervalo.
 * @return q Q8 estrutura com os resultados pretendidos.
 */
Q8 getSalesAndProfit(SGV sgv, int minMonth, int maxMonth){
  Q8 q = init_Q8();

  get_NVendas_Faturacao_EntreMeses(sgv->faturacao,minMonth,maxMonth,q);

  get_Fat_Faturacao_EntreMeses(sgv->faturacao,minMonth,maxMonth,q);

  return q;
}

/*--------------------------------------------------QUERIE9--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os códigos e com o número total de clientes que efetuaram a compra de um dado produto numa certa filial.
 * @param sgv SGV que contém a informação dos módulos.
 * @param productID char* que indica o produto do qual pretendemos obter a informação.
 * @param branch int que indica a filial.
 * @return q Q9 estrutura com os resultados obtidos.
 */
Q9 getProductBuyers(SGV sgv, char* productID, int branch){
  Q9 q = init_Q9(getTotalProdSGV(sgv));
  lista_produtos_comprados_filial(q,sgv->f_produtos,productID,branch);
  return q;
}

/*--------------------------------------------------QUERIE10--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os produtos mais comprados, em quantidade, por um cliente num dado mês, por ordem decrescente.
 * @param sgv SGV que contém a informação dos módulos.
 * @param clientID char que indica o cliente do qual pretendemos obter a informação.
 * @param month int que indica o mês.
 * @return q Q10 estrutura com os resultados pretendidos.
 */
Q10 getClientFavoriteProducts(SGV sgv, char* clientID, int month){
  Q10 q = init_Q10(getTotalProdSGV(sgv));
  produtos_favoritos_cliente(sgv->f_clientes,clientID,month,q);
  return q;
}

/*--------------------------------------------------QUERIE11--------------------------------------------------*/

/**
 @brief Função que retorna uma estrutura com a lista de produtos mais vendidos em todo o ano, o número total de clientes e o número total de unidades vendidas, filial a filial.
 * @param sgv SGV que contém a informação dos módulos.
 * @param limit int que determina quantos produtos a estrutura vai ter.
 * @return q Q11 estrutura com os produtos mais vendidos.
 */
Q11 getTopSelledProducts(SGV sgv, int limit){
  Q11 q = init_Q11(getTotalProdSGV(sgv));
  produtosMaisCompradosQ11(sgv->faturacao,q);
  sortAndGetQ11(q);
  defineNClientes(sgv->f_produtos,q,limit);
  return q;
}

/*--------------------------------------------------QUERIE12--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com os códigos de um produto em que um certo cliente gastou mais dinheiro.
 * @param sgv SGV que contém a informação dos módulos.
 * @param clientID char* do qual se pretende obter a informação.
 * @param limit int que é o limite de produtos que a estrutura tem.
 * @return q Q12 estrutura com os resultados obtidos.
 */
Q12 getClientTopProfitProducts(SGV sgv, char * clientID, int limit){
  Q12 q = init_Q12(getTotalProdSGV(sgv));
  produtosMaisCarosQ12(sgv->f_clientes,clientID,q);
  sortAndGetQ12(q);
  return q;
}

/*--------------------------------------------------QUERIE13--------------------------------------------------*/

/**
 * @brief Função que retorna uma estrutura com o resultado da leitura dos ficheiros na query 1.
 * @param sgv SGV que contém a informação dos módulos.
 * @return q Q13 estrutura com os produtos mais vendidos.
 */
Q13 getCurrentFilesInfo(SGV sgv){
    Q13 q = init_Q13();
    setQ_Clientes13(q,sgv->quantidade_clientes);
    setQ_Produtos13(q,sgv->quantidade_produtos);
    setV_Validas13(q,sgv->vendas_validas);
    setV_Totais13(q,sgv->vendas_totais);
    char *clientes = malloc(BUFFER * sizeof(char));
    char *produtos = malloc(BUFFER * sizeof(char));
    char *sales = malloc(BUFFER * sizeof(char));
    strcpy(clientes,sgv->clients_File_Path);
    strcpy(produtos,sgv->products_File_Path);
    strcpy(sales,sgv->sales_File_Path);
    setClients_Path13(q,clientes);
    setProducts_Path13(q,produtos);
    setSales_Path13(q,sales);
    return q;
}
