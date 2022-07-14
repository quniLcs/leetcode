// with reference to:
// https://leetcode.cn/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/


#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000


/* Dynamic Programming, whose chortcoming is the space managment
char *longestPalindrome(char *s){
    int begin = 0;
    int max_len = 1;
    int total_len = strlen(s);

    int dp[MAX_LEN][MAX_LEN];
    // dp[i][j] represents whether s[i:j] is palinfromic

    for (int cur_len = 1; cur_len <= total_len; cur_len++){
        for (int i = 0; i < total_len; i++){
            int j = cur_len + i - 1;  // j - i + 1 = cur_len
            if (j >= total_len){
                break;
            }

            if (s[i] == s[j]){
                if (j - i < 3){
                    dp[i][j] = 1;
                } 
                else{
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            else{
                dp[i][j] = 0;
            }

            if (dp[i][j] && cur_len > max_len){
                begin = i;
                max_len = cur_len;
            }
        }
    }

    s[begin + max_len] = '\0';
    return s + begin;
}
*/


/* Expansion method, a good trade-off between difficulty and effiency
int *expandAroundCenter(char *s, int total_len, int left, int right){
    int *ret = (int *)malloc(sizeof(int) * 2);

    while (left >= 0 && right < total_len && s[left] == s[right]) {
        left--;
        right++;
    }

    ret[0] = left + 1;
    ret[1] = right - 1;
    return ret;
}

char *longestPalindrome(char *s){
    int begin = 0, end = 0;
    int cur_len = 0, total_len = strlen(s);
    int *ret = (int *)malloc(sizeof(int) * 2);
    
    for (int i = 0; i < total_len; i++){
        ret = expandAroundCenter(s, total_len, i, i);
        if (ret[1] - ret[0] > cur_len) {
            begin = ret[0];
            end = ret[1];
            cur_len = end - begin;
        }

        ret = expandAroundCenter(s, total_len, i, i + 1);
        if (ret[1] - ret[0] > cur_len) {
            begin = ret[0];
            end = ret[1];
            cur_len = end - begin;
        }
    }

    s[end + 1] = '\0';
    return s + begin;
}
*/

// Manacher Algorithm
int expandAroundCenter(char *s, int expanded_len, int left, int right) {
    while (left >= 0 && right < expanded_len && s[left] == s[right]) {
        left--;
        right++;
    }
    return (right - left - 2) / 2;
}

char *longestPalindrome(char *s){
    int total_len = strlen(s);
    int expanded_len = total_len * 2 + 1;

    char t[2 * MAX_LEN + 1];
    t[0] = '#';
    for (int i = 0; i < total_len; i++){
        t[2 * i + 1] = s[i];
        t[2 * i + 2] = '#';
    }

    int begin = 0, end = 0;
    int center = -1, right = -1;
    int arm_len[2 * MAX_LEN + 1];

    for (int i = 0; i < expanded_len; i++){
        if (right >= i){
            int j = center * 2 - i;
            int min_arm_len = arm_len[j] < right - i ? arm_len[j] : right - i ;
            arm_len[i] = expandAroundCenter(t, expanded_len, i - min_arm_len, i + min_arm_len);
        }
        else{
            arm_len[i] = expandAroundCenter(t, expanded_len, i, i);
        }

        if (arm_len[i] * 2 + 1 > end - begin) {
            begin = i - arm_len[i];
            end = i + arm_len[i];
        }
        if (i + arm_len[i] > right) {
            center = i;
            right = i + arm_len[i];
        }
    }

    begin = (begin + 1) / 2;
    end = (end - 1) / 2;

    s[end + 1] = '\0';
    return s + begin;
}


void main(){
    printf("%s\n", longestPalindrome("babad"));
}