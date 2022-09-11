#include<stdio.h>
#include<stdbool.h>

struct TrieItem{
    bool flag;
    struct TrieItem *next[26];
};

typedef struct{
    struct TrieItem *root;
}
Trie;

Trie* trieCreate(){
    Trie *obj = (Trie*)malloc(sizeof(Trie));
    obj -> root = (struct TrieItem*)malloc(sizeof(struct TrieItem));
    obj -> root -> flag = false;
    memset(obj -> root -> next, NULL, sizeof(struct TrieItem*) * 26);
    return obj;
}

void trieInsert(Trie *obj, char *word){
    struct TrieItem *current = obj -> root;
    for (int i = 0, n = strlen(word); i < n; i += 1){
        int j = word[i] - 'a';
        if (current -> next[j] == NULL){
            current -> next[j] = (struct TrieItem*)malloc(sizeof(struct TrieItem));
            current -> next[j] -> flag = false;
            memset(current -> next[j] -> next, NULL, sizeof(struct TrieItem*) * 26);
        }
        current = current -> next[j];
    }
    current -> flag = true;
}

bool trieSearch(Trie *obj, char *word){
    struct TrieItem *current = obj -> root;
    for (int i = 0, n = strlen(word); i < n; i += 1){
        int j = word[i] - 'a';
        if (current -> next[j] == NULL){
            return false;
        }
        current = current -> next[j];
    }
    return current -> flag;
}

bool trieStartsWith(Trie *obj, char *prefix){
    struct TrieItem *current = obj -> root;
    for (int i = 0, n = strlen(prefix); i < n; i += 1){
        int j = prefix[i] - 'a';
        if (current -> next[j] == NULL){
            return false;
        }
        current = current -> next[j];
    }
    return true;
}

void itemFree(struct TrieItem *root){
    for (int i = 0; i < 26; i += 1){
        if (root -> next[i]){
            itemFree(root -> next[i]);
        }
    }
    free(root);
}

void trieFree(Trie *obj){
    itemFree(obj -> root);
    free(obj);
}

/*
Trie* obj = trieCreate();
trieInsert(obj, word);
bool ans = trieSearch(obj, word);
bool ans = trieStartsWith(obj, prefix);
trieFree(obj);
*/