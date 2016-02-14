/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_hasan_men;

/**
 * *,-,/,^,+ operatorlerini barindirir ve gerekli islemleri yapar.
 *
 * @version 4.1.2016
 * @author Hasan
 */
public class Operator extends Expression {

    private char f_operator;

    public Operator(char ch) throws Exception {
        // base clasi ilklendirmeye gerek gormedim. Sadece yapitasi olarak kullanildi.
        //super();
        setOperator(ch);
    }

    /**
     * Yeni bir char olarak operator alir. Gecerli durumda atama yapar.
     *
     * @param ch Atanacak yeni operator
     * @throws Exception operator gecersiz olursa hata firlatir.
     */
    public void setOperator(char ch) throws Exception {

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            f_operator = ch;
        } else {
            throw new HmennExceptions("Unresolved Operator!!!");
        }

    }
    
    public static boolean isOperator(char ch){
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            return true;
        return false;
    }
    /**
     *
     * @return Operatorun char halini dondurur.
     */
    public char getOperator() {
        return f_operator;
    }

    /**
     * toString metodumuz. Operatorun ekran ciktisini olusturur.
     */
    @Override
    public String toString() {
        return String.format(" %c", f_operator);
    }

    /**
     * Operatorlerin oncelik sirasini return eder. Bu siralamalara gore islemler
     * degisecektir.
     */
    public int getOpPrecedence() {
        if (f_operator == '^') {
            return 4;
        } else if (f_operator == '*') {
            return 3;
        } else if (f_operator == '/') {
            return 2;
        } else if (f_operator == '+') {
            return 1;
        } else {
            return 0; // if f_operator equals '-'
        }
    }

    /**
     * Operatorun sag ve sol kisimlarindan yola cikarak hesaplamalari yapar.
     *
     * @param _left Operatorun sol tarafi
     * @param _right Operatorun sag tarafi
     * @param op Operatorumu
     * @return Islem sonucunu return edecektir
     * @throws Exception Olasi islem hatalarini firlatir. 0'a bolme gibi.
     */
    public Operand evaluateOperator(int _left, int _right,
            Operator op) throws Exception {
        int result = 0;

        int left = _left;
        int right = _right;
        switch (op.getOperator()) {
            case '^':
                result = (int) Math.pow(left, right);
                break;
            case '*':
                result = left * right;
                break;
            case '/': {
                if (right == 0) {
                    throw new HmennExceptions("Right operand of divide"
                            + " operator can not be zero!!!");
                }
                result = left / right;
            }
            break;
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            default:
                throw new HmennExceptions("Evaluate Error! Check Expression");
        }
        return new Operand(result);
    }
}
