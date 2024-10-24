#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "Lorem ipsum dolor sit aaaaaaaaaaaaaaaaamet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    strcat(s, " ");
    char p[strlen(s)+2];
    int max = 0;
    int IND = 0;
    int len = 0;
    for(int i = 0; i < strlen(s)+1; i++){
        if (s[i] == ' '){
            if((s[i] == ' ') && len>max){
                max = len;
                IND = i;
                printf("%s\n", p);
            }
            len = 0;
            p[i] = ' ';
        }

        else{
            p[i] = s[i];
            len++;
        }
    }
    printf("%d : %d\n", IND-max, IND);
    printf("%s\n", p);
    for(int i = IND-max; i < IND; i++){
        if(p[i] != ',' && p[i] != '!' && p[i] != '.')
            p[i] = '#';
    }
    printf("%s\n", p);
}