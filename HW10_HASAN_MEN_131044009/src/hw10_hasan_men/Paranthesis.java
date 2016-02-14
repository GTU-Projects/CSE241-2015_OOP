/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_hasan_men;

/**
 * Expresion icinde tutulabilecek parantez clasidir. ( ve ) seklinde char olarak
 * tutar.
 * @version 3.1.2016
 * @author Hasan
 */
public class Paranthesis extends Expression {

    private char f_paranthesis; // field paranthesis
    
    public Paranthesis(char ch) {
        f_paranthesis = ch;
    }

    /**
     * 
     * @return Parantezi char olarak return eder
     */
    public char getParanthesis() {
        return f_paranthesis;
    }

    /**
     * Parantezi yeni deger ile set etmeye yarayan method.
     * @param ch Yeni parantez
     * @throws Exception Olasi gecersi parantez durumunda hata firlatir.
     */
    public void setParanthesis(char ch) throws Exception {
        if (ch == '(' || ch == ')') {
            f_paranthesis = ch;
        } else {
            throw new HmennExceptions("Unresolved Paranthesis character");
        }
    }

    /**
     * Parantezimizi string olarak return eder. Ekrana basim esnasinda kullanilacak. 
     */
    @Override
    public String toString() {
        return String.format(" %c", f_paranthesis);
    }

    public static boolean isParanthesis(char ch){
        if(ch=='(' || ch==')')
            return true;
        return false;
    }
}
