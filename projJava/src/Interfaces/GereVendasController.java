package Interfaces;

import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;

import java.io.IOException;
import java.util.List;

public interface GereVendasController {
    void setModel(GereVendasModel m);

    void setView(GereVendasView v);

    void start() throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException;

    List<String> loadFiles();

}
