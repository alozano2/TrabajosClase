/*Modifica el ejercicio para poder incrementar y decrementar, crea 5 hilos 
que incrementen 1000 veces y 5 que decrementen 1000 veces. Muestra el 
resultado de hacer esta operación con sincronización y sin sincornización. */

public class Contador {
    private int c = 0;

    public Contador (int c) {
        this.c = c;
    }

    
    public void decrementa() {
        synchronized(this){
            c = c - 1;
        }
    }

    public void incrementa() {
        synchronized(this){
            c = c + 1;
        }
    }

    public String toString() {
        return String.valueOf(c);
      }
}
