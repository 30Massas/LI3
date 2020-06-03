package Geral;

import java.io.Serializable;

public class Registo implements Serializable {
    private String codProd;
    private double preco;
    private int quantidade;
    private char modo;
    private int mes;
    private int filial;

    /**
     *  Método que inicializa uma estrutura Registo.
     */
    public Registo() {
        this.codProd = "";
        this.preco = 0;
        this.quantidade = 0;
        this.modo = 0;
        this.mes = 0;
        this.filial = 0;
    }

    /**
     *  Método que inicializa uma estrutura Registo com passagem de parâmetros.
     * @param codProd String que é o código do produto comprado.
     * @param preco double que é o preço a que foi comprado.
     * @param quantidade int que é a quantidade que foi comprada.
     * @param modo char que é o modo em que a compra foi feita 'N' (Normal) ou 'P' (Promocional)
     * @param mes int, mês.
     * @param filial int, filial.
     */
    public Registo(String codProd, double preco, int quantidade, char modo, int mes, int filial) {
        this.codProd = codProd;
        this.preco = preco;
        this.quantidade = quantidade;
        this.modo = modo;
        this.mes = mes;
        this.filial = filial;
    }



    //getters and setters

    /**
     *  Método que retorna o código de produto num registo.
     * @return codProd String que é o código do produto.
     */
    public String getCodProd() {
        return codProd;
    }

    /**
     *  Método que define o código de produto num registo.
     * @param codProd, produto.
     */
    public void setCodProd(String codProd) {
        this.codProd = codProd;
    }

    /**
     *  Método que retorna o preço a que um produto foi comprado.
     * @return preco double que é o preço a que foi comprado.
     */
    public double getPreco() {
        return preco;
    }

    /**
     *  Método que define o preço a que um produto foi comprado.
     * @param preco double, preço.
     */
    public void setPreco(double preco) {
        this.preco = preco;
    }

    /**
     *  Método que retorna a quantidade comprada.
     * @return quantidade int  que é a quantidade comprada.
     */
    public int getQuantidade() {
        return quantidade;
    }

    /**
     *  Método que define a quantidade comprada.
     * @param quantidade int, quantidade.
     */
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    /**
     *  Método que retorna o modo em que a compra foi feita.
     * @return modo char que é o moodo em que a compra foi feita.
     */
    public char getModo() {
        return modo;
    }

    /**
     *  Método que define o modo em que a compra foi feita.
     * @param modo char, modo.
     */
    public void setModo(char modo) {
        this.modo = modo;
    }

    /**
     *  Método que retorna o mes em que a compra foi feita.
     * @return mes int que é o mes em que a compra foi feita.
     */
    public int getMes() {
        return mes;
    }

    /**
     *  Método que define o mes em que a compra foi feita.
     * @param mes int, mês.
     */
    public void setMes(int mes) {
        this.mes = mes;
    }

    /**
     *  Método que retorna a filial em que a compra foi feita.
     * @return filial int que é a filial em que a compra foi feita.
     */
    public int getFilial() {
        return filial;
    }

    /**
     *  Método que define a filial em que a compra foi feita.
     * @param filial int, filial.
     */
    public void setFilial(int filial) {
        this.filial = filial;
    }
}
