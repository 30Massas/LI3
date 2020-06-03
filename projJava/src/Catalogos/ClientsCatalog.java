/**
 * @file ClientsCatalog.java
 * Ficheiro que contém a API relativa à implementação do catálogo de clientes.
 */

package Catalogos;

import java.io.Serializable;
import java.util.*;

public class ClientsCatalog implements CliAndProdCatalogs, Serializable {
    private Map<Integer, Set<String>> clients;

    public ClientsCatalog() {
        this.clients = new HashMap<>();
    }

    /**
     * Método que dado um código de um cliente o adiciona ao catálogo de clientes.
     * @param code String com o código do cliente.
     */
    public void addCode(String code) {
        int index = code.charAt(0) - 'A';
        this.clients.putIfAbsent(index, new TreeSet<>());
        this.clients.get(index).add(code);
    }

    /**
     * Método que verifica se um dado cliente existe no catálogo de clientes.
     * @param code String com o código do cliente.
     * @return boolean com o resultado.
     */
    public boolean checkCode(String code) {
        int index = code.charAt(0) - 'A';
        return this.clients.get(index).contains(code);
    }
}
