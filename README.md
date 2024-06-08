# ExamenFinalSem1

## El problema
Como desarrolladores de software, nos encargaron crear un programa que almacene una base de datos con eventos importantes con sus fechas, y el poder agrgar, eliminar y manejar esos datos con facilidad.
Pero antes de programarlo, debemos buscar y encontrar otras bases de datos, donde podamos sacar esa informacion. 
## Explicacion de base de datos existentes
Antes que nada hay que saber que es una base de datos un conjunto de información perteneciente a un mismo contexto, ordenada de modo sistemático para su posterior recuperación, análisis y transmisión.
### Comparativa 
Teniendo en cuenta las siguientes paginas que son unas bases de datos: 
```
https://es.wikipedia.org/wiki/Wikipedia:Portada
https://www.rae.es/biblioteca-digital
https://dle.rae.es/                            
```
Vemos que cada una tiene un formato para demostrar una base de datos, pero estos estan hechos mas para informar y mostrar al publico sus datos, cada una es distinta, y se dividen en categorias distintas, pero en nuestro caso, solo vamos a hacer una sencilla, y ademas donde el usuario pueda introducir, modificar o mostrar datos, en este caso unas fechas con su respectivo evento. 
### Justificacion de este nuevo desarrollo
Tenemos en cuenta, que el hecho de hacer esto es para poder crear una nueva base de datos, pero que esta almacene tanto fechas importantes, como el evento que acontecio en esta misma, ya que aun que existen bases de datos, no hay una que solo maneje fechas y eventos, aparte, para tener una base de datos de facil acceso y modificacion para el usuario.

## Estructura de repositorio
Dentro del repositorio existiran 2 ramas, al ser 2 personas trabajando dentro de este proyecto, cada rama es para que se pueda mostrar y probar los cambios en el codigo, antes de subirlo al main, y no arruinar el trabajo
## Descripcion de las funciones, estructuras
### FUNCION PRINCIPAL
Inicia el bucle para la pedida de los datos y segun el comando que se pida se llama a las distintas funciones creadas
### FUNCION ES_DIGITO:
Verifica que la fecha este compuesta de solamente numeros
### FUNCION FORMATO_DE_FECHA:
Verifica que la fecha ingresada por el usuario este en el formato que se especifica: que pueda aceptar años negativos, que pueda aceptar el simbolo "+" antes de la fecha, que el mes no sea menor a 0 o mayor a 12, que el mes no sea 
menor a 0 o mayor a 31 y que no se acepte doble guion
### FUNCION REVERSA:
Invierte el orden de los datos en el map
### FUNCION ADD:
Añade los datos introducidos por el usuario al map de base_de_datos
### FUNCION DEL:
Elimina el dato o datos que el usuario desee, si el usuario ingrese una fecha se borran todos los eventos que comparten la misma fecha, en cambio si el usuario ingresa fecha y evento se borra especificamente ese conjunto de la base de datos
### FUNCION FIND:
Busca los eventos de la fecha ingresada por el usuario y los devuelve ordenados de forma ascendente
### FUNCION PRINT:
Imprime todos los datos almacenados en la base de datos, las devuelve ordenadas las fechas de forma ascendente y si en la misma fecha hay eventos diferentes los ordena de forma alfabetica
## Diagrama de flujo
![DIAGRAMA](https://github.com/Soysakiaytuno/ExamenFinalSem1/assets/152195270/207206d1-a875-4c05-b19a-1d7d27cbb1cb)
## CREDITOS
### >Dariana Pol
### >Mijael Callejas

## Herramientas utilizadas
```
Visual Studio
Chat gpt 
Google
Draw.io
PAINT
```
