/**
 * @file GestVendasController.java
 * Ficheiro que contém a API relativa à implementação do controlador.
 */

package Controller;


import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;
import Geral.Crono;
import Interfaces.*;
import Models.GestVendas;
import Observers.ObserverQ10;
import Queries.*;
import Readers.Input;
import Views.*;

import java.io.IOException;
import java.io.Serializable;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import static Geral.DefVariaveis.*;


public class GestVendasController implements GereVendasController, Serializable {
    private GereVendasModel model;
    private GereVendasView view;

    /**
     * Método que define o modelo a utilizar.
     * @param m GereVendasModel que é quem tem acesso à informação e funções necessárias para efetuar os pedidos do utilizador.
     */
    @Override
    public void setModel(GereVendasModel m) {
        this.model = m;
    }

    /**
     * Método que define a view a utilizar.
     * @param v GereVendasView que é quem tem apresenta a informação ao utilizador.
     */
    @Override
    public void setView(GereVendasView v) {
        this.view = v;
    }

    /**
     * Método que comunica com o utilizador e obtém os ficheiros desejados.
     * @return Lista com os paths dos ficheiros.
     */
    @Override
    public List<String> loadFiles() {
        boolean flag = false;
        List<String> paths = new ArrayList<>();
        int opcao;
        do {
            this.view = new LoadFilesView();
            this.view.show("\033[H\033[2J");
            System.out.flush();
            this.view.show();
            opcao = Input.lerInt();
            if (opcao != 1 && opcao != 2 && opcao != 3) {
                this.view = new ErrorView();
                this.view.show("Opção inválida");
            }
        } while (opcao != 1 && opcao != 2 && opcao != 3);
        if (opcao == 1) {
            return null;
        }
        else if(opcao == 2) {
            String clientes, produtos, vendas;
            this.view.show(2);
            do {
                this.view.show("Clientes: ");
                clientes = Input.lerString();
                if (clientes.isEmpty()) {
                    clientes = clientFileDefault;
                    paths.add(clientes);
                    flag = true;
                } else if (Files.exists(Paths.get(clientes))) {
                    paths.add(clientes);
                    flag = true;
                } else {
                    this.view.show("Ficheiro de Clientes inválido\n");
                }
            } while (!flag);
            flag = false;
            do {
                this.view.show("Produtos: ");
                produtos = Input.lerString();
                if (produtos.isEmpty()) {
                    produtos = productFileDefault;
                    paths.add(produtos);
                    flag = true;
                } else if (Files.exists(Paths.get(produtos))) {
                    paths.add(produtos);
                    flag = true;
                } else {
                    this.view.show("Ficheiro de Produtos inválido\n");
                }
            } while (!flag);
            flag = false;
            do {
                this.view.show("Vendas: ");
                vendas = Input.lerString();
                if (vendas.isEmpty()) {
                    vendas = salesFileDefault;
                    paths.add(vendas);
                    flag = true;
                } else if (Files.exists(Paths.get(vendas))) {
                    paths.add(vendas);
                    flag = true;
                } else {
                    this.view.show("Ficheiro de Vendas inválido\n");
                }
            } while (!flag);
        }
        else {
            do {
                view.show("Insira o nome do ficheiro objeto: ");
                String filename = Input.lerString();
                if(filename.isEmpty()) {
                    return null;
                }
                else if(Files.exists(Paths.get(filename))){
                    paths.add(filename);
                    flag = true;
                }
                else{
                    this.view.show("Ficheiro Objeto inválido\n");
                }
            }while(!flag);
        }
        return paths;
    }


