/**
 * @file Querie6.java
 *  Ficheiro que contém a API relativa à implementação da query 6.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

public class Querie6 implements Querie, Serializable {
    private int[] nClientes; // filiais
    private int[] quantidadeComprada;
    private Map<Integer, List<String>> produtos; // faturacao

    /**
     *  Método que inicializa uma estrutura Querie6.
     * @param n int que é o número pedido pelo utilizador.
     */
    public Querie6(int n) {
        this.nClientes = new int[n];
        this.quantidadeComprada = new int[n];
        this.produtos = new TreeMap<>(Collections.reverseOrder());
    }

    /**
     *  Método que devolve o número de clientes que compraram cada produto.
     * @param n int que é o número pedido pelo utilizador.
     * @return aux int[] que contém o número de clientes que compraram cada produto.
     */
    public int[] getnClientes(int n) {
        int[] aux = new int[n];
        for (int i = 0; i < n; i++)
            aux[i] = this.nClientes[i];
        return aux;
    }

    /**
     *  Método que devolve a quantidade comprada de cada produto.
     * @param n int que é o número pedido pelo utilizador.
     * @return aux int[] que contém a quantidade comprada de cada produto.
     */
    public int[] getQuantidadeComprada(int n) {
        int[] aux = new int[n];
        for (int i = 0; i < n; i++)
            aux[i] = this.quantidadeComprada[i];
        return aux;
    }

    /**
     *  Método que devolve a quantidade comprada de um dado produto.
     * @param index int que é a posição referente ao produto.
     * @return int que é a quantidade.1
     */
    public int getQtdComprada(int index) {
        return this.quantidadeComprada[index];
    }

    /**
     *  Método que devolve o número de clientes que compraram um dado produto.
     * @param index int que é a posição referente ao produto.
     * @return int que é o número de clientes.
     */
    public int getnClientesIndex(int index) {
        return this.nClientes[index];
    }

    /**
     *  Método que atualiza o número de clientes que compraram um dado produto.
     * @param index int que é a posição do produto.
     * @param numero int que é o número de clientes.
     */
    public void addNClientes(int index, int numero) {
        this.nClientes[index] += numero;
    }

    /**
     *  Método que adiciona um produto e a quantidade comprada.
     * @param qtdProd int que é a quantidade comprada.
     * @param produto String que é o código do produto.
     */
    public void addProduto(int qtdProd, String produto) {
        this.produtos.putIfAbsent(qtdProd, new ArrayList<>());
        this.produtos.get(qtdProd).add(produto);
    }

    /**
     *  Método que devolve uma lista com os N produtos pedidos pelo utilizador.
     * @param n int que é o número de produtos pedidos pelo utilizador
     * @return List que contém os códigos de produto.
     */
    public List<String> getNProdutosMaisVendidos(int n) {
        int i = 0;
        List<String> res = new ArrayList<>();
        for (Map.Entry<Integer, List<String>> l : this.produtos.entrySet()) {
            for (String s : l.getValue()) {
                if (i < n && i < this.produtos.size())
                    this.quantidadeComprada[i++] = l.getKey();
                res.add(s);
            }
        }
        return res.stream().limit(n).collect(Collectors.toList());    // cria uma sublista de (0 -> n)
    }

}

