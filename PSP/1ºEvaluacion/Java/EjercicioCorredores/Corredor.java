package EjercicioCorredores;

public class Corredor implements Runnable{
    private static final long TIEMPO_DESCANSO = 500;
    private static final double MAX_INTERVALO_KM = 10;
    int kmRecorrido;
    int kmTotales;
    int dorsal;
    Object salida;

    public Corredor(int kmTotales, int dorsal, Object salida) {
        this.kmTotales = kmTotales;
        this.dorsal = dorsal;
        this.kmRecorrido = 0;
        this.salida = salida;
    }

    public void run() {

        synchronized (salida) {
            try {
                salida.wait();
            } catch (Exception e) {
                System.out.println("Error en la sincronizacion");
            }
        }

        System.out.println(String.format("Soy el dorsal %d inicio mi carrera", dorsal));
        while (kmRecorrido < kmTotales) {
            try {
                long descanso = (long) (Math.random() * TIEMPO_DESCANSO + TIEMPO_DESCANSO);
                Thread.sleep(descanso);
                System.out.println(String.format("Soy el dorsal %d he descansado: %d", dorsal, descanso));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            kmRecorrido += Math.random() * MAX_INTERVALO_KM;
            System.out.println(
                    String.format("Soy el dorsal %d he recorrido: %d de: %d!!", dorsal, kmRecorrido, kmTotales));
        }
        System.out.println(String.format("Soy el dorsal %d Termine!!", dorsal));

    }
}

/*1. Atributos:

TIEMPO_DESCANSO: Constante que define el tiempo máximo de descanso.
MAX_INTERVALO_KM: Constante que define la distancia máxima que puede recorrer el corredor en un intervalo.
kmRecorrido: La distancia recorrida por el corredor.
kmTotales: La distancia total que el corredor debe recorrer.
dorsal: Número de identificación del corredor.
salida: Objeto utilizado para la sincronización entre corredores.

2. Constructor:
Inicializa los atributos kmTotales, dorsal, kmRecorrido, y salida.

3. Método run():
Utiliza sincronización con el objeto salida para esperar la señal de inicio de carrera.
Cuando se recibe la señal, el corredor muestra un mensaje de inicio de carrera.
En un bucle, simula el descanso aleatorio y muestra el progreso del corredor.
Calcula la distancia recorrida y la muestra.
Cuando el corredor alcanza la distancia total, muestra un mensaje de finalización.
*/

//gcc -o tal cual -lssl -lcrypto
