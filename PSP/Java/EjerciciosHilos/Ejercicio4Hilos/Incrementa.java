public class Incrementa implements Runnable {
    int c = 0;

    public Incrementa (int c) {
        this.c = c;
    }

    public synchronized void incrementa() {
        c++;
    }

    public void run() {
        for (int i = 0; i < c; i++) {
            incrementa();
            System.out.println(c);
        }
    }
}
