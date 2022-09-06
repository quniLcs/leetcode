#include<stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int maxProfit(int k, int *prices, int pricesSize){
    if (k == 0 || pricesSize == 0) return 0;

    int *buy = (int*)malloc(sizeof(int) * k);
    int *sell = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i += 1){
        buy[i] = -prices[0];
        sell[i] = 0;
    }

    for (int time = 1; time < pricesSize; time += 1){
        buy[0] = max(buy[0], -prices[time]);
        sell[0] = max(sell[0], buy[0] + prices[time]);
        for (int i = 1; i < k; i += 1){
            buy[i] = max(buy[i], sell[i - 1] - prices[time]);
            sell[i] = max(sell[i], buy[i] + prices[time]);
        }
    }

    return sell[k - 1];
}

void main(){
    maxProfit(2, NULL, 0);
}