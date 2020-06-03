package Interfaces;

import Exceptions.ClientNotFoundException;
import Exceptions.ProductNotFoundException;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.Collection;
import java.util.List;

public interface GereVendasModel extends Serializable {
    void loadDefault() throws FileNotFoundException;
    void loadFiles(List<String> paths);
    Querie interpreta(int num, Collection<Object> l) throws ClientNotFoundException, ProductNotFoundException, IOException, ClassNotFoundException;
}
