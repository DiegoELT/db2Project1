# Introducción
Proyecto de base de datos II sobre organización de archivos en C++ con Qt para la visualización.

# Alcance
- Datos a usar (buscar en kaggle): 
- Poder organizar 2 CSV (unidos por un key) mediante 3 tipos de organización de archivos.
- Inserción y búsqueda usando Random File.
- Inserción y búsqueda usando Static Hashing.
- Inserción y búsqueda usando Dynamic Hashing.
- [EXTRA] Ejecutar un join.

# Formato
- Case Style: camelCase para variables, PascalCase para clases y headers, snake_case para nombres de files.
- Identación: 
if (true) {

}

# Headers

## Record
Tenemos una clase Record para hacer lo básico:
- Funct Set Data
- Funct Show Data
- Funct Write y Read
- Var Key

### RecordA
Detalles del record de la FileA

### RecordB
Detalles del record de la FileB

## FileOrganization
Tenemos una clase base FileOrganization que acepta templates de Record (para pasarle cualquier objeto que sea record).
- file Name
- Constructor y Destructor (guarda index)
- Insertion
- Search
- Scan (int n) o Scan (), determina cuántas filas mostrar.

### RandomFile
Implementación de RandomFile

### HashFile
Implementación de Hash File. Función Hash puede ser un parámetro.

#### Static Hash File
Implementación de Static Hash

#### Dynamic Hash File
Implementación de Dynamic Hash

## Otros
Contiene funciones para: 
- Read Strings
- Write Strings
