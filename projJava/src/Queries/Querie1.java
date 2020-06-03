/**
 * @file Querie1.java
 *  Ficheiro que contém a API relativa à implementação da query 1.
 */

package Queries;

import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class Querie1 implements Querie, Serializable {

    private Set<String> products_not_bought;
    private int total;

    /**
     *  Método que inicializa uma estrutura Querie1.
     */
    public Querie1(){
        this.products_not_bought = new TreeSet<>();
        this.total = 0;
    }

    /**
     *  Método que inicializa uma estrutura Querie1 com passagem de parâmetros.
     * @param total int que é o total de produtos.
     * @param products_not_bought que contém os códigos de produto.
     */
    public Querie1(int total, Set<String> products_not_bought) {
        setProdutos(products_not_bought);
        this.total = total;
    }

    /**
     *  Método que devolve o total de produtos não comprados.
     * @return int que é o total de produtos.
     */
    public int getSizeQuerie1(){
        return this.products_not_bought.size();
    }

    /**
     *  Método que define os produtos não comprados.
     * @param p que contém os códigos dos produtos.
     */
    public void setProdutos(Set<String> p){
        this.products_not_bought = new TreeSet<>();
        p.forEach(v -> this.products_not_bought.add(v));
    }

    /**
     *  Método que devolve o conjunto dos produtos não comprados.
     * @return aux que contém os códigos dos produtos.
     */
    public Set<String> getProdutos(){
        Set<String> aux = new TreeSet<>();
        this.products_not_bought.forEach(v -> aux.add(v));
        return aux;
    }

    /**
     *  Método que devolve uma lista com os produtos não comprados.
     * @return aux que contém os códigos dos produtos.
     */
    public List<String> getProdutosList(){
        List<String> aux = new ArrayList<>();
        this.products_not_bought.forEach(v -> aux.add(v));
        return aux;
    }

    /**
     *  Método que define o total de produtos.
     * @param t int que é o total.
     */
    public void setTotal(int t){
        this.total = t;
    }

    /**
     *  Método que devolve o total de produtos.
     * @return int que é o total.
     */
    public int getTotal(){
        return this.total;
    }
}
