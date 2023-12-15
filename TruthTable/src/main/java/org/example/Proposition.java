package org.example;

public class Proposition {
    String formula;
    int[] va1 = new int[16];
    int[] va2 = new int[16];
    int[] va3 = new int[16];
    int[] va4 = new int[16];
    int[] truth = new int[16];

    Proposition(String formula) {
        this.formula = formula;
    }
}