/**
 * @file Q2StatsView.java
 *  Ficheiro que contém a API relativa à implementação da view da query 2 estatística.
 */

package Views;

import Interfaces.GereVendasView;
import Geral.DefVariaveis;
import Queries.Q2Stats;

import java.io.Serializable;
import java.util.Map;

public class Q2StatsView implements GereVendasView,DefVariaveis, Serializable {

    private Q2Stats q2Stats;

    /**
     *  Método que inicializa uma estrutura Q2StatsView por cópia.
     * @param q2Stats Q2Stats que vai ser copiada.
     */
    public Q2StatsView(Q2Stats q2Stats){
        this.q2Stats = q2Stats;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query2 Estatística.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        int i,m;
        double aux = 0;
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\nFATURAÇÃO GLOBAL -> " + this.q2Stats.getFat_total() + "\n");
        for(i=0;i<FILIAIS;i++){
            System.out.println("FILIAL #" + (i+1) );
            for(m=0;m<MES;m++) {
                System.out.println();
                System.out.println(MESES.get(m));
                System.out.println("FATURAÇÃO TOTAL -> " + this.q2Stats.getFaturadoFilialMes((i+1),m));
                System.out.println("NÚMERO DE CLIENTES QUE COMPRARAM -> " + this.q2Stats.getNClientesFilialMes((i+1),m));
            }
            System.out.println("TOTAL FATURADO NA FILIAL #" + (i+1) + " -> " + this.q2Stats.getFatFilial(i+1));
            System.out.println();
        }
        System.out.println("\n");
        for(m=0;m<MES;m++){
            System.out.println(MESES.get(m));
            System.out.println("TOTAL DE VENDAS -> " + this.q2Stats.getNVendasMes(m));
        }
    }
}
