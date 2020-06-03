/**
 * @file InformacaoVendaProduto.java
 *  Ficheiro que contém a API relativa à implementação da informação de venda dos produtos.
 */

package FilialStuff;

import Geral.DefVariaveis;

import java.io.Serializable;

public class InformacaoVendaProduto implements DefVariaveis, Comparable<InformacaoVendaProduto>, Serializable {

    private String code;
    private int qtd;
    private double fat;
    private int[] nvendas_mes;

    /**
     *  Método que inicializa a estrutura com a informação de venda de um produto.
     */
    public InformacaoVendaProduto() {
        this.code = "";
        this.qtd = 0;
        this.fat = 0;
        this.nvendas_mes = new int[MES];
    }

    /**
     *  Método que inicializa a estrutura com a informação da venda de um produto.
     * @param c String que é o código do produto comprado.
     * @param q int que é a quantidade comprada desse produto.
     * @param f double que é o faturado com esse produto.
     */
    public InformacaoVendaProduto(String c, int q, double f) {
        this.code = c;
        this.qtd = q;
        this.fat = f;
        this.nvendas_mes = new int[MES];
    }

    /**
     *  Método que inicializa a estrutura com a informação da venda de um produto.
     * @param info InformacaoVendaProduto que é a estrutura a copiar.
     */
    public InformacaoVendaProduto(InformacaoVendaProduto info) {
        this.code = info.getCode();
        this.qtd = info.getQtd();
        this.fat = info.getFat();
        this.nvendas_mes = info.getNVendasMes();
    }

    /**
     *  Método que adiciona informação sobre a compra de um produto.
     * @param q int que é a quantidade comprada.
     * @param f double que é o faturado com esse produto.
     * @param m int que é o mês em que o produto foi comprado.
     */
    public void addInfo(int q, double f, int m) {
        this.qtd += q;
        this.fat += f;
        this.nvendas_mes[m - 1]++;
    }

    //Getters

    /**
     *  Método que devolve o código de um produto.
     * @return String que é o código do produto comprado.
     */
    public String getCode() {
        return this.code;
    }

    /**
     *  Método que devolve o total faturado de um produto.
     * @return double que é o total faturado de um produto.
     */
    public double getFat() {
        return this.fat;
    }

    /**
     *  Método que devolve o código de um produto.
     * @return int que é a quantidade comprada de um produto.
     */
    public int getQtd() {
        return this.qtd;
    }

    public int[] getNVendasMes() {
        return this.nvendas_mes;
    }


    //Setters

    /**
     *  Método que define o código de um produto.
     * @param c String que é o código do produto comprado.
     */
    public void setCode(String c) {
        this.code = c;
    }

    /**
     *  Método que define o total faturado de um produto.
     * @param f double que é o faturado por um produto.
     */
    public void setFat(double f) {
        this.fat = f;
    }

    /**
     *  Método que define a quantidade comprada de um produto.
     * @param q int que é a quantidade comprada de um produto.
     */
    public void setQtd(int q) {
        this.qtd = q;
    }

    /**
     *  Método que define o número de vezes que um produto foi comprado em cada mês.
     * @param m int[] que é o array com o número de vezes que um produto foi comprado em cada mês.
     */
    public void setNvendasMes(int[] m) {
        this.nvendas_mes = m;
    }

    /**
     *  Método que retorna uma cópia da estrutura.
     * @return InformacaoVendaProduto que é a cópia da estrutura.
     */
    public InformacaoVendaProduto clone() {
        return new InformacaoVendaProduto(this);

    }

    /**
     *  Método que compara duas classes InformaçãoVendaProduto com base na quantidade comprada de um produto. Caso sejam iguais, compara os códigos dos produtos.
     * @param informacaoVendaProduto InformacaoVendaProduto que é a estrutura a comparar.
     * @return int que é o resultado da comparação.
     */
    @Override
    public int compareTo(InformacaoVendaProduto informacaoVendaProduto) {
        if (informacaoVendaProduto.getQtd() > this.getQtd()) return 1;
        else if (informacaoVendaProduto.getQtd() < this.getQtd()) return -1;
        else return this.getCode().compareTo(informacaoVendaProduto.getCode());
    }
}
