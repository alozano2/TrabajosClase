package EjerciciosHilos;

public class EjemploThread implements Runnable {

    public void run() {
        System.out.println("¡Como molan los threads joderrrrrr!");
    }

    public static void main(String[] args) throws InterruptedException {
        EjemploThread myThread = new EjemploThread();
        Thread myThread2b = new Thread(myThread);
        myThread2b.start();

        System.out.println("A ver que tal funcionan estos threadsssssss......");

        HolaThread thread2 = new HolaThread("Alvaro", 6);
        Thread thread2b = new Thread(thread2);
        thread2b.start();
        thread2b.sleep(3000);
        boolean estaVivo = thread2b.isAlive();
        System.out.println(estaVivo);
    }   
}
