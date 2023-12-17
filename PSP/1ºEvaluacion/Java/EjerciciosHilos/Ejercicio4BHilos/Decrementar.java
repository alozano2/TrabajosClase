

public class Decrementar implements Runnable {
    Contador cont;

    public Decrementar (Contador c){
        this.cont = c;
    }

    @Override
    public void run() {
        for(int i = 0; i< ContadorMain.NVECES; i++){
            cont.decrementa();
        }
   
    }
}
