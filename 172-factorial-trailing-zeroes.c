int factors(int n, int k){
    int c = 0;
    while (n){
        n /= k;
        c += n;
    }
    return c;
}

int trailingZeroes(int n){
    // int factor2 = factors(n, 2);
    int factor5 = factors(n, 5);
    return factor5;
}