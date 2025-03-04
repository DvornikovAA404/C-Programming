#include <stdio.h>
#include <math.h>

int main(){
	float x;
	float y;
	printf("Enter x y: ");
	scanf("%f %f", &x, &y);
	if (((x>=-1)&&(x<=1)&&(y<=1))&&!((x>y)&&(-x>y))){
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}
