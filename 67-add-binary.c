#include<stdio.h>

char *addBinary(char *a, char *b){
    int n = strlen(a);
    int m = strlen(b);

    if (m > n){
        int t = n;
        n = m;
        m = t;
        char *u = a;
        a = b;
        b = u;
    }
    
    char *s = (char*)malloc(sizeof(char) * (n + 2)); 
    memcpy(s + 1, a, sizeof(char) * (n + 1));
    s[0] = '0';

    for (int i = n, j = m - 1, r = 0; j >= 0 || r; i--, j--){
        if (j >= 0) s[i] += b[j] - '0' + r;
        else s[i] += r;

        if (s[i] > '1'){
            s[i] -= 2;
            r = 1;
        }
        else{
            r = 0;
        }
    }

    if (s[0] != '0') return s;
    else return s + 1;
}

void main(){
    printf("%s\n", addBinary("11", "1"));
}

/*
void reserve(char* s){
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++){
        char t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }
}

char* addBinary(char* a, char* b){
    reserve(a);
    reserve(b);

    int len_a = strlen(a), len_b = strlen(b);
    int n = fmax(len_a, len_b), carry = 0, len = 0;
    char* ans = (char*)malloc(sizeof(char) * (n + 2));
    for (int i = 0; i < n; ++i) {
        carry += i < len_a ? (a[i] == '1') : 0;
        carry += i < len_b ? (b[i] == '1') : 0;
        ans[len++] = carry % 2 + '0';
        carry /= 2;
    }

    if (carry) {
        ans[len++] = '1';
    }
    ans[len] = '\0';
    reserve(ans);

    return ans;
}
*/