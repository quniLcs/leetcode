// Almost directly copied from
// https://leetcode.cn/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/


/* dynamic programming
int longestValidParentheses(char *s){
    int ans = 0;
    int n = strlen(s);

    int *dp = (int*)malloc(sizeof(int) * n);
    memset(dp, 0, sizeof(int) * n);

    for (int i = 1; i < n; i++){
        if (s[i] == ')'){
            if (s[i - 1] == '('){
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            ans = dp[i] > ans ? dp[i] : ans;
        }
    }

    return ans;
}
*/


/* stack
int longestValidParentheses(char *s){
    int ans = 0;
    int n = strlen(s);

    int* stk = (int*)malloc(sizeof(int) * (n + 1));
    int top = 0;

    stk[top++] = -1;
    for (int i = 0; i < n; i++){
        if (s[i] == '('){
            stk[top++] = i;
        }
        else{
            top--;
            if (top == 0) stk[top++] = i;
            else ans =  i - stk[top - 1] > ans ? i - stk[top - 1] : ans;
        }
    }

    return ans;
}
*/


int longestValidParentheses(char* s){
    int ans = 0;
    int n = strlen(s);

    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') left++;
        else right++;
        if (left == right) ans = left + right > ans ? left + right : ans;
        else if (right > left) left = right = 0;
    }

    left = right = 0;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == '(') left++;
        else right++;
        if (left == right) ans = left + right > ans ? left + right : ans;
        else if (left > right) left = right = 0;
    }

    return ans;
}