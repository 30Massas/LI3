/**
 * @file Querie10.java
 *  Ficheiro que contém a API relativa à implementação da query 10.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

import static Geral.DefVariaveis.MES;

public class Querie10 implements Querie, Serializable {
    // filial                            // mes     fat
    private Map<Integer, Map<String, Map<Integer, Double>>> prods;

    /**
     *  Método que inicializa uma estrutura Querie10
     */
    public Querie10() {
        this.prods = new HashMap<>();
    }

    /**
     *  Método que devolve um Map organizado por filial, onde está guardado para cada produto o gasto em cada mês
     * @return res que contém os produtos e a sua informação.
     */
    public Map<Integer, Map<String, Map<Integer, Double>>> getProds() {
        Map<Integer, Map<String, Map<Integer, Double>>> res = new HashMap<>();
        for (Integer i : this.prods.keySet()) {
            Map<String, Map<Integer, Double>> in = this.prods.get(i);
            for (Map.Entry<String, Map<Integer, Double>> f : in.entrySet()) {
                res.putIfAbsent(i, new TreeMap<>());
                res.get(i).putIfAbsent(f.getKey(),new HashMap<>());
                Map<Integer, Double> aux = f.getValue();
                for(Map.Entry<Integer,Double> map : aux.entrySet())
                    res.get(i).get(f.getKey()).put(map.getKey(),map.getValue());
            }
        }
        return res;
    }

    /**
     *  Método que adiciona numa dad filial, os valores faturados de um produto em cada mês.
     * @param index int que é a filial a averiguar.
     * @param val que contém a informação do produto.
     */
    public void addValue(int index, Map<String, Map<Integer, Double>> val) {
        this.prods.put(index, val);
    }

    /**
     *  Método que adiciona a um dado produto, numa dada filial, o total faturado em cada mês.
     * @param index int que é a filial a averiguar,
     * @param code String que é o código de produto.
     * @param fat double[] que contém o total faturado em cada mês.
     */
    public void addProdFat(int index, String code, double[] fat) {
        this.prods.putIfAbsent(index, new TreeMap<>());
        this.prods.get(index).putIfAbsent(code, new HashMap<>());
        for (int i = 0; i < MES; i++)
            if (fat[i] != 0)
                this.prods.get(index).get(code).put(i+1, fat[i]);
    }

}
