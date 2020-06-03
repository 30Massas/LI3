/**
 * @file Q1Stats.java
 *  Ficheiro que contém a API relativa à implementação da query 1 estatística.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;

public class Q1Stats implements Querie, Serializable {

    private String ficheiro;
    private int nvendas_erradas;
    private int total_produtos;
    private int total_produtos_diferentes;
    private int total_produtos_nao_comprados;
    private int total_clientes;
    private int total_clientes_compradores;
    private int total_clientes_nada_compraram;
    private int vendas_a_zero;
    private double fat_total;

    /**
     *  Método que inicializa uma estrutura Q1Stats.
     */
    public Q1Stats(){
        this.ficheiro = "";
        this.nvendas_erradas = 0;
        this.total_produtos = 0;
        this.total_produtos_diferentes = 0;
        this.total_produtos_nao_comprados = 0;
        this.total_clientes = 0;
        this.total_clientes_nada_compraram = 0;
        this.vendas_a_zero = 0;
        this.fat_total = 0;
    }

    /**
     *  Método que devolve o caminho do ficheiro de vendas lido.
     * @return ficheiro String que é o caminho do ficheiro.
     */
    public String getFicheiro() {
        return ficheiro;
    }

    /**
     *  Método que define o caminho do ficheiro de vendas lido.
     * @param ficheiro String que é o caminho do ficheiro
     */
    public void setFicheiro(String ficheiro) {
        this.ficheiro = ficheiro;
    }

    /**
     *  Método que devolve o número de linhas de venda erradas do ficheiro lido.
     * @return nvendas_erradas int que é o total de linhas erradas.
     */
    public int getNvendas_erradas() {
        return nvendas_erradas;
    }

    /**
     *  Método que define o número de linhas de venda erradas do ficheiro lido.
     * @param nvendas_erradas int que é o total de linhas erradas.
     */
    public void setNvendas_erradas(int nvendas_erradas) {
        this.nvendas_erradas = nvendas_erradas;
    }

    /**
     *  Método que devolve o número total de produtos lidos.
     * @return total_produtos int que é o total de produtos contabilizados.
     */
    public int getTotal_produtos() {
        return total_produtos;
    }

    /**
     *  Método que define o número total de produtos lidos.
     * @param total_produtos int que é o total de produtos contabilizados.
     */
    public void setTotal_produtos(int total_produtos) {
        this.total_produtos = total_produtos;
    }

    /**
     *  Método que devolve o número total de produtos diferentes que foram efetivamente comprados.
     * @return total_produtos_diferentes int que é o total de produtos diferentes.
     */
    public int getTotal_produtos_diferentes() {
        return total_produtos_diferentes;
    }

    /**
     *  Método que define o número total de produtos diferentes que foram efetivamente comprados.
     * @param total_produtos_diferentes int que é o total de produtos diferentes.
     */
    public void setTotal_produtos_diferentes(int total_produtos_diferentes) {
        this.total_produtos_diferentes = total_produtos_diferentes;
    }

    /**
     *  Método que devolve o número total de produtos não comprados.
     * @return total_produtos_nao_comprados int que é o total de produtos não comprados.
     */
    public int getTotal_produtos_nao_comprados() {
        return total_produtos_nao_comprados;
    }

    /**
     *  Método que define o número total de produtos não comprados.
     * @param total_produtos_nao_comprados int que é o total de produtos não comprados.
     */
    public void setTotal_produtos_nao_comprados(int total_produtos_nao_comprados) {
        this.total_produtos_nao_comprados = this.total_produtos - total_produtos_nao_comprados;
    }

    /**
     *  Método que devolve o número total de clientes lidos.
     * @return total_clientes int que é o total de clientes contabilizados.
     */
    public int getTotal_clientes() {
        return total_clientes;
    }

    /**
     *  Método que define o número total de clientes lidos.
     * @param total_clientes int que é o total de clientes contabilizados.
     */
    public void setTotal_clientes(int total_clientes) {
        this.total_clientes = total_clientes;
    }

    /**
     *  Método que devolve o número total de clientes que fizeram no mínimo uma compra.
     * @return total_clientes_compradores int que é o total de clientes.
     */
    public int getTotal_clientes_compradores() {
        return total_clientes_compradores;
    }

    /**
     *  Método que define o número total de clientes que fizeram no mínimo uma compra.
     * @param total_clientes_compradores int que é o total de clientes.
     */
    public void setTotal_clientes_compradores(int total_clientes_compradores) {
        this.total_clientes_compradores = total_clientes_compradores;
    }

    /**
     *  Método que devolve o número total de clientes que nada compraram.
     * @return total_clientes_nada_compraram int que é o total de clientes.
     */
    public int getTotal_clientes_nada_compraram() {
        return total_clientes_nada_compraram;
    }

    /**
     *  Método que define o número total de clientes que nada compraram.
     * @param total_clientes_nada_compraram int que é o total de clientes.
     */
    public void setTotal_clientes_nada_compraram(int total_clientes_nada_compraram) {
        this.total_clientes_nada_compraram = total_clientes_nada_compraram;
    }

    /**
     *  Método que devolve o número total de vendas com faturação zero.
     * @return vendas_a_zero int que é o número total de vendas.
     */
    public int getVendas_a_zero() {
        return vendas_a_zero;
    }

    /**
     *  Método que define o número total de vendas com faturação zero.
     * @param vendas_a_zero int que é o número total de vendas.
     */
    public void setVendas_a_zero(int vendas_a_zero) {
        this.vendas_a_zero = vendas_a_zero;
    }

    /**
     *  Método que devolve a faturação total das vendas lidas.
     * @return fat_total double que é a faturação total.
     */
    public double getFat_total() {
        return fat_total;
    }

    /**
     *  Método que define a faturação total das vendas lidas.
     * @param fat_total double que é a faturação total.
     */
    public void setFat_total(double fat_total) {
        this.fat_total = fat_total;
    }
}
