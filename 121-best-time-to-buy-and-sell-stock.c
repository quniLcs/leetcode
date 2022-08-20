int maxProfit(int *prices, int pricesSize){
    int time = 0;
    int buy = -1;
    int sell = -2;
    int ans = 0;

    while (time < pricesSize){
        while (time < pricesSize - 1 && prices[time] >= prices[time + 1]) time++;
        if (time == pricesSize - 1) break;
        else if (buy == -1 || prices[buy] >= prices[time]) buy = time++;

        while (time < pricesSize - 1 && prices[time] <= prices[time + 1]) time++;
        if (sell < buy || prices[sell] <= prices[time]) sell = time++;

        if (sell > buy && prices[sell] - prices[buy] > ans) ans = prices[sell] - prices[buy];
    }

    return ans;
}