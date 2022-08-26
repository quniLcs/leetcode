// almost directly copied from
// https://leetcode.cn/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/

int candy(int *ratings, int ratingsSize){
    int pre = 1;
    int ans = 1;

    int inc = 1;
    int dec = 0;

    for (int i = 1; i < ratingsSize; i += 1){
        if (ratings[i] > ratings[i - 1]){
            pre += 1;
            ans += pre;
            inc = pre;
            dec = 0;
        }
        else if (ratings[i] == ratings[i - 1]){
            inc = 1;
            dec = 0;
            pre = 1;
            ans += 1;
        }
        else{
            dec += 1;
            if (dec == inc){
                dec += 1;
                inc -= 1;
            }
            pre = 1;
            ans += dec;
        }
    }

    return ans;
}