/**
 * @file Query10View.java
 *  Ficheiro que contém a API relativa à implementação da view da query 10.
 */

package Views;

import Interfaces.GereVendasView;
import Interfaces.Observer;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static Geral.DefVariaveis.MESES;

public class Query10View implements GereVendasView, Serializable {

    private int index; // pagina
    private int pageTotal; // Total de páginas
    private int infoPPag; // Total de informação p/ página
    private int mes;
    private int filial;
    private Observer observer;

    private Map<Integer, Map<String, Map<Integer, Double>>> info;
    private List<String> lista;
    private ListView view;

    /**
     *  Método que inicializa uma estrutura Query10View.
     */
    public Query10View() {
        this.info = new HashMap<>();
        this.view = new ListView();
        this.lista = new ArrayList<>();
        this.index = 0;
    }

    /**
     *  Método que inicializa uma estrutura Query10View com passagem de parâmetros.
     * @param info que contém a informação a apresentar.
     * @param infoPPag int que é a página a visualizar.
     * @param obs Observer que é uma ferramenta auxiliar para a visualização.
     */
    public Query10View(Map<Integer, Map<String, Map<Integer, Double>>> info, int infoPPag, Observer obs) {
        this.info = info;
        this.infoPPag = infoPPag;
        this.index = 0;
        this.observer = obs;
        this.lista = new ArrayList<>();
    }

    /**
     *  Método que define a informação a apresentar.
     * @param info que contém a informação.
     */
    public void setInfo(Map<Integer, Map<String, Map<Integer, Double>>> info) {
        this.info = info;
    }

    /**
     *  Método que apresenta ao utilizador uma mensagem pré-definida.
     */
    @Override
    public void show() {
        System.out.println("Filial:=>   1 = <- | 3 = ->");
        System.out.println("Mês   :=>   Q = <- | E = ->");
        System.out.println("Insert letter: ");
    }

    /**
     *  Método que apresenta ao utilizador os resultados da Query10.
     * @param o Object que é um argumento.
     */
    @Override
    public void show(Object o) {
        List<Integer> aux;
        if (o instanceof Integer) { // muda d página
            System.out.print("\033[H\033[2J");
            System.out.flush();
            if (this.observer.isChanged()) {
                aux = this.observer.pull();
                this.filial = aux.get(0);
                this.mes = aux.get(1);
                this.lista = new ArrayList<>();
                for (Map.Entry<String, Map<Integer, Double>> entry : this.info.get(filial).entrySet())
                    if (entry.getValue().containsKey(mes))
                        this.lista.add(String.format("%s -> %-15.4f", entry.getKey(), entry.getValue().get(mes)));

                this.index = 0;
                this.pageTotal = (lista.size() % 90 == 0) ? lista.size() / 90 : lista.size() / 90 + 1;
                this.observer.update(2, this.pageTotal);
                this.view = new ListView(0, 90, this.lista);
            }

            System.out.println("FILIAL : " + this.filial + " | Mês : " + MESES.get(this.mes-1));
            this.view.show(o);
        }
        else if(o instanceof String){
            System.out.print((String) o);
        }


    }
}



