#include<stdbool.h>

bool *vis;
int *ans;
int ansSize;
int maxSize;

bool grayCodeRecursively(int n){
    if (ansSize == maxSize){
        int dif;
        if (ans[ansSize - 1] >= ans[0]) dif = ans[ansSize - 1] - ans[0];
        else dif = ans[0] - ans[ansSize - 1];

        int count = 0;
        while (dif){
            if (dif & 1) count++;
            dif >>= 1;
        }

        if (count == 1) return true;
        else return false;
    }
    else{
        for (int i = 0; i < n; i++){
            if ((ans[ansSize - 1] >> i & 1) == 0) ans[ansSize] = ans[ansSize - 1] + (1 << i);
            else ans[ansSize] = ans[ansSize - 1] - (1 << i);

            if (vis[ans[ansSize]] == false){
                vis[ans[ansSize]] = true;
                ansSize++;
                if (grayCodeRecursively(n)) return true;
                vis[ans[ansSize]] = false;
                ansSize--;
            }
        }
        return false;
    }
}

int *grayCode(int n, int *returnSize){
    *returnSize = 1 << n;

    ans = (int*)malloc(sizeof(int) * (*returnSize));
    vis = (bool*)malloc(sizeof(bool) * (*returnSize));
    memset(vis, false, sizeof(bool) * (*returnSize));

    ans[0] = 0;
    vis[0] = true;
    ansSize = 1;
    maxSize = *returnSize;

    grayCodeRecursively(n);
    return ans;
}

void main(){
    int n = 1;
    int returnSize = 0;
    grayCode(n, &returnSize);
}