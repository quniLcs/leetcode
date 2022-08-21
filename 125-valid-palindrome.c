#include<stdbool.h>

bool isAlphaNum(char c){
    if (c >= '0' && c <= '9') return true;
    else if (c >= 'a' && c <= 'z') return true;
    else if (c >= 'A' && c <= 'Z') return true;
    else return false;
}

char adjustUpper(char c){
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

bool isPalindrome(char *s){
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j){
        while (i < j && !isAlphaNum(s[i])) i++;
        s[i] = adjustUpper(s[i]);

        while (i < j && !isAlphaNum(s[j])) j--;
        s[j] = adjustUpper(s[j]);

        if (s[i] != s[j]) return false;

        i++;
        j--;
    }

    return true;
}

void main(){
    isPalindrome("A man, a plan, a canal: Panama");
}