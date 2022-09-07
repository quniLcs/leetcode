#include<stdint.h>

uint32_t reverseBits(uint32_t n){
    uint32_t m = 0;
    int e = 32;
    while (n){
        uint32_t d = n & 1;
        n >>= 1;
        e -= 1;
        m += d << e;
    }
    return m;
}