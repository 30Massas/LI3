/**
 * @file InfoCliente.java
 *  Ficheiro que contém a API relativa à implementação da informação dos clientes.
 */

package FilialStuff;

import Geral.DefVariaveis;
import Geral.Registo;

import java.io.Serializable;
import java.util.Map;
import java.util.HashMap;

public class InfoCliente implements Comparable, DefVariaveis, Serializable {
    private String code; // client code
    private Map<String, InformacaoVendaProduto> products_bought;
    private int[] qtd_total_mes;
    private double[] fat_total_mes;
    private int[] nvendas_mes;


    /**
     *  Método que inicializa a estrutura com a informação de um cliente.
     */
    public InfoCliente() {
        this.code = "";
        this.products_bought = new HashMap<>();
        this.qtd_total_mes = new int[MES];
        this.fat_total_mes = new double[MES];
        this.nvendas_mes = new int[MES];
    }

    /**
     *  Método que calcula o numero de produtos diferentes para N clientes.
     * @param c String que é o cogio de clientes.
     * @param pb que é a lista de produtos comprados por esse cliente e a informação sobre a compra dos mesmos.
     * @param qtd int[] que é a quantidade de produtos comprada por mês.
     * @param fat double[] que é o gasto por mês.
     * @param n int[] que é o numero de compras por mês.
     */
    public InfoCliente(String c, Map<String,InformacaoVendaProduto> pb, int[] qtd, double[] fat, int[] n){
        this.code = c;
        setProductsBought(pb);
        this.qtd_total_mes = qtd;
        this.fat_total_mes = fat;
        this.nvendas_mes = n;
    }

    /**
     *  Método que calcula o numero de produtos diferentes para N clientes.
     * @param info InfoCliente que é uma estrutura já inicializada.
     */
    public InfoCliente(InfoCliente info){
        this.code = info.getCode();
        this.products_bought = info.getProducts_bought();
        this.qtd_total_mes = info.getQtdTotalMes();
        this.fat_total_mes = info.getFatTotalMes();
        this.nvendas_mes = info.getNVendas();
    }

    /**
     *  Método que atualiza as informações sobre um cliente que já tenha sido inicializado.
     * @param e Registo que contém a informação sobre a venda.
     */
    public void addRegisto(Registo e) {
        this.products_bought.putIfAbsent(e.getCodProd(),new InformacaoVendaProduto(e.getCodProd(),0,0));
        this.products_bought.get(e.getCodProd()).addInfo(e.getQuantidade(),e.getPreco()*e.getQuantidade(),e.getMes());
        this.qtd_total_mes[e.getMes()-1] += e.getQuantidade();
        this.fat_total_mes[e.getMes()-1] += e.getQuantidade() * e.getPreco();
        this.nvendas_mes[e.getMes()-1]++;
    }


    /**
     *  Método que insere na estrutura um cliente novo e a informação sobre a venda realizada.
     * @param cliente String que é o código do cliente a inicializar.
     * @param e Registo que contém a informação sobre a venda.
     */
    public void addRegisto(String cliente, Registo e) {
        this.code = cliente;
        InformacaoVendaProduto i = new InformacaoVendaProduto(e.getCodProd(),e.getQuantidade(),e.getPreco()*e.getQuantidade());
        this.products_bought.put(e.getCodProd(),i);
        this.qtd_total_mes[e.getMes()-1] += e.getQuantidade();
        this.fat_total_mes[e.getMes()-1] += e.getQuantidade() * e.getPreco();
        this.nvendas_mes[e.getMes()-1]++;
    }

    /**
     *  Método que define a quantidade de produtos comprada em cada mês.
     * @param qtd int[] que contém a quantidade de produtos em cada mês.
     */
    public void setQtdTotalMes(int[] qtd){
        for(int i=0;i<MES;i++) this.qtd_total_mes[i] = qtd[i];
    }

