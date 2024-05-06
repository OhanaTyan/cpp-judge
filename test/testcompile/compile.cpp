#include "compile.h"

#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*
	@input:		input  file name
	@output:	output file name
	@argv:		args passed to g++
	@return:	0 if compile successfully else 1
*/
extern "C" int compile(const char* input, const char* output, const char *argv[]){
	int child_pid = fork();
	if (child_pid == 0){
		// child process

		// get the len of argv
		int len_of_argv = 0;
		for (; argv[len_of_argv]!=NULL; len_of_argv++){
			// do nothing
		}

		int my_len_of_argv = len_of_argv + 5;
		// the pointer here is no need to free
		const char ** my_argv = (const char**)malloc(sizeof(char*) * len_of_argv);
		// copy the pointer of argv[i] to my_argv
		for (int i=0; i<len_of_argv; i++){
			my_argv[i] = argv[i];
		}

		my_argv[len_of_argv] = input;
		my_argv[len_of_argv+1] = "-o";
		my_argv[len_of_argv+2] = output;
		my_argv[len_of_argv+3] = NULL;

		execvp("g++", (char*const*)my_argv);
		printf("this line will never be passed\n");
	}
	// father process

	// try to get the stop signal of child process for 10 times
	for (int try_time=0; try_time<10; try_time++){
		// sleep for 1s
		sleep(1);
		int status;
		if (waitpid(child_pid, &status, WNOHANG) == -1) {
			// the child process havn't stopped
			continue;
		} 

		return WEXITSTATUS(status);
	}

	return -1;

}









