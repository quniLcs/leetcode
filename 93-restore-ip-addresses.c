char **ans;
char *cur;
int ansSize;
int curSize;

void restoreRecursively(char *s, int i, int j){
    // i refers to the index of string
    // j refers to the number of integers in the current ip address

    if (j == 4){
        if (s[i] == '\0'){
            cur[curSize - 1] = '\0';
            ans[ansSize] = (char*)malloc(sizeof(char) * curSize);
            strcpy(ans[ansSize], cur);
            ansSize += 1;            
        }
    }
    else{
        if (s[i]){
            cur[curSize] = s[i];
            cur[curSize + 1] = '.';
            curSize += 2;
            restoreRecursively(s, i + 1, j + 1);
            curSize -= 2;
        }
        if (s[i] && s[i] != '0' && s[i + 1]){
            cur[curSize + 1] = s[i + 1];
            cur[curSize + 2] = '.';
            curSize += 3;
            restoreRecursively(s, i + 2, j + 1);
            curSize -= 3;
        }
        if (s[i] && s[i] != '0' && s[i + 1] && s[i + 2] && 100 * (s[i] - '0') + 10 * (s[i + 1] - '0') + (s[i + 2] - '0') <= 255){
            cur[curSize + 2] = s[i + 2];
            cur[curSize + 3] = '.';
            curSize += 4;
            restoreRecursively(s, i + 3, j + 1);
            curSize -= 4;
        }
    }
}

char **restoreIpAddresses(char *s, int *returnSize){
    ans = (char**)malloc(sizeof(char*) * 100);
    cur = (char*)malloc(sizeof(char) * 16);
    ansSize = 0;
    curSize = 0;

    restoreRecursively(s, 0, 0);
    *returnSize = ansSize;
    return ans;
}