/**
 * @file Query7View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 7.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Querie7;


import java.io.Serializable;

import static Geral.DefVariaveis.FILIAIS;

public class Query7View implements GereVendasView, Serializable {
    private Querie7 q7;

    /**
     *  Método que inicializa uma estrtura Query7View.
     */
    public Query7View() {
        this.q7 = new Querie7();
    }

    /**
     *  Método que inicializa uma estrutura Query7View por cópia.
     * @param q7 Querie7 que vai ser copiada.
     */
    public Query7View(Querie7 q7) {
        this.q7 = q7;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query7.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        for (int i = 1; i < FILIAIS + 1; i++) {
            System.out.println("3 maiores Compradores p/ Lucro na filial : " + i);
            for (String s : this.q7.top3Buyers(i)) {
                System.out.println(s + " = " + q7.getGastoIndex(s, i));
            }
        }
    }
}
