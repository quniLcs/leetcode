#include<stdio.h>

/*
void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void reverse(char *nums, int left, int right){
    while (left < right){
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}


void nextPermutation(char *nums, int numsSize){
    int i = numsSize - 2;
    while (nums[i] >= nums[i + 1]) i--;

    int j = numsSize - 1;
    while (nums[i] >= nums[j]) j--;

    swap(nums + i, nums + j);
    reverse(nums, i + 1, numsSize - 1);
}


char *getPermutation(int n, int k){
    char *s = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++){
        s[i] = i + '1';
    }
    s[n] = '\0';

    for (int i = 1; i < k; i++){
        nextPermutation(s, n);
    }

    return s;
}
*/

char *getPermutation(int n, int k){
    int *fact = (int*)malloc(sizeof(int) * n);
    // fact[0] = (n-1)!
    // fact[1] = (n-2)!
    // fact[i] = (n-i-1)!
    // fact[n-1] = 1

    fact[n - 1] = 1;
    for (int i = n - 2, j = 1; i >= 0; i--, j++){
        fact[i] = fact[i + 1] * j;
    }

    char *r = (char*)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++){
        r[i] = i + '1';
    }

    char *s = (char*)malloc(sizeof(char) * (n + 1));
    s[n] = '\0';
    for (int i = 0; i < n; i++){
        int t = (k - 1) / fact[i];
        s[i] = r[t];
        for (int j = t; j < n - 1; j++){
            r[j] = r[j + 1];
        }
        k -= t * fact[i];
    }
    return s;
}

void main(){
    printf("%s\n", getPermutation(3, 3));
}