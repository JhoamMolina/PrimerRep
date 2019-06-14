#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
	pid_t pid;

	pid = fork();
	if(pid == 0){
	sleep(3);
	printf("Hola soy el hijo y mi identificador es (pid:%d)\n", (int) getpid());
}else
	int status;
	pid_t pid2;

	printf("hola soy el padre, mi identificaor es %d  y el de mi hijo es (pid:%d)\n", (int) getpid(), pid);
	pid2 = wait(NULL);
	printf("Termino mi hijo %d\n",pid2);
	
}

