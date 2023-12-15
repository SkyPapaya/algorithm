package model;

public class Expression {
    boolean value;
    //存储两个不同的命题变元及他们对应的值
    char variableLeft;
    int leftValue;
    char variableRight;
    int rightValue;
    char operator;
    //用来存储得到的暂时的真值
    boolean tempTable[] = new boolean[4];
    int count = 0;
    //存放完整表达式
    String content;
    //存放部分表达式
    String tempContent;

    public String getTempContent() {
        return tempContent;
    }

    public void setTempContent(Expression expression) {
        this.tempContent = String.valueOf(expression.getVariableLeft()) + String.valueOf(expression.getOperator()) + String.valueOf(expression.getVariableRight());
        ;
    }

    public char getOperator() {
        return operator;
    }

    public void setOperator(char operator) {
        this.operator = operator;
    }

    public boolean isValue() {
        return value;
    }

    public void setValue(boolean value) {
        this.value = value;
    }

    public char getVariableLeft() {
        return variableLeft;
    }

    public void setVariableLeft(char variableLeft) {
        this.variableLeft = variableLeft;
    }

    public int getLeftValue() {
        return leftValue;
    }

    public void setLeftValue(int leftValue) {
        this.leftValue = leftValue;
    }

    public char getVariableRight() {
        return variableRight;
    }

    public void setVariableRight(char variableRight) {
        this.variableRight = variableRight;
    }

    public int getRightValue() {
        return rightValue;
    }

    public void setRightValue(int rightValue) {
        this.rightValue = rightValue;
    }

    //逻辑与的运算
    public boolean and() {
        tempTable[count] = leftValue != 0 && rightValue != 0;
        count++;
        return (leftValue != 0 && rightValue != 0);
    }

    //逻辑非的运算
    public boolean negation() {
        if (leftValue == 1) {
            leftValue = 0;
        } else {
            leftValue = 1;
        }
        return or();

    }

    //逻辑或的运算
    public boolean or() {
        tempTable[count] = leftValue != 0 || rightValue != 0;
        count++;
        return (leftValue != 0 || rightValue != 0);
    }

    //逻辑单条件的运算
    public boolean oneWay() {
        if (leftValue == 1 && rightValue == 0) {
            tempTable[count] = false;
            count++;
            return false;
        } else {
            tempTable[count] = false;
            count++;
            return true;
        }
    }

    public boolean[] getTempTable() {
        return tempTable;
    }

    public void setTempTable(boolean[] tempTable) {
        this.tempTable = tempTable;
    }

    //逻辑双条件的运算
    public boolean bothWay() {
        boolean resultLeft = oneWay();
        //进行逻辑运算得到左值后进行变量值的交换
        int temp = 0;
        temp = leftValue;
        leftValue = rightValue;
        rightValue = temp;
        boolean resultRight = oneWay();
        temp = leftValue;
        leftValue = rightValue;
        rightValue = temp;

        tempTable[count] = resultLeft && resultRight;
        count++;
        return (resultLeft && resultRight);
    }

    public String getContent() {
        return content;
    }

    public void setContent(Expression content) {
        this.content = content.getVariableLeft() + " " + content.getVariableRight() + " " + content.getVariableLeft() + content.operator + content.getVariableRight();
    }

    public String toString() {
        String result = null;
        switch (operator) {
            case '|' -> {
                //循环交换4次真假值
                //00
                leftValue = 0;
                rightValue = 0;
                result = String.valueOf(or());
                //将每一次运算得到的结果暂存到表
                tempTable[0] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(or());
                tempTable[2] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                leftValue = 1;
                rightValue = 0;
                result = String.valueOf(or());
                tempTable[3] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(or());
                tempTable[4] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);
            }

            case '&' -> {
                leftValue = 0;
                rightValue = 0;
                result = String.valueOf(and());
                tempTable[0] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(and());
                tempTable[1] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                leftValue = 1;
                rightValue = 0;
                result = String.valueOf(and());
                tempTable[2] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(and());
                tempTable[3] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);
            }

            case '~' -> {
                leftValue = 0;
                rightValue = 0;
                result = String.valueOf(negation());
                tempTable[0] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(negation());
                tempTable[1] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                leftValue = 1;
                rightValue = 0;
                result = String.valueOf(negation());
                tempTable[2] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(negation());
                tempTable[3] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);
            }


            case '>' -> {
                leftValue = 0;
                rightValue = 0;
                result = String.valueOf(oneWay());
                tempTable[0] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(oneWay());
                tempTable[1] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                leftValue = 1;
                rightValue = 0;
                result = String.valueOf(oneWay());
                tempTable[2] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(oneWay());
                tempTable[3] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);
            }

            case '<' -> {
                rightValue = 0;
                leftValue = 0;
                result = String.valueOf(bothWay());
                tempTable[0] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(bothWay());
                tempTable[1] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                leftValue = 1;
                rightValue = 0;
                result = String.valueOf(bothWay());
                tempTable[2] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);

                rightValue = 1;
                result = String.valueOf(bothWay());
                tempTable[3] = Boolean.parseBoolean(result);
                System.out.println(leftValue + " " + rightValue + " " + result);
            }
        }
        return " ";
    }
}
