/**
 * @file Querie9.java
 *  Ficheiro que contém a API relativa à implementação da query 9.
 */

package Queries;


import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;


public class Querie9 implements Querie, Serializable {

    private double[] gasto;
    private int[] qtd;
    private List<String> cli_qtd;


    /**
     *  Método que inicializa uma estrutura Querie9
     * @param n int que é o número pedido pelo utilizador.
     */
    public Querie9(int n){
        this.gasto = new double[n];
        this.qtd = new int[n];
        this.cli_qtd = new ArrayList<>();
    }

    /**
     *  Método que devolve o total gasto por um dado cliente.
     * @param index int que é a posição referente ao cliente.
     * @return double que é o gasto.
     */
    public double getGastoIndex(int index){
        return this.gasto[index];
    }

    /**
     *  Método que devolve a quantidade total comprada por um dado cliente.
     * @param index int que é a posição referente ao cliente.
     * @return int que é a quantidade.
     */
    public int getQtdIndex(int index){
        return this.qtd[index];
    }

    /**
     *  Método que devolve uma lista com os códigos de clientes.
     * @return aux que contém os códigos de cliente.
     */
    public List<String> getCliCodes(){
        List<String> aux = new ArrayList<>();
        for(String s : this.cli_qtd){
            aux.add(s);
        }
        return aux;
    }

    /**
     *  Método que define o total gasto por um dado cliente.
     * @param i int que é a posição referente ao cliente.
     * @param spent double que é o gasto pelo cliente.
     */
    public void setCliMoneySpent(int i, double spent){
        this.gasto[i] += spent;
    }

    /**
     *  Método que adiciona um cliente e a quantidade comprada.
     * @param cli String que é o código de cliente.
     * @param qtd int que é a quantidade comprada.
     * @param i int que é a posição do cliente.
     */
    public void addCli(String cli, int qtd, int i){
        this.cli_qtd.add(i,cli);
        this.qtd[i] += qtd;
    }

    /**
     *  Método que devolve a quantidade comprada por um dado cliente.
     * @param i int que é a posição referente ao cliente.
     * @return int que é a quantidade.
     */
    public int getQuantityBoughtByClient(int i){
        return this.qtd[i];
    }

    /**
     *  Método que devolve o gasto por um dado cliente.
     * @param i int que é a posição referente ao cliente.
     * @return double que é o gasto.
     */
    public double getSpentIndex(int i){
        return this.gasto[i];
    }

}
