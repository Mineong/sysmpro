#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid, gid;
	printf("PARENT: PID = %d  GID = %d \n", getpid(), getpgrp());
	pid = fork();
	if (pid == 0) {
		setpgid(0, 0);
		printf("CHILD: PID = %d  GID = %d \n", getpid(), getpgrp());
	}
}

