package EjerciciosHilos.Ejercicio1Hilos;

/*En este caso, al ser Runnable una interfaz que solo tiene un método,
 * podemos implementarla mediante un lambda en el propio main.
 */
public class CreacionHiloConLambda {

    public static void main(String[] args) {

        Runnable b1 = () -> {
        System.out.println("Hola mundo con lambda!!");
        };

        Thread tb1 = new Thread(b1);
        tb1.start();

    }
}
