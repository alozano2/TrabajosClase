/*Crea un programa Java que describa las ips que tiene en ordenador en Windows. (ESTO 
SERIA PONIENDO EL COMANDO DEL EJERCICIO 9, DE LA MISMA FORMA QUE HICE EL 10.
COMO JORGE DIJO QUE ESTO NO ENTRABA, HE USADO EL COMANDO 'WHOAMI' DE LINUX EN SU LUGAR.) */ 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Ejercicio11 {
    public static void main(String[] args) throws IOException {
        String comandos [] = {"whoami"};
        ProcessBuilder pb = new ProcessBuilder(comandos);
        Process proceso = pb.start();
        
        BufferedReader lector = new BufferedReader(new InputStreamReader(proceso.getInputStream()));
        String linea;
        while((linea = lector.readLine()) != null){
            System.out.println(linea);
        }
    }
}