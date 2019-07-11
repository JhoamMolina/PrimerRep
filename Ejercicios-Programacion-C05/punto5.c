#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



void myfork(pid_t value, pid_t cpid);


int main()
{
	
	pid_t value, cpid;
	


	myfork(value, cpid);//Invocación  de la función

	return 0;
} 


void myfork(pid_t value, pid_t cpid)
{
	
	value = fork(); 
	
	if (value < 0) 
	{
	
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar
	}
	else if(value == 0) 
	{
	
	
		cpid = wait(NULL);
		printf("%d: Soy el proceso hijo, el pid de mi padre es %d\n", (int)getpid(), (int)cpid);
		
	}else
	{

		
		cpid = wait(NULL);
		printf("%d: Soy el proceso padre, el pid de mi hijo es %d\n", (int)getpid(), (int)cpid);
		
	}
			
}
