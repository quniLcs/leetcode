// with reference to
// https://leetcode.cn/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode-solutio-tqdw/

#include<stdio.h>
#include"uthash.h"

struct hashItem{
    long key;
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

void hashInsert(long ikey, int ival){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> key = ikey;
    item -> val = ival;
    HASH_ADD(hh, hashTable, key, sizeof(long), item);
}

struct hashItem *hashFind(long ikey){
    struct hashItem *item;
    HASH_FIND(hh, hashTable, &ikey, sizeof(long), item);
    return item;
}

char *fractionToDecimal(int numerator, int denominator){
    char *ans = (char*)malloc(sizeof(char) * 10001);
    int i = 0;

    // decide the sign
    if (numerator < 0 && denominator > 0) ans[i++] = '-';
    else if (numerator > 0 && denominator < 0) ans[i++] = '-';
    long numeratorLong = numerator;
    long denominatorLong = denominator;
    if (numerator < 0) numeratorLong = -numeratorLong;
    if (denominator < 0) denominatorLong = -denominatorLong;

    // decide the integer part
    long quotient = numeratorLong / denominatorLong;
    long remainder = numeratorLong % denominatorLong;
    if (quotient){
        char *integer = (char*)malloc(sizeof(char) * 11);
        int j = 0;
        while (quotient){
            integer[j++] = quotient % 10 + '0';
            quotient /= 10;
        }
        while (j){
            ans[i++] = integer[--j];
        }
        free(integer);
    }
    else{
        ans[i++] = '0';
    }

    // decide the point
    if (remainder == 0){
        ans[i] = '\0';
        return ans;
    }
    else{
        ans[i++] = '.';
    }

    // decide the fraction part
    char *fraction = (char*)malloc(sizeof(char) * 10001);
    int j = 0;
    hashTable = NULL;
    while (remainder){
        struct hashItem *item = hashFind(remainder);
        if (item == NULL){
            hashInsert(remainder, j);
            remainder *= 10;
            fraction[j++] = remainder / denominatorLong + '0';
            remainder %= denominatorLong;
        }
        else{  
            int k = j++;        
            while (k > item -> val){
                fraction[k--] = fraction[k-1];
            }
            fraction[k] = '(';
            fraction[j++] = ')';
            break;
        }
    }
    fraction[j] = '\0';
    strcpy(ans + i, fraction);
    free(fraction);

    return ans;
}