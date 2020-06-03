/**
 * @file GestVendasTestes.java
 *  Ficheiro que contém a API relativa à implementação dos testes da aplicação.
 */

import Catalogos.*;
import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;
import Faturacao.Faturacao;
import FilialStuff.Filial;
import FilialStuff.InformacaoVendaProduto;
import Geral.*;
import Queries.*;
import Readers.Parser;


public class GestVendasTestes implements DefVariaveis {


    public static void main(String[] args) throws ClientNotFoundException, ProductNotFoundException {
        Crono.start();
        int i;
        ClientsCatalog clientes = new ClientsCatalog();
        ProductsCatalog produtos = new ProductsCatalog();
        Faturacao faturacao = new Faturacao();
        Filial filial = new Filial();

        Q1Stats q1stats = new Q1Stats();

        Parser p = new Parser();
        p.parser(clientes, produtos, faturacao, filial,q1stats);
        System.out.println(Crono.getTImeString());

        Crono.start();
        querie1stats(q1stats,faturacao,filial);
        System.out.println("Q1Stats " + Crono.getTImeString());
//        System.out.println();
//        System.out.println("FICHEIRO LIDO -> " + q1stats.getFicheiro());
//        System.out.println("TOTAL VENDAS INVÁLIDAS -> " + q1stats.getNvendas_erradas());
//        System.out.println("TOTAL PRODUTOS -> " + q1stats.getTotal_produtos());
//        System.out.println("TOTAL PRODUTOS COMPRADOS -> " + q1stats.getTotal_produtos_diferentes());
//        System.out.println("TOTAL PRODUTOS NAO COMPRADOS -> " + q1stats.getTotal_produtos_nao_comprados());
//        System.out.println("TOTAL CLIENTES -> " + q1stats.getTotal_clientes());
//        System.out.println("TOTAL CLIENTES COMPRADORES -> " + q1stats.getTotal_clientes_compradores());
//        System.out.println("TOTAL CLIENTES NADA COMPRARAM -> " + q1stats.getTotal_clientes_nada_compraram());
//        System.out.println("TOTAL VENDAS COM FATURACAO ZERO -> " + q1stats.getVendas_a_zero());
//        System.out.println("FATURAÇÃO TOTAL -> " + q1stats.getFat_total());


        Crono.start();
        Q2Stats q2Stats = querie2stats(faturacao,filial);
        System.out.println("Q2Stats " + Crono.getTImeString());
//        System.out.println(q2Stats.getFat_total());
//        for(i=1; i<FILIAIS+1;i++) {
//            System.out.println("FILIAL #" + i);
//            for (int j = 0; j < MES; j++) {
//                System.out.println("MES #" + (j+1));
//                System.out.println("NVendas -> " + q2Stats.getNVendasMes(j));
//                System.out.println("FATURADO TOTAL -> " + q2Stats.getFatTotalMes(j));
//                System.out.println("Faturado -> " + q2Stats.getFaturadoFilialMes(i, j) );
//            }
//            System.out.println();
//        }


        Crono.start();
        Querie1 q1int = querie1(faturacao,produtos);
        System.out.println("Q1 " + Crono.getTImeString());
//        int x = q1int.getTotal();
//        System.out.println(x);

        Crono.start();
        Querie2 q2 = querie2(filial,2,1);
        System.out.println("Q2 " + Crono.getTImeString());
//        System.out.println(q2.getNclientes());
//        System.out.println(q2.getNvendas());

        Crono.start();
        Querie3 q3 = querie3(filial,"F2916");
        System.out.println("Q3 " + Crono.getTImeString());
//        int[] nvendas = q3.getNvendas();
//        int[] nprod = q3.getNprodutos();
//        double[] fat = q3.getFat();
//        for(i=0;i<MES;i++) System.out.println("Mes:" + (i+1) + " NVendas->" + nvendas[i] + " NProdutos->" + nprod[i] + " Faturado->" + fat[i]);

        Crono.start();
        Querie4 q4 = querie4(filial, "AF1184");
        System.out.println("Q4 " + Crono.getTImeString());
//        int[] times_bought = q4.getTimes_bought();
//        int[] clients_bought = q4.getClients_bought();
//        double[] fatQ4 = q4.getFat_mes();
//        for (i = 0; i < MES; i++)
//            System.out.println("Mes:" + (i + 1) + " VezesComprado->" + times_bought[i] + "NClientes->" + clients_bought[i] + " Faturado->" + fatQ4[i]);

        Crono.start();
        Querie5 q5 = querie5(filial, "Z5000");
        System.out.println("Q5 " + Crono.getTImeString());
//        for (InformacaoVendaProduto f : q5.getProdsAndQtd())
//            System.out.println("Produto ->" + f.getCode() + " Qtd ->" + f.getQtd());

        Crono.start();
        Querie6 q6 = querie6(faturacao,filial,20);
        System.out.println("Q6 " + Crono.getTImeString());
//        System.out.println("ola");
//        i = 0;
//        for(String s : q6.getNProdutosMaisVendidos(20)){
//            System.out.println(s + " -> " + q6.getQtdComprada(i) + " -> nrClientes = " + q6.getnClientesIndex(i++));
//        }

        Crono.start();
        Querie7 q7 = querie7(filial);
        System.out.println("Q7 " + Crono.getTImeString());
//        for(i=1; i<FILIAIS+1;i++)
//            for(String s : q7.top3Buyers(i)){
//                System.out.println(s + " Valor gasto ->" + q7.getGastoIndex(s,i));
//            }


        Crono.start();
        Querie8 q8 = querie8(filial,20);
        System.out.println("Q8 " + Crono.getTImeString());
//        i=0;
//        for(String s : q8.getCliCodes()){
//            System.out.println(s + " -> " + "NProds ->" + q8.getnProdutosIndex(i++));
//        }

        Crono.start();
        Querie9 q9 = querie9(filial,"AF1184", 10);
        System.out.println("Q9 " + Crono.getTImeString());
//        i=0;
//        for(String s : q9.getCliCodes()){
//            System.out.println(s + "  -> " + " Quanto comprou ->" + q9.getQuantityBoughtByClient(i) +  " Quanto gastou->" + q9.getSpentIndex(i++));
//        }

        Crono.start();
        Querie10 q10 = querie10(filial);
        System.out.println("Q10 "+ Crono.getTImeString());

    }


