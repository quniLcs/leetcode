#include<stdbool.h>

// original brutal force solution
bool isPalindrome(char *s, int n){
    int i = 0;
    int j = n - 1;

    while (i < j){
        if (s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}

char *shortestPalindrome(char *s){
    int m = strlen(s);
    int n = m;
    while (!isPalindrome(s, n)) n--;

    char *t = (char*)malloc(sizeof(char) * (2 * m - n + 1));
    for (int i = 0; i < m - n; i++) t[i] = s[m - 1 - i];
    strcpy(t + m - n, s);
    return t;
}

// Knuth-Morris-Pratt algorithm with reference to:
// https://leetcode.cn/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-leetcode-solution/
/*
char *shortestPalindrome(char *s){
    int m = strlen(s);
    if (m == 0) return "";

    int *pi = (int*)malloc(sizeof(int) * m);
    pi[0] = 0;
    for (int i = 1, j = 0; i < m; i++){
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }

    int n = 0;
    for (int i = m - 1; i >= 0; i--){
        while (n > 0 && s[i] != s[n]) n = pi[n - 1];
        if (s[i] == s[n]) n++;
    }

    char *t = (char*)malloc(sizeof(char) * (2 * m - n + 1));
    for (int i = 0; i < m - n; i++) t[i] = s[m - 1 - i];
    strcpy(t + m - n, s);
    return t;
}
*/