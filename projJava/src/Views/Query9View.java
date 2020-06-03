/**
 * @file Query9View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 9.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Querie9;

import java.io.Serializable;


public class Query9View implements GereVendasView, Serializable {
    private Querie9 q9;

    /**
     *  Método que inicializa uma estrutura Query7View por cópia.
     * @param q9 Querie9 que vai ser copiada.
     */
    public Query9View(Querie9 q9) {
        this.q9 = q9;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query9.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        int i = 0;
        System.out.print("\033[H\033[2J");
        System.out.flush();
        for(String s : this.q9.getCliCodes()){
            System.out.printf("%s | quantos comprou : %-3d | lucro = %f\n",s,this.q9.getQtdIndex(i),this.q9.getGastoIndex(i++));
        }
    }
}
