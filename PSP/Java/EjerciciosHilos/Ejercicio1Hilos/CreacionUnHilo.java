package EjerciciosHilos.Ejercicio1Hilos;

/*En este caso, al extender la clase de Thread, no tenemos que convertir el 
    *objeto que creamos a tal clase ya que ya extiende de el. Al extender ya de él,
    *cuenta ya con el método start por si mismo.
*/

public class CreacionUnHilo extends Thread {
    
    @Override
    public void run() {
        System.out.println("Hola mundo extendiendo de Thread!!!");
    }

    public static void main(String[] args) {
        
        CreacionUnHilo b = new CreacionUnHilo();
        b.start();
    }
}
