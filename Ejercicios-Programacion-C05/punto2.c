#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void myfork(int fd, pid_t value, int sz);


int main()
{
	
	int fd, sz;
	pid_t value;

	fd = open ("archivo.txt",O_RDONLY | O_CREAT);
	
	if (fd < 0)
	{
		perror("Error al abrir el archivo!!");
		exit(1);//Terminar proceso
	}else
	{
		myfork(fd, value, sz);
	}

	if(close(fd) < 0) 
	{
		perror("Error: El archivo no se pudo cerrar!!");
		exit(1);
	}
	return 0;
} 


void myfork(int fd, pid_t value, int sz)
{
	
	value = fork();

	if (value < 0) 
	{
	
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);
	}
	else if(value == 0) 
	{

		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf("%d: El file descriptor es %d\n",(int)getpid(), fd);		
		
		sz = write(fd, "Hola, soy el proceso hijo\n", strlen("Hola, soy el proceso hijo\n"));		

		
	}else
	{
	
		printf("%d: Soy el proceso padre\n", (int)getpid());

		printf("%d: El file descriptor es %d\n",(int)getpid(), fd);

		sz = write(fd, "Hola, soy el proceso padre\n", strlen("Hola, soy el proceso padre\n"));		
		
	}
			
	if(sz < 0)
	{

		perror("Error al escribir el archivo!!");
		exit(1);
	}

	printf("%d: Escritura exitosa!!!\n", (int)getpid());

}	
