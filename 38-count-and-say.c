#include<stdio.h>

char *countAndSay(int n){
    char **string = (char**)malloc(sizeof(char*) * n);
    string[0] = "1";

    for (int i = 1; i < n; i++){
        string[i] = (char*)malloc(sizeof(char) * 4500);

        int j = 0;
        int k = -2;
        while (string[i - 1][j]){
            if (j == 0 || string[i - 1][j] != string[i - 1][j - 1]){
                k += 2;
                string[i][k + 1] = string[i - 1][j];
                string[i][k] = '1';
            } else string[i][k] += 1;
            j++;
        }
        k += 2;
        string[i][k] = '\0';    
    }

    return string[n - 1];
}

void main(){
    for (int i = 30; i <= 30; i++){
        printf("%s\n", countAndSay(i));
    }
}