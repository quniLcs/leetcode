#include<stdbool.h>
#include<stdio.h>

bool isNumber(char *s){
    // s only contains alphabets, dights, '+', '-' and '.' 

    // sign part: optional '+' or '-'
    // num  part: 'ddd', 'ddd.', '.ddd' or 'ddd.ddd'
    // exp  part: optional 'eddd', 'Eddd', 'e+ddd', 'E+ddd', 'e-ddd' or 'E-ddd'

    int i = 0;
    if (s[i] == '+' || s[i] == '-'){
        i++;
    }

    bool dot = false;
    bool num = false;
    while (s[i] == '.' || s[i] >= '0' && s[i] <= '9'){
        if (s[i] == '.'){
            if (dot) return false;
            else dot = true;
        }
        else{
            num = true;
        }
        i++;
    }
    if (!num) return false;

    if (s[i] == 'E' || s[i] == 'e'){
        i++;
        if (s[i] == '+' || s[i] == '-'){
            i++;
        }
        num = false;
        while (s[i] >= '0' && s[i] <= '9'){
            num = true;
            i++;
        }
        if (!num) return false;
    }

    if (s[i]) return false;
    else return true;
}

void main(){
    printf("%d\n", isNumber("-90E3"));
    printf("%d\n", isNumber("3e+7"));
    printf("%d\n", isNumber("+6e-1"));
    printf("%d\n", isNumber("53.5e93"));
    printf("%d\n", isNumber("-123.456e789"));
    printf("%d\n", isNumber("abc"));
    printf("%d\n", isNumber("1a"));
    printf("%d\n", isNumber("1e"));
    printf("%d\n", isNumber("e3"));
    printf("%d\n", isNumber("99e2.5"));
}