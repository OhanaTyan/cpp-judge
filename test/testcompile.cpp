// this file tests the compile() function 

#include <cstdio>
#include <cstdlib>
#include "../src/compile.h"

int main(){
	const char *p = NULL;
	printf("%d\n", compile("helloworld.cpp", "helloworld", &p));
	printf("%d\n", compile("badworld.cpp", "badworld", &p));
	return 0;
}
