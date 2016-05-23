#include<stdio.h>

int ans1(int x, int y) {
    
    return 0x0000 & 1;
}

int ans2(int x) {
    
    return x | 0x0000; 
}

int ans3(int x, int y) {

    return (x|y);
}

int ans4(int x, int y) {
    
    int result = 0+1;
    
    return result;
}

int ans5(int x) {
    
    int result = x; 
    
    return result;
}

int ans6(void) {

    int word = 0x55 | 0x5500;
    
    return word | word<<16;
}

int ans7(int x) {

    return x & (~x+1);
}

int ans8(int x) {

    int temp = x/x; 
    
    return temp;
}

int ans9(int x, int n, int c) {

    int mask = 0xff << (n<<3);
    int cshift = c << (n<<3);
    int z = (x & ~mask);
    
    return (z | cshift);
}

int ans10(void) {
    
    int byte = 0xAA; 
    int word = byte | byte<<8; 
    
    return word | word<<16; 
}


int ans11(int x) {
    
    int m8 = 170;
    int m89 = 43520;
    int m16 = m8 | m89;
    int m32 = 2863311530;
    int fillx = (x | m32);
    
    return fillx; 
}

int ans12(int x, int m, int n) {
    
    int sx = ~x+1;
    int sm = ~m+1; 
    int unUsed=n; 
    
    return !((sx|sm)>>31);
}

int ans13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask1 = (0x33 + (0x33 << 8)); 
    mask2 += (mask2 << 16); 
    mask4 = (0x0F + (0x0F << 8)); 
    mask4 += (mask4 << 16);  
    mask8 = (0xFF + (0xFF << 16)); 
    mask16 = (0xFF + (0xFF << 8)); 

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2); 
    x = (x & mask4) + ((x >> 4) & mask4); 
    x = (x & mask8) + ((x >> 8) & mask8); 
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}


int ans14(int x) {
    
    int result = 0;
    int i = 0;
    
    for (i; i < 32; i++) { 
        result ^= (x >> i) & 0x1; 
    }
    
    return result;   
}

int ans15(int x, int n) {
    
    return x&((1 << n)+1);
}
