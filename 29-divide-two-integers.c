#include<stdio.h>
#include<stdbool.h>
#define INT_MIN -2147483648
#define INT_MAX  2147483647


/* brutal force solution time limit exceeded
int divide(int dividend, int divisor){
    if (dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    else if (divisor == INT_MIN){
        if (dividend == INT_MIN) return 1;
        else return 0;
    }
    else{
        int sign = 1;
        if (divisor < 0){
            divisor = -divisor;
            sign = -1;
        }
        int value = 0;
        if (dividend >= 0){
            while (dividend >= divisor){
                dividend -= divisor;
                value++;
            }
        }
        else{
            while (dividend <= -divisor){
                dividend += divisor;
                value++;
            }
            value = -value;
        }
        return sign * value;
    }
}
*/


// binary search with reference to:
// https://leetcode.cn/problems/divide-two-integers/solution/liang-shu-xiang-chu-by-leetcode-solution-5hic/
/*
bool quickAddCheck(int divisor, int mid, int dividend){
    // divisor < 0
    // dividend < 0
    // mid >= 0

    // check if mid * divisor >= dividend
    int result = 0;
    while (mid){
        if (mid & 1){  // mid % 2 == 1
            if (result < dividend - divisor) return false;
            result += divisor;  // result + divisor >= dividend
        }
        if (mid != 1){
            if (divisor < dividend - divisor) return false;
            divisor += divisor;  // divisor + divisor >= dividend
        }
        mid >>= 1;
    }
    return true;
}

int divide(int dividend, int divisor){
    if (dividend == INT_MIN){
        if (divisor == -1) return INT_MAX;  // a real overflow
        if (divisor ==  1) return INT_MIN;  // not within the range of binary search
    }
    else if (dividend == 0){
        return 0;
        // so that quickAddCheck won't cause overflow
    }
    
    int sign = 1;
    if (dividend > 0){
        dividend = -dividend;
        sign = -sign;
    }
    if (divisor > 0){
        divisor = -divisor;
        sign = -sign;
    }

    int left = 0;
    int right = INT_MAX;
    int value = 0;
    while (left <= right){
        int mid = left + ((right - left) >> 1);
        if (quickAddCheck(divisor, mid, dividend)){
            value = mid;
            if (mid == INT_MAX) break;
            else left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return sign * value;
}
*/


// quasi-binary search
int divide(int dividend, int divisor){
    if (dividend == INT_MIN){
        if (divisor == -1) return INT_MAX;  // a real overflow
        if (divisor ==  1) return INT_MIN;  // not within the range of binary search
    }
    else if (dividend == 0){
        return 0;
        // so that building candidate won't cause overflow
    }

    int sign = 1;
    if (dividend > 0){
        dividend = -dividend;
        sign = -sign;
    }
    if (divisor > 0){
        divisor = -divisor;
        sign = -sign;
    }

    int candidate[32] = {divisor};
    int candidateLength = 1;
    while (candidate[candidateLength - 1] >= dividend - candidate[candidateLength - 1]){
        candidate[candidateLength] = candidate[candidateLength - 1] + candidate[candidateLength - 1];
        candidateLength++;
    }

    int value = 0;
    for (int index = candidateLength - 1; index >= 0; index--){
        if (candidate[index] >= dividend){
            value += (1 << index);
            dividend -= candidate[index];
        }
    }

    return sign * value;
}


void main(){
    printf("%d\n", divide(10, 3));
    printf("%d\n", divide(7, -3));
    printf("%d\n", divide(-2147483648, 1));
}