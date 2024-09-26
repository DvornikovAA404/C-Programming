#include <stdio.h>

int main(){
	int n = 5;
	for(int s = 1, i = 0; i <= n; i++, s = s*2)
		printf("%d\n", s);
}

//Возводит 2 в степень n.
