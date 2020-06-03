/**
 * @file Query3View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 3.
 */

package Views;

import Interfaces.GereVendasView;
import Queries.Querie3;

import java.io.Serializable;
import java.util.ArrayList;

import static Geral.DefVariaveis.MES;
import static Geral.DefVariaveis.MESES;

public class Query3View implements GereVendasView, Serializable {
    private Querie3 q3;

    /**
     *  Método que inicializa uma estrutura Query3View.
     */
    public Query3View() {
        this.q3 = new Querie3();
    }

    /**
     *  Método que inicializa uma estrutura Query3View por cópia.
     * @param q3 Querie3 que vai ser copiada.
     */
    public Query3View(Querie3 q3) {
        this.q3 = q3;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query3.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof ArrayList) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            ArrayList<Object> lista = new ArrayList<>((ArrayList<Object>) o);
            String cliente = (String) lista.get(0);
            for (int mes = 1; mes < MES + 1; mes++) {
                System.out.println("Mês : " + MESES.get(mes - 1));
                System.out.println(" Nr Compras: " + this.q3.getNvendas(mes - 1)
                        + " Nr Produtos distintos: " + this.q3.getNprodutos(mes - 1)
                        + " Gasto Total: " + this.q3.getFat_mes(mes - 1));
            }
        }
    }
}
