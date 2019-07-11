#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



void myfork(pid_t value, char **args);


int main()
{
	
	pid_t value;
	char *args[] ={"/bin/ls",NULL};


	myfork(value, args);

	return 0;
} 


void myfork(pid_t value, char **args)
{
	
	value = fork(); //Crear proceso hijo
	
	if (value < 0) 
	{

		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar
	}
	else if(value == 0) 
	{
		int i;
		char *envp[] = { NULL };


		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf(" **Menu**\n1. execvp( )\n2. execlp( )\n3. execve( )\n");
		printf("Digite una opción del Menu:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: execvp(args[0], args);
			break;
			case 2:execlp(args[0],"ls",NULL);
			break;
			case 3: execve(args[0],args,envp);
			default:
				printf("Opción incorrecta");
				exit(1);
			break;
		}
		
	}else
	{
	
		
		wait(NULL);
		printf("%d: Soy el proceso padre\n", (int)getpid());
		
	}
			
}	
