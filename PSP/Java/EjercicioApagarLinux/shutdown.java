package EjercicioApagarLinux;

import java.io.IOException;
import java.util.Scanner;

public class shutdown{
    public static void main(String[] args) throws IOException {
        int eleccion;
        Scanner in = new Scanner(System.in);
        Process apa;

        String [] commandsApagar = {
            "shutdown",
            "-s",
            "now"
        };

        String [] commandsReiniciar = {
            "shutdown",
            "-r",
            "now"
        };

        String [] commandsHibernar = {
            "shutdown",
            "-h",
            "now"
        };

        System.out.println("Elige una opcion: \n1. Apagar.\n2.Reiniciar.\n3.Hibernar");
        eleccion = in.nextInt();

        switch (eleccion) {
            case 1:
                System.out.println("Has decidido apagar el ordenador. Apagando......");
                ProcessBuilder apagar = new ProcessBuilder(commandsApagar);
                apa = apagar.start();
                break;

            case 2:
                System.out.println("Has seleccionado reiniciar el ordenador. Reiniciando......");
                ProcessBuilder reiniciar = new ProcessBuilder(commandsReiniciar);
                apa = reiniciar.start();
                break;
            
            case 3:
                System.out.println("Has seleccionado hibernar. Hibernando.......");
                ProcessBuilder hibernar = new ProcessBuilder(commandsHibernar);
                apa = hibernar.start();
                break;
            default:
                System.out.println("La opcion que has seleccionado no es correcta.");
                break;
        }
    }
}
