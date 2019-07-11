#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>


void myfork(int x, pid_t value);

int main()
{
	
	int x; 
	pid_t value;

	x = 100; //Inicialización variable

	myfork(x, value);//Invocación  de la función
	return 0;
} 


void myfork(int x,pid_t value)
{
	value = fork(); //Crear proceso hijo

	if (value < 0) 
	{
		
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar proceso
	}
	else if(value == 0) 
	{
		
		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf("%d: El valor de la variable x es %d\n",(int)getpid(), x);		
				
		x = 40; //Cambiar valor de la variable x
		
		
	}else
	{
		
		printf("%d: Soy el proceso padre\n", (int)getpid());

		printf("%d: El valor de la variable x es %d\n", (int)getpid() , x);

		x= 70; //Cambiar valor de la variable x
	}
	
	printf("%d: El nuevo valor de la variable x es %d\n",(int)getpid(), x);

}	
