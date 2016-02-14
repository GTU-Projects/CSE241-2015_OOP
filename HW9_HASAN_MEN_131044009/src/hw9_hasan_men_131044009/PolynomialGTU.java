package hw9_hasan_men_131044009;

import java.util.Arrays;

/**
 * This class is store polynomial number and makes sum mathmatical operations.
 *
 * @since 26.12.2015
 * @version 1.02
 * @author Hasan MEN - 131044009
 */
public class PolynomialGTU {

    /**
     * coefficients of polynomial number
     */
    private double[] coefficients;

    /**
     * Default(No parameter constructor) create a*x+b = 1*x+1
     */
    public PolynomialGTU() {

        coefficients = new double[2];
        setIndexCoef(0, 1);
        setIndexCoef(1, 1);

    }

    /**
     *
     * @param object is a copy polinomial. Constructor will initialize fields
     * with object fields.
     */
    public PolynomialGTU(PolynomialGTU object) {
        coefficients = new double[object.getSize()];

        for (int i = 0; i < getSize(); ++i) {
            coefficients[i] = object.coefficients[i];
        }

    }

    /**
     *
     * @param newCoef is array of coefficients. Will create new polnomial number
     * with new coefficients.
     */
    public PolynomialGTU(double[] newCoef) {

        coefficients = new double[newCoef.length];

        for (int i = 0; i < getSize(); ++i) {
            coefficients[i] = newCoef[i];
        }
    }

    /**
     *
     * @return array of coeffients
     */
    public double[] getCoefs() {
        return coefficients;
    }

    /**
     *
     * @return size of array of coefficients
     */
    public int getSize() {
        return coefficients.length;
    }

    /**
     * @param index is sequence of number in polnomial array
     * @return number in index
     */
    public double getIndexCoef(int index) {
        if (index >= 0 && index < getSize()) {
            return coefficients[index];
        } else {
            return 0.0;
        }
    }

    /**
     * Sets item in index with new value
     *
     * @param index index is sequence of number in polnomial array
     * @param value new value of number in index
     */
    public void setIndexCoef(int index, double value) {
        if (index >= 0 && index < getSize()) {
            coefficients[index] = value;
        } else {
            System.err.printf("\n%s\n", "Invalid index for setter.");
        }
    }

    /**
     * Takes x paramater end calculate polynomial
     *
     * @param x is a number which used for calculate polynomial with substitute
     * @return value of polynomial after substitute and calculate
     */
    public double calcultePoly(double x) {

        double total = 0;
        for (int i = 0; i < getSize(); ++i) {
            total += getIndexCoef(i) * Math.pow(x, getSize() - i - 1);
        }
        return total;
    }

    /**
     * Takes new polnomial and add first.
     *
     * @param other rigth hand side polynomial
     * @return addition two polynomial
     */
    public PolynomialGTU add(PolynomialGTU other) {

        int max = 0;
        int min = 0;
        PolynomialGTU maxPol = null;
        PolynomialGTU minPol = null;

        //find max and min polinomials
        if (getSize() >= other.getSize()) {
            maxPol = new PolynomialGTU(this); // max pol
            max = getSize();
            min = other.getSize();
            minPol = other;
        } else {
            maxPol = new PolynomialGTU(other);
            max = other.getSize();
            min = getSize();
            minPol = this;
        }

        int j = 0;

        // find distance and begin add number on old polynomial
        for (int i = max - min; i < max; ++i) {
            maxPol.setIndexCoef(i, maxPol.getIndexCoef(i) + minPol.getIndexCoef(j));
            ++j;
        }
        
        minPol =null;

        return maxPol;

    }

    /**
     * Takes a polynomial and substruct first polynomial.
     *
     * @param other right hand side polynomial.
     * @return new polynomial after substuction.
     */
    public PolynomialGTU substract(PolynomialGTU other) {
        int max = 0;
        int min = 0;
        PolynomialGTU maxPol = null;
        PolynomialGTU minPol = null;

        //find max and min polinomials
        if (getSize() >= other.getSize()) {
            maxPol = new PolynomialGTU(this); // max pol
            max = getSize();
            min = other.getSize();
            minPol = other;
        } else {
            maxPol = new PolynomialGTU(other);
            max = other.getSize();
            min = getSize();
            minPol = this;
        }

        int j = 0;

        // find distance and begin substruct number on old polynomial
        for (int i = max - min; i < max; ++i) {
            maxPol.setIndexCoef(i,maxPol.getIndexCoef(i)-minPol.getIndexCoef(j));
            ++j;
        }

        minPol=null;
        return maxPol;

    }


/**
 * Multiplies two polynomial number.
 *
 * @param other rigth hand side polynomial for multiply
 * @return multplicaton of two polynomial
 */
public PolynomialGTU multiply(PolynomialGTU other) {
        int sizeLeftPol = getSize();
        int sizeRightPol = other.getSize();
        int newLength = sizeLeftPol + sizeRightPol - 1; // new length
        double[] newCoef = new double[newLength]; // new coefficients

        // multiply all coeffient in order
        for (int i = 0; i < sizeLeftPol; i++) {
            for (int j = 0; j < sizeRightPol; j++) {
                newCoef[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return new PolynomialGTU(newCoef);
    }

    /**
     * @return string of polynomial
     */
    @Override
        public String toString() {
        String temp = "Polynomial = ";
        for (int i = 0; i < getSize(); ++i) {
            // dont show number, coefficients zero(0)
            if (getIndexCoef(i) != 0) {
                temp += String.format("+(%.2f)(X^%d) ",
                        getIndexCoef(i), getSize() - 1 - i);
            }
        }
        return temp;
    }

    @Override
        /**
         * Take polnomial and compare with our polynomial
         *
         * @param another polynomial
         */
        public boolean equals(Object other) {
        // look if object is polynomial
        if (!(other instanceof PolynomialGTU)) {
            return false;
        }
        // if the same object
        if (other == this) {
            return true;
        }

        // cast object to polynomai
        PolynomialGTU temp = (PolynomialGTU) other;

        int max;
        max = getSize() >= temp.getSize() ? getSize() : temp.getSize();

        // compare all coefficints in order
        for (int i = 0; i < max; ++i) {
            if (getIndexCoef(i) != temp.getIndexCoef(i)) {
                return false;
            }
        }
        return true;
    }
}
