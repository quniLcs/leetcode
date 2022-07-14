// with reference to:
// https://leetcode.cn/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode-solution-4n3u/

#include<stdio.h>

/* an ordinary solution
char *convert(char *s, int numRows){
    if (numRows == 1){
        return s;
    }

    int n = strlen(s);
    int r = numRows;
    int t = 2 * r - 2;
    int c = (n + t - 1) / t * (r - 1);

    char **mat = (char **)malloc(sizeof(char *) * r);
    for (int i = 0; i < r; i++) {
        mat[i] = (char *)malloc(sizeof(char) * c); 
        memset(mat[i], 0, sizeof(char) * c);                       
    }
    for (int i = 0, x = 0, y = 0; i < n; i++) {
        mat[x][y] = s[i];
        if (i % t < r - 1) {
            x++;
        }
        else {
            x--;
            y++;
        }
    }

    int p = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j]){
                s[p++] = mat[i][j];
            }
        }
        free(mat[i]);
    }
    free(mat);

    return s;
}
*/

/* // Thought it is said to be more space-efficient, it is actually not
char *convert(char *s, int numRows){
    if (numRows == 1){
        return s;
    }

    int n = strlen(s);
    int r = numRows;
    int t = 2 * r - 2;

    char **mat = (char **)malloc(sizeof(char *) * r);
    for (int i = 0; i < r; i++) {
        mat[i] = (char *)malloc(sizeof(char) * n); 
        memset(mat[i], 0, sizeof(char) * n);                       
    }

    int *col = (int *)malloc(sizeof(int) * r);
    memset(col, 0, sizeof(int) * r);
    
    for (int i = 0, x = 0; i < n; i++) {
        mat[x][col[x]++] = s[i];
        i % t < r - 1 ? x++ : x--;
    }

    int p = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < col[i]; j++){
            s[p++] = mat[i][j];
        }
        free(mat[i]);
    }
    free(mat);
    free(col);

    return s;
}
*/

char *convert(char *s, int numRows){
    if (numRows == 1){
        return s;
    }

    int n = strlen(s);
    int r = numRows;
    int t = 2 * r - 2;

    char *ans = (char *)malloc(sizeof(char) * (n + 1));

    int pos = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j + i < n; j += t){ // the first index in every cycle
            ans[pos++] = s[j + i];
            if (i > 0 && i < r - 1 && j + t - i < n) {
                ans[pos++] = s[j + t - i];
            }
        }
    }
    ans[pos] = '\0';
    
    return ans;
}

void main(){
    printf("%s\n", convert("PAYPALISHIRING", 3));
    // "PAHNAPLSIIGYIR"
}