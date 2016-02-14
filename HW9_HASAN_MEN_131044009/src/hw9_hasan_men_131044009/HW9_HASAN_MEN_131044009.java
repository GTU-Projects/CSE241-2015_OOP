package hw9_hasan_men_131044009;

/**
 * This class include test for polynomal class
 *
 * @since 26.12.2015
 * @version 1.02
 * @author Hasan MEN 131044009
 */
public class HW9_HASAN_MEN_131044009 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        double[] arr = {1, 1}; // x+1
        double[] arr2 = {1, -1}; // x-1
        double[] arr3 = {4, 1, 8, 4}; // 4x^3+ x^2 + 8x + 4
        double[] arr4 = {3}; // 3
        double[] arr5 = {3, 3, 3, 3, 3, 3, 3};

        PolynomialGTU pol1 = new PolynomialGTU(arr);
        PolynomialGTU pol2 = new PolynomialGTU(arr2);
        PolynomialGTU pol3 = new PolynomialGTU(arr3);
        PolynomialGTU pol4 = new PolynomialGTU(arr4);
        PolynomialGTU pol5 = new PolynomialGTU(arr5);
        PolynomialGTU pol6 = new PolynomialGTU(pol3);
        
        System.out.print("1.");
        System.out.println(pol1);
        System.out.print("2.");
        System.out.println(pol2);
        System.out.print("3.");
        System.out.println(pol3);
        System.out.print("4.");
        System.out.println(pol4);
        System.out.print("5.");
        System.out.println(pol5);
        System.out.print("6.");
        System.out.println(pol6);

        System.out.println("\nEVALUATE TEST POLIES\n");
        System.out.printf("1 Poly.(x=5) %.2f\n", pol1.calcultePoly(5));
        System.out.printf("2 Poly.(x=12) %.2f\n", pol2.calcultePoly(12));
        System.out.printf("3 Poly.(x=-5) %.2f\n", pol3.calcultePoly(-5));
        System.out.printf("4 Poly.(x=-1) %.2f\n", pol4.calcultePoly(-1));
        System.out.printf("5 Poly.(x=8) %.2f\n", pol5.calcultePoly(8));

        System.out.println("\nADD TEST POLIES\n");
        System.out.println("1+2:" + pol1.add(pol2));
        System.out.println("2+5:" + pol2.add(pol5));
        System.out.println("3+4:" + pol3.add(pol4));
        System.out.println("1+5:" + pol1.add(pol5));

        System.out.println("\n SUBSTRUCT TEST POLIES\n");
        System.out.println("1-2:" + pol1.substract(pol2));
        System.out.println("2-5:" + pol2.substract(pol5));
        System.out.println("3-4:" + pol3.substract(pol4));
        System.out.println("1-5:" + pol1.substract(pol5));

        System.out.println("\n MULTIPLY TEST POLIES\n");
        System.out.println("3*2:" + pol3.multiply(pol2));
        System.out.println("4*1:" + pol4.multiply(pol1));
        System.out.println("5*2:" + pol5.multiply(pol2));
        System.out.println("4*2:" + pol4.multiply(pol2));

        System.out.println("\n EQUALTY TEST POLIES\n");
        System.out.println("1 == 2 : " + pol1.equals(pol2));
        System.out.println("4 == 3 : " + pol4.equals(pol3));
        System.out.println("6 == 3 : " + pol6.equals(pol3));
        System.out.println("2 == 5 : " + pol2.equals(pol5));
        
        System.out.println("\n CHANGING INDEX OF POLY TEST\n");
        System.out.println("TEST WILL SHOW ON 3.POLY");
        System.out.println("3."+pol3);
        System.out.println("\nChange 1.coeff -> 2 ; \n2.coeff -> 5; \n3.coeff->9\n");
        pol3.setIndexCoef(1,2);
        pol3.setIndexCoef(2,5);
        pol3.setIndexCoef(3,9);
        System.out.println("New 3."+pol3);
        System.out.printf("Value of 3.Poly for x=3 : %.2f\n",pol3.calcultePoly(3));
        
    }

}
