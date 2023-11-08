public class HolaThread implements Runnable{

    private String nombre;
    private int veces;
    

    public HolaThread(String nombre, int veces) {
        this.nombre = nombre;
        this.veces = veces;
    }

    @Override
    public void run() {
        for(int i = 0; i < veces; i++){
            System.out.println(nombre);
        }

    }
   
}
