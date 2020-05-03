#include "headers.h"

typedef struct querie2 *Q2;

Q2 init_Q2(int n);
void freeQ2(Q2 q);
char** getLista_ProdsQ2(Q2 q);
int getNum_TotalQ2(Q2 q);
void setLista_ProdsQ2(char** a, Q2 q);
void setNum_totalQ2(int n, Q2 q);
void insere_ProdQ2(char * key, Q2 q);
char* getProdQ2(Q2 q, int i);


typedef struct querie3 *Q3;

Q3 init_Q3();
int getQt_NQ3(Q3 q);
void setQt_NQ3(int n, Q3 q);
int getQt_PQ3(Q3 q);
void setQt_PQ3(int n, Q3 q);
double getFat_NQ3(Q3 q);
void setFat_NQ3(double n, Q3 q);
double getFat_PQ3(Q3 q);
void setFat_PQ3(double n, Q3 q);


typedef struct querie5 *Q5;
Q5 init_Q5(int n);
void freeQ5(Q5 q);
char** getLista_ClientesQ5(Q5 q);
void setLista_ClientesQ5(char** a, Q5 q);
void insere_ClienteQ5(char * key, Q5 q);
char* getClientedQ5(Q5 q, int i);
int getNum_TotalQ5(Q5 q);

typedef struct querie6 *Q6;

Q6 init_Q6();
int getNumProdsQ6(Q6 q);
int getNumClientessQ6(Q6 q);
void setNumProdsQ6(Q6 q, int n);
void setNumClientesQ6(Q6 q, int n);

typedef struct querie7 *Q7;

Q7 init_Q7();
int getQt_FilialQ7(Q7 q, int i, int j);
void setQt_FilialQ7(Q7 q, int n, int i, int j);

typedef struct querie8 *Q8;

Q8 init_Q8();
int getNVendas_Q8(Q8 q);
void setNVendas_Q8(int n, Q8 q);
double getFat_Q8(Q8 q);
void setFat_Q8(double n, Q8 q);

typedef struct querie9 *Q9;

Q9 init_Q9(int n);
void freeQ9(Q9 q);
int getTotalNQ9(Q9 q);
void setTotalNQ9(Q9 q, int n);
char** getLista_ProdsNQ9(Q9 q);
void setLista_ProdsNQ9(char** a, Q9 q);
void insere_ProdNQ9(char * key, Q9 q);
char* getProdNQ9(Q9 q, int i);
int getTotalPQ9(Q9 q);
void setTotalPQ9(Q9 q, int n);
char** getLista_ProdsPQ9(Q9 q);
void setLista_ProdsPQ9(char** a, Q9 q);
void insere_ProdPQ9(char * key, Q9 q);
char* getProdPQ9(Q9 q, int i);

typedef struct querie10 *Q10;

Q10 init_Q10(int n);
void freeQ10(Q10 q);
void insere_ProdInfoQ10(Q10 q, char* p , int qtd);
char* getProdutoQ10(Q10 q,int i);
int getQ10QtdProduto(Q10 q, int i);
int getNum_TotalQ10(Q10 q);
int compare10(const void* a, const void* b);
void sortAndGetQ10(Q10 q);

typedef struct querie11 *Q11;

Q11 init_Q11(int n);
void freeQ11(Q11 q);
void insere_ProdInfoQ11(Q11 q, char* p , int qt[]);
char* getProdutoQ11(Q11 q,int i);
int getQ11QtdProduto(Q11 q, int i);
int getQ11NClientes(Q11 q, int i);
int getNum_TotalQ11(Q11 q);
int getQtdFilialQ11(Q11 q,int pos, int filial);
int getNClientesFilialQ11(Q11 q, int pos, int filial);
void alteraNClientesQ11(Q11 q, int j, int nc, int filial);
int compareQ11(const void * a, const void * b);
void sortAndGetQ11(Q11 q);

typedef struct querie12 *Q12;

Q12 init_Q12(int n);
void freeQ12(Q12 q);
void insere_ProdInfoQ12(Q12 q, char* p , double faturado);
char* getProdutoQ12(Q12 q,int i);
double getQ12QtdProduto(Q12 q, int i);
double getQ12Faturado(Q12 q, int i);
int getNum_TotalQ12(Q12 q);
int compareQ12(const void* a, const void* b);
void sortAndGetQ12(Q12 q);

typedef struct querie13 *Q13;

Q13 init_Q13();
void free_Q13(Q13 q);
int getQ_Clientes13(Q13 q);
int getQ_Produtos13(Q13 q);
int getV_Validas13(Q13 q);
int getV_Totais13(Q13 q);
char* getClients_Path13(Q13 q);
char* getProducts_Path13(Q13 q);
char* getSales_Path13(Q13 q);
void setQ_Clientes13(Q13 q, int n);
void setQ_Produtos13(Q13 q, int n);
void setV_Validas13(Q13 q, int n);
void setV_Totais13(Q13 q, int n);
void setClients_Path13(Q13 q, char *file);
void setProducts_Path13(Q13 q, char *file);
void setSales_Path13(Q13 q, char *file);
