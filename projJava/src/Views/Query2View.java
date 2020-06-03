/**
 * @file Query2View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 2.
 */

package Views;

import Interfaces.GereVendasView;

import java.io.Serializable;
import java.util.ArrayList;

import static Geral.DefVariaveis.MESES;

public class Query2View implements GereVendasView, Serializable {

    private int nClientes;
    private int nVendas;

    /**
     *  Método que inicializa uma estrutura Query2View com passagem de parâmetros.
     * @param nClientes numero de clientes.
     * @param nVendas numero de vendas.
     */
    public Query2View(int nClientes, int nVendas) {
        this.nClientes = nClientes;
        this.nVendas = nVendas;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query2.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof ArrayList) {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            ArrayList<Object> lista = new ArrayList<>((ArrayList<Object>) o);
            String filial = ((Integer) lista.get(0) == 0) ? "Global" : ((Integer) lista.get(0)).toString();
            int mes = (Integer) lista.get(1);
            System.out.println("Filial : " + filial + " | Mês : " + MESES.get(mes - 1));
            System.out.printf("%s %d\n", "Número Total de Vendas : ", this.nVendas);
            System.out.printf("%s %d\n", "Número de Clientes Distintos: ", this.nClientes);
        }
    }


}
