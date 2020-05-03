#include "headers.h"
#include "produtos.h"
#include "macros.h"
#include <sys/ioctl.h>

#define JAN "Jan"
#define FEB "Feb"
#define MAR "Mar"
#define APR "Apr"
#define MAY "May"
#define JUN "Jun"
#define JUL "Jul"
#define AUG "Aug"
#define SEP "Sep"
#define OCT "Oct"
#define NOV "Nov"
#define DEC "Dec"




void imprime_menu(char n, int v);
void printchoice(char c);

/*-----QUERIE2-----*/
void querie2Print(char **a, char aux, int i, int f, int num, int pag);

/*-----QUERIE3-----*/
void querie3Print(int a, float b, int c, float d, char* product, int month);

/*-----QUERIE4-----*/
void querie4Print(int filial, char **a, int total, int paginaAtual, int prodPorPag, int totalpag);

/*-----QUERIE5-----*/
void querie5Print(char **a, int total, int atual, int prodPorPag, int totalpag);

/*-----QUERIE6-----*/
void querie6Print(int prod, int c);

/*-----QUERIE7-----*/
void querie7Print(Q7 q, int n);

/*-----QUERIE8-----*/
void querie8Print(int month1, int month2, Q8 q);

/*-----QUERIE9-----*/
void querie9Print(char **n, int totaln, char **p, int totalp);

/*-----QUERIE10----*/
void querie10Print(Q10 q, int mes);

/*-----QUERIE11----*/
void querie11Print(Q11 q, int total,int atual, int codePorPag,int totalPag);

/*-----QUERIE12----*/
void querie12Print(Q12 q, int total,int atual, int codePorPag, int totalPag);

/*-----QUERIE13-----*/
void querie13Print(Q13 q);

/* obter número de colunas do terminal */
struct winsize w;
int col_aux;
#define GETCOL() ioctl(0, TIOCGWINSZ, &w);col_aux = w.ws_col;
