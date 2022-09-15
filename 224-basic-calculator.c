#include<stdbool.h>

int calculate(char *s){
    int i = 0;
    int n = strlen(s);
    
    int *operandStack = (int*)malloc(sizeof(int) * ((n + 1) / 2));
    int *operatorStack = (int*)malloc(sizeof(int) * (n / 2));
    int operandTop = 0;
    int operatorTop = 0;
    bool unary = true;

    while (i < n){
        if (s[i] == ' '){
            i += 1;
        }
        else if (s[i] == '('){
            i += 1;
            operatorStack[operatorTop++] = '(';
            unary = true;
        }
        else if (s[i] == ')'){
            i += 1;
            operatorTop--;
            if (operatorTop && operatorStack[operatorTop - 1] != '('){
                operatorTop -= 1;
                operandTop -= 1;
                if (operatorStack[operatorTop] == '+') operandStack[operandTop - 1] += operandStack[operandTop];
                else operandStack[operandTop - 1] -= operandStack[operandTop];
            }
        }
        else if (s[i] == '+'){
            i += 1;
            operatorStack[operatorTop++] = '+';
        }
        else if (s[i] == '-'){
            i += 1;
            if (unary) operandStack[operandTop++] = 0;
            operatorStack[operatorTop++] = '-';
        }
        else{
            int m = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                m = m * 10 + (s[i] - '0');
                i += 1;
            }
            operandStack[operandTop++] = m;
            if (operatorTop && operatorStack[operatorTop - 1] != '('){
                operatorTop -= 1;
                operandTop -= 1;
                if (operatorStack[operatorTop] == '+') operandStack[operandTop - 1] += operandStack[operandTop];
                else operandStack[operandTop - 1] -= operandStack[operandTop];
            }
            unary = false;
        }
    }

    return operandStack[0];
}