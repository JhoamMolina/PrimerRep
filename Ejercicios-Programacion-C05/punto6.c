#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



void myfork(pid_t value, pid_t cpid, int status);


int main()
{
	
	pid_t value, cpid;
	int status;
	
	myfork(value ,cpid, status);

	return 0;
} 


void myfork(pid_t value, pid_t cpid, int status)
{
	
	value = fork();
	
	if (value < 0) 
	{
		//Error
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);
	}
	else if(value == 0) 
	{
	

		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
	}else
	{
		cpid = waitpid (value, &status, 0);//Permite especificar el proceso hijo por el que se desea esperar
		printf("%d: Soy el proceso padre, el pid de mi hijo es %d\n", (int)getpid(), (int)cpid);
		
	}
			
}
