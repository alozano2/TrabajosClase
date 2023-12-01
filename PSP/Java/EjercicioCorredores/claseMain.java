package EjercicioCorredores;

import java.util.ArrayList;
import java.util.Scanner;

public class claseMain {
    private static final int TOTAL_CARRERA = 100;
    private static final int Corredores = 10;
    private static final int Hilos = 10;
    private static final int START_DORSAL = 1;
    private static final int CUENTA_ATRAS = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Object salida = new Object();
        Corredor[] Arraycorredores = new Corredor[Corredores];
        for (int i = 0; i < Arraycorredores.length; i++) {
            Arraycorredores[i] = new Corredor(TOTAL_CARRERA, START_DORSAL + i, salida);
        }

        Thread[] Arraythreads = new Thread[Hilos];
        for (int i = 0; i < Arraythreads.length; i++) {
            Arraythreads[i] = new Thread(Arraycorredores[i]);
        }


        System.out.println("La carrera va a comenzar");
        for (int i = 0; i < Arraythreads.length; i++) {
            Arraythreads[i].start();
        }
        System.out.println("Pulsa para empezar la carrera.");
        sc.nextLine();
        sc.close();
        for(int i = 10; i>=CUENTA_ATRAS; i--){
            System.out.println(i + "!!!!");
        }
        System.out.println("SALIDA!!!!!!!");
        
        synchronized (salida) {
            try {
                salida.notifyAll();
            } catch (Exception e) {
                System.out.println("Error en la sincronizacion");
            }
        }
        for (int i = 0; i < Arraythreads.length; i++) {
            try {
                Arraythreads[i].join();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("La carrera ha terminado");
    }
}

/*1. Creación de objetos:
    -Se crea un objeto Scanner para la entrada estándar (System.in) para recibir la entrada del usuario.
    -Se instancia un objeto salida de tipo Object, probablemente para sincronización entre hilos.
    -Se crea un array Arraycorredores de objetos Corredor con una longitud Corredores (supongo que es una variable definida previamente).

2. Inicialización de corredores:
    -Se itera sobre Arraycorredores usando un bucle for, creando un nuevo Corredor en cada índice con parámetros TOTAL_CARRERA, START_DORSAL + i y el objeto salida.

3. Creación de hilos:
    -Se crea un array Arraythreads de hilos (Thread) con longitud Hilos (presumiblemente otra variable definida previamente).
    -Se itera sobre Arraythreads usando un bucle for, inicializando cada hilo con un Corredor correspondiente del array Arraycorredores.

4. Inicio de la carrera:
    -Se muestra un mensaje indicando que la carrera está por comenzar.
    -Los hilos de los corredores se inician llamando al método start() en cada hilo en el array Arraythreads.

5. Espera para iniciar la carrera:
    -Se muestra un mensaje para que el usuario inicie la carrera, esperando a que el usuario presione "Enter".
    -El scanner captura la línea siguiente y se cierra después.

6. Cuenta atrás:
    -Se ejecuta un bucle for para contar desde 10 hasta CUENTA_ATRAS (supongo que es una constante definida previamente), imprimiendo cada número como una cuenta regresiva.

7. Inicio de la carrera:
    -Se imprime "SALIDA!!!!!!!" como señal de inicio de la carrera.

8. Sincronización y notificación de los corredores:
    -Se usa una sincronización con el objeto salida para notificar a los corredores que deben comenzar. Se llama al método notifyAll() en el objeto salida.

9. Espera a que los corredores terminen:
    -Se utiliza join() en cada hilo del array Arraythreads para que el hilo principal espere a que todos los hilos de los corredores terminen antes de continuar.

10. Finalización de la carrera:
    -Se imprime un mensaje indicando que la carrera ha terminado. */
