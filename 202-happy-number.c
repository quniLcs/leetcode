#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    int kk;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int n){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &n, item);
    return item;
}

bool hashInsert(int n){
    struct hashItem* item = hashFind(n);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> kk = n;
        HASH_ADD_INT(hashTable, kk, item);
        return true;
    }
    else{
        return false;
    }
}

bool isHappy(int n){
    hashTable = NULL;
    while (true){
        int m = 0;
        while (n){
            int d = n % 10;
            n /= 10;
            m += d * d;
        }
        if (m == 1) return true;
        else if (hashInsert(m)) n = m;
        else return false;        
    }
}

void main(){
    isHappy(19);
}