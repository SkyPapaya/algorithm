package org.example;

public class JudgeMent {

    //存储元素的个数
    int number = 5;


    //输入偏序关系以#结尾
    String relation = "ab|ba|ac|bc|aa#";
    int[][] relMixin = new int[number][number];

    public void init() {
        int index = 2;
        char indexChar = relation.charAt(index);
        //a = 97
        //最后一次没有扫描进去
        int indexTemp = 0;
        //分别指向偏序集的key和value
        char key = relation.charAt(indexTemp);
        char value = relation.charAt(indexTemp + 1);
        //初始化关系矩阵
        relMixin[key - 97][value - 97] = 1;
        while (!(indexChar == '#')) {
            indexTemp += 3;
            //逻辑问题
            index += 3;
            indexChar = relation.charAt(index);
            //分别指向偏序集的key和value
            key = relation.charAt(indexTemp);
            value = relation.charAt(indexTemp + 1);
            //初始化关系矩阵
            relMixin[key - 97][value - 97] = 1;
        }


    }

    public void output() {
        //打印关系矩阵
        System.out.println("关系矩阵为：");
        for (int i = 0; i < relMixin.length; i++) {
            for (int j = 0; j < relMixin[i].length; j++) {
                System.out.print(relMixin[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("自反性：" + reflexivity(relMixin));
        System.out.println("反自反性：" + !reflexivity(relMixin));
        System.out.println("对称性：" + symmetry(relMixin));
        System.out.println("反对称性：" + antisymmetry(relMixin));
        System.out.println("传递性：" + transitivity(relMixin));

    }

    //自反性验证
    public static boolean reflexivity(int[][] data) {
        boolean result = true;
        //遍历data
        for (int i = 0; i < data.length; i++) {
            if (data[i][i] == 0) {
                result = false;
                break;
            }
        }
        return result;
    }

    //对称性验证
    public static boolean symmetry(int[][] data) {
        boolean result = true;
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data.length; j++) {
                if (data[i][j] != data[j][i]) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }

    //反对称性验证
    public static boolean antisymmetry(int[][] data) {
        boolean result = true;
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data.length; j++) {
                if (data[i][j] != data[j][data.length - i - 1]) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }

    //传递性验证
    public static boolean transitivity(int[][] data) {
        boolean result = true;
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data.length; j++) {
                for (int k = 0; k < data.length; k++) {
                    if (data[i][j] != 0 && data[j][k] != 0 && data[i][k] == 0) {
                        result = false;
                        break;
                    }
                }
            }
        }

        return result;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getRelation() {
        return relation;
    }

    public void setRelation(String relation) {
        this.relation = relation;
    }

    public int[][] getRelMixin() {
        return relMixin;
    }

    public void setRelMixin(int[][] relMixin) {
        this.relMixin = relMixin;
    }
}
