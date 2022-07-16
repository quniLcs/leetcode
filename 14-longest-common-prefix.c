// the first solution is completely independently written
// the following is referred to:
// https://leetcode.cn/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode-solution/


#include<stdio.h>
#include<stdbool.h>


char *longestCommonPrefix(char **strs, int strsSize){
    char *common = (char *)malloc(sizeof(char) * 201);
    int j = 0;

    while (strs[0][j]){
        for (int i = 1; i < strsSize; i++){
            if (strs[i][j] != strs[0][j]){
                common[j] = '\0';
                return common;
            }
        }
        common[j] = strs[0][j];
        j++;
    }
    common[j] = '\0';
    return common;
}


/*
char *longestCommonPrefixBwtween(char *str1, char *str2){
    int index = 0;

    while (str1[index] && str1[index] == str2[index]) {
        index++;
    }
    str1[index] = '\0';

    return str1;
}

char *longestCommonPrefix(char **strs, int strsSize){
    char *common = strs[0];

    for (int i = 1; i < strsSize; i++){
        common = longerCommonPrefix(common, strs[i]);
        if (common[0] == '\0'){
            break;
        }
    }

    return common;
}
*/


/* Devide and Conquer
char *longestCommonPrefixBwtween(char *str1, char *str2){
    int index = 0;

    while (str1[index] && str1[index] == str2[index]) {
        index++;
    }
    str1[index] = '\0';

    return str1;
}

char *longestCommonPrefixDevided(char **strs, int begin, int end){
    if (begin == end) {
        return strs[begin];
    }
    else{
        int mid = (begin + end) / 2;
        char *left = longestCommonPrefixDevided(strs, begin, mid);
        char *right = longestCommonPrefixDevided(strs, mid + 1, end);
        return longestCommonPrefixBwtween(left, right);
    }
}

char *longestCommonPrefix(char **strs, int strsSize){
    return longestCommonPrefixDevided(strs, 0, strsSize - 1);
}
*/


/*
bool isCommonPrefix(char **strs, int strsSize, int low, int mid){
    for (int i = 1; i < strsSize; i++) {
        for (int j = low; j < mid; j++) {
            if (strs[i][j] != strs[0][j]) {
                return false;
            }
        }
    }
    return true;
}


char *longestCommonPrefix(char **strs, int strsSize){
    int curSize, minSize = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++){
        curSize = strlen(strs[i]);
        minSize = minSize < curSize ? minSize : curSize;
    }

    int low = 0, high = minSize;
    while (low < high){
        int mid = (high - low + 1) / 2 + low;
        if (isCommonPrefix(strs, strsSize, low, mid)) low = mid;
        else high = mid - 1;
    }

    strs[0][low] = '\0';
    return strs[0];
}
*/


void main(){
    char *strs[3] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(strs, 3));
}