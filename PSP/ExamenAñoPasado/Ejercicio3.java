import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Ejercicio3 {
    private static final int POSICION_USO_MEMORIA = 3;

    public static void main(String[] args) {
        //Compruebo que haya ingresado el parametro
        if(args.length != 1){
            System.out.println("Debe ingresar un parametro con un nombre");
        }

        String nombre = args[0];
        String commands [] = {"ps", "aux"};
        try{
            ProcessBuilder constructorProceso = new ProcessBuilder(commands);
            Process proceso = constructorProceso.start();

            BufferedReader reader = new BufferedReader(new InputStreamReader(proceso.getInputStream()));
            String linea;

            // Mostrar la cabecera
            if ((linea = reader.readLine()) != null) {
                System.out.println(linea);
            }

            // Filtrar y mostrar procesos del usuario que consumen más del 0.0 de memoria
            while ((linea = reader.readLine()) != null) {
                String[] infoProceso = linea.split("\\s+"); // Dividir la línea por espacios en blanco

                // Comprobar si la línea pertenece al usuario indicado y tiene más del 0.0 de memoria
                if (infoProceso.length > POSICION_USO_MEMORIA && infoProceso[0].equals(nombre) && Double.parseDouble(infoProceso[3]) > 0.0) {
                    System.out.println(linea);
                }
            }

            reader.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}

/*Explicacion del programa:
    * 1.Verificación del parámetro de entrada:
    El programa espera que se le pase un nombre como argumento al ejecutarse (args[0]). 
    Si no se proporciona un argumento, muestra un mensaje indicando que se debe ingresar un 
    parámetro con un nombre.

        if(args.length != 1){
                System.out.println("Debe ingresar un parametro con un nombre");
        }

    
    * 2. Recuperación del nombre de usuario:
    Toma el nombre proporcionado como parámetro (args[0]) y lo guarda en la variable nombre.
    
    * 3. Definición del comando a ejecutar:
    Define el comando que se ejecutará como un arreglo de strings. En este caso, el comando es 
    ps aux, que se usa para obtener información sobre los procesos en ejecución.

        String commands [] = {"ps", "aux"};
        ProcessBuilder constructorProceso = new ProcessBuilder(commands);
    
    
    * 4. Inicio del proceso ps aux:
    Crea un nuevo proceso con el comando ps aux usando ProcessBuilder.
    Obtiene el flujo de entrada del proceso para poder leer su salida.

        Process proceso = constructorProceso.start();
   
    
    * 5. Lectura de la salida del proceso:
    Lee la primera línea de salida (la cabecera de la tabla de procesos) y la muestra por consola.

        BufferedReader reader = new BufferedReader(new InputStreamReader(proceso.getInputStream()));
        String linea;
    
    * 6. Filtrado y visualización de procesos del usuario con memoria consumida:
    Lee las líneas restantes (la información de los procesos) una por una.
    Divide cada línea en campos individuales usando split("\\s+"), que divide la línea por espacios en blanco.
    Verifica si la línea pertenece al usuario indicado (infoProceso[0].equals(nombre)) y si tiene más de 0.0 de memoria consumida (Double.parseDouble(infoProceso[3]) > 0.0).
    Si la línea cumple con estas condiciones, la muestra por consola.
        
        while ((linea = reader.readLine()) != null) {
                String[] infoProceso = linea.split("\\s+"); // Dividir la línea por espacios en blanco

                // Comprobar si la línea pertenece al usuario indicado y tiene más del 0.0 de memoria
                if (infoProceso.length > POSICION_USO_MEMORIA && infoProceso[0].equals(nombre) && Double.parseDouble(infoProceso[3]) > 0.0) {
                    System.out.println(linea);
                }
        }

    * 7. Cierre del flujo de lectura:
    Finalmente, cierra el BufferedReader utilizado para leer la salida del proceso.
 */
