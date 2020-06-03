/**
 * @file Query4View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 4.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Querie4;

import java.io.Serializable;
import java.util.ArrayList;

import static Geral.DefVariaveis.MES;
import static Geral.DefVariaveis.MESES;

public class Query4View implements GereVendasView, Serializable {

    private Querie4 q4;

    /**
     *  Método que inicializa uma estrutura Qery4View.
     */
    public Query4View() {
        this.q4 = new Querie4();
    }

    /**
     *  Método que inicializa uma estrutura Query4View por cópia.
     * @param q4 Querie4 que vai ser copiada.
     */
    public Query4View(Querie4 q4) {
        this.q4 = q4;
    }

    /**
     *  Método que define a estrutura Querie4 com a informaçaão a apresentar.
     * @param q4 Querie4 que vai ser copiada.
     */
    public void setQ4(Querie4 q4) {
        this.q4 = q4;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query4.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof ArrayList) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            ArrayList<Object> lista = new ArrayList<>((ArrayList<Object>) o);
            String produto = (String) lista.get(0);
            for (int mes = 1; mes < MES + 1; mes++) {
                System.out.println("Mês : " + MESES.get(mes - 1));
                System.out.println("Número de vezes comprado : " + this.q4.getNVezesCompradaMes(mes-1)
                        + " Número de clientes distintos : " + this.q4.getNClientesMes(mes-1)
                        + " Total Faturado : " + this.q4.getFatPMes(mes-1));
            }
        }
    }

}
