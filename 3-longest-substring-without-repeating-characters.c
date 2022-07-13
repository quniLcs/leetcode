// The algorithms is not so easy with reference to:
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
// However this coding realization is original.


#include<stdio.h>
#include"uthash.h"


struct charinset{
    char cc;
    UT_hash_handle hh;
};

struct charinset *charset;


void add_char(char ccnew){
    struct charinset* c = malloc(sizeof(struct charinset));
    c->cc = ccnew;
    HASH_ADD(hh, charset, cc, sizeof(char), c);
}

struct charinset *find_char(char ccnew){
    struct charinset *c;
    HASH_FIND(hh, charset, &ccnew, sizeof(char), c);
    return c;
}

void delete_char(struct charinset *c){
    HASH_DEL(charset, c);
}

// This function is used to debug
void print_charset(){
	for (struct charinset *c = charset; c != NULL; c = c->hh.next){
		printf("%c", c->cc);
	}
    printf("\n");
}


int lengthOfLongestSubstring(char *s){
    int max, cur, start, end, total = strlen(s);
    charset = NULL;

    for (start = end = max = 0; start < total; start++){
        if (start){
            delete_char(find_char(s[start - 1]));
        }
        while (end < total && find_char(s[end]) == NULL){
            add_char(s[end]);
            end++;
        }
        cur = end - start;
        max = max > cur ? max : cur;
    }

    return max;
}

void main(){
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
}