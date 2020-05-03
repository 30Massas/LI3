/**
 * @file vista.c
 * @brief Ficheiro que contém a API relativa à implementação da vista.
 */

#include "../include/vista.h"
static void printLogo();
static void (imprime_espacos(int n));
static void imprime_menuNONE();
static void imprime_menu0();
static void imprime_menu1();
static void imprime_menu2(Boolean v);
static void imprime_menu3(Boolean v);
static void imprime_menu4(Boolean v);
static void imprime_menu5(Boolean v);
static void imprime_menu6(Boolean v);
static void imprime_menu7(Boolean v);
static void imprime_menu8(Boolean v);
static void imprime_menu9(Boolean v);
static void imprime_menu10(Boolean v);
static void imprime_menu11(Boolean v);
static void imprime_menu12(Boolean v);
static void imprime_menu13(Boolean v);

/**
 * @brief Função que imprime a escolha do utilizador.
 * @param c Escolha do utilizador.
 */
void printchoice(char c){
    switch (c)
    {
    case '1':
        LOG_GREEN("1  • Ler Ficheiros;\n");
        break;
    case '2':
        LOG_GREEN("2  • Lista e nº total de produtos começados por uma dada letra | <Letra>;\n");
        break;
    case '3':
        LOG_GREEN("3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
        break;
    case '4':
        LOG_GREEN("4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
        break;
    case '5':
        LOG_GREEN("5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
        break;
    case '6':
        LOG_GREEN("6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
        break;
    case '7':
        LOG_GREEN("7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
        break;
    case '8':
        LOG_GREEN("8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
        break;
    case '9':
        LOG_GREEN("9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
        break;
    case 'A':
        LOG_GREEN("A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
        break;
    case 'B':
        LOG_GREEN("B • Lista dos N Produtos mais vendidos | <N>;\n");
        break;
    case 'C':
        LOG_GREEN("C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
        break;
    case 'D':
        LOG_GREEN("D • Apresentar resultados da leitura;\n");
        break;
    default:
        break;
    }
}

/**
 * @brief Função que imprime o logotipo.
 */
static void printLogo() {

	if(system("clear"));
    GETCOL();
	putchar('\n');
    int a = (col_aux)/2 - 41;
    imprime_espacos(a); printf("%s _____           _                   _        _   _                _           \n",GREEN);
    imprime_espacos(a); printf("│  __ \\         │ │                 │ │      │ │ │ │              │ │          \n");
    imprime_espacos(a); printf("│ │  \\/ ___  ___│ │_ ___  _ __    __│ │ ___  │ │ │ │ ___ _ __   __│ │ __ _ ___ \n");
    imprime_espacos(a); printf("│ │ __ / _ \\/ __│ __/ _ \\│ '__│  / _` │/ _ \\ │ │ │ │/ _ \\ '_ \\ / _` │/ _` / __│\n");
    imprime_espacos(a); printf("│ │_\\ \\  __/\\__ \\ ││ (_) │ │    │ (_│ │  __/ \\ \\_/ /  __/ │ │ │ (_│ │ (_│ \\__ \\\n");
    imprime_espacos(a); printf(" \\____/\\___││___/\\__\\___/│_│     \\__,_│\\___│  \\___/ \\___│_│ │_│\\__,_│\\__,_│___/\n");
    imprime_espacos(a); printf("  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n%s",RESET);


}
/**
 * @brief Função que imprime os resultados da Query 2.
 * @param a Lista de Produtos começados pela letra dada pelo Utilizador.
 * @param aux Letra dada pelo Utilizador.
 * @param i Página atual onde o Utilizador se encontra.
 * @param f Número de produtos por página.
 * @param num Total de elementos no array de Produtos.
 * @param pag Número total de páginas.
 */
void querie2Print(char **a, char aux, int i, int f, int num,int pag){
    int atual = i + 1;
    int k = f;
    i = i * f;
    f = i + f;
    int col;
  printf("\n%s%42s%s\n",BOLDCYAN,"RESULTADOS QUERIE2",RESET);
  for(;i<f && i<num;){
    for(col=0;col<6 && i<f && i<num; i++,col++)
        printf("| %s | ", a[i]);
    puts("\n");
  }

  printf("%32d/%d(%d)\n",atual,pag,k);
  printf("%153s\n","┌──────────────────────────────────────────────┐");
  printf("%46s%c :   %s%-7d%s│\n","│ TOTAL DE PRODUTOS COMEÇADOS POR ", aux,GREEN,num,RESET);
  printf("%153s\n","└──────────────────────────────────────────────┘");
  printf("%44s\n","1 <- previous || 2 -> next");
  printf("%19s %s(-)%s clients || 4 -> %s(+)%s clients\n","3 <-",RED,RESET,RED,RESET);
}
/**
 * @brief Função que imprime os resultados da Query 3.
 * @param qt_nq Vendas registadas em regime Normal.
 * @param fat_nq Faturação total em regime Normal.
 * @param qt_pq Vendas registadas em regime Promocional.
 * @param fat_pq Faturação total em regime Promocional.
 * @param product Produto introduzido pelo Utilizador.
 * @param month Mês introduzido pelo Utilizador.
 */
void querie3Print(int qt_nq, float fat_nq, int qt_pq, float fat_pq, char* product, int month){
    char *meses[MESES] = {"JANEIRO","FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};

  printf("\n┌───────────────────────RESULTADOS QUERIE3─────────────────────────┐\n");

  printf("│ -> PRODUTO :  %s%-23s%sMÊS :  %s%-21s%s│\n", RED,product,RESET,RED, meses[month-1],RESET);

  printf("├──────────────────────────────────────────────────────────────────┤\n");

  printf("│ -> VENDAS REGISTADAS EM REGIME NORMAL:  %s%-25d%s│\n",GREEN, qt_nq,RESET);

  printf("│ -> FATURAÇÃO TOTAL   EM REGIME NORMAL:  %s%-25f%s│\n", GREEN,fat_nq,RESET);

  printf("│ -> VENDAS REGISTADAS EM REGIME PROMOCIONAL:  %s%-20d%s│\n", GREEN,qt_pq,RESET);

  printf("│ -> FATURAÇÃO TOTAL   EM REGIME PROMOCIONAL:  %s%-20f%s│\n", GREEN,fat_pq,RESET);

  printf("└──────────────────────────────────────────────────────────────────┘\n");
}
/**
 * @brief Função que imprime os resultados da Query 4.
 * @param filial Escolha do utilizador entre Global, ou Filial.
 * @param a Lista de Produtos não comprados, por filial, ou global.
 * @param total Total de elementos no array de Produtos.
 * @param atual Página atual onde o Utilizador se encontra.
 * @param prodPorPag Número de produtos por página.
 * @param totalpag Número total de páginas.
 */
void querie4Print(int filial, char **a, int total, int atual, int prodPorPag, int totalpag){
    int k = prodPorPag;
    int paginaAtual = atual+1;
    atual *= prodPorPag;
    prodPorPag += atual;
    int col=0;
    if(filial==0) {
        printf("%s%42s%s\n",BOLDCYAN,"Resultado Global: ",RESET);
        printf("%46s%s%d%s\n","PRODUTOS NÃO COMPRADOS GLOBAL: ",GREEN,total,RESET);
        printf("┌────────┬─┬────────┬─┬────────┬─┬────────┬─┬────────┬─┬────────┐\n");
        for(;atual<prodPorPag && atual < total;){
            for(col = 0; col < 6 && atual < prodPorPag && atual < total;atual++,col++)
                printf("│ %s │ ",a[atual]);
            if(atual<prodPorPag && atual < total) printf("\n│        │ │        │ │        │ │        │ │        │ │        │\n");
        }
        for(;col<6;col++)printf("│        │ ");
        printf("\n└────────┴─┴────────┴─┴────────┴─┴────────┴─┴────────┴─┴────────┘\n");
    }
    else{
        printf("%s%42s %d%s\n",BOLDCYAN,"Resultado da Filial ",filial,RESET);
        printf("%46s %d: %s%d%s\n","PRODUTOS NÃO COMPRADOS NA FILIAL",filial,GREEN, total,RESET );

        printf("┌────────┬─┬────────┬─┬────────┬─┬────────┬─┬────────┬─┬────────┐\n");
        for(;atual<prodPorPag && atual < total;){
            for(col = 0; col < 6 && atual < prodPorPag && atual < total;atual++,col++)
                printf("│ %s │ ",a[atual]);
            if(atual<prodPorPag && atual < total) printf("\n│        │ │        │ │        │ │        │ │        │ │        │\n");
        }
        for(;col<6;col++)printf("│        │ ");
        printf("\n└────────┴─┴────────┴─┴────────┴─┴────────┴─┴────────┴─┴────────┘\n");
    }
    printf("%32d/%d(%d)\n",paginaAtual,totalpag,k);
    printf("%44s\n","1 <- previous || 2 -> next");
    printf("%19s %s(-)%s clients || 4 -> %s(+)%s clients\n","3 <-",RED,RESET,RED,RESET);
    printf("%34sq%s -> exit\n",RED,RESET);
}

/**
 * @brief Função que imprime os resultados da Query 5.
 * @param a Lista de Clientes que realizaram compras em todas as filiais.
 * @param total Total de elementos no array de Clientes.
 * @param atual Página atual onde o Utilizador se encontra.
 * @param prodPorPag Número de produtos por página.
 * @param totalpag Número total de páginas.
 */
void querie5Print(char **a, int total, int atual, int prodPorPag, int totalpag){

    int i = atual + 1;
    int k = prodPorPag;
    atual = atual * prodPorPag;
    prodPorPag = atual + prodPorPag;
    int col;
  printf("\n%s%39s%s\n",BOLDCYAN,"RESULTADOS QUERIE5",RESET);
  for(;atual<prodPorPag && atual<total;){
    for(col=0;col<6 && atual<prodPorPag && atual<total; atual++,col++)
        printf("| %s | ", a[atual]);
    puts("\n");
  }

  printf("%29d/%d(%d)\n",i,totalpag,k);
  printf("%148s\n","┌──────────────────────────────────────────────┐");
  printf("%26s     :   %s%-18d%s│\n","│ TOTAL DE CLIENTES ",GREEN,total,RESET);
  printf("%148s\n","└──────────────────────────────────────────────┘");
  printf("%41s\n","1 <- previous || 2 -> next");
  printf("%16s %s(-)%s clients || 4 -> %s(+)%s clients\n","3 <-",RED,RESET,RED,RESET);
  printf("%31sq%s -> exit\n",RED,RESET);
}

/**
 * @brief Função que imprime os resultados da Query 6.
 * @param prod Número de Produtos que ninguém comprou.
 * @param c Número de Clientes que não realizaram compras.
 */
void querie6Print(int prod, int c){
    printf("%153s\n","┌──────────────────────────────────────────────┐");
    printf("         │ Clients : %s%-10d%s  | Products : %s%-10d%s│\n",GREEN,c,RESET,GREEN,prod,RESET);
    printf("%153s\n","└──────────────────────────────────────────────┘");
}

/**
 * @brief Função que imprime os resultados da Query 7.
 * @param q Estrutura que contém uma matriz de quantidades por filal/mes.
 * @param a Número da página em que o Utilizador se encontra.
 */
void querie7Print(Q7 q, int n){
    int i,j=0;
    char *meses[MESES] = {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

    char *nfiliais[FILIAL] = {"            ___    _              _         _ \n          /'___)_ (_ )  _        (_ )     /' )\n         | (__ (_) | | (_)   _ _  | |    (_, |\n         | ,__)| | | | | | /'_` ) | |      | |\n         | |   | | | | | |( (_| | | |      | |\n         (_)   (_)(___)(_)`\\__,_)(___)     (_)\n","            ___    _              _         __   \n          /'___)_ (_ )  _        (_ )     /'__`\\ \n         | (__ (_) | | (_)   _ _  | |    (_)  ) )\n         | ,__)| | | | | | /'_` ) | |       /' / \n         | |   | | | | | |( (_| | | |     /' /( )\n         (_)   (_)(___)(_)`\\__,_)(___)   (_____/'\n","            ___    _              _         ___ \n          /'___)_ (_ )  _        (_ )     /'_  )\n         | (__ (_) | | (_)   _ _  | |    (_)_) |\n         | ,__)| | | | | | /'_` ) | |     _(_ < \n         | |   | | | | | |( (_| | | |    ( )_) |\n         (_)   (_)(___)(_)`\\__,_)(___)   `\\____)\n"};


    int k;

    printf("\n%s%37s%s\n",BOLDCYAN,"RESULTADOS QUERIE7",RESET);

    printf("%s\n",nfiliais[n]);

    for(i=0;i<3;i++){
            printf("┌────%s%s%s────┐  ┌────%s%s%s────┐  ┌────%s%s%s────┐  ┌────%s%s%s────┐\n",BOLDCYAN,meses[i*3+0],RESET,BOLDCYAN,meses[i*3+1],RESET,BOLDCYAN,meses[i*3+2],RESET,BOLDCYAN,meses[i*3+3],RESET);
        for(j=0;j<4;j++){
            k = getQt_FilialQ7(q,n,i*3+j);
            if( k < 10)
                printf("│%6d     │  ",k);
            else
                printf("│%7d    │  ",k);
            }
        printf("\n└───────────┘  └───────────┘  └───────────┘  └───────────┘\n");

    }
    printf("%40s\n","1 <- previous || 2 -> next");
    printf("%30sq%s -> exit\n",RED,RESET);

}

/**
 * @brief Função que imprime os resultados da Query 8.
 * @param month1 Mês 1, selecionado pelo Utilizador.
 * @param month2 Mês 2, selecionado pelo Utilizador.
 * @param q Estrutura com os resultados de vendas totais, e total faturado.
 */
void querie8Print(int month1, int month2, Q8 q){
  char buffer[128];
  int a;
  char *meses[MESES] = {"JANEIRO","FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};

  printf("\n┌────────────────────────RESULTADOS QUERIE8────────────────────────┐\n");
  a = sprintf(buffer,"│ ->VALORES ENTRE O MÊS DE %s--%s--%s E O MÊS DE %s--%s--%s",RED,meses[month1-1],RESET,RED,meses[month2-1],RESET);
  printf("%s",buffer);
  for(;a<89;a++) printf(" ");
  puts("│");
  printf("├──────────────────────────────────────────────────────────────────┤\n");
  a = sprintf(buffer,"│ -> VENDAS REGISTADAS  :  %s%d%s",GREEN,getNVendas_Q8(q),RESET);
  printf("%s",buffer);
  for(;a<78;a++) printf(" ");
  puts("│");
  printf("│                                                                  │\n");
  a = sprintf(buffer,"│ -> FATURAÇÃO TOTAL    :  %s%f%s", GREEN,getFat_Q8(q),RESET);
  printf("%s",buffer);
  for(;a<80;a++) printf(" ");
  puts("│");
  printf("│                                                                  │\n");
  printf("└──────────────────────────────────────────────────────────────────┘\n");
}

/**
 * @brief Função que imprime os resultados da Query 9.
 * @param n Lista de Clientes que compraram o produto em modo N.
 * @param totaln Total de Clientes que compraram o produto em modo N.
 * @param p Lista de Clientes que compraram o produto em modo P.
 * @param totalp Total de Clientes que compraram o produto em modo P.
 */
void querie9Print(char **n, int totaln, char **p, int totalp){
    printf("\n   %sModo N(%s%d%s):%s \n",BOLDWHITE,BOLDCYAN,totaln,BOLDWHITE,RESET);
    int i;
    for(i=0;i<totaln;i++) printf("%s%8s%s%s\n",BOLDCYAN,":",RESET,n[i]);
    printf("   %sModo P(%s%d%s):%s \n",BOLDWHITE,BOLDCYAN,totalp,BOLDWHITE,RESET);
    for(i=0;i<totalp;i++) printf("%s%8s%s%s\n",BOLDCYAN,":",RESET,p[i]);
    printf("\n");
}


/**
 * @brief Função que imprime os resultados da Query 10.
 * @param q Estrutura que contém os resultados da Query 10.
 * @param mes Mês introduzido pelo utilizador.
 */
void querie10Print(Q10 q,int mes){
    int i,k;
    char *meses[MESES] = {"JANEIRO","FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};
    int r = 9 - (strlen(meses[mes-1])/2);
    int total = getNum_TotalQ10(q);
    printf("\n");
    imprime_espacos(r);
    printf("%s%s%s\n",YELLOW,meses[mes-1],RESET);
    printf("┌────────┬────────┐\n");
    for(i=0;i<total;i++){
        k = getQ10QtdProduto(q,i);
        if(k>=0 && k <10)printf("│ %s%s%s │%5d   │\n",BOLDCYAN,getProdutoQ10(q,i),RESET,k);
        else printf("│ %s%s%s │%5d   │\n",BOLDCYAN,getProdutoQ10(q,i),RESET,k);
        if(i < total-1)
            printf("├────────┼────────┤\n");
    }
    printf("└────────┴────────┘\n");

}

/**
 * @brief Função que imprime os resultados da Query 11.
 * @param q Estrutura que contém os resultados da Query 11.
 * @param total Número máximo de elementos.
 * @param atual Página atual onde o Utilizador se encontra.
 * @param codePorPag Número de elementos por página.
 * @param totalpag Número total de páginas.
 */
void querie11Print(Q11 q, int total,int atual, int codePorPag,int totalPag){
    int i = atual +1;
    int k = codePorPag;
    atual *= codePorPag;
    codePorPag+=atual;
    int col;
    printf("\n%s%s%s\n",YELLOW,"RESULTADOS QUERIE11",RESET);
    for(;atual<codePorPag && atual < total;atual++){
        printf("%sCode:%s %-8s %sn_buyers:%s %-4d ",BOLDCYAN,RESET,getProdutoQ11(q,atual),BOLDCYAN,RESET, getQ11NClientes(q,atual));
        for(col = 0; col<FILIAL; col++)
            printf("%sn_sold_f%d:%s %-7d",BOLDCYAN,col+1,RESET,getQtdFilialQ11(q,atual,col));
        printf("%sn_sold_total:%s %-6d\n",BOLDCYAN,RESET,getQ11QtdProduto(q,atual));
    }
    printf("\n%45d/%d(%d)\n",i,totalPag,k);
    printf("%57s\n","1 <- previous || 2 -> next");
    printf("%32s %s(-)%s clients || 4 -> %s(+)%s clients\n","3 <-",RED,RESET,RED,RESET);
    printf("%47sq%s -> exit\n",RED,RESET);

}

/**
 * @brief Função que imprime os resultados da Query 12.
 * @param q Estrutura que contém os resultados da Query 12.
 * @param total Número máximo de elementos.
 * @param atual Página atual onde o Utilizador se encontra.
 * @param codePorPag Número de elementos por página.
 * @param totalpag Número total de páginas.
 */
void querie12Print(Q12 q, int total,int atual, int codePorPag, int totalPag){
    int i = atual +1;
    int k = codePorPag;
    atual *= codePorPag;
    codePorPag+=atual;
    int col;
    printf("\n%s%s%s\n",YELLOW,"RESULTADOS QUERIE12",RESET);
    for(;atual<codePorPag && atual < total;){
        for(col = 0; col<3 && atual < codePorPag && atual < total;atual++, col++)
            printf("│ %s%s%s - %-14f ",BOLDCYAN,getProdutoQ12(q,atual),RESET,getQ12Faturado(q,atual));
        printf("│\n");
    }
    printf("\n%44d/%d(%d)\n",i,totalPag,k);
    printf("%56s\n","1 <- previous || 2 -> next");
    printf("%31s %s(-)%s clients || 4 -> %s(+)%s clients\n","3 <-",RED,RESET,RED,RESET);
    printf("%46sq%s -> exit\n",RED,RESET);

}

/**
 * @brief Função que imprime os resultados da Query 13.
 * @param q Estrutura que contém os resultados da Query 13.
 */
void querie13Print(Q13 q){
    char *c = getClients_Path13(q);
    char *p = getProducts_Path13(q);
    char *s = getSales_Path13(q);
    printf("\n%s%47s%s\n",BOLDCYAN,"RESULTADOS QUERIE13",RESET);
    printf("┌───────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│ Quantidade total de clientes----------%s%-40d%s│\n",GREEN,getQ_Clientes13(q),RESET);
    printf("│ Quantidade total de produtos----------%s%-40d%s│\n",GREEN,getQ_Produtos13(q),RESET);
    printf("│ Quantidade total de vendas válidas----%s%-40d%s│\n",GREEN,getV_Validas13(q),RESET);
    printf("│ Quantidade total de vendas lidas------%s%-40d%s│\n",GREEN,getV_Totais13(q),RESET);
    printf("│ Ficheiro lido dos Clientes------------%s%-40s%s│\n",GREEN,c,RESET);
    printf("│ Ficheiro lido dos Produtos------------%s%-40s%s│\n",GREEN,p,RESET);
    printf("│ Ficheiro lido das Vendas--------------%s%-40s%s│\n",GREEN,s,RESET);
    printf("└───────────────────────────────────────────────────────────────────────────────┘\n");

}
/**
 * @brief Função que imprime o menú correspondente ao estado atual.
 * @param n Opção escolhida pelo Utilizador.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
void imprime_menu(char n, Boolean v){
    printLogo();
    switch (n)
    {
    case '0':
        imprime_menu0();
        break;
    case '1':
        imprime_menu1();
        break;
    case '2':
        imprime_menu2(v);
        break;
    case '3':
        imprime_menu3(v);
        break;
    case '4':
        imprime_menu4(v);
        break;
    case '5':
        imprime_menu5(v);
        break;
    case '6':
        imprime_menu6(v);
        break;
    case '7':
        imprime_menu7(v);
        break;
    case '8':
        imprime_menu8(v);
        break;
    case '9':
        imprime_menu9(v);
        break;
    case 'A':
        imprime_menu10(v);
        break;
    case 'B':
        imprime_menu11(v);
        break;
    case 'C':
        imprime_menu12(v);
        break;
    case 'D':
        imprime_menu13(v);
        break;

    default:
        imprime_menuNONE();
        break;
    }

}
/**
 * @brief Função que imprime espaços.
 * @param n Número de espaços a serem imprimidos.
 */
static void (imprime_espacos(int n)){
    int i;
    for(i = 0; i<n; i++) printf(" ");
}
/**
 * @brief Função que imprime menu sem opção selecionada.
 */
static void imprime_menuNONE(){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 0 selecionada.
 */
static void imprime_menu0(){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    LOG_GREEN("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 1 selecionada.
 */
static void imprime_menu1(){
    LOG_GREEN("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 2 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu2(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    if(v) LOG_GREEN("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    else LOG_RED("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 3 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu3(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    if(v) LOG_GREEN("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    else LOG_RED("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");

    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 4 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu4(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    if(v) LOG_GREEN("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    else LOG_RED("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 5 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu5(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    if(v) LOG_GREEN("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    else LOG_RED("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 6 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu6(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    if(v) LOG_GREEN("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    else LOG_RED("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 7 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu7(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    if(v) LOG_GREEN("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    else  LOG_RED("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 8 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu8(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    if(v) LOG_GREEN("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    else LOG_RED("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção 9 selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu9(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    if(v) LOG_GREEN("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    else LOG_RED("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção A selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu10(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    if(v) LOG_GREEN("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    else LOG_RED("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção B selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu11(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    if(v) LOG_GREEN("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    else LOG_RED("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção C selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu12(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    if(v) LOG_GREEN("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    else LOG_RED("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    printf("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
/**
 * @brief Função que imprime menu com a opção D selecionada.
 * @param v Boolean que indica se o estado está carregado, ou não.
 */
static void imprime_menu13(Boolean v){
    printf("\n     1  • Ler Ficheiros;\n");
    printf("     2  • Lista e número total de produtos começados por uma dada letra | <Letra>;\n");
    printf("     3  • Apresentar número total de vendas e total faturado num mês com um dado produto, N e/ou P | <Produto> <Mes>;\n");
    printf("     4  • Lista Ordenada dos códigos dos produtos que ninguém comprou | <Total>/<Filial>:\n");
    printf("     5  • Lista ordenada de Clientes que realizaram compras em todas as filiais;\n");
    printf("     6  • Número de Clientes registados que não realizaram compras e Produtos que ninguém comprou;\n");
    printf("     7  • Número total de Produtos comprados por um dado Cliente | <Cliente>;\n");
    printf("     8  • Determinar o Total de Vendas registadas e Total Faturado num intervalo de tempo | <Mês / Mẽs>;\n");
    printf("     9  • Lista dos Clientes que compraram um certo produto/N/P | <Produto> <Filial>;\n");
    printf("     A • Lista de Produtos mais comprados (quantidade) | <Cliente> <Mês>;\n");
    printf("     B • Lista dos N Produtos mais vendidos | <N>;\n");
    printf("     C • Lista dos N Produtos em que mais gastou dinheiro | <Cliente>;\n");
    if(v) LOG_GREEN("     D • Apresentar resultados da leitura;\n");
    else LOG_RED("     D • Apresentar resultados da leitura;\n");
    printf("     0  • Sair.\n");
}
