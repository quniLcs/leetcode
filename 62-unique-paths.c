#include<Stdio.h>

int uniquePaths(int m, int n){
    // m-1 steps horizontally
    // n-1 steps vertically
    // m+n-2 steps in total

    // choose m-1 from m+n-2
    // the answer is (m+n-2)(m+n-3)...n/(m-1)(m-2)...1

    // long long data type should be used here with reference to
    // https://leetcode.cn/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/

    long long ans = 1;
    for (int i = 1; i < m; i++){
        ans = ans * (i + n - 1) / i;
    }
    return ans;
}

void main(){
    printf("%d\n", uniquePaths(23, 12));
}