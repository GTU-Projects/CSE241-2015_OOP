package hw10_hasan_men;

/**
 * Daha anlasilir exceptionlar firlatmak icin kullanilacaktir.
 * @author Hasan
 */
public class HmennExceptions extends Exception {
    private String message;
    public HmennExceptions(){
        message = "Undefined error!!!";
    }
    
    public HmennExceptions(String error){
        message = "Error =" + error;
    }
    @Override
    public String toString(){
        return String.format(message);
    }
}
