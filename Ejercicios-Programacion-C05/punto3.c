#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include <string.h>


void myfork(pid_t value);


int main()
{
	
	pid_t value;

	myfork(value);
	
	return 0;
} 


void myfork(pid_t value)
{
	
	value = fork(); //Crear proceso hijo

	if (value < 0) 
	{

		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar proceso
	}
	else if(value == 0) 
	{

		printf("%d: Hello\n", (int)getpid());
					
		
	}else
	{
	

		sleep(1);
		printf("%d:Goodbye\n", (int)getpid());
		
	}

}	