    /**
     *  Método que retorna um array com a quantidade de produtos comprada em cada mês.
     * @return aux int[] que contém a quantidade de produtos comprada por mês.
     */
    public int[] getQtdTotalMes(){
        int[] aux = new int[MES];
        for(int i=0;i<MES;i++) aux[i] = this.qtd_total_mes[i];
        return aux;
    }

    /**
     *  Método que retorna um código de cliente.
     * @return String que é o código do cliente.
     */
    public String getCode() {
        return this.code;
    }

    /**
     *  Método que define o código de cliente associado a uma estrutura.
     * @param code String que é o código de cliente.
     */
    public void setCode(String code) {
        this.code = code;
    }


    /**
     *  Método que define os produtos comprados por um cliente bem como a informação sobre as suas vendas.
     * @param pb que contém os produtos e a informação das vendas realizadas por um cliente.
     */
    public void setProductsBought(Map<String,InformacaoVendaProduto> pb){
        this.products_bought = new HashMap<>();
        for(Map.Entry<String,InformacaoVendaProduto> e : pb.entrySet())
            this.products_bought.put(e.getKey(),e.getValue());
    }

    /**
     *  Método que retorna os produtos comprados por um cliente, bem como a informação da sua compra.
     * @return aux que são os produtos comprados por um cliente bem como a informação acerca da sua compra.
     */
    public Map<String,InformacaoVendaProduto> getProducts_bought() {
        Map<String,InformacaoVendaProduto> aux = new HashMap<>();
        for(Map.Entry<String, InformacaoVendaProduto> e : this.products_bought.entrySet())
            aux.put(e.getKey(),e.getValue().clone());
        return aux;
    }

    /**
     *  Método que retorna um array com a faturação total em cada mês.
     * @return aux double[] que contém a faturação total por mês.
     */
    public double[] getFatTotalMes(){
        double[] aux = new double[MES];
        for(int i=0;i<MES;i++) aux[i] = this.fat_total_mes[i];
        return aux;
    }

    /**
     *  Método que retorna a faturação total de um cliente no ano.
     * @return aux double que é a faturação total.
     */
    public double getFatTotal() {
        double aux = 0;
        for (int i = 0; i < MES; i++) aux += this.fat_total_mes[i];
        return aux;
    }

    /**
     *  Método que retorna .
     * @return aux int[] que contém a quantidade de produtos comprada por mês.
     */
    public int[] getNVendas(){
        int[] aux = new int[MES];
        for(int i=0;i<MES;i++) aux[i] = this.nvendas_mes[i];
        return aux;
    }

    /**
     *  Método que retorna a faturação total de um cliente num mês específico.
     * @param mes int, mês.
     * @return double que é a faturação total.
     */
    public double getFat_Mes_Especifico(int mes) { return this.fat_total_mes[mes]; }

    /**
     *  Método que retorna a quantidade total de vendas realizadas por um cliente num mês específico.
     * @param mes int, mês.
     * @return int que é o número de vendas total.
     */
    public int getNVendas_Mes_Especifico(int mes){
        return this.nvendas_mes[mes];
    }

    /**
     *  Método que retorna a quantidade total de vendas realizadas por um cliente.
     * @return int que é o número de vendas total.
     */
    public int getNVendasTotal(){
        int aux=0;
        for(int i=0;i<MES;i++){
            aux += this.nvendas_mes[i];
        }
        return aux;
    }

    /**
     *  Método copia uma estrutura InfoCliente.
     * @return InfoCliente que é a cópia da estrutura.
     */
    public InfoCliente clone(){
        return (new InfoCliente(this));
    }

    /**
     *  Método que compara duas estruturas InfoCliente.
     * @param o object, objeto a comparar.
     * @return int que é o resultado da comparação.
     */
    @Override
    public int compareTo(Object o) {
        InfoCliente i = (InfoCliente) o;
        return this.code.compareTo(i.getCode());
    }
}
