
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