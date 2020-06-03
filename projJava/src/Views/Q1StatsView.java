/**
 * @file Q1StatsView.java
 *  Ficheiro que contém a API relativa à implementação da view da query 1 estatística.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Q1Stats;

import java.io.Serializable;

public class Q1StatsView implements GereVendasView, Serializable {

    private Q1Stats q1Stats;

    /**
     *  Método que inicializa uma estrutura Q1StatsView por cópia.
     * @param q1Stats Q1Stats que é a estrutura a copiar.
     */
    public Q1StatsView(Q1Stats q1Stats){
        this.q1Stats = q1Stats;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query1 Estatística.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("FICHEIRO LIDO -> " + this.q1Stats.getFicheiro());
        System.out.println("TOTAL DE LINHAS DE VENDA ERRADAS -> " + this.q1Stats.getNvendas_erradas());
        System.out.println("TOTAL DE PRODUTOS -> " + this.q1Stats.getTotal_produtos());
        System.out.println("TOTAL DE PRODUTOS COMPRADOS -> " + this.q1Stats.getTotal_produtos_diferentes());
        System.out.println("TOTAL DE PRODUTOS NÃO COMPRADOS -> " + this.q1Stats.getTotal_produtos_nao_comprados());
        System.out.println("TOTAL DE CLIENTES -> " + this.q1Stats.getTotal_clientes());
        System.out.println("TOTAL DE CLIENTES QUE COMPRARAM -> " + this.q1Stats.getTotal_clientes_compradores());
        System.out.println("TOTAL DE CLIENTES QUE NÃO COMPRARAM -> " + this.q1Stats.getTotal_clientes_nada_compraram());
        System.out.println("TOTAL COMPRAS COM FATURAÇÃO ZERO -> " + this.q1Stats.getVendas_a_zero());
        System.out.println("TOTAL FATURADO -> " + this.q1Stats.getFat_total());
    }
}
