import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class serverUDP {
    public static void main(String[] args) {
        int puerto = 0;

        try{
            puerto = Integer.parseInt(args[0]);
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ERROR. DEBES INGRESAR UN PARAMETRO, EL NUMERO DEL PUERTO");
            System.out.println("Parametros ingresados " + args.length);
            System.exit(0);
        }

        try {
            DatagramSocket socket = new DatagramSocket(puerto); // Abre el socket en el puerto 9876
            byte[] receivedData = new byte[1024];

            while(true) {
                DatagramPacket receivedPacket = new DatagramPacket(receivedData, receivedData.length);
                socket.receive(receivedPacket); // Espera y recibe el paquete

                // Extrae la información del paquete
                String message = new String(receivedPacket.getData(), 0, receivedPacket.getLength());
                System.out.println("Mensaje recibido: " + message);
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