    public static void querie1stats(Q1Stats q1, Faturacao f, Filial fi){
        f.getProdsValues(q1);
        fi.getCliValues(q1);
    }

    public static Q2Stats querie2stats(Faturacao f,Filial fi){
        Q2Stats q2s = f.getFatValuesQ2Stats();
        fi.getClientValuesQ2Stats(q2s);
        return q2s;
    }

    public static Querie1 querie1(Faturacao f, ProductsCatalog p) {
        return f.comparaQ1(p.getProducts());
    }

    public static Querie2 querie2(Filial f, int mes, int filial) {
        if (filial == 0) return f.countGlobalQ2(mes);
        else return f.countFilialQ2(mes, filial);
    }

    public static Querie3 querie3(Filial f, String cliente) throws ClientNotFoundException {
        return f.clientMonthlyValuesQ3(cliente);
    }

    public static Querie4 querie4(Filial f, String produto) throws ProductNotFoundException {
        return f.productMonthlyValuesQ4(produto);
    }

    public static Querie5 querie5(Filial f, String cliente) throws ClientNotFoundException {
        return f.mostBoughtProductsQ5(cliente);
    }

    public static Querie6 querie6(Faturacao fat, Filial filial ,int n){
        Querie6 q6 = fat.produtosMaisVendidos(n);
        filial.clientesDistintosCompraramProduto(q6,n);
        return q6;
    }

    public static Querie7 querie7(Filial f) { return f.top3Buyers(); }

    public static Querie8 querie8(Filial f, int n){
        return f.differentBoughtProductsByNClientsQ8(n);
    }

    public static Querie9 querie9(Filial f, String prod, int n) throws ProductNotFoundException { return f.productTopBuyersQ9(prod,n);}

    public static Querie10 querie10(Filial f){
        return f.fatMesMesFilialFilialProds();
    }
}
