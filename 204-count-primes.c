/* original code but time limit exceeded
#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    int kk;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int key){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &key, item);
    return item;
}

void hashInsert(int key){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> kk = key;
    HASH_ADD_INT(hashTable, kk, item);
}

int hashCount(){
    return HASH_COUNT(hashTable);
}

int countPrimes(int n){
    hashTable = NULL;
    for (int i = 2; i < n; i += 1){
        bool isPrime = true;
        for (struct hashItem *item = hashTable; item; item = item -> hh.next){
            if (i % item -> kk == 0){
                isPrime = false;
                break;
            }
        }
        if (isPrime) hashInsert(i);
    }
    return hashCount();
}
*/


// almost directly copied from
// https://leetcode.cn/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/
#include<stdbool.h>

int countPrimes(int n) {
    bool *isPrime = (bool*)malloc(sizeof(bool) * n);
    memset(isPrime, true, sizeof(bool) * n);

    int count = 0;
    for (int i = 2; i < n; i += 1){
        if (isPrime[i]){
            count += 1;
            for (long j = (long)i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
    }
    return count;
}


void main(){
    printf("%d\n", countPrimes(499979));
}