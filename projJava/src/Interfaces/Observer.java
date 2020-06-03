package Interfaces;

import java.util.List;

public interface Observer {
    void update(int fil, int mes , int pag);
    void update(int index, int value);
    void update(boolean t);
    boolean isChanged();
    List<Integer> pull();
}
