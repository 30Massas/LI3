/**
 * @file Querie4.java
 *  Ficheiro que contém a API relativa à implementação da query 4.
 */

package Queries;

import Geral.DefVariaveis;
import Interfaces.Querie;

import java.io.Serializable;


public class
Querie4 implements DefVariaveis, Querie, Serializable {

    private int[] times_bought;
    private int[] clients_bought;
    private double[] fat_mes;

    /**
     *  Método que inicializa uma estrutura Querie4.
     */
    public Querie4() {
        this.times_bought = new int[MES];
        this.clients_bought = new int[MES];
        this.fat_mes = new double[MES];
    }

    /**
     *  Método que inicializa uma estrutura Querie4 com passagem de parâmetros.
     * @param times_bought int[] que contém o número de vezes comprado em cada mês.
     * @param clients_bought int[] que contém o número de clientes que compraram que cada mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public Querie4(int[] times_bought, int[] clients_bought, double[] fat_mes) {
        this.times_bought = times_bought;
        this.clients_bought = clients_bought;
        this.fat_mes = fat_mes;
    }

    /**
     *  Método que retorna o número de vezes compradas em cada mês.
     * @return times_bought int[] que contém o número de vezes compradas em cada mês.
     */
    public int[] getTimes_bought() {
        return times_bought;
    }

    /**
     *  Método que devolve o número de vezes comprado num dado mês.
     * @param index int que é o mês a averiguar.
     * @return int que é o número de vezes comprado.
     */
    public int getNVezesCompradaMes(int index) {
        return times_bought[index];
    }

    /**
     *  Método que devolve o número de clientes que compraram num dado mês.
     * @param index int que é o mês a averiguar.
     * @return int que é o número de clientes que compraram.
     */
    public int getNClientesMes(int index) {
        return clients_bought[index];
    }

    /**
     *  Método que devolve o total faturado num dado mês.
     * @param index int que é o mês a averiguar
     * @return double que é a faturação.
     */
    public double getFatPMes(int index) {
        return fat_mes[index];
    }

    /**
     *  Método que define o número de vezes comprado em cada mês.
     * @param times_bought int[] que contém o número de vezes comprado em cada mês.
     */
    public void setTimes_bought(int[] times_bought) {
        this.times_bought = times_bought;
    }

    /**
     *  Método que atualiza o total de vezes comprado em cada mês.
     * @param times_bought int[] que contém o número de vezes comprada em cada mês.
     */
    public void addTimesBought(int[] times_bought) {
        for (int i = 0; i < MES; i++) {
            this.times_bought[i] += times_bought[i];
        }
    }

    /**
     *  Método que devolve o número de clientes por mês.
     * @return int[] que contém o número de clientes em cada mês.
     */
    public int[] getClients_bought() {
        return this.clients_bought;
    }

    /**
     *  Método que define o total de clientes por mês.
     * @param clients_bought int[] que contém o total de clientes em cada mês.
     */
    public void setClients_bought(int[] clients_bought) {
        this.clients_bought = clients_bought;
    }

    /**
     *  Método que atualiza o número de clientes em cada mês.
     * @param mes int que é o mês a atualizar.
     */
    public void addClientsBought(int mes) {
        this.clients_bought[mes]++;
    }

    /**
     *  Método que devolve o total faturado por mês.
     * @return double[] que contém o total faturado em cada mês.
     */
    public double[] getFat_mes() {
        return this.fat_mes;
    }

    /**
     *  Método que define o total faturado por mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public void setFat_mes(double[] fat_mes) {
        this.fat_mes = fat_mes;
    }

    /**
     *  Método que atualiza o total faturado em cada mês.
     * @param fat_mes double[] que contém o total faturado em cada mês.
     */
    public void addFatQ4(double[] fat_mes) {
        for (int i = 0; i < MES; i++) {
            this.fat_mes[i] += fat_mes[i];
        }
    }

    /**
     *  Método que incrementa o número de clientes que compraram num dado mês.
     * @param mes int que é o mês a averiguar.
     */
    public void incNClientes(int mes) { this.clients_bought[mes-1]++;}

}
