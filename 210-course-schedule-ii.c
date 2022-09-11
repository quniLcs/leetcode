#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

int **neighbour;
int *neighbourSize;
int *color;
int *ans;
int ansSize;

bool dfs(int i){
    color[i] = 1;
    for (int j = 0; j < neighbourSize[i]; j += 1){
        if (color[neighbour[i][j]] == 1) return false;
        else if (color[neighbour[i][j]] == 0 && !dfs(neighbour[i][j])) return false;
    }
    color[i] = 2;
    ans[ansSize++] = i;
    return true;
}

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize){
    neighbour = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i += 1){
        neighbour[i] = (int*)malloc(sizeof(int) * numCourses);
    }

    neighbourSize = (int*)malloc(sizeof(int) * numCourses);
    memset(neighbourSize, 0, sizeof(int) * numCourses);

    for (int i = 0; i < prerequisitesSize; i += 1){
        assert(prerequisitesColSize[i] == 2);
        neighbour[prerequisites[i][0]][neighbourSize[prerequisites[i][0]]++] = prerequisites[i][1];
    }

    color = (int*)malloc(sizeof(int) * numCourses);
    memset(color, 0, sizeof(int) * numCourses);

    ans = (int*)malloc(sizeof(int) * numCourses);
    ansSize = 0;

    for (int i = 0; i < numCourses; i += 1){
        if (color[i] == 0 && !dfs(i)){
            *returnSize = 0;
            return NULL;
        }
    }
    
    *returnSize = numCourses;
    return ans;
}