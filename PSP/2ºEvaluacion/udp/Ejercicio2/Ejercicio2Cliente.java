package Ejercicio2;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Ejercicio2Cliente {
    public static final int DATABYTE = 1024;
    public static final int NUMERO_PUERTO = 8765;
    public static void main(String[] args) {
        int puerto = NUMERO_PUERTO;
        String mensaje = "Hola buenos dias.";

        try{
        DatagramSocket socket = new DatagramSocket();
        InetAddress direccionIp = InetAddress.getByName("10.0.2.15");
        byte[] memoriaEnvio = new byte[DATABYTE];
        memoriaEnvio = mensaje.getBytes();

        DatagramPacket paqueteEnvio = new DatagramPacket(memoriaEnvio, memoriaEnvio.length, direccionIp, puerto);
        socket.send(paqueteEnvio);
        System.out.println("Mensaje enviado");
        
        byte[] receivedData = new byte[DATABYTE];
        DatagramPacket paqueteRecibido = new DatagramPacket(receivedData, receivedData.length);
        socket.receive(paqueteRecibido);
        String message = new String(paqueteRecibido.getData(), 0, paqueteRecibido.getLength());
        System.out.println("Mensaje recibido: " + message);

        }catch(Exception e){
            e.printStackTrace();
        }
    } 
}
