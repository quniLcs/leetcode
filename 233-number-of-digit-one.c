int countDigitOne(int n){
    int ans = 0;
    long exp = 1;
    while (n >= exp){
        ans += n / (exp * 10) * exp;
        if (n % (exp * 10) >= exp * 2 - 1) ans += exp;
        else if (n % (exp * 10) >= exp) ans += n % (exp * 10) - exp + 1;
        exp *= 10;
    }
    return ans;
}