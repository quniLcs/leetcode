#include<stdio.h>

/* original O(n) solution
char *reverseWords(char *s){
    int n = strlen(s);
    int i = n - 1;
    int j = 0;
    char *t = (char*)malloc(sizeof(char) * (n + 1));

    while (s[i] == ' ') i--;
    while (i >= 0){
        int k = i;
        s[k + 1] = '\0';
        while (i >= 0 && s[i] != ' ') i--;
        if (j) t[j++] = ' ';
        strncpy(t + j, s + i + 1, k - i);
        j += k - i;
        t[j] = '\0';
        while (i >= 0 && s[i] == ' ') i--;
    }

    return t;
}
*/

// O(1) solution with reference to
// https://leetcode.cn/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
void reverse(char *s, int i, int j){
    j--;
    while (i < j){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
}

char *reverseWords(char *s){
    int n = strlen(s);
    int i = 0;
    int j = 0;

    reverse(s, 0, n);
    while (s[i] == ' ') i++;
    while (i < n){
        if (j) s[j++] = ' ';
        int k = j;
        while (i < n && s[i] != ' ') s[j++] = s[i++];
        reverse(s, k, j);
        while (i < n && s[i] == ' ') i++;
    }
    s[j] = '\0';

    return s;
}

void main(){
    printf("%s\n", reverseWords("the sky is blue"));
}