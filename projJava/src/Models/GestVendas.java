/**
 * @file GestVendas.java
 *  Ficheiro que contém a API relativa à implementação do model.
 */

package Models;

import Catalogos.ClientsCatalog;
import Catalogos.ProductsCatalog;
import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;
import Faturacao.Faturacao;
import FilialStuff.Filial;
import Interfaces.GereVendasModel;
import Interfaces.Querie;
import Queries.*;
import Readers.Parser;

import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class GestVendas implements GereVendasModel, Serializable {

    private ClientsCatalog clientes;
    private ProductsCatalog produtos;
    private Faturacao faturacao;
    private Filial filial;
    private Q1Stats q1Stats;

    /**
     *  Método que inicializa o modelo do SGV.
     */
    public GestVendas() {
        this.clientes = new ClientsCatalog();
        this.produtos = new ProductsCatalog();
        this.faturacao = new Faturacao();
        this.filial = new Filial();
    }

    /**
     *  Método que retorna a informação de uma query pedida pelo utilizador.
     * @param num int que é a opção do utilizador.
     * @param l que contém, caso necessário, os argumentos para a execução da query.
     * @return Querie que contém o resultado da query pedida pelo utilizador.
     */
    public Querie interpreta(int num, Collection<Object> l) throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException {
        List<Object> lista = new ArrayList<>(l);
        switch (num) {
            case 1:
                return querie1();
            case 2:
                return querie2((Integer) lista.get(1), (Integer) lista.get(0));
            case 3:
                return querie3((String) lista.get(0));
            case 4:
                return querie4((String) lista.get(0));
            case 5:
                return querie5((String) lista.get(0));
            case 6:
                return querie6((Integer) lista.get(0));
            case 7:
                return querie7();
            case 8:
                return querie8((Integer) lista.get(0));
            case 9:
                return querie9((String) lista.get(0), (Integer) lista.get(1));
            case 10:
                return querie10();
            case 11:
                return querie1stats();
            case 12:
                return querie2stats();
            case 13:
                gravarGestVendas((String) lista.get(0));
            default:
                return null;
        }
    }

    /**
     *  Método que retorna a informação pedida na Query1 Estatística.
     * @return Q1Stats que contém a informação relativa à Query1 Etatística.
     */
    public Q1Stats querie1stats(){
        this.faturacao.getProdsValues(this.q1Stats);
        this.filial.getCliValues(this.q1Stats);
        return this.q1Stats;
    }

    /**
     *  Método que retorna a informação pedida na Query2 Estatística.
     * @return Q2Stats que contém a informação relativa à Query2 Etatística.
     */
    public Q2Stats querie2stats() {
        Q2Stats q2s = this.faturacao.getFatValuesQ2Stats();
        this.filial.getClientValuesQ2Stats(q2s);
        return q2s;
    }

    /**
     *  Método que retorna a informação pedida na Query1.
     * @return Querie1 que contém a informação relativa à Query1.
     */
    public Querie1 querie1() {
        return this.faturacao.comparaQ1(this.produtos.getProducts());
    }

    /**
     *  Método que retorna a informação pedida na Query2.
     * @param mes int, mês.
     * @param filial int, filial.
     * @return Querie2 que contém a informação relativa à Query2.
     */
    public Querie2 querie2(int mes, int filial) {
        if (filial == 0) return this.filial.countGlobalQ2(mes);
        else return this.filial.countFilialQ2(mes, filial);
    }

    /**
     *  Método que retorna a informação pedida na Query3.
     * @param cliente, cliente.
     * @throws ClientNotFoundException exceção.
     * @return Querie3 que contém a informação relativa à Query3.
     */
    public Querie3 querie3(String cliente) throws ClientNotFoundException {
        return this.filial.clientMonthlyValuesQ3(cliente);
    }

    /**
     *  Método que retorna a informação pedida na Query4.
     * @param produto, produto.
     * @throws ProductNotFoundException exceção.
     * @return Querie4 que contém a informação relativa à Query4.
     */
    public Querie4 querie4(String produto) throws ProductNotFoundException {
        return this.filial.productMonthlyValuesQ4(produto);
    }

    /**
     *  Método que retorna a informação pedida na Query5.
     * @param cliente, cliente.
     * @throws ClientNotFoundException exceção.
     * @return Querie5 que contém a informação relativa à Query5.
     */
    public Querie5 querie5(String cliente) throws ClientNotFoundException{
        return this.filial.mostBoughtProductsQ5(cliente);
    }

    /**
     *  Método que retorna a informação pedida na Query6.
     * @param n, inteiro.
     * @return Querie6 que contém a informação relativa à Query6.
     */
    public Querie6 querie6(int n) {
        Querie6 q6 = this.faturacao.produtosMaisVendidos(n);
        filial.clientesDistintosCompraramProduto(q6, n);
        return q6;
    }

    /**
     *  Método que retorna a informação pedida na Query7.
     * @return Querie7 que contém a informação relativa à Query7.
     */
    public Querie7 querie7() {
        return this.filial.top3Buyers();
    }

    /**
     *  Método que retorna a informação pedida na Query8.
     * @param n, inteiro.
     * @return Querie8 que contém a informação relativa à Query8.
     */
    public Querie8 querie8(int n) {
        return this.filial.differentBoughtProductsByNClientsQ8(n);
    }

    /**
     *  Método que retorna a informação pedida na Query9.
     * @param prod, produto.
     * @param n, inteiro.
     * @throws ProductNotFoundException exceção.
     * @return Querie9 que contém a informação relativa à Query9.
     */
    public Querie9 querie9(String prod, int n)throws ProductNotFoundException {
        return this.filial.productTopBuyersQ9(prod, n);
    }

    /**
     *  Método que retorna a informação pedida na Query10.
     * @return Querie10 que contém a informação relativa à Query10.
     */
    public Querie10 querie10() {
        return this.filial.fatMesMesFilialFilialProds();
    }

    /**
     *  Método que carrega com os caminhos pré-definidos o modelo do programa.
     * @throws FileNotFoundException exceção.
     */
    @Override
    public void loadDefault() throws FileNotFoundException {
        Parser p = new Parser();
        this.q1Stats = new Q1Stats();
        p.parser(this.clientes, this.produtos, this.faturacao, this.filial, q1Stats);
    }
    /**
     *  Método que carrega com os caminhos dados pelo Utiilizador, o modelo do programa.
     * @param paths Lista com os caminhos inseridos pelo Utilizador.
     */
    @Override
    public void loadFiles(List<String> paths){
        Parser p = new Parser();
        this.q1Stats = new Q1Stats();
        p.parserDiffFiles(paths,this.clientes,this.produtos,this.faturacao,this.filial,q1Stats);
    }

    /**
     *  Método que permite guardar o modelo do programa como um objeto .dat.
     * @param filename String que será o nome do ficheiro.
     * @throws IOException exceção.
     */
    public void gravarGestVendas(String filename) throws IOException {
        ObjectOutputStream o = new ObjectOutputStream(new FileOutputStream(filename));
        o.writeObject(this);
        o.flush();
        o.close();
    }

    /**
     *  Método que permite carregar um modelo do programa com um objeto .dat.
     * @param filename String que será o nome do ficheiro.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     * @return GestVendas gestor de vendas.
     */
    public static GestVendas loadGestVendas(String filename) throws IOException, ClassNotFoundException {
        ObjectInputStream o = new ObjectInputStream(new FileInputStream(filename));
        GestVendas d = (GestVendas) o.readObject();
        o.close();
        return d;
    }


}
