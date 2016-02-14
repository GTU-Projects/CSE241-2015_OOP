package hw10_hasan_men;

import java.util.Scanner;

/**
 * Bu class expression clasi icin test adimlarini icerir.
 *
 * @version 8.1.2016
 * @author Hasan
 */
public class hw10_hasan_men_131044009 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Expression expression = new Expression();

        final String EQUAL = "=";
        Scanner scan = new Scanner(System.in);
        /*
        System.out.printf("%s\n", "Enter your expression, after each operator "
                + "or operand press enter, to end the expression press =");
        System.out.printf("%s\n", "Enter your expression element");
        String line;
        
                
        try {
            while (!(line = scan.nextLine()).equals(EQUAL)) {
                expression.addElement(line);
                System.out.println("Enter your expression element");
                
            }
            expression.solve();
        } catch (Exception e) {
            if(e instanceof HmennExceptions)
                System.out.println(e + "\nProgram Aborted!!!");
            else System.out.println("Unresolved Expression!!!" + "\nProgram Aborted!!!");
            //Runtime.getRuntime().exit(0)
            System.exit(1);
        }
        System.out.println("Result = " + expression);
         */
        System.out.print("Enter your expression :");
        String line = scan.nextLine();
        String parse = "";
        try {
            expression.addStr(line);
            expression.solve();
        } catch (Exception e) {
            if (e instanceof HmennExceptions) {
                System.out.println(e + "\nProgram Aborted!!!");
            } else {
                System.out.println("Unresolved Expression!!!" + "\nProgram Aborted!!!");
            }
            //Runtime.getRuntime().exit(0)
            System.exit(1);
        }
        System.out.println("Result = " + expression);

    }
}
