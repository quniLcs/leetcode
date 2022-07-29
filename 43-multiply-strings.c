// Almost directly copied from
// https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/


#include<stdio.h>


/*
int max(int a, int b){
    return a > b ? a : b;
}

char *add(char *num1, char *num2){
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int next = 0;

    char *ans = (char*)malloc(sizeof(char) * (max(i, j) + 3));
    int len = 0;

    while (i >= 0 || j >= 0 || next != 0){
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + next;
        ans[len++] = result % 10;
        next = result / 10;
        i--;
        j--;
    }

    for (int i = 0; i < len / 2; i++){
        char temp = ans[i];
        ans[i] = ans[len - 1 - i];
        ans[len - 1 - i] = temp;
    }
    for (int i = 0; i < len; i++){
        ans[i] += '0';
    }
    ans[len] = '\0';

    return ans;
}

char *multiply(char *num1, char *num2){
    char *ans = (char*)malloc(sizeof(char) * 2);
    ans[0] = '0';
    ans[1] = '\0';

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0') return ans;

    for (int j = len2 - 1; j >= 0; j--){
        int i = len1 - 1;
        int y = num2[j] - '0';
        int next = 0;

        char *cur = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
        int len = 0;

        for (int k = len2 - 1; k > j; k--){
            cur[len++] = 0;
        }

        while (i >= 0 || next != 0){
            int x = i >= 0 ? num1[i] - '0' : 0;
            int result = x * y + next;
            cur[len++] = result % 10;
            next = result / 10;
            i--;
        }

        for (int i = 0; i < len / 2; i++){
            char temp = cur[i];
            cur[i] = cur[len - 1 - i];
            cur[len - 1 - i] = temp;
        }
        for (int i = 0; i < len; i++) {
            cur[i] += '0';
        }
        cur[len] = 0;

        char *temp = add(ans, cur);
        free(ans);
        free(cur);
        ans = temp;
    }

    return ans;
}
*/


char* multiply(char* num1, char* num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0') return "0";

    char* ans = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    int* arr = (int*)malloc(sizeof(int) * (len1 + len2));
    memset(ans, 0, sizeof(char) * (len1 + len2 + 1));    
    memset(arr, 0, sizeof(int) * (len1 + len2));
    int len = 0;

    for (int i = len1 - 1; i >= 0; i--){
        int x = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--){
            int y = num2[j] - '0';
            arr[i + j + 1] += x * y;
        }
    }

    for (int i = len1 + len2 - 1; i > 0; i--){
        arr[i - 1] += arr[i] / 10;
        arr[i] %= 10;
    }

    for (int i = arr[0] == 0 ? 1 : 0; i < len1 + len2; i++){
        ans[len++] = arr[i] + '0';
    }

    return ans;
}


void main(){
    printf("%s\n", multiply("123", "456"));
}