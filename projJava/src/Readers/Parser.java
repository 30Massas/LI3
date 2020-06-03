package Readers;

import Catalogos.ClientsCatalog;
import Catalogos.ProductsCatalog;
import Faturacao.Faturacao;
import FilialStuff.Filial;
import Geral.*;
import Queries.Q1Stats;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.util.List;

public class Parser implements DefVariaveis, Serializable {

    /**
     *  Método que lê ficheiros de clientes, produtos e vendas e insere nas respetivas estruturas
     * @param clientsCatalog ClientesCatalog onde serão inseridos os códigos de cliente lidos.
     * @param productsCatalog ProductsCatalog onde serão inseridos os códigos de produto lidos.
     * @param faturacao Faturacao onde será inserida toda a informação de faturação de cada produto comprado.
     * @param filial Filial onde será inserida a informação de cada filial, organizada quer por clientes, quer por produtos.
     * @param q1Stats Q1Stats onde serão guardados valores referentes à Query1 Estatística.
     */
    public void parser(ClientsCatalog clientsCatalog, ProductsCatalog productsCatalog, Faturacao faturacao, Filial filial, Q1Stats q1Stats) {
        int nvendas_validas = 0;
        int nvendas_total = 0;
        int nclientes = 0;
        int nprods = 0;
        int vendas_a_zero = 0;
        try {
            BufferedReader cbr = new BufferedReader(new FileReader(clientFileDefault));
            BufferedReader pbr = new BufferedReader(new FileReader(productFileDefault));
            BufferedReader vbr = new BufferedReader(new FileReader(salesFileDefault));

            q1Stats.setFicheiro(salesFileDefault);

            String lineu;
            String[] buffer;

            while ((lineu = cbr.readLine()) != null) {
                clientsCatalog.addCode(lineu);
                nclientes++;
            }
            cbr.close();
            q1Stats.setTotal_clientes(nclientes);
            while ((lineu = pbr.readLine()) != null) {
                productsCatalog.addCode(lineu);
                nprods++;
            }
            pbr.close();
            q1Stats.setTotal_produtos(nprods);
            while ((lineu = vbr.readLine()) != null){
                buffer = lineu.split(" ");
                nvendas_total++;
                if(clientsCatalog.checkCode(buffer[4]) && productsCatalog.checkCode(buffer[0])) {
                    Registo e = new Registo(buffer[0], Double.parseDouble(buffer[1]), Integer.parseInt(buffer[2])
                            , buffer[3].charAt(0), Integer.parseInt(buffer[5]), Integer.parseInt(buffer[6]));
                    faturacao.addInformacaoFat(e);
                    nvendas_validas++;
                    filial.addRegistoCli(buffer[4],e);
                    filial.addRegistoProd(buffer[4],e);
                    if(Double.parseDouble(buffer[1]) == 0 || Integer.parseInt(buffer[2])==0) vendas_a_zero++;
                }
            }
            vbr.close();
            q1Stats.setNvendas_erradas(nvendas_total-nvendas_validas);
            q1Stats.setVendas_a_zero(vendas_a_zero);
            System.out.println(nvendas_validas);
        } catch (IOException e) {
            System.out.println("Ficheiro(s) inválido(s)");
        }
    }

    /**
     *  Método que lê ficheiros de clientes, produtos e vendas e insere nas respetivas estruturas.
     * @param paths que contém os caminhos dos ficheiros a ler.
     * @param clientsCatalog ClientesCatalog onde serão inseridos os códigos de cliente lidos.
     * @param productsCatalog ProductsCatalog onde serão inseridos os códigos de produto lidos.
     * @param faturacao Faturacao onde será inserida toda a informação de faturação de cada produto comprado.
     * @param filial Filial onde será inserida a informação de cada filial, organizada quer por clientes, quer por produtos.
     * @param q1Stats Q1Stats onde serão guardados valores referentes à Query1 Estatística.
     */
    public void parserDiffFiles(List<String> paths,ClientsCatalog clientsCatalog, ProductsCatalog productsCatalog, Faturacao faturacao, Filial filial, Q1Stats q1Stats){
        int nvendas_validas = 0;
        int nvendas_total = 0;
        int nclientes = 0;
        int nprods = 0;
        int vendas_a_zero = 0;
        try {
            BufferedReader cbr = new BufferedReader(new FileReader(paths.get(0)));
            BufferedReader pbr = new BufferedReader(new FileReader(paths.get(1)));
            BufferedReader vbr = new BufferedReader(new FileReader(paths.get(2)));

            q1Stats.setFicheiro(paths.get(2));

            String lineu;
            String[] buffer;

            while ((lineu = cbr.readLine()) != null) {
                clientsCatalog.addCode(lineu);
                nclientes++;
            }
            cbr.close();
            q1Stats.setTotal_clientes(nclientes);
            while ((lineu = pbr.readLine()) != null) {
                productsCatalog.addCode(lineu);
                nprods++;
            }
            pbr.close();
            q1Stats.setTotal_produtos(nprods);
            while ((lineu = vbr.readLine()) != null){
                buffer = lineu.split(" ");
                nvendas_total++;
                if(clientsCatalog.checkCode(buffer[4]) && productsCatalog.checkCode(buffer[0])) {
                    Registo e = new Registo(buffer[0], Double.parseDouble(buffer[1]), Integer.parseInt(buffer[2])
                            , buffer[3].charAt(0), Integer.parseInt(buffer[5]), Integer.parseInt(buffer[6]));
                    faturacao.addInformacaoFat(e);
                    nvendas_validas++;
                    filial.addRegistoCli(buffer[4],e);
                    filial.addRegistoProd(buffer[4],e);
                    if(Double.parseDouble(buffer[1]) == 0 || Integer.parseInt(buffer[2])==0) vendas_a_zero++;
                }
            }
            vbr.close();
            q1Stats.setNvendas_erradas(nvendas_total-nvendas_validas);
            q1Stats.setVendas_a_zero(vendas_a_zero);
            System.out.println(nvendas_validas);
        } catch (IOException e) {
            System.out.println("Ficheiro(s) inexistente(s)");
            System.exit(-1);
        }
    }
}
