

public class Incrementar implements Runnable {
    Contador cont;

    public Incrementar(Contador c) {
        this.cont = c;
    }

    @Override
    public void run() {
        for (int i = 0; i < ContadorMain.NVECES; i++) {
            cont.incrementa();
        }
    }
}
