/*Crea un programa Java que describa
 las ips que tiene en ordenador en linux */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Ejercicio10 {
    public static void main(String[] args) throws IOException{
        String[] comandos = {"ip", "a"};
        ProcessBuilder pb = new ProcessBuilder(comandos);
        Process proceso = pb.start();

        // Lee la salida del proceso
        BufferedReader reader = new BufferedReader(new InputStreamReader(proceso.getInputStream()));
        String linea;
        while ((linea = reader.readLine()) != null) {
            System.out.println(linea);
        }
    }
}