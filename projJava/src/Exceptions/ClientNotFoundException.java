/**
 * @file ClientNotFoundException.java
 * Ficheiro que contém a API relativa à implementação da exceção ClientNotFound.
 */

package Exceptions;

import java.io.Serializable;

public class ClientNotFoundException extends Exception implements Serializable {

    /**
     * Método que retorna uma excepção quando um dado código de cliente não existe.
     */
    public ClientNotFoundException() {
        super();
    }

    /**
     * Método que retorna uma mensagem de excepção quando um dado código de cliente não existe.
     * @param m String que é a mensagem.
     */
    public ClientNotFoundException(String m) {
        super(m);
    }
}
