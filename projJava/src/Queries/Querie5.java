/**
 * @file Querie5.java
 *  Ficheiro que contém a API relativa à implementação da query 5.
 */

package Queries;

import FilialStuff.InformacaoVendaProduto;
import Interfaces.Querie;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Querie5 implements Querie, Serializable {

    private Set<InformacaoVendaProduto> prods_and_qtd;

    /**
     *  Método que inicializa uma estrutura Querie5.
     */
    public Querie5() {
        this.prods_and_qtd = new TreeSet<>();
    }

    /**
     *  Método que retorna uma lista de InformacaoVendaProduto
     * @return List que é a lista.
     */
    public List<InformacaoVendaProduto> getProds_and_qtdList(){
        return this.prods_and_qtd.stream().map(InformacaoVendaProduto::clone).collect(Collectors.toCollection(ArrayList::new));
    }

    /**
     *  Método que inicializa uma estrutura Querie5 com passagem de parâmetros
     * @param p Set que contém a informação.
     */
    public Querie5(Set<InformacaoVendaProduto> p) {
        setProdsAndQtd(p);
    }

    /**
     *  Método que inicializa uma estrutura Querie5 por cópia.
     * @param q Querie5 que vai ser copiada.
     */
    public Querie5(Querie5 q) {
        this.prods_and_qtd = q.getProdsAndQtd();
    }

    /**
     *  Método que adiciona à lista uma InformaçãoVendaProduto.
     * @param i InformacaoVendaProduto.
     */
    public void addInformacaoVendaProduto(InformacaoVendaProduto i) {
        this.prods_and_qtd.add(i);
    }

    /**
     *  Método que devolve o conjunto de InformacaoVendaProduto.
     * @return aux que é o conjunto.
     */
    public Set<InformacaoVendaProduto> getProdsAndQtd() {
        Set<InformacaoVendaProduto> aux = new TreeSet<>();
        for (InformacaoVendaProduto i : this.prods_and_qtd)
            aux.add(i.clone());
        return aux;
    }

    /**
     *  Método que define o conjunto de InformacaoVendaProduto.
     * @param p que é o conjunto.
     */
    public void setProdsAndQtd(Set<InformacaoVendaProduto> p) {
        this.prods_and_qtd = new TreeSet<>();
        p.stream().map(InformacaoVendaProduto::clone).forEach(v -> this.prods_and_qtd.add(v));
    }
}
