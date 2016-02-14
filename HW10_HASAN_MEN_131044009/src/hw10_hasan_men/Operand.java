package hw10_hasan_men;

/**
 *
 * Matematiksel ifadelerdeki sayilari tutmak icin kullanilacak.
 * Suan icin sadece int olarak kaydetme yapilabilir.
 * @author Hasan
 */
public class Operand extends Expression{
    
    private int f_operand;
    /**
     * Tek parametreli constructor
     * @param op atanacak deger
     */
    public Operand(int op){
        f_operand = op;
    }
    
    /**
     * @return Operandin degerini return eder
     */
    public int getOperand(){
        return f_operand;
    }
    
    /**
     * Operandi set ekmek icin kullanilir.
     * @param newValue Yeni operand degeri
     */
    public void setOperand(int newValue){
        f_operand = newValue;
    }
    
    /**
     * Integer olan degeri ekrana string olarak return edecektir.
     */
    @Override
    public String toString(){
        return String.format(" %d" ,f_operand);
    }
    
}
