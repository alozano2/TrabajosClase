package EjerciciosHilos.Ejercicio3Hilos;

import java.util.Random;

public class LosElefantes implements Runnable {
    private String animal;
    private String accion;
    private static int numeroMaximo;
    private int contador;

    public LosElefantes (String animal, String accion, int numeroMaximo) {
        this.animal = animal;
        this.accion = accion;
        this.numeroMaximo = numeroMaximo;
    }

    @Override
    public void run() {

        for(contador = 1; contador <= numeroMaximo; contador++){
            int numeroAleatorio = numeroAleatorio(100000 , 300000);

            System.out.println(contador + " " + animal + " se " + accion + " sobre la tela de una araña\n" + 
            "Como veía que resistía, fue a llamar otro " + animal);

            if(esPrimo(numeroAleatorio) == true){
                System.out.println("El numero aleatorio " + numeroAleatorio + " es primo.");
            }else{
                System.out.println("El numero aleatorio " + numeroAleatorio + " NO es primo.");
            }

            try{
                Thread.sleep(1000);
            }catch (InterruptedException e){
                e.getMessage();
            }

        }
    }

    public int numeroAleatorio (int min, int max) {
        Random random = new Random();
        return random.nextInt(max - min + 1) + min;
    }

    public boolean esPrimo (int numero) {
        for (int i = 2; i <= Math.sqrt(numero); i++) {
            if (numero % i == 0) {
                return false; // Si es divisible por algún número en este rango, no es primo
            }
        }
    
        return true;
    }
    
    public static void main(String[] args) {
        LosElefantes leon = new LosElefantes("leon", "helaba", 6);
        LosElefantes cabra = new LosElefantes("cabra", "encabritaba", 3);
        LosElefantes araña = new LosElefantes("araña", "añaraba", 9);
        
        Thread tLeon = new Thread(leon);
        Thread tCabra = new Thread(cabra);
        Thread tAraña = new Thread(araña);
        
        tLeon.setPriority(Thread.NORM_PRIORITY);
        tCabra.setPriority(Thread.MAX_PRIORITY);
        tAraña.setPriority(Thread.MIN_PRIORITY);

        tLeon.start();
        tCabra.start();
        tAraña.start();
    }
}
