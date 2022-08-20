// almost directly copied from
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iii-by-wrnt/

int max(int a, int b){
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for (int time = 1; time < pricesSize; time += 1){
        buy1 = max(buy1, -prices[time]);
        sell1 = max(sell1, buy1 + prices[time]);
        buy2 = max(buy2, sell1 - prices[time]);
        sell2 = max(sell2, buy2 + prices[time]);
    }

    return sell2;
}