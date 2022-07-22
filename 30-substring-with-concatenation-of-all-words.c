#include<stdio.h>
#include"uthash.h"


struct hashItem{
    char key[32];
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;


struct hashItem *find(char *ikey){
    struct hashItem *item;
    HASH_FIND_STR(hashTable, ikey, item);
    return item;
}

void edit(char *ikey, int ival){
    struct hashItem *item = find(ikey);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        strcpy(item->key, ikey);
        item->val = ival;
        HASH_ADD_STR(hashTable, key, item);
    }
    else{
        item->val += ival;
        if (item->val == 0){
            HASH_DEL(hashTable, item);
        }
    }
}

void clear(){
    struct hashItem *current, *temp;
    HASH_ITER(hh, hashTable, current, temp){
        HASH_DEL(hashTable, current);
    }
}


int *findSubstring(char *s, char **words, int wordsSize, int *returnSize){    
    int wordLength = strlen(words[0]);
    int stringLength = strlen(s);

    char *word = (char*)malloc(sizeof(char) * (wordLength + 1));
    word[wordLength] = '\0';

    int *result = (int*)malloc(sizeof(int) * stringLength);
    *returnSize = 0;

    for (int i = 0; i < wordLength; i++){
        if (i + wordsSize * wordLength > stringLength) break;
        hashTable = NULL;
        for (int j = 0; j < wordsSize; j++){
            strncpy(word, s + i + j * wordLength, wordLength);
            edit(word, 1);
            edit(words[j], -1);
        }
        for (int j = i; j + wordsSize * wordLength <= stringLength; j += wordLength){
            if (j != i){
                strncpy(word, s + j + (wordsSize - 1) * wordLength, wordLength);
                edit(word, 1);
                strncpy(word, s + j - wordLength, wordLength);
                edit(word, -1);
            }
            if (HASH_COUNT(hashTable) == 0){
                result[*returnSize] = j;
                (*returnSize)++;
            }
        }
        clear();
    }
    
    return result;
}


void main(){
    char *s = "barfoothefoobarman";
    char *words[2] = {"foo", "bar"};
    int wordsSize = 2;
    int returnSize = 0;

    int *result = findSubstring(s, words, wordsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) printf("%d\n", result[i]);
}