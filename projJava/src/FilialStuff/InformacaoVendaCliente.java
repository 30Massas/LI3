/**
 * @file InformacaoVendaCliente.java
 *  Ficheiro que contém a API relativa à implementação da informação de venda dos clientes.
 */

package FilialStuff;

import Geral.DefVariaveis;

import java.io.Serializable;

public class InformacaoVendaCliente implements DefVariaveis, Serializable {

    private String code;
    private int mes;
    private int modo_compra;
    private double spent_on_product;
    private int qtd_comprada;

    /**
     *  Método que inicializa uma estrutura InformacaoVendaCliente.
     */
    public InformacaoVendaCliente() {
        this.code = "";
        this.mes = 0;
        this.modo_compra = 0;
        this.spent_on_product = 0;
        this.qtd_comprada = 0;
    }

    /**
     *  Método que inicializa uma estrutura InformacaoVendaCliente.
     * @param c String que é o código de cliente.
     * @param mes int que é o mês em que comprou.
     * @param modo_compra int que é o modo como comprou o produto.
     * @param spent double que é o que gastou no produto.
     * @param qtd int que é a quantidade comprada do produto.
     */
    public InformacaoVendaCliente(String c,int mes, int modo_compra,double spent, int qtd) {
        this.code = c;
        this.mes = mes;
        this.modo_compra = modo_compra;
        this.spent_on_product = spent;
        this.qtd_comprada = qtd;
    }

    /**
     *  Método que inicializa uma estrutura InformacaoVendaCliente.
     * @param info InformacaoVendaCliente que é a estrutura a copiar.
     */
    public InformacaoVendaCliente(InformacaoVendaCliente info) {
        this.code = info.getCode();
        this.mes = info.getMes();
        this.modo_compra = info.getModoCompra();
        this.spent_on_product = info.getSpent();
        this.qtd_comprada = info.getQuantidade();
    }

    /**
     *  Método que devolve o código de cliente.
     * @return String que é o código de cliente.
     */
    public String getCode() {
        return code;
    }

    /**
     *  Método que define o código de cliente.
     * @param code String que é o código de cliente.
     */
    public void setCode(String code) {
        this.code = code;
    }

    /**
     *  Método que devolve o mês em que o cliente comprou.
     * @return int que é o mês.
     */
    public int getMes() {
        return this.mes;
    }

    /**
     *  Método que define o mês em que o cliente comprou.
     * @param mes int que é o mês.
     */
    public void setMes(int mes) {
        this.mes = mes;
    }

    /**
     *  Método que devolve o modo em que o cliente comprou.
     * @return int que é o modo.
     */
    public int getModoCompra() {
        return this.modo_compra;
    }

    /**
     *  Método que define o modo em que o cliente comprou.
     * @param modo_compra int, que é o modo.
     */
    public void setModoCompra(int modo_compra) {
        this.modo_compra = modo_compra;
    }

    /**
     *  Método que devolve o valor gasto pelo cliente.
     * @return double que é o modo.
     */
    public double getSpent() {
        return spent_on_product;
    }

    /**
     *  Método que define o valor gasto pelo cliente.
     * @param spent_on_product double que é o modo.
     */
    public void setSpent(double spent_on_product) {
        this.spent_on_product = spent_on_product;
    }

    /**
     *  Método que devolve a quantidade comprada pelo cliente.
     * @return int que é a quantidade.
     */
    public int getQuantidade() {
        return qtd_comprada;
    }

    /**
     *  Método que devolve a quantidade comprada pelo cliente.
     * @param qtd_comprada int que é a quantidade.
     */
    public void setQuantidade(int qtd_comprada) {
        this.qtd_comprada = qtd_comprada;
    }

    /**
     *  Método que adiciona informação da compra de um produto ao cliente.
     * @param client String que é o cliente a adicionar.
     * @param spent double que é o gasto pelo cliente.
     * @param mes int que é o mês em que comprou.
     * @param modo int que é o modo em que o cliente comprou.
     * @param qtd int que é a quantidade comprada
     */
    public void addInfo(String client, double spent, int mes, int modo, int qtd) {
        this.code = client;
        this.spent_on_product += spent;
        this.mes = mes;
        this.modo_compra = modo;
        this.qtd_comprada += qtd;
    }

    /**
     *  Método que copia uma estrutura InformacaoVendaCliente.
     * @return InformacaoVendaCliente que é a cópia da estrutura.
     */
    public InformacaoVendaCliente clone() {
        return new InformacaoVendaCliente(this);
    }


}
