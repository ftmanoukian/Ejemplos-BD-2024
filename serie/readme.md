# Ejemplo de comunicación entre Python y Arduino a través de puerto serie

## Archivos en esta carpeta
* ```programa_py.py```: Programa que correrá en la computadora.
* ```programa_arduino/programa_arduino.ino```: Programa que debe subirse al Arduino.

## Funcionamiento del ejemplo
### Python
El archivo de Python transmite un dato determinado a través del puerto serie, utilizando los módulos ```struct``` para convertir la información desde Python a un formato comprensible por el Arduino, y ```serial``` para transmitir dicha información a través del puerto serie.

### Arduino
El Arduino, si detecta que hay información disponible en el puerto serie, lee la cantidad de Bytes correspondiente al tipo de dato establecido en el programa y los almacena en el Struct. Luego, en base al estado de la variable ```estado_led``` decide si encender o apagar el LED.

## Factos
### ¿Qué es un struct?
El _struct_ es un concepto heredado del lenguaje de programación *C*. Su función es organizar uno o más datos de forma contigua en memoria. 

En este caso, vamos a aprovecharlo para _ordenar_ los datos que viajan entre la PC y el Arduino.

### ¿Para qué sirve en Python?
Python, siendo un lenguaje de alto nivel, nos abstrae de lo que pasa dentro de la compu