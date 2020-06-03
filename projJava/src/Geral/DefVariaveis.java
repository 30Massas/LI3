package Geral;

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;

public interface DefVariaveis extends Serializable {

    int MODO = 2;
    int FILIAIS = 3;
    int MES = 12;
    List<String> MESES = Arrays.asList("JANEIRO", "FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO");

    String clientFileDefault = "Resources/Clientes.txt";
    String productFileDefault = "Resources/Produtos.txt";
    String salesFileDefault = "Resources/Vendas_1M.txt";
}
