#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	const char*p[] = {
		"g++",
		"helloworld.cpp",
		"-o",
		"helloworld", 
		NULL
	};
	execvp("/usr/bin/g++", (char*const*)p);
}
