#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

extern char **environ;
char **ptr;

void printEnviron()
{
	for(char **ptr = environ; *ptr != 0; ptr++)
	{
		char *value = getenv(*ptr);
		if (value != NULL)
		{
			if(strcmp(*ptr, "HOME") == 0)
			{
				printf("HOME = %s\n", getenv("HOME"));
			}
			else if(strcmp(*ptr, "SHELL") == 0)
			{
				printf("SHELL = %s\n", getenv("SHELL"));
			}
			else if(strcmp(*ptr, "PAHT") == 0)
			{
				printf("PATH = %s\n", getenv("PATH"));
			}
			else
			{
				printf("%s\n", *ptr);
			}
		}
		exit(0);
	}
}

void realUserID()
{
       	printf("My real user ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
	exit(0);
}

void effectiveUserID()
{
	printf("My effective user ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	exit(0);
}

void processNum()
{
	printf("My process number: [%d]\n", getpid());
	exit(0);
}

void parentNum()
{
	printf("My parent's process number: [%d]\n", getppid());
	exit(0);
}

int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
	    if(strcmp(argv[i], "-e") == 0)
	    {
		    printEnviron();
	    }
	    else if(strcmp(argv[i], "-u") == 0)
	    {
		    realUserID();
	    }
	    else if(strcmp(argv[i], "-g") == 0)
	    {
		    effectiveUserID();
	    }
	    else if(strcmp(argv[i], "-i") == 0)
	    {
		    processNum();
	    }
	    else if(strcmp(argv[i], "-p") == 0)
	    {
		    parentNum();
	    }
    }

    return 0;
}
