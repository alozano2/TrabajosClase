
import java.io.IOException;

public class Compresor {
    public static void main(String[] args) throws IOException {

        if (args.length < 2) {
            System.out.println("Uso: java Compresor <nombre_del_archivo_salida> <archivos_a_comprimir>");
            return;
        }

        String nombreArchivo = "";
        nombreArchivo = args[1].replace("/", "_") + "_2023_10_31";

        String [] commands = {
            "tar",
            "-czvf",
            nombreArchivo,
            args[1]
        };

        for(int i = 0; i < args.length; i++){
            ProcessBuilder compresor = new ProcessBuilder(commands);
            Process p = compresor.start();
        }
    }
}

