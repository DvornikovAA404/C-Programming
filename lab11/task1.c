#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int n)
{
for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}
int main()
{
int n = 10;
int *arr = malloc(n * sizeof(int));
init(arr, n);
for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
}
return 0;
}