    /**
     * Método que interpreta a opção do utilizador e reencaminha para o pretendido.
     * @throws ClientNotFoundException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    @Override
    public void start() throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException {
        String opcao = "";
        do {
            view.show();
            opcao = Input.lerString();
            opcao = opcao.toUpperCase();
            switch (opcao) {
                case "A":
                    statisticsQuery1();
                    break;
                case "B":
                    statisticsQuery2();
                    break;
                case "1":
                    listProductsNeverBought();
                    break;
                case "2":
                    numeroClientesVendasMesGlobalFilial();
                    break;
                case "3":
                    infoClientePMes();
                    break;
                case "4":
                    infoProdutoPMes();
                    break;
                case "5":
                    produtosMaisCompradosPCliente();
                    break;
                case "6":
                    xProdutosMaisVendidos();
                    break;
                case "7":
                    top3Buyers();
                    break;
                case "8":
                    xClientesMaisCompradores();
                    break;
                case "9":
                    xClientesQMaisCompraramProdutoY();
                    break;
                case "10":
                    fatTotalMesFilial();
                    break;
                case "G":
                    guardarGestVendas();
                    break;
                case "L":
                    loadGestVendas();
                case "S":
                    break;


            }
        } while (!opcao.equals("S"));
    }

    /**
     * Método que obtém os valores da Query1 Estatística e apresenta ao utilizador
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void statisticsQuery1() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        Crono.start();
        Q1Stats q1Stats = (Q1Stats) model.interpreta(11, new ArrayList<>());
        System.out.println(Crono.getTImeString());
        this.view = new Q1StatsView(q1Stats);
        view.show(0);
        view.show();
        Input.lerString();
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query2 Estatística e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void statisticsQuery2() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        Crono.start();
        Q2Stats q2Stats = (Q2Stats) model.interpreta(12, new ArrayList<>());
        System.out.println(Crono.getTImeString());
        this.view = new Q2StatsView(q2Stats);
        view.show(0);
        view.show();
        Input.lerString();
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query1 e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void listProductsNeverBought() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        int index = 0;
        String opcao = "";
        Crono.start();
        Querie1 q1 = (Querie1) model.interpreta(1, new ArrayList<>());
        System.out.println(Crono.getTImeString());
        view = new ListView(0, 30, q1.getProdutosList());
        int maxPag = q1.getSizeQuerie1();
        maxPag = (maxPag % 30 == 0) ? maxPag / 30 : maxPag / 30 + 1;
        do {
            view.show("\033[H\033[2J");
            System.out.flush();
            view.show(index);
            view.show();
            opcao = Input.lerString();
            opcao = opcao.toUpperCase();
            String[] args = opcao.split(" ");
            try {
                switch (args[0]) {
                    case "A":
                        if (index > 0)
                            index--;
                        break;
                    case "D":
                        if (index < maxPag - 1)
                            index++;
                        break;
                    case "J":
                        try {
                            int j = Integer.parseInt(args[1]);
                            if (j > 0 && j <= maxPag)
                                index = j - 1;
                            else
                                view.show("Página inválida\n");
                        } catch (NumberFormatException | NullPointerException e) {
                            view.show("Insira um número válido\n");
                        }
                        break;
                    default:
                        break;
                }
            } catch (StringIndexOutOfBoundsException e) {
                System.out.println(e.getMessage() + "\nthats a no no");
            }
        } while (!opcao.equals("S"));
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query2 e a apresenta ao utilizador.
     * @throws ClientNotFoundException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void numeroClientesVendasMesGlobalFilial() throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException {
        int mes = 0;
        int filial = 0;
        boolean verify = false;
        do {
            try {
                do {
                    view.show("Mês: ");
                    mes = Input.lerInt();
                    if (mes > 0 && mes < MES + 1) verify = true;
                    else view.show("Mês inválido | 0 < MES <= 12\n");

                } while (!verify);
                verify = false;

                do {
                    view.show("Filial: ");
                    filial = Input.lerInt();
                    if (filial >= 0 && filial < FILIAIS + 1) verify = true;
                    else view.show("Filial inválida | 0 <= FILIAL <= 3\n");

                } while (!verify);

            } catch (NumberFormatException | NullPointerException e) {
                view.show("Insira num número válido\n");
            }
        } while (!verify);

        List<Object> arg = new ArrayList<>();
        arg.add(filial);
        arg.add(mes);
        Crono.start();
        Querie2 q2 = (Querie2) model.interpreta(2, arg);
        System.out.println(Crono.getTImeString());
        this.view = new Query2View(q2.getNclientes(), q2.getNvendas());
        view.show(arg);
        view.show();
        Input.lerString();
        view = new MainMenuView();

    }

    /**
     * Método que obtém a informação da Query3 e a apresenta ao utilizador.
     */
    private void infoClientePMes() {
        String opcao = "";
        view.show("Cliente: ");
        opcao = Input.lerString();
        opcao = opcao.toUpperCase();
        if (opcao.isEmpty()) return;
        List<Object> arg = new ArrayList<>();
        arg.add(opcao);
        try {
            Crono.start();
            this.view = new Query3View((Querie3) model.interpreta(3, arg));
            System.out.println(Crono.getTImeString());
            view.show(arg);
            view.show();
            Input.lerString();
        } catch (ClientNotFoundException | ProductNotFoundException | IOException | ClassNotFoundException m) {
            System.out.println(m.getMessage() + " não existente");
        }
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query4 e a apresenta ao utilizador.
     */
    private void infoProdutoPMes() {
        String opcao = "";
        view.show("Produto: ");
        opcao = Input.lerString();
        opcao = opcao.toUpperCase();
        if (opcao.isEmpty()) return;
        List<Object> arg = new ArrayList<>();
        arg.add(opcao);
        try {
            Crono.start();
            this.view = new Query4View((Querie4) model.interpreta(4, arg));
            System.out.println(Crono.getTImeString());
            view.show(arg);
            view.show();
            Input.lerString();
        } catch (ProductNotFoundException | ClientNotFoundException | IOException | ClassNotFoundException m) {
            this.view.show(m.getMessage() + " não existente.\n<Enter> to continue\n");
            Input.lerString();
        }
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query5 e a apresenta ao utilizador.
     */
    private void produtosMaisCompradosPCliente() {
        String opcao;
        view.show("Cliente: ");
        opcao = Input.lerString();
        opcao = opcao.toUpperCase();
        if (opcao.isEmpty()) return;
        List<Object> arg = new ArrayList<>();
        arg.add(opcao);
        try {
            Crono.start();
            this.view = new Query5View(((Querie5) model.interpreta(5, arg)).getProds_and_qtdList());
            System.out.println(Crono.getTImeString());
            view.show(arg);

            view.show();
            Input.lerString();
        } catch (ClientNotFoundException | ProductNotFoundException | IOException | ClassNotFoundException m) {
            System.out.println(m.getMessage() + " não existente.\n<Enter> to continue\n");
            Input.lerString();
        }
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query6 e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void xProdutosMaisVendidos() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        view.show("Número de produtos: ");
        List<Object> arg = new ArrayList<>();
        int n;
        do {
            n = Input.lerInt();
            if(n<1) view.show("Valor inválido!\nNúmero de produtos: ");
        }while (n<1);
        arg.add(n);
        Crono.start();
        Querie6 q6 = (Querie6) model.interpreta(6, arg);
        System.out.println(Crono.getTImeString());
        this.view = new Query6View(q6.getnClientes(n), q6.getQuantidadeComprada(n), (q6.getNProdutosMaisVendidos(n)));
        view.show(n);
        view.show();
        Input.lerString();


        view = new MainMenuView();

    }

    /**
     * Método que obtém a informação da Query7 e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void top3Buyers() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        Crono.start();
        this.view = new Query7View((Querie7) model.interpreta(7, new ArrayList<>()));
        System.out.println(Crono.getTImeString());
        view.show(1);
        view.show();
        Input.lerString();

        view = new MainMenuView();

    }

    /**
     * Método que obtém a informação da Query8 e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void xClientesMaisCompradores() throws ProductNotFoundException, ClientNotFoundException, IOException, ClassNotFoundException {
        view.show("Número de clientes: ");
        int n;
        do {
            n = Input.lerInt();
            if (n < 0) view.show("Número inválido\nNúmero de clientes: ");
        } while (n < 0);
        List<Object> arg = new ArrayList<>();
        arg.add(n);
        Crono.start();
        this.view = new Query8View((Querie8) model.interpreta(8, arg));
        System.out.println(Crono.getTImeString());
        view.show(n);
        view.show();
        Input.lerString();

        view = new MainMenuView();

    }

    /**
     * Método que obtém a informação da Query9 e a apresenta ao utilizador.
     * @throws ProductNotFoundException exceção.
     * @throws ClientNotFoundException exceção.
     */
    private void xClientesQMaisCompraramProdutoY() throws ProductNotFoundException, ClientNotFoundException {
        String produto;
        int n;
        view.show("Produto: ");
        produto = Input.lerString();
        produto = produto.toUpperCase();
        view.show("Número de clientes: ");
        do {
            n = Input.lerInt();
            if (n < 0) view.show("Número inválido\nNúmero de clientes: ");
        } while (n < 0);
        List<Object> arg = new ArrayList<>();
        arg.add(produto);
        arg.add(n);
        try {
            Crono.start();
            this.view = new Query9View((Querie9) model.interpreta(9, arg));
            System.out.println(Crono.getTImeString());
            view.show(n);
            view.show();
            Input.lerString();

        } catch (ProductNotFoundException | IOException | ClassNotFoundException m) {
            System.out.println(m.getMessage() + " não existente.\n<Enter> to continue\n");
            Input.lerString();
        }
        view = new MainMenuView();
    }

    /**
     * Método que obtém a informação da Query10 e a apresenta ao utilizador.
     * @throws ClientNotFoundException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    private void fatTotalMesFilial() throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException {
        int filial = 1;
        int mes = 1;
        int index = 0;
        Observer observer = new ObserverQ10(filial, mes);
        String opcao = "";
        Crono.start();
        Querie10 q10 = (Querie10) model.interpreta(10, new ArrayList<>());
        System.out.println(Crono.getTImeString());
        this.view = new Query10View(q10.getProds(), 90, observer);

        List<Integer> l = new ArrayList<>();
        l.add(filial);
        l.add(mes);
        view.show(0);
        view.show();

        do {
            if (observer.isChanged()) {
                l = observer.pull();
                observer.update(false);
            }
            opcao = Input.lerString();
            opcao = opcao.toUpperCase();
            String[] args = opcao.split(" ");

            switch (args[0]) {
                case "A":
                    if (index > 0)
                        index--;
                    break;
                case "D":
                    if (index < l.get(2) - 1)
                        index++;
                    break;
                case "J":
                    try {
                        int j = Integer.parseInt(args[1]);
                        if (j > 0 && j <= l.get(2))
                            index = j - 1;
                        else
                            view.show("Página inválida\n");
                    } catch (NumberFormatException | NullPointerException e) {
                        view.show("Insira um número válido\n");
                    }
                    break;
                case "1":
                    if (l.get(0) > 1) {
                        observer.update(0, l.get(0) - 1);
                        l.add(0, l.get(0) - 1);
                        index = 0;
                    }
                    break;
                case "3":
                    if (l.get(0) < FILIAIS) {
                        observer.update(0, l.get(0) + 1);
                        l.add(0, l.get(0) + 1);
                        index = 0;
                    }
                    break;
                case "Q":
                    if (l.get(1) > 1) {
                        observer.update(1, l.get(1) - 1);
                        l.add(1, l.get(1) - 1);
                        index = 0;
                    }
                    break;
                case "E":
                    if (l.get(1) < MES) {
                        observer.update(1, l.get(1) + 1);
                        l.add(1, l.get(1) + 1);
                        index = 0;
                    }
                    break;
                default:
                    break;
            }


            view.show(index);
            view.show();


        } while (!opcao.equals("S"));

        view = new MainMenuView();
    }

    /**
     * Método que permite guardar o modelo que gere o programa como um ficheiro.
     * @throws ClientNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws ClassNotFoundException exceção.
     */
    public void guardarGestVendas() throws ClientNotFoundException, IOException, ProductNotFoundException, ClassNotFoundException {
        List<Object> aux = new ArrayList<>();
        String defaultFileName = "gestVendas.dat";
        aux.add(defaultFileName);
        model.interpreta(13, aux);
    }

    /**
     * Método que permite carregar o modelo que gere o programa com um ficheiro.
     * @throws ClientNotFoundException exceção.
     * @throws ProductNotFoundException exceção.
     * @throws IOException exceção.
     * @throws ClassNotFoundException exceção.
     */
    public void loadGestVendas() throws ClientNotFoundException, IOException, ProductNotFoundException, ClassNotFoundException {
        boolean valid = false;
        String filename;
        do {
            view.show("Insira o nome do ficheiro objeto: ");
            filename = Input.lerString();
            if (filename.isEmpty()) return;
            else if (Files.exists(Paths.get(filename))) {
                valid = true;
            } else {
                this.view.show("Ficheiro Objeto inválido\n");
            }
        } while (!valid);
        this.model = GestVendas.loadGestVendas(filename);
    }
}
