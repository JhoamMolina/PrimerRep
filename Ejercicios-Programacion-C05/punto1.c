#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>


void myfork(int x, pid_t value);

int main()
{
	
	int x; 
	pid_t value;

	x = 100; 

	myfork(x, value);
	return 0;
} 


void myfork(int x,pid_t value)
{
	value = fork();

	if (value < 0) 
	{
		
		perror("Error: creación de hijo fallida!");
		exit(1);
	}
	else if(value == 0) 
	{
		
		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf("%d: El valor de la variable x es %d\n",(int)getpid(), x);		
				
		x = 40;
		
		
	}else
	{
		
		printf("%d: Soy el proceso padre\n", (int)getpid());

		printf("%d: El valor de la variable x es %d\n", (int)getpid() , x);

		x= 70;
	}
	
	printf("%d: El nuevo valor de la variable x es %d\n",(int)getpid(), x);

}	
