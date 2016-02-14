package hw10_hasan_men;

import java.util.ArrayList;

/**
 * @version 1.1
 * @author Hasan
 */
public class Expression {

    //Operator, operand ve parantezleri tutacaktir.
    // ArrayList daha seri islem yapmak icin secilmistir.
    private ArrayList<Expression> elements;

    /**
     * ArrayListin icinde parantez icermeyen araliklari cozer. Onceligi en buyuk
     * operatoru bulup sag ve sol tarafini isleme alir. Islem sonunda arrayList
     * guncellenir. Eskiler silinip sonuc eklenir. --- A + B olan liste C ye
     * donusur.
     *
     * @param start baslangic noktasi
     * @param end bitis noktasi
     * @throws Exception Kendi exceptionlarimi firlatacam
     * @return Islem sonucunu hem arraya ekler hem return eder.
     *
     * baslangic noktasi sabittir. Islem yapildikca aralik kuculur. 9+5*4-3
     * sirayla 9+20-3 = 29-3 = 26 olur. | | | | | | | | | | | | | --Baslangic 0
     * bitis 0. | | | | ----------Baslangic 0 bitis 2. | |
     * --------------------Baslangic 0 bitis 4.
     * ------------------------------------Baslangic 0 bitis 6.
     */
    private Expression solvePure(int start, int end) throws Exception {

        // Bitis baslangica esit olana kadar islem yapilir.
        while (end - start != 0) {
            System.out.println(this);
            Operator tempOp;
            int prior = -1;
            int index = 0;
            for (int i = start; i <= end; ++i) {
                // operatorleri bul
                if (elements.get(i) instanceof Operator) {
                    tempOp = (Operator) elements.get(i);
                    // opetorun onceligine bak
                    int newPriority = tempOp.getOpPrecedence();
                    // en buyuk oncelikli olani bul
                    if (prior < newPriority) {
                        index = i;
                        prior = newPriority;
                    }
                }
            }

            // hatali ifade varsa uyari firlat
            if (prior == -1) {
                throw new HmennExceptions("Operator failed.Add an operator"
                        + "Between numbers!!!");
            }

            Operand left;
            Operand right;
            // + 8 9 DURUMUNDA SOLA BAKIP ARRAY DISINA CIKMAMASI LAZIM
            if (index > 0 && elements.get(index - 1) instanceof Operand) {
                left = (Operand) elements.get(index - 1);
            } else {
                throw new HmennExceptions("Operator failed. Left operand must be a number!!!");
            }

            // 4 9 + DURUMUNDA SAGA BAKIP ARRAY DISINA CIKMAMASI LAZIM
            if (index + 1 < elements.size() && elements.get(index + 1) instanceof Operand) {
                right = (Operand) elements.get(index + 1);
            } else {
                throw new HmennExceptions("Operator failed. Rigth operand must be a number!!!");
            }

            // gecerli bir operator olup olmamasina yukarida bakildi.Bir daha
            // instanceof a gerek yok
            tempOp = (Operator) elements.get(index);

            //sag ve sol operandlar operator ile isleme sokuldu.
            Operand newValue = tempOp.evaluateOperator(left.getOperand(), right.getOperand(), tempOp);

            // sol eleman yeni sonuc ile guncellendi.
            //Operator ve sag elemanda silindi.
            addResult(index, newValue);

            end = end - 2; // aralik 2 azaldi.
        }
        // en son guncellenen eleman sonuctur.Return edilir.
        return elements.get(start);
    }

    /**
     *
     * Bu method indexlenen yeri gunceller. 5 + 7 | | | | | -- sag silinecek |
     * ---- index silinecek ------ sol eleman guncellenecek
     *
     * @param index where temp will add
     * @param temp guncellenecek obje
     */
    private void addResult(int index, Expression temp) {

        elements.set(index - 1, temp);
        elements.remove(index); // operatoru sil
        elements.remove(index); // operator silinince olan yere right saiysi geldi

    }

    /**
     * Bu method aldiği karmasik ifadeleri ufak parcalara ayirarak cozer.
     * Parantez varsa en ictekini bularak orayi hesaplar ve genisler.
     *
     * (3+4*(5+2)) | | ------- Once bu aralik bulunur ve solvePure methodu ile
     * hesaplanir. (3+4*7) | | ------------- Arasi isleme sokulur ve son sunuc
     * arrayin ilk elemaninda yer alir.
     *
     * @throws Exception mainde handle edilmesi lazim.
     */
    /**
     * Expression arrayinin icindeki gecerli olabilecek parantezleri sayar
     * Kapanmayan parantez durumunda -1 return edecek
     *
     * @return Gecerli parantez sayisi
     */
    private int numOfParanthesis() throws Exception {
        int openParan = 0;
        int closeParan = 0;

        for (Expression items : elements) {
            if (items instanceof Paranthesis) {
                Paranthesis temp = (Paranthesis) items;
                if (temp.getParanthesis() == '(') {
                    ++openParan;
                } else {
                    ++closeParan;
                }
            }
        }
        if (openParan != closeParan) {
            throw new HmennExceptions("Paranthesis didn't closed/opened!!!");
        }

        return openParan;
    }

    /**
     * Parametre almayan constructor'dur. Bos bir ArrayList olusturur.
     */
    public Expression() {
        elements = new ArrayList<>();
    }

