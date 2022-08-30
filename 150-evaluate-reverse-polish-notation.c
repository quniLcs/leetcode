#include<stdio.h>
#include<stdbool.h>

bool isOperator(char *token){
    if (strlen(token) != 1) return false;
    else if (token[0] == '+') return true;
    else if (token[0] == '-') return true;
    else if (token[0] == '*') return true;
    else if (token[0] == '/') return true;
    else return false;
};

int toOperand(char *token){
    int num = 0;
    int sign = token[0] == '-' ? -1 : 1;
    int length = strlen(token);
    for (int index = token[0] == '-' ? 1 : 0; index < length; index += 1){
        num = 10 * num + token[index] - '0';
    }
    return sign * num;
}

int evalRPN(char **tokens, int tokensSize){
    int *stack = (int*)malloc(sizeof(int) * tokensSize);
    int top = 0;

    for (int index = 0; index < tokensSize; index += 1){
        if (isOperator(tokens[index])){
            if (tokens[index][0] == '+') stack[top - 2] += stack[top - 1];
            else if (tokens[index][0] == '-') stack[top - 2] -= stack[top - 1];
            else if (tokens[index][0] == '*') stack[top - 2] *= stack[top - 1];
            else stack[top - 2] /= stack[top - 1];
            top -= 1;
        }
        else{
            stack[top] = toOperand(tokens[index]);
            top += 1;
        }
        // if (top == 1) printf("%d\n", stack[0]);
        // else if (top == 2) printf("%d\t%d\n", stack[0], stack[1]);
    }

    return stack[0];
}

void main(){
    int tokensSize = 3;
    char **tokens = (char**)malloc(sizeof(char*) * tokensSize);
    tokens[0] = "3";
    tokens[1] = "-4";
    tokens[2] = "+";

    printf("%d\n", evalRPN(tokens, tokensSize));
}