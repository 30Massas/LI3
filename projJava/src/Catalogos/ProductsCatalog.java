/**
 * @file ClientsCatalog.java
 * Ficheiro que contém a API relativa à implementação do catálogo de produtos.
 */

package Catalogos;

import java.io.Serializable;
import java.util.*;

public class ProductsCatalog implements CliAndProdCatalogs, Serializable {
    private Map<Integer, Set<String>> products;

    public ProductsCatalog() {
        this.products = new HashMap<>();
    }

    /**
     * @param code String com o código do produto.
     * Método que dado um código de um produto o adiciona ao catálogo de produtos.
     */
    public void addCode(String code) {
        int index = code.charAt(0) - 'A';
        this.products.putIfAbsent(index, new TreeSet<>());
        this.products.get(index).add(code);
    }

    /**
     * Método que verifica se um dado produto existe no catálogo de produtos.
     * @param code String com o código do produto.
     * @return boolean com o resultado.
     */
    public boolean checkCode(String code) {
        int index = code.charAt(0) - 'A';
        return this.products.get(index).contains(code);
    }

    /**
     * Método que percorre o catálogo de produtos e os adiciona os seus códigos a um Set.
     * @return Set com os códigos dos produtos.
     */
    public Set<String> getProducts() {
        Set<String> novo = new TreeSet<>();
        for (Integer i : products.keySet()) {
            for (Set<String> s : products.values()) {
                s.forEach(st -> novo.add(st));
            }
        }
        return novo;
    }

}
