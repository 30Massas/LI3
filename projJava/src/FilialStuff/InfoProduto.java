/**
 * @file InfoProduto.java
 *  Ficheiro que contém a API relativa à implementação da informação dos produtos.
 */

package FilialStuff;

import Geral.DefVariaveis;
import Geral.Registo;

import java.io.Serializable;
import java.util.Map;
import java.util.HashMap;



public class InfoProduto implements DefVariaveis, Serializable {

    private String code;
    private Map<String, InformacaoVendaCliente> clients_who_bought; /* 0 => Normal, 1 => Promoção, 2 => Normal + Promoção */
    private int[] qtd_total_comprada_mes;
    private int[] numero_vezes_comprada_mes;
    private double[] faturacao_total_mes;

    /**
     *  Método que inicializa uma estrutura InfoProduto.
     */
    public InfoProduto() {
        this.code = "";
        this.clients_who_bought = new HashMap<>();
        this.qtd_total_comprada_mes = new int[MES];
        this.numero_vezes_comprada_mes = new int[MES];
        this.faturacao_total_mes = new double[MES];
    }

    /**
     *  Método que inicializa uma estrutura InfoProduto.
     * @param code String que é o código do produto.
     * @param cb que são os clientes que compraram dado produto.
     * @param qtd_total_comprada_mes int[] que contém a quantidade total comprada de um produto em cada mês
     * @param numero_vezes_comprada_mes int[] que contém o número de vezes que um dado produto foi comprado em cada mês.
     * @param faturacao_total_mes double[] que contém a faturação em cada mês de um dado produto.
     */
    public InfoProduto(String code, Map<String, InformacaoVendaCliente> cb, int[] qtd_total_comprada_mes, int[] numero_vezes_comprada_mes, double[] faturacao_total_mes) {
        this.code = code;
        setClientsBought(cb);
        this.qtd_total_comprada_mes = qtd_total_comprada_mes;
        this.numero_vezes_comprada_mes = numero_vezes_comprada_mes;
        this.faturacao_total_mes = faturacao_total_mes;
    }

    /**
     *  Método que inicializa uma estrutura InfoProduto.
     * @param info InfoProduto que é a estrutura a copiar.
     */
    public InfoProduto(InfoProduto info) {
        this.code = info.getCode();
        this.clients_who_bought = info.getClientsBought();
        this.qtd_total_comprada_mes = info.getQtdTotalCompradaMes();
        this.numero_vezes_comprada_mes = info.getNumeroVezesCompradaMes();
        this.faturacao_total_mes = info.getFaturacaoTotalMes();
    }

    /**
     *  Método que devolve o código de produto.
     * @return String que é o código de produto.
     */
    public String getCode() {
        return this.code;
    }

    /**
     *  Método que define o código de produto.
     * @param code String que é o código do produto.
     */
    public void setCode(String code) {
        this.code = code;
    }

    /**
     *  Método que devolve os clientes que compraram dado produto, bem como a informação relativa as suas vendas.
     * @return aux que contém os clientes que compraram um dado produto e a informação das suas vendas.
     */
    public Map<String, InformacaoVendaCliente> getClientsBought() {
        Map<String, InformacaoVendaCliente> aux = new HashMap<>();
        for (Map.Entry<String, InformacaoVendaCliente> e : this.clients_who_bought.entrySet()) {
            aux.put(e.getKey(), e.getValue().clone());
        }
        return aux;
    }

    /**
     *  Método que define os clientes que compraram dado produto, bem como a informação relativa as suas vendas.
     * @param cb que contém os clientes que compraram um dado produto e a informação das suas vendas.
     */
    public void setClientsBought(Map<String, InformacaoVendaCliente> cb) {
        this.clients_who_bought = new HashMap<>();
        for (Map.Entry<String, InformacaoVendaCliente> e : cb.entrySet()) {
            this.clients_who_bought.put(e.getKey(), e.getValue());
        }
    }

    /**
     *  Método que devolve a quantidade total comprada por mês de um dado produto.
     * @return aux int[] que contém a quantidade total comprada de um dado produto em cada mês.
     */
    public int[] getQtdTotalCompradaMes() {
        int[] aux = new int[MES];
        for (int i = 0; i < MES; i++) {
            aux[i] = this.qtd_total_comprada_mes[i];
        }
        return aux;
    }

