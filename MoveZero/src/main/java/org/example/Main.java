package org.example;

public class Main {
    public static void main(String[] args) {
        int[] numbers = {1, 0, 9, 0, 9, 8, 9, 0};
        int index = 0;

        //遍历一次数组，将非0元素全部提前并记录最后一个非0元素的下标
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] != 0) {
                numbers[index] = numbers[i];
                index++;
            }
        }

        //将最后一个非0元素的后面全部变成0;
        for (int i = index ; i < numbers.length; i++) {
            numbers[i] = 0;

        }
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
    }
}