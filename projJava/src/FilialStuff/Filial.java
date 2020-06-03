/**
 * @file Filial.java
 * Ficheiro que contém a API relativa à implementação das filiais.
 */

package FilialStuff;

import Comparadores.ReverseOrderValorNome;
import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;
import Geral.*;
import Queries.*;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Filial implements DefVariaveis, Serializable { 
    private Map<Integer, Map<String, InfoCliente>> filialClientes;
    private Map<Integer, Map<String, InfoProduto>> filialProdutos;

    /**
     * Método que inicializa as Filiais.
     */
    public Filial() {
        this.filialClientes = new HashMap<>();
        this.filialProdutos = new HashMap<>();
    }

    /**
     * Método que inicializa as filiais com estruturas já inicializadas.
     * @param fc que é a filial de clientes.
     * @param fp que é a filial de produtos.
     */
    public Filial(Map<Integer, Map<String, InfoCliente>> fc, Map<Integer, Map<String, InfoProduto>> fp) {
        setFilialClientes(fc);
        setFilialProdutos(fp);
    }

    /**
     * Método que inicializa as filiais com base numa estrutura Filial.
     * @param f Filial.
     */
    public Filial(Filial f) {
        this.filialClientes = f.getFilialClientes();
        this.filialProdutos = f.getFilialProdutos();
    }

    /*-------------------------------------------------CLIENTES-------------------------------------------------*/

    /**
     * Método que retorna a estrutura da filial de clientes.
     * @return last que é a estrutura da filial de clientes.
     */
    public Map<Integer, Map<String, InfoCliente>> getFilialClientes() {
        Map<Integer, Map<String, InfoCliente>> last = new HashMap<>();
        Map<String, InfoCliente> aux = new HashMap<>();
        for (Integer i : filialClientes.keySet()) {
            for (Map<String, InfoCliente> f : filialClientes.values()) {
                for (String s : f.keySet()) {
                    aux.put(s, f.get(s).clone());
                }
            }
            last.put(i, aux);
        }
        return last;
    }

    /**
     * Método que estabelece a filial de clientes com uma estrutura já inicializada.
     * @param f que é a estrutura da filial de clientes a usar.
     */
    public void setFilialClientes(Map<Integer, Map<String, InfoCliente>> f) {
        this.filialClientes = new HashMap<>();
        Map<String, InfoCliente> aux = new HashMap<>();
        for (Integer i : f.keySet()) {
            for (Map<String, InfoCliente> info : f.values()) {
                for (String s : info.keySet()) {
                    aux.put(s, info.get(s).clone());
                }
            }
            this.filialClientes.put(i, aux);
        }
    }

    /*-------------------------------------------------PRODUTOS-------------------------------------------------*/

    /**
     * Método que retorna a estrutura da filial de produtos.
     * @return last que é a estrutura da filial de produtos.
     */
    public Map<Integer, Map<String, InfoProduto>> getFilialProdutos() {
        Map<Integer, Map<String, InfoProduto>> last = new HashMap<>();
        Map<String, InfoProduto> aux = new HashMap<>();
        for (Integer i : filialProdutos.keySet()) {
            for (Map<String, InfoProduto> f : filialProdutos.values()) {
                for (String s : f.keySet()) {
                    aux.put(s, f.get(s).clone());
                }
            }
            last.put(i, aux);
        }
        return last;
    }

    /**
     * Método que estabelece a filial de produtos com uma estrutura já inicializada.
     * @param f que é a estrutura da filial de produtos a usar.
     */
    public void setFilialProdutos(Map<Integer, Map<String, InfoProduto>> f) {
        this.filialProdutos = new HashMap<>();
        Map<String, InfoProduto> aux = new HashMap<>();
        for (Integer i : f.keySet()) {
            for (Map<String, InfoProduto> info : f.values()) {
                for (String s : info.keySet()) {
                    aux.put(s, info.get(s).clone());
                }
            }
            this.filialProdutos.put(i, aux);
        }
    }


    /*-------------------------------------------------BOTH-------------------------------------------------*/


    /**
     * Método que adiciona à filial de clientes um dado cliente e a informação relativa à venda realizada.
     * @param cliente String que é o cliente a ser inserido.
     * @param r Registo que contém a informação referente à venda
     */
    public void addRegistoCli(String cliente, Registo r) {
        int index = r.getFilial();
        this.filialClientes.putIfAbsent(index, new HashMap<>());
        InfoCliente i = this.filialClientes.get(index).get(cliente);
        if (i != null) {
            i.addRegisto(r);
        } else {
            i = new InfoCliente();
            i.addRegisto(cliente, r);
        }
        this.filialClientes.get(index).put(cliente, i);
    }

    /**
     * Método que adiciona à filial de produtos um produto e a informação relativa à sua compra, bem como o cliente que o comprou.
     * @param client String que é o cliente que comprou o produto.
     * @param r Registo que contém a informação referente à venda
     */
    public void addRegistoProd(String client, Registo r) {
        int index = r.getFilial();
        this.filialProdutos.putIfAbsent(index, new HashMap<>());
        InfoProduto i = this.filialProdutos.get(index).get(r.getCodProd());
        if (i != null) {
            i.addRegistoExistente(client, r);
        } else {
            i = new InfoProduto();
            i.addRegistoNovo(client, r);
        }
        this.filialProdutos.get(index).put(r.getCodProd(), i);
    }

    /*----------------------------------------------------QUERIES-----------------------------------------------------*/

    /*--------------------------------------------------QUERIE1STATS--------------------------------------------------*/

    /**
     * Método que adiciona à Q1Stats a informação relativa aos clientes.
     * @param q1 Q1Stats que é a estrutura onde inserir a informação.
     */
    public void getCliValues(Q1Stats q1) {
        Set<String> clientes_compradores = new TreeSet<>();
        Set<String> clientes_nada_compraram = new TreeSet<>();
        for (Integer i : this.filialClientes.keySet()) {
            for (String s : this.filialClientes.get(i).keySet()) {
                if (this.filialClientes.get(i).get(s).getNVendasTotal() == 0) clientes_nada_compraram.add(s);
                else clientes_compradores.add(s);
            }
        }
        q1.setTotal_clientes_nada_compraram(clientes_nada_compraram.size());
        q1.setTotal_clientes_compradores(clientes_compradores.size());
    }


    /*--------------------------------------------------QUERIE2STATS--------------------------------------------------*/

    /**
     * Método que adiciona à Q2Stats a informação relativa aos clientes.
     * @param q2Stats Q2Stats que é a estrutura onde inserir a informação.
     */
    public void getClientValuesQ2Stats(Q2Stats q2Stats) {
        for (Integer i : this.filialClientes.keySet()) {
            for (String s : this.filialClientes.get(i).keySet()) {
                for (int j = 0; j < MES; j++) {
                    if (this.filialClientes.get(i).get(s).getNVendas_Mes_Especifico(j) != 0) {
                        q2Stats.incNClientes(i, j);
                    }
                }
            }
        }
        for (Integer i : this.filialProdutos.keySet()) {
            for (String s : this.filialProdutos.get(i).keySet()) {
                q2Stats.addFatFilial(i, this.filialProdutos.get(i).get(s).getFaturacaoTotalMes());
            }
        }
    }


    /*----------------------------------------------------QUERIE2----------------------------------------------------*/

    /**
     * Método que calcula o total de vendas a nivel global de um mês.
     * @param mes int que é o mês a averiguar.
     * @return res Querie2 que é a estrutura a inserir a informação.
     */
    public Querie2 countGlobalQ2(int mes) {
        Querie2 res = new Querie2();
        int nvendas = 0;
        int nclientes;
        Set<String> clientes = new TreeSet<>();
        for (Map<String, InfoCliente> fC : this.filialClientes.values()) {
            for (String s : fC.keySet()) {
                if (fC.get(s).getNVendas_Mes_Especifico(mes - 1) != 0) clientes.add(s);
                nvendas += fC.get(s).getNVendas_Mes_Especifico(mes - 1);
            }
        }
        nclientes = clientes.size();
        res.setNclientes(nclientes);
        res.setNvendas(nvendas);
        return res;
    }

    /**
     * Método que calcula o total de vendas de uma filial num mês.
     * @param mes int que é o mês a averiguar.
     * @param filial int que é a filial a averiguar.
     * @return res Querie2 que é a estrutura a inserir a informação.
     */
    public Querie2 countFilialQ2(int mes, int filial) {
        Querie2 res = new Querie2();
        int nvendas = 0;
        int nclientes;
        Set<String> clientes = new TreeSet<>();
        Map<String, InfoCliente> f = this.filialClientes.get(filial);
        for (String s : f.keySet()) {
            if (f.get(s).getNVendas_Mes_Especifico(mes - 1) != 0) clientes.add(s);
            nvendas += f.get(s).getNVendas_Mes_Especifico(mes - 1);
        }
        nclientes = clientes.size();
        res.setNvendas(nvendas);
        res.setNclientes(nclientes);
        return res;
    }


    /*----------------------------------------------------QUERIE3----------------------------------------------------*/

    /**
     * Método que, dado um código de cliente, calcula o número de vendas realizadas, o total faturado e o total de produtos comprados por mês.
     * @param cliente String que é o cliente a averiguar.
     * @throws ClientNotFoundException exceção.
     * @return q3 Querie3 que é a estrutura a inserir a informação.
     */
    public Querie3 clientMonthlyValuesQ3(String cliente) throws ClientNotFoundException {
        Querie3 q3 = new Querie3();

        for (Integer i : this.filialClientes.keySet()) {
            if (!this.filialClientes.get(i).containsKey(cliente)) throw new ClientNotFoundException(cliente);
            q3.addNvendas(this.filialClientes.get(i).get(cliente).getNVendas());
            q3.addFat(this.filialClientes.get(i).get(cliente).getFatTotalMes());
            for (String s : this.filialClientes.get(i).get(cliente).getProducts_bought().keySet()) {
                q3.addNprodutos(this.filialClientes.get(i).get(cliente).getProducts_bought().get(s).getNVendasMes());
            }
        }
        return q3;
    }

    /*----------------------------------------------------QUERIE4----------------------------------------------------*/

    /**
     * Método que, dado um código de produto, calcula o número de vezes que foi comprado, o total faturado e o total de clientes que o compraram por mês.
     * @param produto String que é o produto a averiguar.
     * @throws ProductNotFoundException exceção.
     * @return q4 Querie4 que é a estrutura a inserir a informação.
     */
    public Querie4 productMonthlyValuesQ4(String produto) throws ProductNotFoundException {
        Querie4 q4 = new Querie4();
        for (Integer i : this.filialProdutos.keySet()) {
            if(!this.filialProdutos.get(i).containsKey(produto)) throw new ProductNotFoundException(produto);
            q4.addTimesBought(this.filialProdutos.get(i).get(produto).getNumeroVezesCompradaMes());
            for (String s : this.filialProdutos.get(i).get(produto).getClientsBought().keySet()) {
                q4.addClientsBought(this.filialProdutos.get(i).get(produto).getClientsBought().get(s).getMes());
            }
            q4.addFatQ4(this.filialProdutos.get(i).get(produto).getFaturacaoTotalMes());
        }
        return q4;
    }

    /*----------------------------------------------------QUERIE5----------------------------------------------------*/

    /**
     * Método que, dado um código de cliente, calcula os produtos que mais comprou.
     * @param cliente String que é o cliente a averiguar.
     * @throws ClientNotFoundException exceção.
     * @return q5 Querie5 que é a estrutura a inserir a informação.
     */
    public Querie5 mostBoughtProductsQ5(String cliente) throws ClientNotFoundException {
        Querie5 q5 = new Querie5();
        for (Integer i : this.filialClientes.keySet()) {
            if(!this.filialClientes.get(i).containsKey(cliente)) throw new ClientNotFoundException(cliente);
            for (InformacaoVendaProduto p : this.filialClientes.get(i).get(cliente).getProducts_bought().values()) {
                q5.addInformacaoVendaProduto(p.clone());
            }
        }
        return q5;
    }

    /*----------------------------------------------------QUERIE6----------------------------------------------------*/

    /**
     * Método que averigua quantos clientes compraram cada produto.
     * @param q6 Querie6 que é  a estrutura a inserir a informação.
     * @param n int que é o numero de produtos a averiguar.
     */
    public void clientesDistintosCompraramProduto(Querie6 q6, int n) {
        List<String> prods = q6.getNProdutosMaisVendidos(n);
        int aux = 0;
        int i = 0;
        for (String s : prods) {
            for (Integer j : this.filialProdutos.keySet()) {
                if(this.filialProdutos.get(j).containsKey(s))
                    aux += this.filialProdutos.get(j).get(s).getClientsBought().keySet().stream().collect(Collectors.toCollection(TreeSet::new)).size();

            }
            q6.addNClientes(i++, aux);
            aux = 0;
        }
    }

    //*----------------------------------------------------QUERIE7----------------------------------------------------*/

    /**
     * Método que calcula os 3 maiores compradores, em faturação, de cada filial.
     * @return q7 Querie7 que é a estrutura a inserir a informação.
     */
    public Querie7 top3Buyers() {
        Querie7 q7 = new Querie7();
        for(Integer k : this.filialClientes.keySet()){
            Map<String,Double> aux = new HashMap<>();
            for (String s : this.filialClientes.get(k).keySet()) {
                aux.putIfAbsent(s,this.filialClientes.get(k).get(s).getFatTotal());
            }
            List<Map.Entry<String,Double>> auxL = new ArrayList<>();
            for(Map.Entry<String, Double> l : aux.entrySet()) {
                auxL.add(l);
            }
            auxL.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));
            int i=0;
            for(Map.Entry<String,Double> s : auxL){
                if(i<3) {
                    q7.setClientes(k,s.getKey(),s.getValue());
                }
                i++;
            }
        }

        return q7;
    }


    /*----------------------------------------------------QUERIE8----------------------------------------------------*/

    /**
     * Método que calcula o numero de produtos diferentes para N clientes.
     * @param n int que é o número de clientes a averiguar.
     * @return q8 Querie8 que é a estrutura a inserir a informação.
     */
    public Querie8 differentBoughtProductsByNClientsQ8(int n) {
        Querie8 q8 = new Querie8(n);
        Map<String,Integer> aux = new HashMap<>();
        for (Integer i : this.filialClientes.keySet()) {
            for (InfoCliente info : this.filialClientes.get(i).values())
                if(aux.putIfAbsent(info.getCode(),info.getProducts_bought().keySet().stream().collect(Collectors.toCollection(TreeSet::new)).size())==null);
                else{
                    int help = aux.get(info.getCode());
                    help += info.getProducts_bought().keySet().stream().collect(Collectors.toCollection(TreeSet::new)).size();
                    aux.put(info.getCode(),help);
                }
        }
        List<Map.Entry<String,Integer>> auxL = new ArrayList<>();
        for(Map.Entry<String, Integer> l : aux.entrySet()) {
            auxL.add(l);
        }
        auxL.sort(new ReverseOrderValorNome());
        int i=0;
        for(Map.Entry<String,Integer> s : auxL){
            if(i<n){
                q8.addProduto(s.getValue(),s.getKey(),i);
            }
            i++;
        }
        return q8;
    }

    /*----------------------------------------------------QUERIE9----------------------------------------------------*/

    /**
     * Método que calcula os N clientes que mais compraram um produto dado e quanto gastaram.
     * @param prod String que é o produto a averiguar.
     * @param n int que é o número de clientes a averiguar.
     * @throws ProductNotFoundException exceção.
     * @return q9 Querie9 que é a estrutura a inserir a informação.
     */
    public Querie9 productTopBuyersQ9(String prod, int n) throws ProductNotFoundException {
        Querie9 q9 = new Querie9(n);
        Map<String, Integer> aux = new HashMap<>();
        Map<String, Double> auxD = new HashMap<>();
        for (Integer i : this.filialProdutos.keySet()) {
            if (!this.filialProdutos.get(i).containsKey(prod)) throw new ProductNotFoundException(prod);
            for (String s : this.filialProdutos.get(i).get(prod).getClientsBought().keySet()) {
                aux.put(s, this.filialProdutos.get(i).get(prod).getClientsBought().get(s).getQuantidade());
                auxD.put(s,this.filialProdutos.get(i).get(prod).getClientsBought().get(s).getSpent());
            }
        }
        List<Map.Entry<String, Integer>> auxL = new ArrayList<>();
        for (Map.Entry<String, Integer> l : aux.entrySet()) {
            auxL.add(l);
        }
        auxL.sort(new ReverseOrderValorNome());
        int i=0;
        for(Map.Entry<String,Integer> s : auxL){
            if(i<n){
                q9.addCli(s.getKey(),s.getValue(),i);
                i++;
            }
        }
        i=0;
        for(String s : q9.getCliCodes()){
                if(i<n){
                    q9.setCliMoneySpent(i,auxD.get(s));
                }
            i++;
        }
        return q9;
    }

    /*----------------------------------------------------QUERIE10---------------------------------------------------*/

    /**
     * Método que calcula para cada produto, em cada mês , para cada filial, o seu total de faturação.
     * @return q10 Querie10 que é a estrutura a inserir a informação.
     */
    public Querie10 fatMesMesFilialFilialProds() {
        Querie10 q10 = new Querie10();
        for (Integer i : this.filialProdutos.keySet()) {
            Map<String, InfoProduto> m = this.filialProdutos.get(i);
            for (InfoProduto info : m.values()) {
                q10.addProdFat(i, info.getCode(), info.getFaturacaoTotalMes());
            }
        }
        return q10;
    }

}