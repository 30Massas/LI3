/**
 * @file ObserverQ10.java
 *  Ficheiro que contém a API relativa à implementação do observer da Query10.
 */

package Observers;

import Interfaces.Observer;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class ObserverQ10 implements Observer, Serializable {
    private List<Integer> list;
    private boolean changed;

    /**
     *  Método que inicializa uma estrutra ObserverQ10.
     */
    public ObserverQ10() {
        this.list = new ArrayList<>();
    }

    /**
     *  Método que inicializa uma estrutura ObserverQ10 com passagem de parâmetros.
     * @param filial int que é a filial a adicionar.
     * @param mes int que é o mês a adicionar.
     */
    public ObserverQ10(int filial, int mes){
        this.list = new ArrayList<>();
        this.list.add(filial);
        this.list.add(mes);
        this.changed = true;
    }

    /**
     *  Método que atualiza a lista com os valores dados pelo utilizador
     * @param fil int que é a filial a procurar.
     * @param mes int que é o mês a procurar.
     * @param pag int que é a página a procurar.
     */
    public void update(int fil, int mes, int pag){
        this.list.add(0,fil);
        this.list.add(0,mes);
        this.list.add(0,pag);
        this.changed = true;
    }

    /**
     *  Método que atualiza os valores apresentados.
     * @param index que é a posição a atualizar.
     * @param value que é o valor a usar.
     */
    public void update(int index, int value){
        this.list.add(index,value);
        this.changed = true;
    }

    /**
     *  Método que atualiza se foi modificado ou não.
     * @param t boolean que define se foi atualizado ou não.
     */
    public void update(boolean t){
        this.changed = t;
    }

    /**
     *  Método que verifica se foi modificado.
     * @return boolean
     */
    public boolean isChanged(){
        return this.changed;
    }

    public List<Integer> pull() {
        return this.list.stream().collect(Collectors.toCollection(ArrayList::new));
    }

    public void addComponent(int index, int value) {
        this.list.add(index, value);
    }

    public void addComponent(int value) {
        this.list.add(value);
    }
}
