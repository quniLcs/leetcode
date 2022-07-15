// completely independently written
#include<stdio.h>

int reverse(int x){
    int y = 0;
    int y_sign = x < 0;
    int y_digit[10];
    int y_len = 0;

    int min_digit[10] = {-2, -1, -4, -7, -4, -8, -3, -6, -4, -8};
    int max_digit[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    
    while (x){
        y_digit[y_len] = x % 10;
        x /= 10;
        y_len++;
    }

    if (y_len == 10){
        if (y_sign){  // negative
            for (int y_ind = 0; y_ind < 10; y_ind++){
                if (y_digit[y_ind] < min_digit[y_ind]){
                    return 0;
                }
                else if (y_digit[y_ind] > min_digit[y_ind]){
                    break;
                }
            }
        }
        else{
            for (int y_ind = 0; y_ind < 10; y_ind++){
                if (y_digit[y_ind] > max_digit[y_ind]){
                    return 0;
                }
                else if (y_digit[y_ind] < min_digit[y_ind]){
                    break;
                }    
            }
        }
    }

    for (int y_ind = 0; y_ind < y_len; y_ind++){
        y = y * 10 + y_digit[y_ind];
    }

    return y;
}

void main(){
    printf("%d\n", reverse(-2147483412));
    // -2143847412
}