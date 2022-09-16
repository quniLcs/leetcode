int calculate(char *s){
    int i = 0;
    int n = strlen(s);

    int *operandStack = (int*)malloc(sizeof(int) * 3);
    int *operatorStack = (int*)malloc(sizeof(int) * 2);
    int operandTop = 0;
    int operatorTop = 0;

    while (i < n){
        if (s[i] == ' '){
            i += 1;
        }
        else if (s[i] == '+' || s[i] == '-'){
            while (operatorTop){
                operatorTop -= 1;
                operandTop -= 1;
                if (operatorStack[operatorTop] == '+') operandStack[operandTop - 1] += operandStack[operandTop];
                else if (operatorStack[operatorTop] == '-') operandStack[operandTop - 1] -= operandStack[operandTop];
                else if (operatorStack[operatorTop] == '*') operandStack[operandTop - 1] *= operandStack[operandTop];
                else operandStack[operandTop - 1] /= operandStack[operandTop];
            }
            operatorStack[operatorTop++] = s[i];
            i += 1;
        }
        else if (s[i] == '*' || s[i] == '/'){
            if (operatorTop && (operatorStack[operatorTop - 1] == '*' || operatorStack[operatorTop - 1] == '/')){
                operatorTop -= 1;
                operandTop -= 1;
                if (operatorStack[operatorTop] == '*') operandStack[operandTop - 1] *= operandStack[operandTop];
                else operandStack[operandTop - 1] /= operandStack[operandTop];
            }
            operatorStack[operatorTop++] = s[i];
            i += 1;
        }
        else{
            int m = 0;
            while (s[i] >= '0' && s[i] <= '9'){
                m = m * 10 + (s[i] - '0');
                i += 1;
            }
            operandStack[operandTop++] = m;
        }
    }

    while (operatorTop){
        operatorTop -= 1;
        operandTop -= 1;
        if (operatorStack[operatorTop] == '+') operandStack[operandTop - 1] += operandStack[operandTop];
        else if (operatorStack[operatorTop] == '-') operandStack[operandTop - 1] -= operandStack[operandTop];
        else if (operatorStack[operatorTop] == '*') operandStack[operandTop - 1] *= operandStack[operandTop];
        else operandStack[operandTop - 1] /= operandStack[operandTop];
    }

    return operandStack[0];
}