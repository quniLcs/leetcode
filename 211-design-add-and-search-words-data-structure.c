#include<stdio.h>
#include<stdbool.h>

typedef struct{
    bool flag;
    WordDictionary *next[26];
}
WordDictionary;

WordDictionary *wordDictionaryCreate(){
    WordDictionary *obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    obj -> flag = false;
    memset(obj -> next, NULL, sizeof(WordDictionary*) * 26);
    return obj;
}

void wordDictionaryAddWord(WordDictionary *obj, char *word){
    WordDictionary *current = obj;
    for (int i = 0, n = strlen(word); i < n; i += 1){
        int j = word[i] - 'a';
        if (current -> next[j] == NULL){
            current -> next[j] = (WordDictionary*)malloc(sizeof(WordDictionary));
            current -> next[j] -> flag = false;
            memset(current -> next[j] -> next, NULL, sizeof(WordDictionary*) * 26);
        }
        current = current -> next[j];
    }
    current -> flag = true;
}

bool wordDictionarySearch(WordDictionary *obj, char *word){
    WordDictionary *current = obj;
    for (int i = 0, n = strlen(word); i < n; i += 1){
        if (word[i] == '.'){
            for (char alpha = 'a'; alpha <= 'z'; alpha += 1){
                word[i] = alpha;
                if (wordDictionarySearch(current, word + i)){
                    return true;
                }
            }
            word[i] = '.';
            return false;
        }
        else{
            int j = word[i] - 'a';
            if (current -> next[j] == NULL) return false;
            else current = current -> next[j];
        }
    }
    return current -> flag;
}

void wordDictionaryFree(WordDictionary *obj){
    for (int i = 0; i < 26; i += 1){
        if (obj -> next[i]){
            wordDictionaryFree(obj -> next[i]);
        }
    }
    free(obj);
}

/*
WordDictionary* obj = wordDictionaryCreate();
wordDictionaryAddWord(obj, word);
bool ans = wordDictionarySearch(obj, word);
wordDictionaryFree(obj);
*/
