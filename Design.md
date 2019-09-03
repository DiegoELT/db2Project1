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
- Case Style:
- Identación:

# Headers

## Record
Tenemos una clase Record para hacer lo básico:
- Funct Set Data
- Funct Show Data
- Var Key
Por herencia, sacamos dos clases de Record (una por cada archivo):
- RecordA
- RecordB
(agregar un nombre más descriptivo).

## FileOrganization
Tenemos una clase base FileOrganization que acepta templates de Record (para pasarle cualquier objeto que sea record).
- file Name
- Constructor y Destructor (guarda index)
- Insertion
- Search
- Scan (int n) o Scan (), determina cuántas filas mostrar.

### RandomFile
### HashFile
#### Static Hash File
#### Dynamic Hash File

## Otros
Contiene funciones para: 
- Read Strings
- Write Strings
