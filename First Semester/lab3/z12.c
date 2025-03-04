#include <stdio.h>

int main(){
	int a = 123;
	int k = 0;
	for (int n = a, s = 0; n!=0; n = n/10){
		k = n%10;
		s = s+k;
		printf("k = %d, s = %d\n", k, s);
	}
}
