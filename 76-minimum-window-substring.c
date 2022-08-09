// with reference to:
// https://leetcode.cn/problems/minimum-window-substring/solution/zui-xiao-fu-gai-zi-chuan-by-leetcode-solution/


#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"


struct hashItem{
    char key;
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;


struct hashItem *find(char ikey){
    struct hashItem *item;
    HASH_FIND(hh, hashTable, &ikey, sizeof(char), item);
    return item;
}

void insert(char ikey){
    struct hashItem *item = find(ikey);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> key = ikey;
        item -> val = -1;
        HASH_ADD(hh, hashTable, key, sizeof(char), item);
    }
    else{
        item -> val -= 1;
    }
}

bool edit(char ikey, int ival){
    struct hashItem *item = find(ikey);
    if (item == NULL){
        return false;
    }
    else{
        item -> val += ival;
        return true;
    }
}

bool check(){
    for (struct hashItem *item = hashTable; item; item = item -> hh.next){
        if (item -> val < 0) return false;
    }
    return true;
}


char *minWindow(char *s, char *t){
    int m = strlen(s);
    int n = strlen(t);

    hashTable = NULL;
    for (int j = 0; j < n; j++){
        insert(t[j]);
    }

    // initialize left index
    int left = 0;
    while (left < m && !find(s[left])){
        left++;
    }

    // initialize right index
    int right = left;
    while (right < m && (!edit(s[right++], 1) || !check()));

    // fail to initialize
    if (!check()) return "";

    int len = right - left;
    int start = left;
    while (1){
        edit(s[left++], -1);

        // update the left index
        while (left < m && !find(s[left])){
            left++;
        }

        // update the right index
        if (!check()){
            while (right < m && (!edit(s[right++], 1) || !check()));
        }

        // fail to update
        if (!check()) break;

        if (right - left < len){
            len = right - left;
            start = left;
        }
    }

    char *ans = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(ans, s + start, len);
    ans[len] = '\0';
    return ans;
}


void main(){
    printf("%s\n", minWindow("ADOBECODEBANC", "ABC"));
    printf("%s\n", minWindow("a", "a"));
}