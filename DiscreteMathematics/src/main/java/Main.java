import model.Expression;

import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        Stack<Character> expressions = new Stack<>();
        int numberOfVariable = 3;
        char char1 = 'P';
        char char2 = 'Q';
        String input = ">P&PQ";

        //在这里定义每个运算符的输入
        //|或
        //&与
        //~非
        //>单条件
        //<双条件
        //用后缀表达式的形式输入

        char[] chars = input.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            expressions.push(chars[i]);
        }
        //存储最终的表达式
        Expression expressionFinal = new Expression();
        //存储上一次运算的表达式
        Expression expressionTemplate = new Expression();


        expressionTemplate.setVariableLeft(expressions.pop());
        expressionTemplate.setVariableRight(expressions.pop());
        expressionTemplate.setOperator(expressions.pop());
        //System.out.println(expressionTemplate);

        boolean tempTable[] = new boolean[4];
        //同步暂存的真值表
        for (int i = 0; i < tempTable.length; i++) {
            tempTable[i] = expressionTemplate.getTempTable()[i];
        }
        expressionFinal.setVariableLeft(expressions.pop());
        expressionFinal.setOperator(expressions.pop());
        expressionFinal.setContent(expressionFinal);
        expressionTemplate.setTempContent(expressionTemplate);
        String finalExpression = String.valueOf(char1) + " " + String.valueOf(char2) + " " + expressionFinal.getVariableLeft() + expressionFinal.getOperator() + "(" + expressionTemplate.getTempContent() + ")";
        System.out.println(finalExpression);
        System.out.println(expressionFinal);


        String principalDisjunctive = "";
        String principalConjunctive = "";
        //得到主析取范式和主合取范式
        for (int i = 0; i < 4; i++) {

            if (!expressionFinal.getTempTable()[i]) {
                switch (i) {
                    case 0:
                        principalDisjunctive += "(~P&~Q)|";
                        break;
                    case 1:
                        principalDisjunctive += "(~P&Q)|";
                        break;
                    case 2:
                        principalDisjunctive += "(P&~Q)|";
                        break;
                    case 3:
                        principalDisjunctive += "(P&Q)|";
                        break;
                }

            } else {
                switch (i) {
                    case 0:
                        principalConjunctive += "(P|Q)&";
                        break;
                    case 1:
                        principalConjunctive += "(P|~Q)&";
                        break;
                    case 2:
                        principalConjunctive += "(~P|Q)&";
                        break;
                    case 3:
                        principalConjunctive += "(~P|~Q)&";
                        break;
                }

            }
        }
        System.out.print("主析取范式：");
        System.out.println(principalDisjunctive.substring(0, principalDisjunctive.length() - 1));
        System.out.print("主合取范式：");
        System.out.println(principalConjunctive.substring(0,principalConjunctive.length() - 1));

    }
}
