package Catalogos;

import java.io.Serializable;

public interface CliAndProdCatalogs extends Serializable {

    void addCode(String code);
    boolean checkCode(String code);

}