    /**
     *  Método que define a quantidade total comprada por mês de um dado produto.
     * @param qtd int[] que contém a quantidade total comprada de um dado produto em cada mês.
     */
    public void setQtdTotalCompradaMes(int[] qtd) {
        for (int i = 0; i < MES; i++) {
            this.qtd_total_comprada_mes[i] = qtd[i];
        }
    }

    /**
     *  Método que devolve o número de vezes comprada por mês de um dado produto.
     * @return aux int[] que contém o número de vezes comprado de um dado produto em cada mês.
     */
    public int[] getNumeroVezesCompradaMes() {
        int[] aux = new int[MES];
        for (int i = 0; i < MES; i++) {
            aux[i] = this.numero_vezes_comprada_mes[i];
        }
        return aux;
    }

    /**
     *  Método que define o número de vezes comprada por mês de um dado produto.
     * @param numeroVezesComprada int[] que contém o número de vezes comprado de um dado produto em cada mês.
     */
    public void setNumeroVezesCompradaMes(int[] numeroVezesComprada) {
        for (int i = 0; i < MES; i++) {
            this.numero_vezes_comprada_mes[i] = numeroVezesComprada[i];
        }
    }

    /**
     *  Método que devolve o faturado por mês de um dado produto.
     * @return aux double[] que contém o faturado de um dado produto em cada mês.
     */
    public double[] getFaturacaoTotalMes() {
        double[] aux = new double[MES];
        for (int i = 0; i < MES; i++) {
            aux[i] = this.faturacao_total_mes[i];
        }
        return aux;
    }

    /**
     *  Método que define o faturado por mês de um dado produto.
     * @param faturacao double[] que contém o faturado de um dado produto em cada mês.
     */
    public void setFaturacaoTotalMes(double[] faturacao) {
        for (int i = 0; i < MES; i++) {
            this.faturacao_total_mes[i] = faturacao[i];
        }
    }

    /**
     *  Método que devolve uma cópia da estrtura InfoProduto.
     * @return InfoProduto que é a cópia da estrutura.
     */
    public InfoProduto clone() {
        return new InfoProduto(this);
    }


    /**
     *  Método que atualiza as informações sobre um produto que já tenha sido inicializado.
     * @param cliente String que é o cliente que comprou o produto.
     * @param r Registo que contém a informação sobre a venda.
     */
    public void addRegistoExistente(String cliente, Registo r) {
        int i = 0;
        if (r.getModo() == 'P') i = 1;
        this.clients_who_bought.putIfAbsent(cliente, new InformacaoVendaCliente());
        if ((i == 0 && clients_who_bought.get(cliente).getModoCompra() == 1) || i == 1 && clients_who_bought.get(cliente).getModoCompra() == 0)
            i = 2;
        this.clients_who_bought.get(cliente).addInfo(cliente, r.getQuantidade() * r.getPreco(),r.getMes() - 1, i,r.getQuantidade());
        this.numero_vezes_comprada_mes[r.getMes() - 1]++;
        this.qtd_total_comprada_mes[r.getMes() - 1] += r.getQuantidade();
        this.faturacao_total_mes[r.getMes() - 1] += r.getQuantidade() * r.getPreco();
    }


    /**
     *  Método que inicializa as informações sobre um produto.
     * @param cliente String que é o cliente que comprou o produto.
     * @param r Registo que contém a informação sobre a venda.
     */
    public void addRegistoNovo(String cliente, Registo r) {
        this.code = r.getCodProd();
        int i = 0;
        if (r.getModo() == 'P') i = 1;
        InformacaoVendaCliente e = new InformacaoVendaCliente(cliente,r.getMes() - 1, i, (r.getQuantidade()*r.getPreco()),r.getQuantidade());
        this.clients_who_bought.put(cliente, e);
        this.numero_vezes_comprada_mes[r.getMes() - 1]++;
        this.qtd_total_comprada_mes[r.getMes() - 1] += r.getQuantidade();
        this.faturacao_total_mes[r.getMes() - 1] += r.getQuantidade() * r.getPreco();
    }


}
