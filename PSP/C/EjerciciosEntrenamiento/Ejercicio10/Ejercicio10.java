/*Crea un programa Java que describa
 las ips que tiene en ordenador en linux */

import java.io.IOException;

public class Ejercicio10 {
    public static void main(String[] args) throws IOException{
        ProcessBuilder procces = new ProcessBuilder("ip", "a");
        Process proceso = procces.start();
    }
}