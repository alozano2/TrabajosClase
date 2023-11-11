package EjerciciosHilos.Ejercicio1Hilos;

public class MetodoPrincipal {
    public static void main(String[] args) {
        //Extendiendo Thread
        CreacionUnHilo extiendaThread = new CreacionUnHilo();
        extiendaThread.start();

        //Implentando Runnable
        CreacionHiloRunnable implementaRun = new CreacionHiloRunnable();
        Thread tImplementaRun = new Thread(implementaRun);
        tImplementaRun.start();

        //Con metodo lambda
        Runnable b1 = () -> {
            System.out.println("Thread con lambda en clase principal.");
        };
        Thread tb1 = new Thread(b1);
        tb1.start();
    }
}
