#include<assert.h>

/* original code
void fillIslands(char **grid, int i, int j, int m, int n){
    grid[i][j] = '0';
    if (i > 0 && grid[i - 1][j] == '1') fillIslands(grid, i - 1, j, m, n);
    if (i < m - 1 && grid[i + 1][j] == '1') fillIslands(grid, i + 1, j, m, n);
    if (j > 0 && grid[i][j - 1] == '1') fillIslands(grid, i, j - 1, m, n);
    if (j < n - 1 && grid[i][j + 1] == '1') fillIslands(grid, i, j + 1, m, n);
}

int numIslands(char **grid, int gridSize, int *gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(gridColSize[i] == n);
    }

    int count = 0;
    for (int i = 0; i < m; i += 1){
        for (int j = 0; j < n; j += 1){
            if (grid[i][j] == '1'){
                count += 1;
                fillIslands(grid, i, j, m, n);
            }
        }
    }
    return count;
}
*/

// though it is enough to use DFS
// it is still necessary to try to write a UnionFind
// with reference to https://leetcode.cn/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
struct UnionFind{
    int *parent;
    int count;
};

/* a more general initialization
struct UnionFind *Initialize(int n){
    struct UnionFind *obj = (struct UnionFind*)malloc(sizeof(struct UnionFind));
    obj -> parent = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1){
        obj -> parent[i] = -1;
    }
    obj -> count = n;
    return obj;
}
*/

struct UnionFind *Initialize(char **grid, int m, int n){
    struct UnionFind *obj = (struct UnionFind*)malloc(sizeof(struct UnionFind));
    obj -> parent = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i += 1){
        obj -> parent[i] = -1;
    }
    obj -> count = 0;
    for (int i = 0; i < m; i += 1){
        for (int j = 0; j < n; j += 1){
            if (grid[i][j] == '1'){
                obj -> count += 1;
            }
        }
    }
    return obj;
}

int Find(struct UnionFind *obj, int i){
    if (obj -> parent[i] < 0){
        return i;
    }
    else{
        obj -> parent[i] = Find(obj, obj -> parent[i]);
        return obj -> parent[i];
    }
}
        
void Union(struct UnionFind *obj, int i, int j){
    int p = Find(obj, i);
    int q = Find(obj, j);
    if (p != q){
        obj -> count -= 1;
        if (obj -> parent[p] <= obj -> parent[q]){
            obj -> parent[p] += obj -> parent[q];
            obj -> parent[q] = p;
        }
        else{
            obj -> parent[q] += obj -> parent[p];
            obj -> parent[p] = q;
        }
    }
}

int numIslands(char **grid, int gridSize, int *gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(gridColSize[i] == n);
    }

    struct UnionFind *obj = Initialize(grid, m, n);
    for (int i = 0; i < m; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (grid[i][j] == '1'){
                if (i > 0 && grid[i - 1][j] == '1') Union(obj, i * n + j, (i - 1) * n + j);
                if (i < m - 1 && grid[i + 1][j] == '1') Union(obj, i * n + j, (i + 1) * n + j);
                if (j > 1 && grid[i][j - 1] == '1') Union(obj, i * n + j, i * n + (j - 1));
                if (j < n - 1 && grid[i][j + 1] == '1') Union(obj, i * n + j, i * n + (j + 1));
            }
        }
    }

    return obj -> count;
}