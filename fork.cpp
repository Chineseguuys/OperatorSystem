#include <stdio.h>
#include <unistd.h>



int main(int argc, char** argv)
{
	/**
	 * Do something
	*/
	pid_t pid = fork();
	if (pid_t == 0)
	{
		int exec_status = exec("calc", argc, argv[0], argv[1],....);
		printf(".....")
	}
	else if (pid_t > 0)
	{
		// ....
	}
	else 
	{
		// ....
	}
}