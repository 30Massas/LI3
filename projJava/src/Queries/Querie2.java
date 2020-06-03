/**
 * @file Querie2.java
 *  Ficheiro que contém a API relativa à implementação da query 2.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;

public class Querie2 implements Querie, Serializable {
    private int nvendas;
    private int nclientes;

    /**
     *  Método que inicializa uma estrutura Querie2.
     */
    public Querie2(){
        this.nvendas = 0;
        this.nclientes = 0;
    }

    /**
     *  Método que inicializa uma estrutura Querie2 com passagem de porâmetros.
     * @param nvendas int que é o número de vendas-
     * @param nclientes int que é o número de clientes.
     */
    public Querie2(int nvendas, int nclientes) {
        this.nvendas = nvendas;
        this.nclientes = nclientes;
    }

    /**
     *  Método que devolve o número de vendas.
     * @return nvendas int que é o número de vendas.
     */
    public int getNvendas() {
        return nvendas;
    }

    /**
     *  Método que define o número de vendas.
     * @param nvendas int que é o número de vendas.
     */
    public void setNvendas(int nvendas) {
        this.nvendas = nvendas;
    }

    /**
     *  Método que devolve o número de clientes.
     * @return nclientes int que é o número de clientes.
     */
    public int getNclientes() {
        return nclientes;
    }

    /**
     *  Método que define o número de clientes.
     * @param nclientes int que é o número de clientes.
     */
    public void setNclientes(int nclientes) {
        this.nclientes = nclientes;
    }


}
