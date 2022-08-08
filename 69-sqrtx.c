#include<stdio.h>

int mySqrt(int x){
    // 0 <= x <= 2147483647
    // 0 <= sqrt(x) <= 46340

    if (x >= 2147395600) return 46340;

    int left = 0;
    int right = 46340;

    while (left < right){
        int mid = (left + right) / 2;
        int cur = mid * mid;

        if (cur == x){
            return mid;
        }
        else if (cur < x){
            if ((mid + 1) * (mid + 1) > x) return mid;
            else left = mid + 1;
        }
        else{  // cur > x
            right = mid - 1;
        }
    }

    return left;
}

void main(){
    printf("%d\n", mySqrt(0));
    printf("%d\n", mySqrt(4));
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(2147395599));
    printf("%d\n", mySqrt(2147395600));
    printf("%d\n", mySqrt(2147483647));
}