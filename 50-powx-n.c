double myRecursivePow(double x, unsigned n){
    if (n == 0){
        return 1;
    }
    else{
        double temp = myRecursivePow(x, n / 2);
        if (n % 2) return temp * temp * x;
        else return temp * temp;
    }
}

double myPow(double x, int n){
    if (n >= 0){
        return myRecursivePow(x, n);
    }
    else{
        unsigned u = n;
        return 1 / myRecursivePow(x, -u);
    }
}