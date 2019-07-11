#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define MSGSIZE 30 


void myfork(int *fds);
void mywrite (int *fds);
void myread (int *fds);


int main()
{
	
	int fds[2];
	if (pipe(fds) < 0)
	{

		perror("Error: En la apertura del pipe!!");
		exit(1);//Terminar

	}else
	{
		myfork(fds);

	return 0;
} 


void myfork(int *fds)
{
	
	pid_t child_pid, pid_child1, pid_child2;
	
	pid_child1 = fork(); 
	if (pid_child1 < 0) 
	{
		
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar
	}
	else if(pid_child1 == 0) 
	{
	

		printf("%d: Soy el primer proceso hijo\n", (int)getpid());
		mywrite(fds);

	}else
	{
		child_pid = wait(NULL);
		printf("%d: Soy el proceso padre, el pid de mi primer hijo es %d\n", (int)getpid(), (int)child_pid);
			
		pid_child2 = fork(); 
		if (pid_child2 < 0) 
		{

			perror("Error: La creación del proceso hijo no fue exitosa!!");
			exit(1);
		}
		else if(pid_child2 == 0) 
		{
	
		
			printf("%d: Soy el segundo proceso hijo\n", (int)getpid());
			myread(fds);

		}else
		{
			child_pid = wait(NULL);
			printf("%d: Soy el proceso padre, el pid de mi segundo hijo es %d\n", (int)getpid(), (int)child_pid);
		
		}
		
	}
	
			
}


void mywrite (int *fds)
{
	char message[MSGSIZE] = "Hola, Buenos dias";


	if (write(fds[1],message,MSGSIZE) < 0) 
	{ 
		perror("w1"); 
		exit(1);
	}else
	{
		close(fds[1]);
		printf("%d: Escribe en el pipe --> %s\n", (int)getpid(), message);
	}
}


void myread (int *fds)
{
	char message[MSGSIZE];

	if (read(fds[0],message, MSGSIZE) < 0) 
	{ 	
		perror("r1"); 
		exit(1); 
	}else
	{
		close(fds[0]);
		printf("%d: Lee del pipe --> %s\n", (int)getpid(), message);
	}
}
