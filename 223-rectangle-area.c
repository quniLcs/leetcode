int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int aw = ax2 - ax1;
    int ah = ay2 - ay1;
    int bw = bx2 - bx1;
    int bh = by2 - by1;

    int iw = max(min(ax2, bx2) - max(ax1, bx1), 0);
    int ih = max(min(ay2, by2) - max(ay1, by1), 0);

    int aa = aw * ah;
    int ba = bw * bh;
    int ia = iw * ih;
    
    return aa + ba - ia;
}