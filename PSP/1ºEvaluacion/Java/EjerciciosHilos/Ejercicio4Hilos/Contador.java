/*Este es el codigo del ejercicio contador pero con el cambio que hace que en vez
 * de estar todo el metodo sincronizado, esté solo la variable c. Esto es lo que dice el ejercicio:
 * Modifica la clase Counter anterior para usar un bloque sincronizado en lugar de un método sincronizado.
 * 
 * EXPLICACION GPT:En esta versión, el método increment() no está marcado como synchronized, 
 * pero contiene un bloque synchronized(this). Este bloque asegura que solo un hilo pueda acceder 
 * al código dentro de él a la vez, utilizando el objeto this (la instancia actual de Counter) como 
 * el monitor para la sincronización.
 */

public class Contador implements Runnable {
    private int c = 0;

    public Contador (int c) {
        this.c = c;
    }

    public void incrementa() {
        synchronized(this){
            c++;
        }
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
}
