package Ejercicio2;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;


public class Ejercicio2Servidor {
    public static final int NUMERO_PUERTO = 8765;
    public static final int DATABYTE = 1024;
    public static void main(String[] args) {
        int puerto = NUMERO_PUERTO;
        String message = "";

        try{
            DatagramSocket socket = new DatagramSocket(NUMERO_PUERTO);
            byte [] memoriaRecibida = new byte[DATABYTE];

            while (true) {
                DatagramPacket paqueteRecibido = new DatagramPacket(memoriaRecibida, memoriaRecibida.length);
                socket.receive(paqueteRecibido);

                message = new String(paqueteRecibido.getData(), 0, paqueteRecibido.getLength());
                System.out.println("Mensaje recibido: " + message + ". Lo devuelvo.");

                // Enviar el mensaje de vuelta al cliente
                DatagramPacket sendPacket = new DatagramPacket(paqueteRecibido.getData(), paqueteRecibido.getLength(),
                        paqueteRecibido.getAddress(), paqueteRecibido.getPort());
                socket.send(sendPacket);
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
