import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class clienteUDP {
    public static final int NUMERO_PARAMETROS = 2;
    public static void main(String[] args) {
        int puerto = 0;
        String mensaje = "ERROR AL ENVIAR EL MENSAJE";

        try{
        puerto = Integer.parseInt(args[0]);
        mensaje = args[1];
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ERROR. DEBES INGRESAR DOS PARAMETROS, EL NUMERO DEL PUERTO Y EL MENSAJE.");
            System.out.println("Parametros ingresados " + args.length);
        }

        try {

            DatagramSocket socket = new DatagramSocket();
            InetAddress IPAddress = InetAddress.getByName("192.168.1.148"); // Dirección del servidor
            byte[] sendData = new byte[1024];
            sendData = mensaje.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, puerto);
            socket.send(sendPacket); // Envía el paquete al servidor
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
