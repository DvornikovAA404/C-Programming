// 12 задание
// 0000000000101101
// 0000000100000000
// 0000000000000000
#include <stdio.h>
int shift(int k){
    int b = 1;
    for (int i = 0; i < k; i++){
        b = b*2;
    }
    return b-1;
}

// 1111110111101000
// 0000000011111111
// 0000000011101000
// 1111110100000000
int main(){
    short a, b;
    printf("Enter the number: ");
    scanf("%hd", &a);
    short Last_byte = a & 0xff;    // 0000000000110000
    short First_byte = a & 0xff00; // 0111010100000000
    b = (Last_byte<<8)|(First_byte>>8); // 0111010100110000
                                        // 0011000001110101
    printf("%d\n", b);
}