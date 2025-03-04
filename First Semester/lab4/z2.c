#include <stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	for(int i = -1, y = 0, o = 0, m = a; i < a; i++, m=m-1, y=1+(m*2), o++){
		for(int k=0; k<o; k++){
			printf(" ");
		}
		for(int z = y; z>0; z=z-1){
			printf("V");
		}
		printf("\n");
	}
}
