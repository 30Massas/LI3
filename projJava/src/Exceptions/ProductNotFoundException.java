/**
 * @file ProductNotFoundException.java
 * Ficheiro que contém a API relativa à implementação da exceção ProductNotFound.
 */

package Exceptions;

import java.io.Serializable;

public class ProductNotFoundException extends Exception implements Serializable {

    /**
     * Método que retorna uma excepção quando um dado código de produto não existe.
     */
    public ProductNotFoundException() {
        super();
    }

    /**
     * Método que retorna uma mensagem de excepção quando um dado código de produto não existe.
     * @param m String que é a mensagem.
     */
    public ProductNotFoundException(String m) {
        super(m);
    }
}
