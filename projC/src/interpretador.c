/**
 * @file interpretador.c
 * @brief Ficheiro que contém a API relativa à implementação do interpretador.
 */

#include "../include/interpretador.h"
#include "time.h"

#define clients_path_default "dados/Clientes.txt"
#define products_path_default "dados/Produtos.txt"
#define sales_path_default "dados/Vendas_1M.txt"

static void loadFromFiles(SGV sgv);
static char* upper_string(char s[]);

    clock_t t1;
    clock_t t6;
    clock_t t7;
    clock_t t8;
    clock_t t9;
    clock_t t10;
    clock_t t11;
    clock_t t12;
    double time_taken;
    char choice = 'l';


/**
 * @brief Função que vai recebendo os inputs do utilizador, passa-os às funções respetivas e retorna o output.
 * @param sgv SGV que contém a informação dos módulos.
 * @return int com o output.
 */
int interpreter(SGV sgv){
    Q2 q2;
    Q3 q3;
    Q5 q5;
    Q6 q6;
    Q7 q7;
    Q8 q8;
    Q9 q9;
    Q10 q10;
    Q11 q11;
    Q12 q12;
    Q13 q13;
    int num_auxiliar_1;
    int num_auxiliar_2;
    int num_auxiliar_3;
    int filial;
    int pag;
    int pagAtual;
    int total;
    char char_aux;
    char letter;
    char input[BUFFER];
    char input2[BUFFER];


    Boolean validado;

    while(1){
        validado = isSGVvalid(sgv);
        imprime_menu(choice,validado);

        printf("> ");
        if(system("stty raw"));
        if(system("stty -echo"));

        while ((char_aux = getchar()) != 13) /* 13 -> ENTER */
        {
            if(system("stty cooked"));
            if(system("stty echo"));
            if(isSGVvalid(sgv));
            imprime_menu((choice = toupper(char_aux)),validado);
            if(system("stty raw"));
            if(system("stty -echo"));
        }

        if(system("stty cooked"));
        if(system("stty echo"));


        if(choice == '0'){
            /*if(system("clear"));*/
            return END;
        }

        if(choice == '1' || isSGVvalid(sgv)){
        if(system("clear"));
        printchoice(choice);


        switch (choice)
        {
        case '1':
            loadFromFiles(sgv);
            break;
        case '2':
            printf("Letra: ");
            if(system("stty raw"));
            if(system("stty -echo"));
            while((letter = toupper(getchar())) != 13 && !isalpha(letter)){
                if(system("stty cooked"));
                if(system("clear"));
                printchoice(choice);
                LOG_RED("Letra invállida\n");
                printf("Letra: ");
                if(system("stty raw"));
            }
            if(letter == 13) return 1;

            q2 = getProductsStartedByLetter(sgv,letter);
            num_auxiliar_1 = 0;
            num_auxiliar_2 = NR_PAG;
            num_auxiliar_3 = getNum_TotalQ2(q2);
            char **d = getLista_ProdsQ2(q2);
            if(num_auxiliar_3%num_auxiliar_2 == 0) pag = num_auxiliar_3/num_auxiliar_2;
            else pag = num_auxiliar_3/num_auxiliar_2 + 1;

            if(system("stty cooked"));
            if(system("clear"));
            printchoice(choice);
            printf("Letra: %s%c%s\n",GREEN,letter,RESET);
            querie2Print(d, letter,num_auxiliar_1,num_auxiliar_2,num_auxiliar_3,pag);
            if(system("stty raw"));
            while ((char_aux = toupper(getchar())) != 13) /* 13 -> ENTER */
            {
                if(char_aux == '2' && num_auxiliar_1 < pag-1) num_auxiliar_1++;
                else if(char_aux == '1' && num_auxiliar_1 > 0) num_auxiliar_1--;
                else if(char_aux == '3' && num_auxiliar_2>NR_PAG) {
                    num_auxiliar_2 -= NR_PAG;
                    num_auxiliar_1 = 0;
                    if(num_auxiliar_3%num_auxiliar_2 == 0) pag = num_auxiliar_3/num_auxiliar_2;
                    else pag = num_auxiliar_3/num_auxiliar_2 + 1;
                }
                else if(char_aux == '4' && num_auxiliar_2<3*NR_PAG){
                    num_auxiliar_2 += NR_PAG;
                    num_auxiliar_1 = 0;
                    if(num_auxiliar_3%num_auxiliar_2 == 0) pag = num_auxiliar_3/num_auxiliar_2;
                    else pag = num_auxiliar_3/num_auxiliar_2 + 1;
                }
                else if(isalpha(char_aux)){
                    num_auxiliar_1 = 0;
                    letter = char_aux;
                    freeQ2(q2);
                    q2 = getProductsStartedByLetter(sgv,letter);
                    d = getLista_ProdsQ2(q2);
                    num_auxiliar_3 = getNum_TotalQ2(q2);
                    if(num_auxiliar_3%num_auxiliar_2 == 0) pag = num_auxiliar_3/num_auxiliar_2;
                    else pag = num_auxiliar_3/num_auxiliar_2 + 1;
                }
                if(system("stty cooked"));
                if(system("clear"));
                printchoice(choice);
                printf("Letra: %s%c%s\n",GREEN,letter,RESET);
                querie2Print(d, letter,num_auxiliar_1,num_auxiliar_2,num_auxiliar_3,pag);
                if(system("stty raw"));

            }
            if(system("stty cooked"));
            if(system("stty echo"));
            freeQ2(q2);
            return RUN;
            break;
        case '3':
            while(1){
                printf("Número do produto: ");
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                upper_string(input);
                if(isalpha(input[0]) && isalpha(input[1]) && isdigit(input[2]) && isdigit(input[3]) && isdigit(input[4]) && isdigit(input[5]) && input[6] == '\0' && existeSGVProduto(sgv,input)){
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do produto: %s%s%s\n",GREEN,input,RESET);
                    printf("Mês: ");

                    while(fgets(input2,BUFFER,stdin)){
                        if(input2[0] == '\n') return RUN;
                        num_auxiliar_2 = atoi(input2);
                        if(num_auxiliar_2>0 && num_auxiliar_2<13)break;
                        if(system("clear"));
                        printchoice(choice);
                        printf("Número do produto: %s%s%s\n",GREEN,input,RESET);
                        LOG_RED("Mês inválido\n");
                        printf("Mês: ");
                    }
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do produto: %s%s%s\n",GREEN,input,RESET);
                    printf("Mês: %s%d%s\n",GREEN,num_auxiliar_2,RESET);
                    q3 = getProductSalesAndProfit(sgv, upper_string(input), num_auxiliar_2);
                    int qt_nq = getQt_NQ3(q3);
                    float fat_nq = getFat_NQ3(q3);
                    int qt_pq = getQt_PQ3(q3);
                    float fat_pq = getFat_PQ3(q3);
                    querie3Print(qt_nq,fat_nq,qt_pq,fat_pq,input,num_auxiliar_2);
                    free(q3);
                }
                else {
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número de produto inválido\n");
                }

            }
            break;
        case '4':
            printf("Global ( '0' ) ou Filial ( Refira a Filial): ");
            while(1){
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                if(isdigit(input[0])){
                    filial = atoi(input);
                    if(filial >= 0 && filial <= FILIAL) break;
                }
                if(system("clear"));
                printchoice(choice);
                LOG_RED("Número inválido; <enter> para sair\n");
                printf("Global ( '0' ) ou Filial ( Refira a Filial): ");
            }
            pagAtual = 0;
            num_auxiliar_2 = NR_PAG;
            q2 = getProductsNeverBought(sgv,filial);
            char **c = getLista_ProdsQ2(q2);
            total = getNum_TotalQ2(q2);
            if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
            else pag = total/num_auxiliar_2 + 1;

            if(system("clear"));
            querie4Print(filial,c,total,pagAtual, num_auxiliar_2,pag);
            if(system("stty raw"));
            if(system("stty -echo"));

            while ((char_aux = toupper(getchar())) != 13 && char_aux != 'Q') {/* 13 -> ENTER */
                if(char_aux == '1' && pagAtual > 0) pagAtual--;
                else if(char_aux == '2' && pagAtual < pag-1) pagAtual++;
                else if(char_aux == '3' && num_auxiliar_2>NR_PAG) {
                    num_auxiliar_2-=NR_PAG;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                else if(char_aux == '4' && num_auxiliar_2<3*NR_PAG) {
                    num_auxiliar_2+=NR_PAG;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                if(system("stty cooked"));
                if(system("clear"));

                querie4Print(filial,c,total,pagAtual, num_auxiliar_2,pag);
                if(system("stty raw"));
            }
            if(system("stty cooked"));
            if(system("stty echo"));
            freeQ2(q2);
            if(char_aux == 'Q') return RUN;
            break;
        case '5':
            /*querie5();*/
            pagAtual = 0;
            num_auxiliar_2 = NR_PAG;
            q5 = getClientsOffAllBranches(sgv);
            char **a = getLista_ClientesQ5(q5);
            total = getNum_TotalQ5(q5);
            if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
            else pag = total/num_auxiliar_2 + 1;

            if(system("clear"));
            printchoice(choice);
            querie5Print(a,total,pagAtual,num_auxiliar_2,pag);
            if(system("stty raw"));
            if(system("stty -echo"));
            while ((char_aux = toupper(getchar())) != 13 && char_aux != 'Q') {/* 13 -> ENTER */
                if(char_aux == '1' && pagAtual > 0) pagAtual--;
                else if(char_aux == '2' && pagAtual < pag-1) pagAtual++;
                else if(char_aux == '3' && num_auxiliar_2>NR_PAG) {
                    num_auxiliar_2-=NR_PAG;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                else if(char_aux == '4' && num_auxiliar_2<3*NR_PAG) {
                    num_auxiliar_2+=NR_PAG;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                if(system("stty cooked"));
                if(system("clear"));
                printchoice(choice);
                querie5Print(a,total,pagAtual,num_auxiliar_2,pag);
                if(system("stty raw"));
            }
            if(system("stty cooked"));
            if(system("stty echo"));
            freeQ5(q5);
            if(char_aux == 'Q') return RUN;
            break;
        case '6':
            t6 = clock();
            q6 = getClientsAndProductsNeverBoughtCount(sgv);
            t6 = clock() - t6;
            num_auxiliar_1 = getNumProdsQ6(q6);
            num_auxiliar_2 = getNumClientessQ6(q6);
            querie6Print(num_auxiliar_1,num_auxiliar_2);
            free(q6);
            break;
        case '7':
            while(1){
                printf("Número do cliente: ");
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                upper_string(input);

                if(!(isalpha(input[0]) && isdigit(input[1]) && isdigit(input[1]) && isdigit(input[3]) && isdigit(input[4]) && input[5] == '\0' && existeSGVCliente(sgv,input))){
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número de cliente inválido\n");
                }
                else{
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do cliente: %s%s%s\n",GREEN,input,RESET);
                    break;
                }
            }
            t7 = clock();
            q7 = getProductsBoughtByClient(sgv,input);
            t7 = clock() - t7;
            pag = 1;
            querie7Print(q7,pag-1);
            if(system("stty raw"));
            if(system("stty -echo"));
            while((char_aux = toupper(getchar())) != 13 && char_aux != 'Q'){
                if(system("clear"));
                if(system("stty cooked"));
                printchoice(choice);
                printf("Número do cliente: %s%s%s\n",GREEN,input,RESET);
                if(char_aux == '1' && pag > 1) pag--;
                else if(char_aux == '2' && pag < 3) pag++;

                querie7Print(q7,pag-1);
                if(system("stty raw"));
            }
            if(system("stty cooked"));
            if(system("stty echo"));
            free(q7);
            if(char_aux == 'Q') return RUN;
            break;
        case '8':
            while (1)
            {
                printf("Mês 1: ");
                if(scanf("%d",&num_auxiliar_2));
                getchar();
                if(num_auxiliar_2 < 1 || num_auxiliar_2 > 12) {
                    if(system("clear"));
                    printchoice('8');
                    LOG_RED("mês inválido\n");
                }
                else {
                    if(system("clear"));
                    printchoice('8');
                    printf("%sMês 1: %d%s\n",GREEN,num_auxiliar_2,RESET);
                    break;
                }
            }
            while (1)
            {
                printf("Mês 2: ");
                if(scanf("%d",&num_auxiliar_1));
                getchar();
                if(num_auxiliar_1 < 1 || num_auxiliar_1 > 12 || num_auxiliar_1<num_auxiliar_2) {
                    if(system("clear"));
                    printchoice('8');
                    LOG_RED("mês inválido\n");
                    printf("%sMês 1: %d%s\n",GREEN,num_auxiliar_2,RESET);
                }
                else {
                    if(system("clear"));
                    printchoice('8');
                    printf("%sMês 1: %d%s\n",GREEN,num_auxiliar_2,RESET);
                    printf("%sMês 2: %d%s\n",GREEN,num_auxiliar_1,RESET);
                    break;
                }
            }
            t8 = clock();
            q8 = getSalesAndProfit(sgv,num_auxiliar_2,num_auxiliar_1);
            t8 = clock() - t8;
            querie8Print(num_auxiliar_2,num_auxiliar_1,q8);
            free(q8);
            break;
        case '9':
            /*querie9();*/
            while(1){
                printf("Número do Produto: ");
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                upper_string(input);
                if(isalpha(input[0]) && isalpha(input[1]) && isdigit(input[2]) && isdigit(input[3]) && isdigit(input[4]) && isdigit(input[5]) && input[6] == '\0' && existeSGVProduto(sgv,input)){
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do Produto: %s%s%s\n",GREEN,input,RESET);
                    printf("Filial: ");
                    while(fgets(input2,BUFFER,stdin)){
                        if(input2[0] == '\n') return RUN;
                        num_auxiliar_1 = atoi(input2);
                        if(num_auxiliar_1 > 0 && num_auxiliar_1 < FILIAL+1){
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Produto: %s%s%s\n",GREEN,input,RESET);
                            printf("Filial: %s%d%s\n",GREEN,num_auxiliar_1,RESET);
                            break;
                        }
                        else {
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Produto: %s%s%s\n",GREEN,input,RESET);
                            LOG_RED("Filial inválida\n");
                            printf("Filial: ");
                        }
                    }
                    t9 = clock();
                    q9 = getProductBuyers(sgv,input,num_auxiliar_1);
                    t9 = clock() - t9;

                    num_auxiliar_2 = getTotalNQ9(q9);
                    char **n = getLista_ProdsNQ9(q9);
                    num_auxiliar_3 = getTotalPQ9(q9);
                    char **p = getLista_ProdsPQ9(q9);

                    querie9Print(n,num_auxiliar_2,p,num_auxiliar_3);

                    freeQ9(q9);
                }
                else {
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número de Produto inválido\n");
                }
            }
            break;
        case 'A':
            /*querie10();*/
            while(1){
                printf("Número do Cliente: ");
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                upper_string(input);
                if(isalpha(input[0]) && isdigit(input[1]) && isdigit(input[2]) && isdigit(input[3]) && isdigit(input[4]) && input[5] == '\0' && existeSGVCliente(sgv,input)){
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                    printf("Mês: ");
                    while(fgets(input2,BUFFER,stdin)){
                        if(input2[0] == '\n') return RUN;
                        num_auxiliar_1 = atoi(input2);
                        if(num_auxiliar_1 > 0 && num_auxiliar_1 < MESES+1){
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                            printf("Mês: %s%d%s\n",GREEN,num_auxiliar_1,RESET);
                            break;
                        }
                        else {
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                            LOG_RED("Mês inválido\n");
                            printf("Mês: ");
                        }
                    }
                    t10 = clock();
                    q10 = getClientFavoriteProducts(sgv,input,num_auxiliar_1);
                    sortAndGetQ10(q10);
                    t10 = clock() - t10;
                    querie10Print(q10,num_auxiliar_1);
                    freeQ10(q10);
                }
                else {
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número de Cliente inválido\n");
                }

            }

            break;
        case 'B':
            /*querie11();*/
            printf("Número de Produtos a apresentar: ");
            while(1){
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                int i;
                int boolean = 1;
                for(i=0;i<strlen(input) && boolean ;i++) if(!isdigit(input[i])) boolean = 0;
                if(boolean){
                    num_auxiliar_1 = atoi(input);
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número de Produtos a apresentar: %d\n",num_auxiliar_1);
                    break;
                }
                else
                {
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número introduzido inválido\n");
                    printf("Número de Produtos a apresentar: ");
                }

            }
            t11 = clock();
            q11 = getTopSelledProducts(sgv,num_auxiliar_1);
            t11 = clock() - t11;

            pagAtual = 0;
            num_auxiliar_2 = 10;
            num_auxiliar_3 = getNum_TotalQ11(q11);

            total = (num_auxiliar_1 > num_auxiliar_3) ? num_auxiliar_3 : num_auxiliar_1;

            if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
            else pag = total/num_auxiliar_2 + 1;
            if(system("clear"));
            printchoice(choice);
            querie11Print(q11,total,pagAtual,num_auxiliar_2,pag);
            if(system("stty raw"));
            if(system("stty -echo"));
            while ((char_aux = toupper(getchar())) != 13 && char_aux != 'Q') {/* 13 -> ENTER */
                if(char_aux == '1' && pagAtual > 0) pagAtual--;
                else if(char_aux == '2' && pagAtual < pag-1) pagAtual++;
                else if(char_aux == '3' && num_auxiliar_2>10) {
                    num_auxiliar_2-=10;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                else if(char_aux == '4' && num_auxiliar_2<3*10) {
                    num_auxiliar_2+=10;
                    pagAtual = 0;
                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                }
                if(system("stty cooked"));
                if(system("clear"));
                printchoice(choice);
                querie11Print(q11,total,pagAtual,num_auxiliar_2,pag);
                if(system("stty raw"));
            }
            if(system("stty cooked"));
            if(system("stty echo"));



            freeQ11(q11);
            if(char_aux == 'Q') return 1;
            break;
        case 'C':
            /*querie12();*/
            while(1){
                printf("Número do Cliente: ");
                if(fgets(input,BUFFER,stdin));
                if(input[0] == '\n') return RUN;
                strtok(input,"\n\r");
                upper_string(input);
                if(isalpha(input[0]) && isdigit(input[1]) && isdigit(input[2]) && isdigit(input[3]) && isdigit(input[4]) && input[5] == '\0' && existeSGVCliente(sgv,input)){
                    if(system("clear"));
                    printchoice(choice);
                    printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                    printf("Número de Produtos a apresentar: ");
                    while(fgets(input2,BUFFER,stdin)){
                        if(input2[0] == '\n') return RUN;
                        strtok(input2,"\n\r");
                        int i;
                        int boolean = 1;
                        for(i=0;i<strlen(input2);i++) if(!isdigit(input2[i])) boolean = 0;
                        if(boolean){
                            num_auxiliar_1 = atoi(input2);
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                            printf("Número de Produtos a apresentar: %s%d%s\n",GREEN,num_auxiliar_1,RESET);
                            break;
                        }
                        else {
                            if(system("clear"));
                            printchoice(choice);
                            printf("Número do Cliente: %s%s%s\n",GREEN,input,RESET);
                            LOG_RED("Número inválido\n");
                            printf("Número de Produtos a apresentar: ");
                        }
                    }


                    t12 = clock();
                    q12 = getClientTopProfitProducts(sgv,input,num_auxiliar_1);
                    t12 = clock() - t12;

                    pagAtual = 0;
                    num_auxiliar_2 = 15;
                    num_auxiliar_3 = getNum_TotalQ12(q12);
                    total = (num_auxiliar_1 > num_auxiliar_3) ? num_auxiliar_3 : num_auxiliar_1;

                    if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                    else pag = total/num_auxiliar_2 + 1;
                    if(system("clear"));
                    printchoice(choice);
                    querie12Print(q12,total,pagAtual,num_auxiliar_2,pag);
                    if(system("stty raw"));
                    if(system("stty -echo"));
                    while ((char_aux = toupper(getchar())) != 13 && char_aux != 'Q') {/* 13 -> ENTER */
                        if(char_aux == '1' && pagAtual > 0) pagAtual--;
                        else if(char_aux == '2' && pagAtual < pag-1) pagAtual++;
                        else if(char_aux == '3' && num_auxiliar_2>15) {
                            num_auxiliar_2-=15;
                            pagAtual = 0;
                            if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                            else pag = total/num_auxiliar_2 + 1;
                        }
                        else if(char_aux == '4' && num_auxiliar_2<4*15) {
                            num_auxiliar_2+=15;
                            pagAtual = 0;
                            if(total%num_auxiliar_2 == 0) pag = total/num_auxiliar_2;
                            else pag = total/num_auxiliar_2 + 1;
                        }
                        if(system("stty cooked"));
                        if(system("clear"));
                        printchoice(choice);
                        querie12Print(q12,total,pagAtual,num_auxiliar_2,pag);
                        if(system("stty raw"));
                    }
                    if(system("stty cooked"));
                    if(system("stty echo"));

                    freeQ12(q12);
                    if (char_aux == 'Q') return 1;
                    break;
                }
                else{
                    if(system("clear"));
                    printchoice(choice);
                    LOG_RED("Número de Cliente inválido\n");
                }
            }


            break;
        case 'D':
            /*querie13();*/
            q13 = getCurrentFilesInfo(sgv);
            querie13Print(q13);
            free_Q13(q13);
            break;
        case 'T':
            time_taken = ((double)t1)/CLOCKS_PER_SEC;
            printf("Query1: Load: %f seconds\n",time_taken);

            time_taken = ((double)t6)/CLOCKS_PER_SEC;
            printf("Query6: Load: %f seconds\n",time_taken);

            time_taken = ((double)t7)/CLOCKS_PER_SEC;
            printf("Query7: Load: %f seconds\n",time_taken);

            time_taken = ((double)t8)/CLOCKS_PER_SEC;
            printf("Query8: Load: %f seconds\n",time_taken);

            time_taken = ((double)t9)/CLOCKS_PER_SEC;
            printf("Query9: Load: %f seconds\n",time_taken);

            time_taken = ((double)t10)/CLOCKS_PER_SEC;
            printf("Query10: Load: %f seconds\n",time_taken);

            time_taken = ((double)t11)/CLOCKS_PER_SEC;
            printf("Query11: Load: %f seconds\n",time_taken);

            time_taken = ((double)t12)/CLOCKS_PER_SEC;
            printf("Query12: Load: %f seconds\n",time_taken);
            break;
        default:
            break;
        }
        printf("Press %s<enter>%s to exit ",RED,RESET);
        getchar();


        }
        else
        {
            if(system("clear"));
            LOG_RED("Ainda não carregou ficheiros\n<enter>\n");
            getchar();
        }

    }

    return RUN;
}


/**
 * @brief Função que carrega os dados presentes nos ficheiros de texto dos clientes, produtos e vendas.
 * @param sgv SGV que contém as informações dos módulos.
 */
static void loadFromFiles(SGV sgv){
    printf("Press %s<enter>%s for default\n",YELLOW,RESET);
    char clients_path[BUFFER];
    char products_path[BUFFER];
    char sales_path[BUFFER];
    FILE *f, *g, *h;
    printf("Clientes: ");
    while(1){
        clients_path[0] = getchar();
        if(clients_path[0] == '\n') strcpy(clients_path,clients_path_default);
        else if(fgets(clients_path+1,BUFFER-1,stdin));
        strtok(clients_path, "\n\r");
        f = fopen(clients_path,"r");
        if (f) {
            if(system("clear"));
            printchoice('1');
            printf("Press %s<enter>%s for default\n",YELLOW,RESET);
            LOG_GREEN("Clientes: check\n");
            break;
        }
        if(system("clear"));
        printchoice('1');
        LOG_RED("Erro: Ficheiro não existente\n");
        printf("Press %s<enter>%s for default\n",YELLOW,RESET);
        LOG_RED("Clientes: ");
    }
    printf("Produtos: ");
    while(1){
        products_path[0] = getchar();
        if(products_path[0] == '\n') strcpy(products_path,products_path_default);
        else if(fgets(products_path+1,BUFFER-1,stdin));
        strtok(products_path,"\n\r");
        g = fopen(products_path,"r");
        if (g) {
            if(system("clear"));
            printchoice('1');
            printf("Press %s<enter>%s for default\n",YELLOW,RESET);
            LOG_GREEN("Clientes: check\n");
            LOG_GREEN("Produtos: check\n");
            break;
        }
        if(system("clear"));
        printchoice('1');
        LOG_RED("Erro: Ficheiro não existente\n");
        printf("Press %s<enter>%s for default\n",YELLOW,RESET);
        LOG_GREEN("Clientes: check\n");
        LOG_RED("Produtos : ");
    }
    printf("Vendas: ");
    while(1){
        sales_path[0] = getchar();
        if(sales_path[0] == '\n') strcpy(sales_path,sales_path_default);
        else if(fgets(sales_path+1,BUFFER-1,stdin));
        strtok(sales_path,"\n\r");
        h = fopen(sales_path,"r");
        if (h) {
            if(system("clear"));
            printchoice('1');
            printf("Press %s<enter>%s for default\n",YELLOW,RESET);
            LOG_GREEN("Clientes: check\n");
            LOG_GREEN("Produtos: check\n");
            LOG_GREEN("Vendas: check\n");
            break;
        }
        if(system("clear"));
        printchoice('1');
        LOG_RED("Erro: Ficheiro não existente\n");
        printf("Press %s<enter>%s for default\n",YELLOW,RESET);
        LOG_GREEN("Clientes: check\n");
        LOG_GREEN("Produtos : check\n");
        LOG_RED("Vendas: ");
    }
    printf("\e[5mLOADING ...\n\e[25m");
    t1 = clock();
    sgv = loadSGVFromFiles(sgv,clients_path,products_path,sales_path,f,g,h);
    t1 = clock() - t1;
    if(system("clear"));
    printchoice('1');
    printf("Press %s<enter>%s for default\n",YELLOW,RESET);
    LOG_GREEN("Clientes: check\n");
    LOG_GREEN("Produtos: check\n");
    LOG_GREEN("Vendas: check\n");
    LOG_GREEN("LOADED\n");

}


/**
 * @brief Função que altera uma string pondo todos os chars que a constituem em maiúsculas.
 * @param s[] char string que vai ser alterada.
 * @return char* com a string alterada.
 */
char* upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
   return s;
}
