#include <stdio.h>

int main(){
	int s, n, a;
	scanf("%d", &a);
	for (s=0,n=2; n<a; n++)
		{ if(a%n==0) s++; }
	if(s==0) puts("Good");
}

//Определяет, является ли число a простым числом.
