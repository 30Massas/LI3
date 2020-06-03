/**
 * @file Query5View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 5.
 */

package Views;

import FilialStuff.InformacaoVendaProduto;
import Interfaces.GereVendasView;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;


public class Query5View implements GereVendasView, Serializable {
    private List<InformacaoVendaProduto> info;


    /**
     *  Método que inicializa uma estrutura Query5View.
     */
    public Query5View() {
        this.info = new ArrayList<>();
    }

    /**
     *  Método que inicializa uma estrtura Query5View com passagem de parâmetros.
     * @param info que contém a informação a apresentar.
     */
    public Query5View(List<InformacaoVendaProduto> info) {
        this.info = info;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query5.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof ArrayList) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            ArrayList<Object> lista = new ArrayList<>((ArrayList<Object>) o);
            String cliente = (String) lista.get(0);
            for (InformacaoVendaProduto i : this.info) {
                System.out.printf("Quantidade = %-3d,código = %s\n",i.getQtd(),i.getCode());
            }
        }
    }
}

