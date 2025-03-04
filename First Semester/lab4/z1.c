#include <stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	int n = 0;
	for(int i = 0; i < a; i++){
		for(int y = 0; y < a; y++){
		 printf("%d ", ++n);
		}
		printf("\n");
	}
}
