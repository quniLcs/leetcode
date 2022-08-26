#include<stdio.h>
#include<stdbool.h>

struct Node{
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

struct Node **t;
bool *created;

struct Node *cloneGraphRecursively(struct Node *s){
    if (!created[s->val]){
        created[s->val] = true;
        t[s->val] = (struct Node*)malloc(sizeof(struct Node));
        t[s->val]->val = s->val;
        t[s->val]->numNeighbors = s->numNeighbors;
        t[s->val]->neighbors = (struct Node**)malloc(sizeof(struct Node*) * s->numNeighbors);
        for (int i = 0; i < s->numNeighbors; i++){
            t[s->val]->neighbors[i] = cloneGraphRecursively(s->neighbors[i]);
        }
    }
    return t[s->val];
}

struct Node *cloneGraph(struct Node *s){
    if (s == NULL) return NULL;
	t = (struct Node**)malloc(sizeof(struct Node*) * 101);
    created = (bool*)malloc(sizeof(bool) * 101);
    memset(created, false, sizeof(bool) * 101);
    return cloneGraphRecursively(s);
}

void main(){
    created = (bool*)malloc(sizeof(bool) * 101);
    memset(created, false, sizeof(bool) * 101);
}