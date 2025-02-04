#include <stdio.h>

int main(){
	int n;
	int a;
	scanf("%d", &a);
	for(n = 2; n < a; n++){
		if(a%n==0){
			break;
		}
	}
	if(n==a){
		puts("Good");
	}
}

//Определяет, простое ли число
