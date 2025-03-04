#include <stdio.h>

int main(){
	int n = 32;
	for(int m=1, k=0; m<=n; k++, m=m*2){ //Код переводит число n в степень двойки, округляя его вниз.
		printf("%d\n", k-1);
	}
}
