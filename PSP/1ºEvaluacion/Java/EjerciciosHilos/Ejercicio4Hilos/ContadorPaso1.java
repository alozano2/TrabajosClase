/*ESTE ES EL CODIGO DEL EJERCICIO QUE PIDE: Crea una clase Counter con un método sincronizado 
increment que incremente una variable count. Crea dos hilos que incrementen el contador y 
observa el resultado. */

/*public class Contador implements Runnable {
    private int c = 0;

    public Contador (int c) {
        this.c = c;
    }

    public synchronized void incrementa() {
        c++;
    }

    public int getC (){
        return c;
    }

     @Override
    public void run() {
        for(int i = 0; i <= c; i++){
            System.out.println(i);
        }
    }
    public static void main(String[] args) {
        Contador c1 = new Contador(100);
        Contador c2 = new Contador(100);

        Thread tb_c1 = new Thread(c1);
        tb_c1.setName("Hilo 1.");
        Thread tb_c2 = new Thread(c2);
        tb_c2.setName("Hilo 2");
        System.out.println("Soy el " + tb_c1.getName() + ". Empiezo.");
        tb_c1.start();
        System.out.println("Soy el " + tb_c2.getName() + ". Empiezo.");
        tb_c2.start();

        try {
            tb_c1.join();
            tb_c2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    }
} */
