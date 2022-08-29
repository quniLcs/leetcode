// with reference to
// https://leetcode.cn/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-le-tq8f/

#include<stdio.h>
#include<assert.h>
#include"uthash.h"

struct hashItem{
    int key[2];
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int x, int y){
    int ikey[2] = {x, y};
    struct hashItem *item;
    HASH_FIND(hh, hashTable, ikey, sizeof(int) * 2, item);
    return item;
}

void hashEdit(int x, int y){
    struct hashItem *item = hashFind(x, y);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> key[0] = x;
        item -> key[1] = y;
        item -> val = 2;
        HASH_ADD(hh, hashTable, key, sizeof(int) * 2, item);
    }
    else{
        item -> val += 1;
    }
}

int abs(int x){
    return x >= 0 ? x : -x;
}

int gcd(int x, int y){
    x = abs(x);
    y = abs(y);
    if (x < y){
        int t = y;
        y = x;
        x = t;
    }
    while (y){
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int maxPoints(int **points, int pointsSize, int *pointsColSize){
    for (int i = 0; i < pointsSize; i += 1){
        assert(pointsColSize[i] == 2);
    }

    int ans = 1;
    for (int i = 0; i < pointsSize; i += 1){
        hashTable = NULL;
        for (int j = i + 1; j < pointsSize; j += 1){
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            int z = gcd(x, y);
            int s = x < 0 || x == 0 && y < 0 ? -1 : 1;
            hashEdit(s * x / z, s * y / z);
        }
        struct hashItem *item, *temp;
        HASH_ITER(hh, hashTable, item, temp){
            if (item -> val > ans) ans = item -> val;
            HASH_DEL(hashTable, item);
            free(item);
        }
    }
    return ans;
}

void main(){
    int pointsSize = 7;

    int *pointsColSize = (int*)malloc(sizeof(int) * pointsSize);
    int **points = (int**)malloc(sizeof(int*) * pointsSize);
    for (int i = 0; i < pointsSize; i += 1){
        pointsColSize[i] = 2;
        points[i] = (int*)malloc(sizeof(int) * 2);
    }
    points[0][0] = 0;
    points[0][1] = 0;
    points[1][0] = 4;
    points[1][1] = 5;
    points[2][0] = 7;
    points[2][1] = 8;
    points[3][0] = 8;
    points[3][1] = 9;
    points[4][0] = 5;
    points[4][1] = 6;
    points[5][0] = 3;
    points[5][1] = 4;
    points[6][0] = 1;
    points[6][1] = 1;

    maxPoints(points, pointsSize, pointsColSize);
}