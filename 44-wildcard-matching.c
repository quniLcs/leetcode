#include<stdio.h>
#include<stdbool.h>


// dynamic programming
/*
bool match(char *s, char *p, int i, int j){
    if (i == 0) return false;
    
    if (p[j - 1] == '?') return true;
    else return p[j - 1] == s[i - 1];
}

bool isMatch(char *s, char *p){
    int m = strlen(s);
    int n = strlen(p);

    bool **f = (bool**)malloc(sizeof(bool*) * (m + 1));
    for (int i = 0; i <= m; i++){
        f[i] = (bool*)malloc(sizeof(bool*) * (n + 1));
    }

    f[0][0] = true;
    for (int i = 1; i <= m; i++){
        f[i][0] = false;
    }

    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (p[j - 1] != '*'){
                if (match(s, p, i, j)){
                    f[i][j] = f[i - 1][j - 1];
                }
                else{
                    f[i][j] = false;
                }
            }
            else{  // p[j - 1] == '*'
                f[i][j] = f[i][j - 1];
                if (i > 0){
                    f[i][j] |= f[i - 1][j];
                }
            }
        }
    }

    return f[m][n];
}
*/


// greedy algorithm with reference to
// https://leetcode.cn/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
bool match(char u, char v){
    return u == v || v == '?'; 
}

bool isMatch(char *s, char *p){
    int m = strlen(s);
    int n = strlen(p);

    while (m && n && p[n - 1] != '*'){
        if (match(s[m - 1], p[n - 1])){
            m--;
            n--;
        }
        else{
            return false;
        }
    }

    if (n == 0){
        return m == 0;
    }

    int sIndex = 0;
    int pIndex = 0;
    int sRecord = -1;
    int pRecord = -1;

    while (sIndex < m && pIndex < n){
        if (p[pIndex] == '*'){
            pIndex++;
            sRecord = sIndex;
            pRecord = pIndex;
        }
        else if (match(s[sIndex], p[pIndex])){
            sIndex++;
            pIndex++;
        }
        else if (sRecord != -1 && sRecord + 1 < m){
            sRecord++;
            sIndex = sRecord;
            pIndex = pRecord;
        }
        else{
            return false;
        }
    }

    while (pIndex < n){
        if (p[pIndex] != '*'){
            return false;
        }
        else {
            pIndex++;
        }
    }
    return true;
}


void main(){
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "*"));
    printf("%d\n", isMatch("cb", "?a"));
    printf("%d\n", isMatch("adceb", "*a*b"));
    printf("%d\n", isMatch("acdcb", "a*c?b"));
    printf("%d\n", isMatch("bbaaababbaaababababbb", "*a*****bb"));
    printf("%d\n", isMatch("babaabbbbbaaaaabbaababbaaaaaaabbaabaabbbabbaabbbbb", "*ba**bbbb"));
    // 0 1 0 1 0 1 1
}