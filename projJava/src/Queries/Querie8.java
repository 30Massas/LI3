/**
 * @file Querie8.java
 *  Ficheiro que contém a API relativa à implementação da query 8.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;


public class Querie8 implements Querie, Serializable {
    private int []nprodutos;
    private List<String> clientes;

    /**
     *  Método que inicializa uma estrutura Querie8.
     * @param n int que é o número pedido pelo utilizador.
     */
    public Querie8(int n){
        this.nprodutos = new int[n];
        this.clientes = new ArrayList<>();
    }

    /**
     *  Método que adiciona um cliente numa posição da lista e na mesma posição num array adicioona a quantidade de produtos que comprou.
     * @param nprodutos int que é a quantidade.
     * @param cliente String que é o código do cliente.
     * @param i int que é a posição.
     */
    public void addProduto(int nprodutos ,String cliente, int i){
        this.clientes.add(i,cliente);
        this.nprodutos[i] += nprodutos;
    }

    /**
     *  Método que devolve um array contendo o número de produtos que cada cliente comprou.
     * @return nprodutos int[] que contém o número de produtos.
     */
    public int[] getnProdutos() {
        return nprodutos;
    }

    /**
     *  Método que devolve o número de produtos de um dado cliente.
     * @param index int que é a posição do cliente.
     * @return int que é o número de produtos.
     */
    public int getnProdutosIndex(int index){
        return this.nprodutos[index];
    }

    /**
     *  Método que devolve uma lista com o código de clientes.
     * @return aux que contém os códigos de cliente.
     */
    public List<String> getCliCodes(){
        List<String> aux = new ArrayList<>();
        for(String s : this.clientes){
            aux.add(s);
        }
        return aux;
    }
}
