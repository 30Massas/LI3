/**
 * @file Query6View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 6.
 */

package Views;

import Interfaces.GereVendasView;


import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;


public class Query6View implements GereVendasView, Serializable {

    private List<String> nProdutosMaisVendidos;
    private int[] nClientes;
    private int[] quantidadeComprada;

    /**
     *  Método que inicializa uma estrtura Query6View.
     */
    public Query6View() {
        this.nProdutosMaisVendidos = new ArrayList<>();
    }

    /**
     *  Método que inicializa uma estrutura Query6View com passagem de parâmetros.
     * @param nClientes int[] que contém o número de clientes.
     * @param quantidadeComprada int[] que contém a quantidade comprada.
     * @param nProdutosMaisVendidos que contém o códigos dos produtos.
     */
    public Query6View(int[] nClientes, int[] quantidadeComprada, List<String> nProdutosMaisVendidos) {
        this.nProdutosMaisVendidos = nProdutosMaisVendidos;
        this.nClientes = nClientes;
        this.quantidadeComprada = quantidadeComprada;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Enter to Exit");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query6.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        if (o instanceof Integer) {
            int n = (int) o;
            System.out.print("\033[H\033[2J");
            System.out.flush();
            for (int i = 0; i < n && i < this.nProdutosMaisVendidos.size(); i++) {
                System.out.println("prod = "
                        + this.nProdutosMaisVendidos.get(i)
                        + ", quantidade = "
                        + this.quantidadeComprada[i]
                        + ", nrClientes = "
                        + this.nClientes[i]);
            }
        }
    }
}
