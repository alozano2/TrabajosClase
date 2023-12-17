package EjerciciosHilos.Ejercicio1Hilos;

/*En este caso, implementamos la interfaz Runnable, la cual por si misma no tiene
 * el metodo start. Por ello, tenemos que instarciar el objeto primero de la clase
 * que implementa Runnable, y a continuacion igualamos esa a un objeto de la clase 
 * Thread, para contar asi con el metodo start().
  */
public class CreacionHiloRunnable implements Runnable {

    @Override
    public void run() {
        System.out.println("Hola Mundo con Runnable!!!!");
    }
    
    public static void main(String[] args) {
        CreacionHiloRunnable b1 = new CreacionHiloRunnable();
        Thread tb1 = new Thread(b1);

        tb1.start();
    }
}
