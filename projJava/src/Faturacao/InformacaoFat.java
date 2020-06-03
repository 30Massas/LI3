/**
 * @file InformacaoFat.java
 * Ficheiro que contém a API relativa à implementação da informação da faturação.
 */

package Faturacao;
import Geral.DefVariaveis;

import java.io.Serializable;

public class InformacaoFat implements DefVariaveis, Serializable {
    private double [][][]fat;
    private int [][][]qtd;
    private int [][][]n_vendas;
    private int []qtd_total;


    /**
     * Método que inicializa a estrutura que contém a informação de faturação.
     */
    public InformacaoFat(){
        this.fat = new double[DefVariaveis.MODO][DefVariaveis.FILIAIS][DefVariaveis.MES];
        this.qtd = new int[DefVariaveis.MODO][DefVariaveis.FILIAIS][DefVariaveis.MES];
        this.n_vendas = new int[DefVariaveis.MODO][DefVariaveis.FILIAIS][DefVariaveis.MES];
        this.qtd_total = new int[DefVariaveis.FILIAIS];
    }

    /**
     * Método que adiciona a informação de uma venda.
     * @param preco doouble que é o preço a que foi comprado.
     * @param qtd int que é a quantidade comprada.
     * @param modo char que é o modo que foi comprado.
     * @param mes int que é o mês em que foi comprado.
     * @param filial int que é a filial onde foi comprada.
     */
    public void addInformacaoFat(double preco, int qtd, char modo, int mes, int filial){
        int m;
        if(modo == 'N') m = 0;
        else m = 1;
        this.fat[m][filial-1][mes-1]+= (preco * qtd);
        this.qtd[m][filial-1][mes-1]+= qtd;
        this.n_vendas[m][filial-1][mes-1]++;
        this.qtd_total[filial-1]+=qtd;
    }

    /**
     * Método que calcula a quantidade total comprada.
     * @return sum int que é a quantidade total comprada.
     */
    public int getQtd_Total(){
        int sum = 0;
        for(int i = 0;i < FILIAIS; i++)
            sum+= this.qtd_total[i];
        return sum;
    }

    /**
     * Método que calcula a quantidade total comprada em cada mês e a guarda num array.
     * @return qtd int[] que é um array com as quantidas compradas em cada mês.
     */
    public int[] getNVendasMes(){
        int[] qtd = new int[MES];
        for (int i=0;i<MODO;i++)
            for(int j=0;j<FILIAIS;j++)
                for(int m=0;m<MES;m++)
                    qtd[m] += this.n_vendas[i][j][m];
        return qtd;
    }

    /**
     * Método que calcula o total faturado em cada mês e o guarda num array.
     * @return fat double[] que é um array com o faturado em cada mês.
     */
    public double[] getFatMes(){
        double[] fat = new double[MES];
        for (int i=0;i<MODO;i++)
            for(int j=0;j<FILIAIS;j++)
                for(int m=0;m<MES;m++)
                    fat[m] += this.fat[i][j][m];
        return fat;
    }


    /**
     * Método que calcula o total faturado.
     * @return fat double que é o total faturado.
     */
    public double getFatTotal(){
        double fat = 0;
        for (int i=0;i<MODO;i++)
            for(int j=0;j<FILIAIS;j++)
                for(int m=0;m<MES;m++)
                    fat += this.fat[i][j][m];
        return fat;
    }
}
