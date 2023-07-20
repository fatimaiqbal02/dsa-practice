#include<stdio.h>
#include<string.h>
#define SIZE 15
int main(){
    char string[] = "3[a]2[bc]";

}
char *decodeString(char string[], int*i){
    char s[] = " ";
    while(*i < SIZE && s[*i] != ']'){
        if(isdigit(s[*i])){
            int k = 0;
            while(*i < SIZE && isdigit(s[*i])){
                k = k*10 + s[*i++] - '0';
            }
            *i++;
            char r[] = decodeString(s,*i);
            while(k-- >0){
                char result[] = strcat(s,r);
                
            }
        }
    }

}
char *decodeString(char string[]){
    int i = 0;
    return decodeString(string,&i);
}
