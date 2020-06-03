/**
 * @file Q2Stats.java
 *  Ficheiro que contém a API relativa à implementação da query 2 estatística.
 */

package Queries;

import Geral.DefVariaveis;
import Interfaces.Querie;


import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;


public class Q2Stats implements DefVariaveis, Querie, Serializable {

    private double fat_total;
    private double[] fat_total_mes;
    private int[] nvendas_mes;
    private Map<Integer, double[]> fat_filial;
    private Map<Integer, int[]> nclientes_filial;

    /**
     *  Método que inicializa uma estrutura Q2Stats.
     */
    public Q2Stats(){
        this.fat_total = 0;
        this.fat_total_mes = new double[MES];
        this.nvendas_mes = new int[MES];
        this.fat_filial = new HashMap<>();
        this.nclientes_filial = new HashMap<>();
    }

    /**
     *  Método que adiciona à filial dada a faturação em cada mês
     * @param f iont que é a filial a adicionar.
     * @param fat double[] que contém a faturação em cada mês.
     */
    public void addFatFilial(int f, double[] fat){
        if(this.fat_filial.putIfAbsent(f,new double[MES])==null){
            this.fat_filial.put(f,fat);
        }
        else{
            double[] aux = this.fat_filial.get(f);
            for(int i=0;i<MES;i++) aux[i] += fat[i];
        }
    }

    /**
     *  Método que define a faturação total e em cada mês.
     * @param fat double[] que contém a faturação em cada mês.
     */
    public void addFat(double[] fat){
        for(int i=0;i<MES;i++) {
            this.fat_total_mes[i] += fat[i];
            this.fat_total += fat[i];
        }
    }

    /**
     *  Método que devolve a faturação total.
     * @return fat_total double que é a faturação total.
     */
    public double getFat_total() {
        return fat_total;
    }

    /**
     *  Método que define a faturação total.
     * @param fat_total double que é a faturação total.
     */
    public void setFat_total(double fat_total) {
        this.fat_total = fat_total;
    }

    /**
     *  Método que incrementa o número de clientes que compraram numa dada filial, num dado mês.
     * @param f int que é a filial a averiguar.
     * @param m int que é o mês a averiguar.
     */
    public void incNClientes(int f, int m){
        if(this.nclientes_filial.putIfAbsent(f,new int[MES])==null){
            int[] aux = this.nclientes_filial.get(f);
            aux[m] += 1;
            this.nclientes_filial.put(f,aux);
        }
        else{
            int[] aux = this.nclientes_filial.get(f);
            aux[m] += 1;
            this.nclientes_filial.put(f,aux);
        }
    }

    /**
     *  Método que define e atualiza o número de vendas em cada mês.
     * @param nv int[] que contém o número de vendas em cada mês
     */
    public void addNVendas(int[] nv){
        for(int i=0;i<MES;i++) this.nvendas_mes[i] += nv[i];
    }

    /**
     *  Método que devolve o total faturado num dado mês de uma dada filial.
     * @param f int que é a filial a averiguar.
     * @param m int que é o mês a averiguar.
     * @return double que é o total faturado.
     */
    public double getFaturadoFilialMes(int f, int m){
        return (this.fat_filial.get(f))[m];
    }

    /**
     *  Método que devolve o número total de clientes num dado mês de uma dada filial.
     * @param f int que é a filial a averiguar.
     * @param m int que é o mês a averiguar.
     * @return double que é o total de clientes.
     */
    public int getNClientesFilialMes(int f, int m){
        return (this.nclientes_filial.get(f))[m];
    }

    /**
     *  Método que devolve o número total de vendas num dado mês.
     * @param m int que é o mês a averiguar.
     * @return int que é o total de vendas.
     */
    public int getNVendasMes(int m){
        return this.nvendas_mes[m];
    }

    /**
     *  Método que devolve o total faturado num dado mês.
     * @param m int que é o mês a averiguar.
     * @return double que é o total faturado.
     */
    public double getFatTotalMes(int m){
        return this.fat_total_mes[m];
    }

    /**
     *  Método que devolve um array com o total de vendas em cada mês.
     * @return int[] que contém o total de vendas em cada mês.
     */
    public int[] getNVendas(){
        return this.nvendas_mes;
    }

    /**
     *  Método que devolve o total faturado numa dada filial.
     * @param f int que é a filial a averiguar.
     * @return aux int que é o total faturado.
     */
    public double getFatFilial(int f){
        double aux=0;
        for(int m=0;m<MES;m++)
            aux += this.fat_filial.get(f)[m];
        return aux;
    }

    /**
     *  Método que devolve um Map com o array de número de clientes em cada filial.
     * @return aux que contém o array de número de clientes para cada filial.
     */
    public Map<Integer, int[]> getNClientesFilial(){
        Map<Integer, int[]> aux = new HashMap<>();
        int[] a = new int[MES];
        for(Integer i : this.nclientes_filial.keySet()){
            for(int m=0;m<MES;m++){
                a[m] = this.nclientes_filial.get(i)[m];
            }
            aux.putIfAbsent(i,a);
        }
        return aux;
    }
}
