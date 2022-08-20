int maxProfit(int *prices, int pricesSize){
    int ans = 0;
    for (int time = 1; time < pricesSize; time += 1){
        if (prices[time] > prices[time - 1]){
            ans += prices[time] - prices[time - 1];
        }
    }
    return ans;
}