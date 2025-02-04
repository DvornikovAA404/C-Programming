#include <stdio.h>

int main() {
	float t;
	char ch;
	float temp;
	printf("Enter: ");
	scanf("%f %c", &t, &ch);
	if((ch == 'f')||(ch == 'F')){
		temp = (t-32)/1.8;
	}
	else if((ch == 'c')||(ch == 'C')){
		temp = (t*1.8)+32;
	}
	else{
		printf("Incorrect form!\n");
		return 0;
	}
	printf("temp = %f\n", temp);
}
