// completely independently coding
#include<stdio.h>

int romanToInt(char *s){
    int integer = 0;
    int roman_index = 0;

    int integer_dict[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *roman_dict[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int dict_index = 12;

    while (s[roman_index]){
        // s[roman_index] is not null
        // s[roman_index+1] may be null

        if (strlen(roman_dict[dict_index]) == 1){
            if (s[roman_index] == roman_dict[dict_index][0]){
                integer += integer_dict[dict_index];
                roman_index++;
            }
            else{
                dict_index--;
            }
        }
        else{  // strlen(roman_dict[index]) == 2
            if (s[roman_index] == roman_dict[dict_index][0] && s[roman_index + 1] == roman_dict[dict_index][1]){
                integer += integer_dict[dict_index];
                roman_index += 2;
            }
            else{
                dict_index--;
            }                
        }
    }

    return integer;
}

void main(){
    printf("%d\n", romanToInt("III"));
    printf("%d\n", romanToInt("IV"));
    printf("%d\n", romanToInt("IX"));
    printf("%d\n", romanToInt("LVIII"));
    printf("%d\n", romanToInt("MCMXCIV"));
}