package org.example;

import java.rmi.AlreadyBoundException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String word1 = "abcdefg";
        String word2 = "abcdefgh ";

        ArrayList<Character> newString = new ArrayList<Character>();
        int index1 = 0;
        int index2 = 0;
        int length1 = word1.length();
        int length2 = word2.length();
        for (int i = 0; i < length1 + length2 - 1; i++) {
            if (index1 <= length1 - 1) {
                newString.add(word1.charAt(index1));
                index1++;
            }
            if (index2 <= length2 - 1) {
                newString.add(word2.charAt(index2));
                index2++;
            }
        }
        String result = "";
        for (int i = 0; i < newString.size(); i++) {
            result += newString.get(i);
        }
        System.out.println(result);
    }
}