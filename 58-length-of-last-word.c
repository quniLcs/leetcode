int lengthOfLastWord(char *s){
    int right = strlen(s) - 1;
    while (s[right] == ' '){
        right--;
    }

    int left = right;
    while (left >= 0 && s[left] != ' '){
        left--;
    }

    return right - left;
}