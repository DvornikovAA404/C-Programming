#include <stdio.h>

int main(){
	int ans;
	char a = 16;
	char b = 17;
// 10001
// 10000
// 10000
	if(b&a){
		ans = 0;
	}
	else {
		ans = 1;
	}
	printf("%d\n", ans);
}
