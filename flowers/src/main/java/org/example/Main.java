package org.example;

public class Main {
    public static void main(String[] args) {
        //测试用例
        int[] flowerbed = {1};
        int n = 0;


        boolean result = true;
        if (flowerbed.length == 1 && flowerbed[0] == 1) {
            result = false;
            System.out.println(result);
        }
        if (flowerbed.length == 1 && flowerbed[0] == 0) {
            result = true;
            System.out.println(result);
        }
        if (n == 0) {
            result = true;
            System.out.println(result);

        }
        //判断首元素
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        //前后都没有1就可以种花
        for (int i = 1; i < flowerbed.length - 2; i++) {
            if (flowerbed[i - 1] + flowerbed[i] == 0 && flowerbed[i] + flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        //队尾元素判断
        if (flowerbed[(flowerbed.length) - 1] == 0 && flowerbed[(flowerbed.length) - 2] == 0) {
            flowerbed[(flowerbed.length - 1)] = 1;
            n--;
        }
        if (n != 0) {
            result = false;
        }

        System.out.println(result);
    }
}