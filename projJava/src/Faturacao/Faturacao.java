/**
 * @file Faturacao.java
 * Ficheiro que contém a API relativa à implementação da faturação.
 */

package Faturacao;

import Geral.DefVariaveis;
import Geral.Registo;
import Queries.*;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;


public class Faturacao implements DefVariaveis, Serializable {
    private Map<Integer, Map<String, InformacaoFat>> faturacao;

    /**
     * Método que inicializa a estrutura de Faturação.
     */
    public Faturacao() {
        this.faturacao = new TreeMap<>();
    }

    /**
     * Método que adiciona a informação de uma venda relativa a um dado produto.
     * @param e Registo que contém a informação a adicionar.
     */
    public void addInformacaoFat(Registo e) {
        int index = e.getCodProd().charAt(0) - 'A';
        this.faturacao.putIfAbsent(index, new HashMap<>());
        this.faturacao.get(index).putIfAbsent(e.getCodProd(), new InformacaoFat());
        this.faturacao.get(index).get(e.getCodProd()).addInformacaoFat(e.getPreco(), e.getQuantidade(), e.getModo(), e.getMes(), e.getFilial());
    }

    /**
     * Método que averigua se existe um dado produto.
     * @param s String que é o código de produto a averiguar.
     * @return boolean que indica se o produto existe ou não.
     */
    public boolean containsProd(String s) {
        int index = s.charAt(0) - 'A';
        return this.faturacao.get(index).containsKey(s);
    }

    /*------------------------------------------------------QUERIE1-------------------------------------------------------*/

    /**
     * Método que dado um conjunto com os códigos de produtos, verifica quais nunca foram comprados.
     * @param produtos com os códigos de produtos.
     * @return q1 Querie1 onde serão guardados os produtos, bem como a quantidade total, que não foram comprados.
     */
    public Querie1 comparaQ1(Set<String> produtos) {
        Querie1 q1 = new Querie1();
        Set<String> res = new TreeSet<>();
        for (String s : produtos) {
            if (!(this.containsProd(s))) {
                res.add(s);
            }
        }
        q1.setProdutos(res);
        q1.setTotal(res.size());
        return q1;
    }

    /*------------------------------------------------------QUERIE6------------------------------------------------------*/

    /**
     * Método que dado um inteiro calcula os N produtos mais vendidos no ano.
     * @param n int com o número de produtos a averiguar.
     * @return q6 Querie6 onde serão guardados os produtos, bem como a quantidade total comprada.
     */
    public Querie6 produtosMaisVendidos(int n) {
        Querie6 q6 = new Querie6(n);
        for (Map<String, InformacaoFat> inf : this.faturacao.values())
            for (Map.Entry<String, InformacaoFat> f : inf.entrySet()) {
                q6.addProduto(f.getValue().getQtd_Total(), f.getKey());
            }
        return q6;
    }

    /*---------------------------QUERIE1 STATISTICS---------------------------*/


    /**
     * Método que insere numa estrutura os valores de faturação.
     * @param q1 Q1Stats que é a estrutura onde inserir a informação.
     */
    public void getProdsValues(Q1Stats q1) {
        double fat_total = 0;
        Set<String> total_prods_comprados = new TreeSet<>();
        for (Integer i : this.faturacao.keySet()) {
            for (String s : this.faturacao.get(i).keySet()) {
                fat_total += this.faturacao.get(i).get(s).getFatTotal();
                total_prods_comprados.add(s);
            }
        }
        q1.setTotal_produtos_diferentes(total_prods_comprados.size());
        q1.setTotal_produtos_nao_comprados(total_prods_comprados.size());
        q1.setFat_total(fat_total);
    }

    /*---------------------------QUERIE2 STATISTICS---------------------------*/

    /**
     * Método que calcula a faturação e o número de vendas para cada mês.
     * @return q2Stats Q2Stats onde serão guardados os valores de faturação e numero de vendas.
     */
    public Q2Stats getFatValuesQ2Stats() {
        Q2Stats q2Stats = new Q2Stats();
        for (Integer i : this.faturacao.keySet()) {
            for (InformacaoFat f : this.faturacao.get(i).values()) {
                q2Stats.addFat(f.getFatMes());
                q2Stats.addNVendas(f.getNVendasMes());
            }
        }
        return q2Stats;
    }


}
