	#include "solucion.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char** argv) {

  printf("Soy el hijo\n");
  int rc = fork();
  if(rc == 0) {
  int x = 20;
  x = fibonacci(x);
  printf("calculo fibonnacci\n");
  guardarEntero("archivo",x);
  printf("Guardo el valor calculado en archivo 'x'\n");
}else {

  wait(NULL);
  printf("Espero a que termine mi hijo");
  int y  =  leerEntero("archivo");
  printf("Leo el valor que calculo mi hijo del archivo 'x'\n");
  int m = y * 100;
  printf("Multiplo por 100 e imprimo en pantalla %d\n", m);
  return 0;
}
}
