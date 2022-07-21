#include<stdbool.h>

// original brutal force solution
int strStr(char *haystack, char *needle){
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);

    for (int i = 0; i <= haystackLength - needleLength; i++){
        bool match = true;
        for (int j = 0; j < needleLength; j++){
            if (haystack[i + j] != needle[j]){
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

// Knuth-Morris-Pratt algorithm with reference to:
// https://leetcode.cn/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode-solution-ds6y/
int strStr(char *haystack, char *needle){
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);

    if (needleLength == 0){
        return 0;
    }
    else{
        int *pi = (int*)malloc(sizeof(int) * needleLength);
        pi[0] = 0;
        for (int i = 1, j = 0; i < needleLength; i++){
            while (j > 0 && needle[i] != needle[j]) j = pi[j - 1];
            if (needle[i] == needle[j]) j++;
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < haystackLength; i++){
            while (j > 0 && haystack[i] != needle[j]) j = pi[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == needleLength) return i - needleLength + 1;
        }
        return -1;
    }
}