# ¿Qué es un HashMap?
Un HashMap es una estructura de datos que almacena pares clave-valor, permitiendo un acceso rápido a los valores a través de una clave única.

# Creación de un HashMap en Java:
HashMap<String, Integer> miHashMap = new HashMap<>();

# Operaciones comunes en un HashMap en Java:
## Agregar Elementos:
    miHashMap.put("clave", valor);
## Obtener un valor a través de una clave:
    Integer valor = miHashMap.get("clave");
## Verificar si una clave existe:
    Boolean existe = miHashMap.containsKey("clave");
## Eliminar un elemento:
    miHashMap.remove("clave");
## Recorrer un HashMap
    for (String clave : miHashMap.keySet()) {
    Integer valor = miHashMap.get(clave);
    // Haz algo con la clave y el valor
    }
## Tamaño del HashMap:
    int size = miHashMap.size();

## Notas importantes:
   - En un HashMap, las claves deben ser únicas.
   - Los valores pueden ser duplicados.
   - La eficiencia de un HashMap depende en gran medida de la función hash utilizada y del factor de carga.

    
