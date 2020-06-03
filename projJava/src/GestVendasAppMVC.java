/**
 * @file GestVendasAppMVC.java
 *  Ficheiro que contém a API relativa à implementação do MVC da aplicação.
 */

import Controller.GestVendasController;
import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;
import Geral.Crono;
import Interfaces.GereVendasController;
import Interfaces.GereVendasModel;
import Interfaces.GereVendasView;
import Models.GestVendas;
import Readers.Input;
import Views.ErrorView;
import Views.MainMenuView;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class GestVendasAppMVC {

    /**
     *  Método que cria o modelo inicial do programa e o carrega com as informações default.
     * @throws FileNotFoundException exceção.
     * @return gvcm GereVendasModel que é o modelo carregado com as informações lidas.
     */
    private static GereVendasModel createData() throws FileNotFoundException {
        GereVendasModel gvm = new GestVendas();
        Crono.start();
        gvm.loadDefault();
        System.out.println(Crono.getTImeString());
        return gvm;
    }

    /**
     *  Método que cria o modelo inicial do programa e o carrega com as informações do Utilizador.
     * @param paths lista com os caminhos dos ficheiros a serem lidos
     * @return gvcm GereVendasModel que é o modelo carregado com as informações lidas.
     */
    private static GereVendasModel createData(List<String> paths){
        GereVendasModel gvm = new GestVendas();
        Crono.start();
        gvm.loadFiles(paths);
        System.out.println(Crono.getTImeString());
        return gvm;
    }

    /**
     *  Método principal que controla o programa.
     * @throws ClientNotFoundException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     * @param args String[] que são possíveis argumentos passados ao Método.
     */
    public static void main(String[] args) throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException {
        GereVendasController control = new GestVendasController();
        GereVendasView view;

        List<String> paths = control.loadFiles();
        GereVendasModel model = null;
        System.out.println("Loading ...");
        if(paths == null){
            model = createData();
        }
        else if(paths.size() == 1) {
            try {
                model = GestVendas.loadGestVendas(paths.get(0));
            }catch (IOException | ClassNotFoundException e){
                view = new ErrorView();
                view.show("Error while loading Object");
                System.exit(-1);
            }
        }
        else{
            model = createData(paths);
        }

        if (model == null) {
            view = new ErrorView();
            view.show("Error while loading model");
            System.exit(-1);
        }

        view = new MainMenuView();
        control.setModel(model);
        control.setView(view);
        control.start();
        System.exit(0);
    }
}
