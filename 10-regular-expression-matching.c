#include<stdio.h>
#include<stdbool.h>


// all possible situations:
// "a"
// "."
// "a*"
// ".*"

// the brutal force solution
/*
bool isMatch(char *s, char *p){
    int i = 0, j = 0, k = 0;

    while (p[j]){
        // p[j] is not null
        // p[j+1] may be null

        if (p[j] != '.' && p[j + 1] != '*'){
            if (p[j] == s[i]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        else if(p[j] == '.' && p[j + 1] != '*'){
            if (s[i]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        else if(p[j] != '.' && p[j + 1] == '*'){
            do if(isMatch(s + i + k, p + j + 2)) return true;
            while (p[j] == s[i + k++]);
            return false;
        }
        else{  // p[j] == '.' && p[j + 1] == '*'
            do if(isMatch(s + i + k, p + j + 2)) return true;
            while (s[i + k++]);
            return false;
        }
    }

    if (s[i]) return false;
    else return true;
}
*/


// dynamic programming with reference to:
// https://leetcode.cn/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
bool match(char *s, char *p, int i, int j){
    if (i == 0) return false;
    
    if (p[j - 1] == '.') return true;
    else return p[j - 1] == s[i - 1];
}

bool isMatch(char *s, char *p){
    int m = strlen(s);
    int n = strlen(p);

    bool f[21][31];
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
            else{
                f[i][j] = f[i][j - 2];
                if (match(s, p, i, j - 1)){
                    f[i][j] |= f[i - 1][j];
                }
            }
        }
    }
    
    return f[m][n];
}


void main(){
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "a*"));
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("ab", ".*c"));
    printf("%d\n", isMatch("aaa", "a*a"));
    printf("%d\n", isMatch("aab", "c*a*b"));
    printf("%d\n", isMatch("a", ".*..a*"));
    // 0 1 1 0 1 1 0
}