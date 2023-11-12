package EjerciciosHilos.Ejercicio2Hilos;

import java.util.ArrayList;

public class Thread1al10 implements Runnable {
    public static final int NUMERO_MAXIMO = 10;
    private int numero;

    public Thread1al10(int numero) {
        this.numero = numero;
    }
    @Override
    public void run() {
        for(int i = 1; i < NUMERO_MAXIMO; i++){
            for (int f = 0; f < NUMERO_MAXIMO; f++){
                int resultado;
                resultado = i * f;
                System.out.println(i + " * " + f + " = " + resultado);
            }
        }
    }
    
    public static void main(String[] args) {
    
        ArrayList<Thread> thread = new ArrayList<>();

        for(int i = 1; i < NUMERO_MAXIMO; i++){
            Thread1al10 b1 = new Thread1al10(i);
            Thread tb1 = new Thread(b1);
            tb1.setName("Tabla del " + i + ": ");
            thread.add(tb1);
        }
        
        for(int i = 1; i < NUMERO_MAXIMO; i++){
            System.out.println("Soy el hilo " + thread.get(i - 1).getName() + " Empiezo a trabajar.");
            thread.get(i - 1).start();
        }

        for(int i = 1; i < NUMERO_MAXIMO; i++){
            try{
                thread.get(i - 1).join();
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }

    /*Para hacer esto: Ejecuta el comando en la terminal, y vuelca su salida a un fichero. 
        Utiliza las redirecciones de linux y el comando sort para verificar que has escrito
        todas las tablas.
        Habria que:
        -Utilizar redirecciones Linux: java EjerciciosHilos.Ejercicio2Hilos.ModifArray > salida.txt
        -Utilizar sort: sort salida.txt
        Y así, una vez compilado el punto Java, conseguimos sacarlo a un fichero. */
}
