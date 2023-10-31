import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Ejemplo {
    public static void main(String[] args) throws IOException, InterruptedException {
        //ProcessBuilder es como la fabrica de procesos.
        ProcessBuilder pb = new ProcessBuilder("xed");

        //Process es para controlar un proceso ya creado
        Process p = pb.start();

        BufferedWriter bf = new BufferedWriter(
            new OutputStreamWriter(
                (p.getOutputStream())));
        
        bf.write("9\n");
        bf.flush();
        bf.close();

        
        /*for(int i = 0; i < args.length; i++){
            pb.start();
        }*/
        //p.waitFor();

        System.out.println("Se ha terminado");
    }
}
