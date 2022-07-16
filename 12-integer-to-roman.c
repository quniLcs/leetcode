// completely independently coding
#include<stdio.h>
#include<string.h>

/*
I   1       IV  4
V   5       IX  9
X   10      XL  40
L   50      XC  90
C   100     CD  400
D   500     CM  900
M   1000
max number 3999
longest number 3888
longest roman  MMMDCCCLXXXVIII
*/

char *intToRoman(int num){
    char *roman = (char*)malloc(sizeof(char) * 16);
    int roman_index = 0;

    int integer_dict[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *roman_dict[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int dict_index = 12;

    while (num){
        if (num >= integer_dict[dict_index]){
            int repetition = num / integer_dict[dict_index];
            num %= integer_dict[dict_index];
            if (strlen(roman_dict[dict_index]) == 1){
                for (int time = 0; time < repetition ; time++){
                    roman[roman_index++] = roman_dict[dict_index][0];
                }
            }
            else{  // strlen(roman_dict[index]) == 2
                for (int time = 0; time < repetition ; time++){
                    roman[roman_index++] = roman_dict[dict_index][0];
                    roman[roman_index++] = roman_dict[dict_index][1];
                }
            }
        }
        dict_index--;
    }
    roman[roman_index] = '\0';

    return roman;
}

void main(){
    printf("%s\n", intToRoman(3));
    printf("%s\n", intToRoman(4));
    printf("%s\n", intToRoman(9));
    printf("%s\n", intToRoman(58));
    printf("%s\n", intToRoman(1994));
}