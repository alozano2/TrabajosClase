public class PrincipalThread {
    public static void main(String[] args) {
        HolaThread ta = new HolaThread("Alice", 7);
        HolaThread tb = new HolaThread("Boby", 12);
        
        Thread exeTa = new Thread(ta);
        Thread exetb = new Thread(tb);

        exeTa.start();
        exetb.start();
    }
}