    /**
     * Kendisine gelen inputu kontrol ederek tipine bakar. Tanimli bir eleman
     * ise arrayListimeze ekler. Gecersiz durumlarda exception firlatir.
     *
     * @param newElem ArrayListe eklenilmesi istenilen eleman.
     * @throws Exception Kendi exception sinifimi ve java exceptionlarini
     * tutacam.
     */
    public void addElement(String newElem) throws Exception {

        // Gelen ifade parantez ise
        if (newElem.equals("(") || newElem.equals(")")) {
            Paranthesis temp = new Paranthesis(newElem.charAt(0));
            elements.add((Expression) temp);
            // gelen ifade bir operator ise
        } else if (newElem.equals("+") || newElem.equals("-")
                || newElem.equals("*") || newElem.equals("/")
                || newElem.equals("^")) {
            Operator temp2 = new Operator(newElem.charAt(0));
            elements.add((Expression) temp2);
        } else { // gelen ifade integer ise
            // integer olmamasi yada gecersiz bir durumda Java otomatik 
            // exception firlatacak ve tutulacak.
            Operand temp3 = new Operand(Integer.parseInt(newElem));
            elements.add((Expression) temp3);
        }
    }

    @Override
    /**
     * ArrayListimizdeki her eleman icin cikti return edecektir. Her elemanin
     * toString methodlarindan polymorfik cagri ile faydalani.r
     */
    public String toString() {
        String output = "";
        for (Expression next : elements) {
            output += next;
        }
        return String.format("%s", output);
    }

    /**
     * Fields olan arrayi birimlerine ayirarak parantezleri bulur. Parantez
     * olmasi durumanda iki parantez arasini pure olarak isaretler ve solvePure
     * fonksiyonuna yollar. Gerkeli sade islemler orada yapilir. Parantez ve
     * icinde sayi kalinca parantezler siliniz ve tekrardan parantez kontrolu
     * yapilarak en sade donusturmeye dogru gidilir
     *
     * @throws Exception Olasi islem hatalari mainde tutulacak
     */
    public void solve() throws Exception {

        // parantezler tamsa
        while (numOfParanthesis() > 0) {

            int openParan = 0;
            int closeParan = elements.size();
            boolean paranDone = false;

            for (int i = 0; i < elements.size(); ++i) {
                if (!paranDone) {
                    if (elements.get(i) instanceof Paranthesis) {
                        Paranthesis temp = (Paranthesis) elements.get(i);
                        if (temp.getParanthesis() == '(') {
                            openParan = i;
                        } else {
                            closeParan = i;
                            paranDone = true;
                        }
                    }
                }
            }

            // gormek amacli parantezleride bas
            System.out.println(this);
            System.out.println("Paranthesis openIndex :" + openParan + " "
                    + "\nParanthesis closeIndex :" + closeParan + "\n");

            // parantez iclerini cozuyoruz
            Expression result = solvePure(openParan + 1, closeParan - 1);
            addResult(openParan + 1, result);
        }
        // en son kalan islem cozulur
        solvePure(0, getSize() - 1);
    }

    /**
     * Aldigi index gecerli ise ona denk elemani dondurur.
     *
     * @param index Getirilmesi istenen index
     * @throws HmennExceptions Olasi indis disi exceptionlari firlatir
     */
    public Expression getElement(int index) throws HmennExceptions {
        if (index < 0 && index >= getSize()) {
            throw new HmennExceptions("Invalid index for get element");
        }
        return elements.get(index);
    }

    /**
     * Expressionun eleman sayisini return eder.
     */
    public int getSize() {
        return elements.size();
    }

    /**
     * 2 tane expresionu karsilastirir. Tum elemanlari tek tek karsilastirir.
     * Sonuc odakli degildir.
     *
     * @param other Karsilatrilacak diger expression
     * @return true or false
     * @throws HmennExceptions Hata olmayabilir ama syntax geregi yazildi
     */
    public boolean equals(Expression other) throws HmennExceptions {

        if (getSize() != other.getSize()) {
            return false;
        }

        // tum elemanlar dynamic cast ile belirlenir
        for (int i = 0; i < getSize(); ++i) {
            if (getElement(i) instanceof Operand && other.getElement(i) instanceof Operand) {
                Operand a1 = (Operand) getElement(i);
                Operand a2 = (Operand) other.getElement(i);
                if (a1.getOperand() != a2.getOperand()) {
                    return false;
                }
            } else if (getElement(i) instanceof Operator && other.getElement(i) instanceof Operator) {
                Operator b1 = (Operator) getElement(i);
                Operator b2 = (Operator) other.getElement(i);
                if (b1.getOperator() != b2.getOperator()) {
                    return false;
                }

            } else if (getElement(i) instanceof Paranthesis && other.getElement(i) instanceof Paranthesis) {
                Paranthesis c1 = (Paranthesis) getElement(i);
                Paranthesis c2 = (Paranthesis) other.getElement(i);
                if (c1.getParanthesis() != c2.getParanthesis()) {
                    return false;
                }

            } else {
                return false;
            }
        }
        return true;
    }

    public void addStr(String line) throws Exception {

        String temp = "";
        int start = 0;
        int end = line.length() - 1;
        boolean findNum = false;

        for (int i = 0; i < line.length(); ++i) {
            if (Operator.isOperator(line.charAt(i))) {
                if (!temp.isEmpty()) {
                    addElement(temp);
                    temp = "";
                }
                addElement(line.substring(i, i + 1));
            } else if (Paranthesis.isParanthesis(line.charAt(i))) {
                if (!temp.isEmpty()) {
                    addElement(temp);
                    temp = "";
                }
                addElement(line.substring(i, i + 1));
            } else if (Character.isDigit(line.charAt(i))) {
                temp += Character.toString(line.charAt(i));
            }
        }
        if (!temp.isEmpty()) {
            addElement(temp);
        }
    }
}
