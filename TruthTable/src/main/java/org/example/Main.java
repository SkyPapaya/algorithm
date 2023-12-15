package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // TODO 自动生成的方法存根
        Scanner scanf = new Scanner(System.in);
        int[] w = new int[4];
        System.out.println("输入命题公式（不超过四个命题变元）：");
        System.out.println("非为‘-’，析取为‘+’，合取为‘*’蕴涵为‘#’，等价为‘$’");
        String prf = scanf.nextLine();
        NormalForm form = new NormalForm(prf);
        //计算命题公式
        form.calculate();
        //输出真值表
        form.table();
        //主析取范式
        form.pdnf();
        //主合取范式
        form.pcnf();
    }
}