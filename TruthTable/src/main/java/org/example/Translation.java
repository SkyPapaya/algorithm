package org.example;

import org.example.LogicalOperation;

public class Translation {
    String pfr;
    char[] op;//命题公式
    char[] op1;//后缀表达式
    char[] op2;//符号，中间数组
    char[] va = new char[4];//变量储存
    int[] variable = new int[4];
    int count1 = -1;//op1计数器
    int count2 = -1;//op2计数器
    int count3 = 0;//va计数器
    int x1, x2, x3, x;//x储存表达式的值
    LogicalOperation lg = new LogicalOperation();

    Translation(String pfr) {
        this.pfr = pfr;
        op = pfr.toCharArray();
        op1 = new char[op.length];
        op2 = new char[op.length];
        for (int i = 0; i < op.length; i++) {//转化为后缀表达式,遍历op数组；
            if (op[i] >= 'a' && op[i] <= 'z') {
                count1++;
                op1[count1] = op[i];
            } else if (op[i] == '(') {
                count2++;
                op2[count2] = op[i];
            } else if (op[i] == '-') {
                if (count2 == -1 || op2[count2] == '+' || op2[count2] == '*' || op2[count2] == '#' || op2[count2] == '$' || op2[count2] == '(') {
                    count2++;
                    op2[count2] = op[i];
                } else if (op2[count2] == '-') {
                    count1++;
                    op1[count1] = '-';
                }
            } else if (op[i] == '+' || op[i] == '*' || op[i] == '#' || op[i] == '$') {
                if (count2 == -1 || op2[count2] == '(') {
                    count2++;
                    op2[count2] = op[i];
                } else if (op2[count2] == '+' || op2[count2] == '*' || op2[count2] == '#' || op2[count2] == '-' || op2[count2] == '$') {
                    count1++;
                    op1[count1] = op2[count2];
                    op2[count2] = op[i];
                }
            } else if (op[i] == ')') {
                while (op2[count2] != '(') {
                    count1++;
                    op1[count1] = op2[count2];
                    count2--;
                }
                count2--;
            }
        }//循环结束
        while (count2 >= 0) {
            count1++;
            op1[count1] = op2[count2];
            count2--;
        }//后缀表达式完成
    }

    int judge() {//判断变量个数
        va[0] = op1[0];
        for (int i = 1; i <= count1; i++) {
            if (op1[i] >= 'a' && op1[i] <= 'z') {
                if (op1[i] != va[0] && op1[i] != va[1] && op1[i] != va[2]) {
                    if (va[1] == 0) {
                        va[1] = op1[i];
                        count3 = 2;
                    } else if (va[2] == 0) {
                        va[2] = op1[i];
                        count3 = 3;
                    } else {
                        va[3] = op1[i];
                        count3 = 4;
                    }
                }
            }
        }
        return count3;
    }

    int operate(int[] xi) {
        int num = -1;
        for (int i = 0; i <= count1; i++) {
            if (op1[i] >= 'a' && op1[i] <= 'z') {
                if (op1[i] == va[0]) {
                    num++;
                    variable[num] = xi[0];
                } else if (op1[i] == va[1]) {
                    num++;
                    variable[num] = xi[1];
                } else if (op1[i] == va[2]) {
                    num++;
                    variable[num] = xi[2];
                } else if (op1[i] == va[3]) {
                    num++;
                    variable[num] = xi[3];
                }
            } else if (op1[i] == '-') {
                variable[num] = lg.nagation(variable[num]);
            } else if (op1[i] == '+') {
                variable[num - 1] = lg.disjunction(variable[num - 1], variable[num]);
                num--;
            } else if (op1[i] == '*') {
                variable[num - 1] = lg.conjunction(variable[num - 1], variable[num]);
                num--;
            } else if (op1[i] == '#') {
                variable[num - 1] = lg.implication(variable[num - 1], variable[num]);
                num--;
            } else if (op1[i] == '$') {
                variable[num - 1] = lg.equivalence(variable[num - 1], variable[num]);
                num--;
            }
        }
        return variable[num];
    }

}