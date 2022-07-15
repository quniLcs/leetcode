#include<stdio.h>
#define INT_MIN -2147483648
#define INT_MAX  2147483647


/* The coarse original code
int myAtoi(char *s){
    int ind = 0;
    int len = 0;
    int sign = 1;
    int num = 0;

    int digit[11];
    int cur_digit;
    int min_digit[10] = {-2, -1, -4, -7, -4, -8, -3, -6, -4, -8};
    int max_digit[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

    // first, deal with spaces
    while (s[ind] == ' '){
        ind++;
    }

    // next, deal with the sign if there exist one
    if (s[ind] == '-'){
        sign = -1;
        ind++;
    }
    else if (s[ind] == '+'){
        ind++;
    }

    // finally, deal with the numbers
    while (s[ind] == '0'){
        ind++;
    }
    while ('0' <= s[ind] && s[ind] <= '9'){
        cur_digit = sign * (s[ind] - '0');
        digit[len] = cur_digit;
        ind++;
        len++;

        if (len == 10){
            if (sign == -1){  // negative
                for (int chk = 0; chk < 10; chk++){
                    if (digit[chk] < min_digit[chk]){
                        return INT_MIN;
                    }
                    else if (digit[chk] > min_digit[chk]){
                        break;
                    }
                }
            }
            else{
                for (int chk = 0; chk < 10; chk++){
                    if (digit[chk] > max_digit[chk]){
                        return INT_MAX;
                    }
                    else if (digit[chk] < max_digit[chk]){
                        break;
                    }
                }    
            }
        }
        else if (len == 11){
            if (sign == -1){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }

        num = num * 10 + cur_digit;
    }

    return num;
}
*/


// a long int should be used with reference to:
// https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
/*
int myAtoi(char *s){
    int ind = 0;
    int len = 0;
    int sign = 1;
    long num = 0;

    // first, deal with spaces
    while (s[ind] == ' '){
        ind++;
    }

    // next, deal with the sign if there exist one
    if (s[ind] == '-'){
        sign = -1;
        ind++;
    }
    else if (s[ind] == '+'){
        ind++;
    }

    // finally, deal with the numbers
    while (s[ind] == '0'){
        ind++;
    }
    while ('0' <= s[ind] && s[ind] <= '9'){
        num = num * 10 + sign * (s[ind] - '0');
        ind++;
        len++;

        if (len >= 10){
            if (sign == -1 && num < INT_MIN){
                return INT_MIN;
            }
            else if (sign == 1 && num > INT_MAX){
                return INT_MAX;
            }
        }
    }

    return num;
}
*/

// automaton should be used with further reference to the above link
int category(char c) {
    if (c == ' ') return 0;
    else if (c == '+' || c == '-') return 1;
    else if (c == '0') return 2;
    else if ('0' < c && c <= '9') return 3;
    else return 4;
}

enum states{START, SIGN, ZERO, NUM, END};

enum states transfer[4][5] = {
        {START, SIGN, ZERO, NUM, END},
        {END, END, ZERO, NUM, END},
        {END, END, ZERO, NUM, END},
        {END, END, NUM, NUM, END},
    };

int myAtoi(char *s){
    enum states state = START;
    int ind = 0;
    int len = 0;
    int sign = 1;
    long num = 0;
    
    while (1){
        state = transfer[state][category(s[ind])];
        if (state == SIGN){
            if (s[ind] == '-'){
                sign = -1;
            }
        }
        else if (state == NUM){
            num = num * 10 + sign * (s[ind] - '0');
            len++;
            if (len >= 10){
                if (sign == -1 && num < INT_MIN){
                    return INT_MIN;
                }
                else if (sign == 1 && num > INT_MAX){
                    return INT_MAX;
                }
            }
        }
        else if (state == END){
            return num;
        }
        ind++;
    }
}

void main(){
    printf("%d\n", myAtoi("1095502006p8"));
}