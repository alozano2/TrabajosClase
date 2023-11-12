package EjercicioCorredores;

public class Corredor implements Runnable{
    public static final long TIEMPO_DESCANSO = 500;
    private static final double MAX_INTERVAL_KM = 10;
    int kmRecorridos;
    int kmTotales;
    int dorsal;

    public Corredor(int kmTotales, int dorsal) {
        this.kmTotales = kmTotales;
        this.dorsal = dorsal;
        this.kmRecorridos = 0;
    }

    @Override
    public void run() {
        System.out.println(String.format("¡¡Soy el dorsal %d inicio mi carrera!!", dorsal));

        while(kmRecorridos < kmTotales){
            try {
                Thread.sleep((long) ((Math.random()*TIEMPO_DESCANSO) + TIEMPO_DESCANSO));
                System.out.println(String.format("Soy el dorsal %d DESCANSANDO...zzZ", dorsal));
                System.out.println(String.format("%d/%d", kmRecorridos,kmTotales));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            kmRecorridos += Math.random() * MAX_INTERVAL_KM;

        }
        System.out.println(String.format("Soy el dorsal %d TERMINÉ", dorsal));
    }

    
}
