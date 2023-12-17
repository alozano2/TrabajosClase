public class MainBanco {
    public static void main (String args[]){
        Transferencia c = new Transferencia(0);
        Thread bob = new Thread (new RealizadorTransferencia(c));
        Thread alice = new Thread (new RealizadorTransferencia(c));

        bob.start();
        alice.start();

        try{
            bob.join();
            alice.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }

        System.out.println(String.format("El contenido de la cuenta es: %s", c));
    }
}
