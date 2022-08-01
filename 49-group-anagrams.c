/* original code
#include<stdbool.h>

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes){
    char ***result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    *returnSize = 0;

    int **counter = (int**)malloc(sizeof(int*) * strsSize);
    bool new = true;

    for (int i = 0; i < strsSize; i++){
        if (new) counter[*returnSize] = (int*)malloc(sizeof(int) * 26);
        memset(counter[*returnSize], 0, sizeof(int) * 26);

        for (int j = 0, n = strlen(strs[i]); j < n; j++){
            counter[*returnSize][strs[i][j] - 'a']++;
        }
        
        int target = -1;
        for (int j = 0; j < *returnSize; j++){
            bool same = true;
            for (int k = 0; k < 26; k++){
                if (counter[j][k] != counter[*returnSize][k]){
                    same = false;
                    break;
                }
            }
            if (same){
                target = j;
                break;
            }
        }

        if (target >= 0){  // 0 <= target < *returnSize
            result[target][(*returnColumnSizes)[target]] = strs[i];
            (*returnColumnSizes)[target]++;
            new = false;
        }
        else{  // target == -1
            result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            result[*returnSize][0] = strs[i];
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
            new = true;
        }
    }
    
    return result;
}
*/


// optimize by hash table with reference to
// https://leetcode.cn/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/
#include<stdio.h>
#include"uthash.h"

struct hashItem{
    int counter[26];
    int index;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int *ikey){
    struct hashItem *item;
    HASH_FIND(hh, hashTable, ikey, sizeof(int) * 26, item);
    return item;
}

int hashInsert(int *ikey, int *returnSize){
    struct hashItem *item = hashFind(ikey);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        memcpy(item->counter, ikey, sizeof(int) * 26);
        item->index = *returnSize;
        HASH_ADD(hh, hashTable, counter, sizeof(int) * 26, item);
    }
    return item->index;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes){
    char ***result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    *returnSize = 0;

    for (int i = 0; i < strsSize; i++){
        int counter[26] = {0};
        for (int j = 0, n = strlen(strs[i]); j < n; j++){
            counter[strs[i][j] - 'a']++;
        }
        
        int target = hashInsert(counter, returnSize);
        if (target == *returnSize){
            result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            result[*returnSize][0] = strs[i];
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        }
        else{
            result[target][(*returnColumnSizes)[target]] = strs[i];
            (*returnColumnSizes)[target]++;
        }
    }
    
    return result;
}

void main(){
    char *strs[] = {"ant", "ant"};
    int returnSize;
    int *returnColumnSizes;
    char ***result = groupAnagrams(strs, 2, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++){
        for (int j = 0 ; j < returnColumnSizes[i]; j++){
            printf("%s\t", result[i][j]);
        }
        printf("\n");
    }
}