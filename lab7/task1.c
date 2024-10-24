#include <stdio.h>
#include <string.h>

int main(){
    char s[2000];
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
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
            }
            len = 0;
            p[i] = ' ';
        }

        else{
            p[i] = s[i];
            len++;
        }
    }
    if(IND == strlen(p)-1)
        IND = IND - 1;
    for(int i = IND-max; i < IND; i++){
        if(p[i] != ',' && p[i] != '!' && p[i] != '.' && p[i] != ' ')
            p[i] = '#';
    }
    printf("%s\n", p);
}