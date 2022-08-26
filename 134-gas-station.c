#include<assert.h>

/* original code but time limit exceeded
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize){
    int n = gasSize;
    assert(n == costSize);

    for (int i = 0; i < n; i += 1){
        gas[i] -= cost[i];
    }

    for (int i = 0; i < n; i += 1){
        int sum = 0;
        for (int j = i; sum >= 0 && j < n; sum += gas[j], j += 1);
        for (int j = 0; sum >= 0 && j < i; sum += gas[j], j += 1);
        if (sum >= 0) return i;
    }
    return -1;
}
*/

// with reference to:
// https://leetcode.cn/problems/gas-station/solution/jia-you-zhan-by-leetcode-solution/
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize){
    int n = gasSize;
    assert(n == costSize);

    int i = 0;
    while (i < n){
        int j = 0;
        int gasSum = 0;
        int costSum = 0;
        while (j < n){
            int k = (i + j) % n;
            gasSum += gas[k];
            costSum += cost[k];
            if (costSum > gasSum) break;
            else j += 1;
        }
        if (j == n) return i;
        else i += j + 1;
    }
    return -1;
}