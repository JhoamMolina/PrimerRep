# REGISTRO DE LOS EJERCICIOS REALIZADOS DEL CAPÍTULO 5

### Ejercicio 01:

Ambos procesos modifican su propia copia de la variable X

* [Ejercicio_01](punto1.c)

```
gcc punto1.c -o punto1 && ./punto1
```

### Ejercicio 02:

Al ambos procesos acceder al archivo y editarlo a la misma vez, estos estaràn sobreescribiendo lo que el anterior a escrito.

* [Ejercicio_02](punto2.c)

```
gcc punto2.c -o punto2 && ./punto2 prueba
```

### Ejercicio 03:

Es posible hacerlo sin el llamado wait() usamos en su lugar un sleep() de 1 segundo con lo cual el hijo hará el hello primero y luego el padre imprimirá el goodbye 

* [Ejercicio_03](punto3.c)

```
gcc punto3.c -o punto3 && ./punto3
```

### Ejercicio 04:

En orden de realizar el reemplazo de procesos, hay varias variantes del mismo llamado basico para que se puedan pasar los argumentos que se pueden pasar por entrada.

* [Ejercicio_04](punto4.c)

```
gcc punto4.c -o punto4 && ./punto4
```

### Ejercicio 05:

Si ponemos el wait() en el proceso child este retorna el PID de este el cual será -1 esto pasa porque no hay ningún proceso secundario

* [Ejercicio_05](punto5.c)

```
gcc punto5.c -o punto5 && ./punto5
```

### Ejercicio 06:

Waitpid() sirve si vamos a poner a trabajar un proceso child en específico en vez de hacerlo aleatoriamente

* [Ejercicio_06](punto6.c)

```
gcc punto6.c -o punto6 && ./punto6
```

### Ejercicio 07:

Si tratamos de imprimir algo despues de haber cerrado el flujo, no se podra imprimir.
* [Ejercicio_07](punto7.c)

```
gcc punto7.c -o punto7 && ./punto7
```
