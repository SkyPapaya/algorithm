package org.example;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        int [] candies = {10,2};
        int extraCandies = 2;
        //遍历数组，找到最大差值，并记录最大元素的下标，如果额外糖果数大于最大差值
        //那所有孩子都能成为

        //记录最大值，最小值和最大差值
        int max = candies[0];
        List<Integer> maxIndex = new ArrayList<Integer>();
        int min = candies[0];
        List<Integer> minIndex = new ArrayList<Integer>();
        //循环找最大最小元素
        for(int i = 1 ; i <= candies.length - 1 ; i ++){
            //find max
            if(candies[i] > max){
                max = candies[i];
                maxIndex.add(i);
            }

            if (candies[i] < min) {
                min = candies[i];
                minIndex.add(i);
            }
        }
        int diff = max - min;
        List<Boolean> results= new ArrayList<Boolean>();

        //如果额外糖果数大于最大差值，那么所有孩子都有机会成为最多的
        if(diff <= extraCandies) {
            int index = 0;
            while (index < candies.length) {
                results.add(true);
                index++;
            }
        }else{
            //当前元素和最大元素的差值小于额外糖果数
            int index2 = 0;
            while (index2 <candies.length) {
                if( max - candies[index2] <= extraCandies) {
                    results.add(true);
                }else {
                    results.add(false);
                }
                index2++;
            }

        }

        System.out.println(diff);
            //输出结果

        System.out.println(results);
    }
}