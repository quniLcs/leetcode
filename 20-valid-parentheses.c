#include<stdio.h>
#include<stdbool.h>

bool isValid(char *s){
    int i, j = 0;
    int length = strlen(s);
    char correct;
    char *stack = (char*)malloc(sizeof(char) * length);

    for (i = 0; i < length; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[j] = s[i];
            j++;
        }
        else{
            if (s[i] == ')') correct = '(';
            else if (s[i] == ']') correct = '[';
            else correct = '{';

            if (j > 0 && stack[j - 1] == correct) j--;
            else return false;
        }
    }

    if (j == 0) return true;
    else return false;
}

void main(){
    printf("%d\n", isValid("()"));
    printf("%d\n", isValid("()[]{}"));
    printf("%d\n", isValid("(]"));
    printf("%d\n", isValid("([)]"));
    printf("%d\n", isValid("{[]}"));
    printf("%d\n", isValid("]"));
}