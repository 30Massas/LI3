#include "headers.h"
#include "clientes.h"
#include "produtos.h"
#include "faturacao.h"
#include "filial.h"
#include "vista.h"

typedef struct sgv *SGV;

SGV initSGV();
void destroySGV(SGV sgv);

SGV loadSGVFromFiles(SGV sgv,char* clientsFilePath,char* productsFilePath,char* salesFilePath,FILE *f, FILE *g, FILE *h);
Q2 getProductsStartedByLetter(SGV sgv, char letter);
Q3 getProductSalesAndProfit(SGV sgv, char* product, int month);
Q2 getProductsNeverBought(SGV sgv, int branchID);
Q5 getClientsOffAllBranches(SGV sgv);
Q6 getClientsAndProductsNeverBoughtCount(SGV sgv);
Q7 getProductsBoughtByClient(SGV sgv, char* clientID);
Q8 getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
Q9 getProductBuyers(SGV sgv, char* productID, int branch);
Q10 getClientFavoriteProducts(SGV sgv, char* clientID, int month);
Q11 getTopSelledProducts(SGV sgv, int limit);
Q12 getClientTopProfitProducts(SGV sgv, char* clientID, int limit);
Q13 getCurrentFilesInfo(SGV sgv);
int getTotalProdSGV(SGV sgv);
Boolean existeSGVCliente(SGV sgv, char* cliente);
Boolean existeSGVProduto(SGV sgv, char* produto);
Boolean isSGVvalid(SGV sgv);
