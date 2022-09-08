#include<stdbool.h>
#define INT_MAX 2147483647

/* the first version using 335ms
int rangeBitwiseAnd(int left, int right){
    int ans = INT_MAX;
    int cur = left;
    if (right == INT_MAX) right -= 1;
    while (ans && cur <= right){
        ans &= cur;
        cur += 1;
    }
    return ans;
}
*/

// using 12ms
int rangeBitwiseAnd(int left, int right){
    int ans = INT_MAX;
    int step = 1;
    int cur = left;
    while (true){
        ans &= cur;
        step = ans - (ans & ans - 1);
        if (step == 0) break;
        else if (cur / step * step <= right - step) cur = cur / step * step + step;
        else break;
    }
    return ans;
}

void main(){
    rangeBitwiseAnd(5, 8);
}