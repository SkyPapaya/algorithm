package org.example;

import static org.example.JudgeMent.*;

public class Cover {
    public int count = 0;

    private JudgeMent judgeMent;

    public String cover() {
        judgeMent = new JudgeMent();
        judgeMent.init();
        //判断是不是偏序集
        if (!antisymmetry(judgeMent.getRelMixin()) && reflexivity(judgeMent.getRelMixin()) && transitivity(judgeMent.getRelMixin())) {

            System.out.println("不满足偏序关系");
            return "";
        }
        String result = "";
        //获取偏序关系对应的关系矩阵
        int[][] relMixin = judgeMent.getRelMixin();
        //去掉自反关系
        for (int i = 0; i < relMixin.length; i++) {
            for (int j = 0; j < relMixin[i].length; j++) {
                if (i == j) {
                    relMixin[i][j] = 0;
                }
            }
        }
        //去掉传递性

        for (int i = 0; i < relMixin.length; i++) {
            for (int j = 0; j < relMixin.length; j++) {
                for (int k = 0; k < relMixin.length; k++) {
                    if (relMixin[i][j] != 0 && relMixin[j][k] != 0 && relMixin[i][k] == 1) {
                        relMixin[i][k] = 0;
                    }
                }
            }
        }

        //根据剩下的关系矩阵拼接出剩余的偏序关系
        for (int i = 0; i < relMixin.length; i++) {
            for (int j = 0; j < relMixin.length; j++) {
                if (relMixin[i][j] != 0) {
                    result += String.valueOf((char) (97 + i)) + String.valueOf((char) (97 + j)) + "|";
                }
            }
        }
        System.out.println(result);
        return result;
    }

    static int gcd(int x, int y) {
        int r = 1;
        while (r != 0) {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    public void supply() {
        boolean flag;
        int Gcd, Lcm;
        for (int i = 1; i < count; i++) {
            flag = false;
            for (int j = 1; j < count; j++) {
                if (i == j)
                    continue;
                Gcd = gcd(judgeMent.getRelMixin()[i][j], judgeMent.getRelMixin()[j][i]);
                Lcm = judgeMent.getRelMixin()[i][j] / Gcd * judgeMent.getRelMixin()[j][i];
                if (Gcd == judgeMent.getRelMixin()[0][j] && Lcm == judgeMent.getRelMixin()[count][j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                System.out.println("该格是有补格");
                return;
            }
        }
        System.out.println("该格不是有补格");
    }


}
