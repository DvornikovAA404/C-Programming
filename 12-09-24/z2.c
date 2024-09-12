#include <stdio.h>

int main(){
	int max = 2147483647+1;
	unsigned int umax = 4294967295+1;
	printf("int = %d\nunsigned int = %u\n", max, umax);
	char min = -128;
	printf("char = %hhd\n", min-1);
}
