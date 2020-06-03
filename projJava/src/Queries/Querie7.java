/**
 * @file Querie7.java
 *  Ficheiro que contém a API relativa à implementação da query 7.
 */

package Queries;

import Geral.DefVariaveis;
import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;


public class Querie7 implements DefVariaveis, Querie, Serializable {


    private Map<Integer,Map<Double,String>> clientes;

    /**
     *  Método que inicializa uma estrutura Querie7.
     */
    public Querie7() {
        this.clientes = new HashMap<>();
    }


    /**
     *  Método que adiciona para uma dada filial,, um cliente e quanto gastou.
     * @param i int que corresponde à filial a averiguar.
     * @param cli String que é o código de cliente.
     * @param fat double que é o quanto gastou.
     */
    public void setClientes(int i,String cli, double fat){
        Map<Double,String> aux = new TreeMap<>(Comparator.reverseOrder());
        if(this.clientes.putIfAbsent(i,aux)==null){
            aux.put(fat,cli);
            this.clientes.put(i,aux);
        }
        else this.clientes.get(i).putIfAbsent(fat,cli);
    }

    /**
     *  Método qu devolve quanto um dado cliente gastou numa dada filial.
     * @param c String que é o código do cliente.
     * @param f int que é a filial a averiguar.
     * @return aux double que é o gasto pelo cliente.
     */
    public double getGastoIndex(String c, int f){
        double aux = 0;
        for(Map.Entry<Double,String> s : this.clientes.get(f).entrySet()){
            if(s.getValue().compareTo(c)==0){
                aux = s.getKey();
                break;
            }
        }
        return aux;
    }


    /**
     *  Método que devolve os 3 maiores compradores numa dada filial.
     * @param n int que é a filial a averiguar.
     * @return aux List que contém os códigos dos clientes.
     */
    public List<String> top3Buyers(int n){
        List<String> aux = new ArrayList<>();
        int i=0;
        for(Map.Entry<Double,String> s : this.clientes.get(n).entrySet()) {
            if (i < 3)
                aux.add(s.getValue());
            i++;
        }
        return aux;
    }

}
