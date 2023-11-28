/*Modifica el ejercicio para poder incrementar y decrementar, crea 5 hilos que incrementen 
1000 veces y 5 que decrementen 1000 veces. Muestra el resultado de hacer esta operación con 
sincronización y sin sincornización. */

public class Modificacion04a {
    public static void main(String[] args) {
        Incrementa tb1 = new Incrementa(1000);
        Incrementa tb2 = new Incrementa(1000);
        Incrementa tb3 = new Incrementa(1000);
        Incrementa tb4 = new Incrementa(1000);
        Incrementa tb5 = new Incrementa(1000);

        Thread tb_c1 = new Thread(tb1);
        tb_c1.setName("Hilo 1");
        System.out.println("Soy el " + tb_c1.getName() + ". Empiezo...");
        tb_c1.start();
        Thread tb_c2 = new Thread(tb2);
        tb_c2.setName("Hilo 2");
        System.out.println("Soy el " + tb_c2.getName() + ". Empiezo...");
        tb_c2.start();
        Thread tb_c3 = new Thread(tb3);
        tb_c3.setName("Hilo 3");
        System.out.println("Soy el " + tb_c3.getName() + ". Empiezo...");
        tb_c3.start();
        Thread tb_c4 = new Thread(tb4);
        tb_c4.setName("Hilo 4");
        System.out.println("Soy el " + tb_c4.getName() + ". Empiezo...");
        tb_c4.start();
        Thread tb_c5 = new Thread(tb5);    
        tb_c5.setName("Hilo 5");    
        System.out.println("Soy el " + tb_c5.getName() + ". Empiezo...");
        tb_c5.start();

        try {
            tb_c1.join();
            tb_c2.join();
            tb_c3.join();
            tb_c4.join();
            tb_c5.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    }
}


