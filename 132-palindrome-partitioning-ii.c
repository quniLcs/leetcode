#include<stdio.h>
#include<stdbool.h>

/* dynamic programming but O(n^3) and time limit exceeded
int minCut(char *s){
    int n = strlen(s);

    bool **isPalindrome = (bool**)malloc(sizeof(bool*) * n);
    for (int i = 0; i < n; i += 1){
        isPalindrome[i] = (bool*)malloc(sizeof(bool) * (n - i + 1));
        isPalindrome[i][0] = isPalindrome[i][1] = true;
    }
    for (int j = 2; j <= n; j += 1){
        for (int i = 0; i + j <= n; i += 1){
            isPalindrome[i][j] = (s[i] == s[i + j - 1]) && isPalindrome[i + 1][j - 2];
        }
    }

    int **numCut = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i += 1){
        numCut[i] = (int*)malloc(sizeof(int) * (n - i + 1));
    }
    for (int j = 1; j <= n; j += 1){
        for (int i = 0; i + j <= n; i += 1){
            if (isPalindrome[i][j]){
                numCut[i][j] = 0;
            }
            else{
                numCut[i][j] = j;
                for (int k = 1; k < j; k += 1){
                    int curCut = numCut[i][k] + numCut[i + k][j - k] + 1;
                    if (curCut < numCut[i][j]) numCut[i][j] = curCut;
                }
            }
        }
    }

    return numCut[0][n];
}
*/

// with reference to
// https://leetcode.cn/problems/palindrome-partitioning-ii/solution/fen-ge-hui-wen-chuan-ii-by-leetcode-solu-norx/
int minCut(char *s){
    int n = strlen(s);

    bool **isPalindrome = (bool**)malloc(sizeof(bool*) * n);
    for (int i = 0; i < n; i += 1){
        isPalindrome[i] = (bool*)malloc(sizeof(bool) * (n - i + 1));
        isPalindrome[i][0] = isPalindrome[i][1] = true;
    }
    for (int j = 2; j <= n; j += 1){
        for (int i = 0; i + j <= n; i += 1){
            isPalindrome[i][j] = (s[i] == s[i + j - 1]) && isPalindrome[i + 1][j - 2];
        }
    }

    int *numCut = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1){
        if (isPalindrome[0][i + 1]){
            numCut[i] = 0;
        }
        else{
            numCut[i] = i;
            for (int j = 0; j < i; j += 1){
                if (isPalindrome[j + 1][i - j] && numCut[j] + 1 < numCut[i]){
                    numCut[i] = numCut[j] + 1;
                }
            }
        }
    }

    return numCut[n - 1];
}