/**
 * @file Querie3.java
 *  Ficheiro que contém a API relativa à implementação da query 3.
 */

package Queries;

import Geral.DefVariaveis;
import Interfaces.Querie;

import java.io.Serializable;


public class Querie3 implements DefVariaveis, Querie, Serializable {
    private int[] nvendas;
    private int[] nprodutos;
    private double[] fat_mes;

    /**
     *  Método que inicializa uma estrutura Querie3.
     */
    public Querie3(){
        this.nvendas = new int[MES];
        this.nprodutos = new int[MES];
        this.fat_mes = new double[MES];
    }

    /**
     *  Método que inicializa uma estrutura Querie3 com passagem de parâmetros.
     * @param nvendas int[] que contém o número de vendas em cada mês.
     * @param nprodutos int[] que contém o número de produtos em cada mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public Querie3(int[] nvendas, int[] nprodutos, double[] fat_mes) {
        this.nvendas = nvendas;
        this.nprodutos = nprodutos;
        this.fat_mes = fat_mes;
    }

    /**
     *  Método que devolve o número total de vendas num dado mês.
     * @param index int que é o mês a averiguar.
     * @return int que é o total de vendas.
     */
    public int getNvendas(int index){
        return this.nvendas[index];
    }

    /**
     *  Método que devolve o número total de produtos num dado mês.
     * @param index int que é o mês a averiguar.
     * @return int que é o total de produtos.
     */
    public int getNprodutos(int index){
        return this.nprodutos[index];
    }

    /**
     *  Método que devolve o total faturado num dado mês.
     * @param index int que é o mês a averiguar.
     * @return double que é o total faturado.
     */
    public double getFat_mes(int index){
        return this.fat_mes[index];
    }

    /**
     *  Método que devolve o número de vendas em cada mês.
     * @return nvendas int[] que contém o número de vendas em cada mês.
     */
    public int[] getNvendas() {
        return nvendas;
    }

    /**
     *  Método que devolve o número de produtos em cada mês.
     * @return nprodutos int[] que contém o número de produtos em cada mês.
     */
    public int[] getNprodutos() {
        return nprodutos;
    }

    /**
     *  Método que devolve o total faturado em cada mês.
     * @return fat_mes double[]´que contém o total faturado em cada mês.
     */
    public double[] getFat() {
        return fat_mes;
    }

    /**
     *  Método que define e atualiza o total de vendas por mês.
     * @param nvendas int[] que contém o total de vendas em cada mês.
     */
    public void addNvendas (int[] nvendas) {
        for (int i = 0; i < MES; i++) {
            this.nvendas[i] += nvendas[i];
        }
    }

    /**
     *  Método que define o total de vendas por mês.
     * @param nvendas int[] que contém o total de vendas por mês.
     */
    public void setNvendas(int[] nvendas) {
        this.nvendas = nvendas;
    }

    /**
     *  Método que define o total de produtos em cada mês.
     * @param nprodutos int[9 que contém o total de produtos por mês.
     */
    public void setNprodutos(int[] nprodutos) {
        this.nprodutos = nprodutos;
    }

    /**
     *  Método que atualiza o total faturado em cada mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public void addFat (double[] fat_mes) {
        for (int i = 0; i < MES; i++) {
            this.fat_mes[i] += fat_mes[i];
        }
    }

    /**
     *  Método que atualiza o número de produtos em cada mês.
     * @param nprods int[] que contém o toal de produtos em cada mês.
     */
    public void addNprodutos(int[] nprods){
        for (int i = 0; i < MES; i++) {
            this.nprodutos[i] += nprods[i];
        }
    }

    /**
     *  Método que define o total faturado em cada mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public void setFat(double[] fat_mes) {
        this.fat_mes = fat_mes;
    }

    /**
     *  Método que define o número total de vendas num dado mês.
     * @param n int que é o número de vendas.
     * @param mes int que é o mês a definir.
     */
    public void setNVendas_Mes(int n, int mes){
        this.nvendas[mes] = n;
    }

    /**
     *  Método que define o número total de produtos num dado mês.
     * @param n int que é o número de produtos.
     * @param mes int que é o mês a definir.
     */
    public void setNProds_Mes(int n, int mes){
        this.nprodutos[mes] = n;
    }

    /**
     *  Método que define o total faturado num dado mês.
     * @param n double que é o total faturado..
     * @param mes int que é o mês a definir.
     */
    public void setFat_Mes(double n, int mes){
        this.fat_mes[mes] = n;
    }
}
