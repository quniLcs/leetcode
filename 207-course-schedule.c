#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

int **neighbour;
int *neighbourSize;
int *color;

bool dfs(int i){
    color[i] = 1;
    for (int j = 0; j < neighbourSize[i]; j += 1){
        if (color[neighbour[i][j]] == 1) return false;
        else if (color[neighbour[i][j]] == 0 && !dfs(neighbour[i][j])) return false;
    }
    color[i] = 2;
    return true;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize){
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

    for (int i = 0; i < numCourses; i += 1){
        if (color[i] == 0 && !dfs(i)) return false;
    }
    return true;
}

void main(){
    int numCourses = 2;

    int prerequisitesSize = 1;
    int *prerequisitesColSize = (int*)malloc(sizeof(int) * prerequisitesSize);
    for (int i = 0; i < prerequisitesSize; i += 1){
        prerequisitesColSize[i] = 2;
    }

    int **prerequisites = (int**)malloc(sizeof(int*) * prerequisitesSize);
    for (int i = 0; i < prerequisitesSize; i += 1){
        prerequisites[i] = (int*)malloc(sizeof(int) * prerequisitesColSize[i]);
    }

    prerequisites[0][0] = 0;
    prerequisites[0][1] = 1;

    printf("%d\n", canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize));
}