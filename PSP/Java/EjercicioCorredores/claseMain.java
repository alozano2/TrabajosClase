package EjercicioCorredores;

import java.util.ArrayList;

public class claseMain {
    public static int TOTAL_CARRERA = 100;
    public static int TOTAL_CARREDORES = 5;

    public static void main(String[] args) {
        ArrayList<Corredor> listaCorredores = new ArrayList<>();
        ArrayList<Thread> listaHilos = new ArrayList<>();

        /*Object salida = new Object();
        synchronized(salida){
        }*/

        for(int i = 0; i <= TOTAL_CARREDORES; i++){
            listaCorredores.add(new Corredor(TOTAL_CARRERA, i + 1));
            listaHilos.add(new Thread(listaCorredores.get(i)));
        }

        System.out.println("La carrera va a comenzar");

        for(int i = 0; i < listaCorredores.size(); i++){
            listaHilos.get(i).start();
        }

        /*El .join() hace que el hilo que ejecuta el main, espere a que terminen los otros dos hilos
        para después él ejecutar el código que venta por debajo.*/
        for(int i = 0; i < listaHilos.size(); i++){
            try{
                listaHilos.get(i).join();
            }catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        

        System.out.println("La carrera ha terminado.");
    }
}
