#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void alarmHandler();

int main()
{
   signal(SIGALRM, alarmHandler);
   alarm(5);    
   printf("loop start \n");
   while (1) {
      sleep(1);
      printf("1 second \n");
   }
   printf("no start\n");
}

void alarmHandler(int signo)
{
   printf("wake up\n");
   exit(0);
}

