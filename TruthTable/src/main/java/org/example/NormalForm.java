package org.example;

public class NormalForm {
    String form;
    int count = 0;
    int count0 = 0;
    int count1 = 0;

    Proposition fo;
    Translation tr;

    NormalForm(String form) {
        this.form = form;
        fo = new Proposition(form);
        tr = new Translation(form);
        tr.judge();
    }

    void calculate() {
        int[] x = new int[4];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        fo.va1[count] = i;
                        fo.va2[count] = j;
                        fo.va3[count] = k;
                        fo.va4[count] = l;
                        x[0] = i;
                        x[1] = j;
                        x[2] = k;
                        x[3] = l;
                        fo.truth[count] = tr.operate(x);
                        if (fo.truth[count] == 0) {
                            count0++;
                        } else {
                            count1++;
                        }
                        count++;
                    }
                }
            }
        }
    }

    void table() {
        if (tr.judge() == 2) {
            System.out.println(tr.va[0] + " " + tr.va[1] + " " + tr.pfr);
            for (int i = 0; i < 4; i++) {
                System.out.println(fo.va1[i * 4] + " " + fo.va2[i * 4] + "   " + fo.truth[i * 4]);
            }
        }
        if (tr.judge() == 3) {
            System.out.println(tr.va[0] + " " + tr.va[1] + " " + tr.va[2] + " " + tr.pfr);
            for (int i = 0; i < 8; i++) {
                System.out.println(fo.va1[i * 2] + " " + fo.va2[i * 2] + " " + fo.va3[i * 2] + "   " + fo.truth[i * 2]);
            }
        }
        if (tr.judge() == 4) {
            System.out.println(tr.va[0] + " " + tr.va[1] + " " + tr.va[2] + " " + tr.va[3] + " " + tr.pfr);
            for (int i = 0; i < 16; i++) {
                System.out.println(fo.va1[i] + " " + fo.va2[i] + " " + fo.va3[i] + " " + fo.va4[i] + "   " + fo.truth[i]);
            }
        }

    }

    void pdnf() {
        //this.calculate();
        count1 = count1 / 2;
        count1--;
        System.out.println("主析取范式为:");
        for (int i = 0; i < 8; i++) {
            if (fo.truth[i * 2] == 1) {
                System.out.print("(");
                if (fo.va1[i * 2] == 0) {
                    System.out.print("-" + tr.va[0]);
                } else {
                    System.out.print(tr.va[0]);
                }
                System.out.print("*");
                if (fo.va2[i * 2] == 0) {
                    System.out.print("-" + tr.va[1]);
                } else {
                    System.out.print(tr.va[1]);
                }
                System.out.print("*");
                if (fo.va3[i * 2] == 0) {
                    System.out.print("-" + tr.va[2]);
                } else {
                    System.out.print(tr.va[2]);
                }
                System.out.print(")");

                if (count1 > 0) {
                    System.out.print("+");
                    count1--;
                }
            }
        }
        System.out.println();
    }

    void pcnf() {
        count0 = count0 / 2;
        count0--;
        System.out.println("主合取范式为:");
        for (int i = 0; i < 8; i++) {
            if (fo.truth[i * 2] == 0) {
                System.out.print("(");
                if (fo.va1[i * 2] == 0) {
                    System.out.print("-" + tr.va[0]);
                } else {
                    System.out.print(tr.va[0]);
                }
                System.out.print("+");
                if (fo.va2[i * 2] == 0) {
                    System.out.print("-" + tr.va[1]);
                } else {
                    System.out.print(tr.va[1]);
                }
                System.out.print("+");
                if (fo.va3[i * 2] == 0) {
                    System.out.print("-" + tr.va[2]);
                } else {
                    System.out.print(tr.va[2]);
                }
                System.out.print(")");

                if (count0 > 0) {
                    System.out.print("*");
                    count0--;
                }
            }
        }
        System.out.println();
    }

    void comeTrue() {
        System.out.println("成真赋值为:");
        for (int i = 0; i < 8; i++) {
            if (fo.truth[i * 2] == 1) {
                System.out.print(fo.va1[i * 2] + " " + fo.va2[i * 2] + " " + fo.va3[i * 2]);
                System.out.print("   ");
            }
        }
        System.out.println();
    }

    void aFalse() {
        System.out.println("成假赋值为:");
        for (int i = 0; i < 8; i++) {
            if (fo.truth[i * 2] == 0) {
                System.out.print(fo.va1[i * 2] + " " + fo.va2[i * 2] + " " + fo.va3[i * 2]);
                System.out.print("   ");
            }
        }
        System.out.println();
    }
}
