#include<stdio.h>
#include<stdbool.h>

/* the coarse original code
bool isPalindrome(int x){
    if (x < 0) return false;
    else if (x == 0) return true;
    else{  // x > 0
        int len = 0;
        int digit[10];
        while (x){
            digit[len] = x % 10;
            x /= 10;
            len++;
        }
        for (int ind = 0; ind < len / 2; ind++){
            if (digit[ind] != digit[len - ind - 1]){
                return false;
            }
        }
        return true;
    }
}
*/

// more space-efficient solution with reference to:
// https://leetcode.cn/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }

    int reverted = 0;
    while (x > reverted) {
        reverted = reverted * 10 + x % 10;
        x /= 10;
    }

    return x == reverted || x == reverted / 10;
}

void main(){
    printf("%d\n", isPalindrome(10));
}