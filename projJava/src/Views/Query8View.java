/**
 * @file Query8View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 8.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Querie8;

import java.io.Serializable;

public class Query8View implements GereVendasView, Serializable {
    private Querie8 q8;

    /**
     *  Método que inicializa uma estrutura Query7View por cópia.
     * @param q8 Querie8 que vai ser copiada.
     */
    public Query8View(Querie8 q8) {
        this.q8 = q8;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query8.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof Integer) {
            int i = 0;
            System.out.print("\033[H\033[2J");
            System.out.flush();
            for(String s : this.q8.getCliCodes()){
                System.out.println(s + " = " + this.q8.getnProdutosIndex(i++));
            }
        }
    }
}
