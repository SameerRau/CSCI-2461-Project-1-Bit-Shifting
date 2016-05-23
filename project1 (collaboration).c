#include <stdio.h>

/*Faisal Harbi; Chris Licata; Sameer Rau*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques15.c -- each of which tests your knowledge of bitwise C operations. Your goal is to determine what each function does and if there
is a simpler way to implement the function. There are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation.
 Once you determine the function, you should run the code to check your answer.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operators in C but will also accept (with less credit on the grade) 'simpler to read'.*/


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instructions: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, you can include comments in your code that may provide a secondary explanation (in case
 your report has errors). You MUST provide an explanation for what the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if
 your answers are simply a collection of examples. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal proof or not. or submit a separate report. It is preferable to write your answers as comments.
 For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar to the example shown in ques0.c
 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile without errors, you will get a zero for Part B of this project.

 Collaboration: You can discuss the project with at most TWO other classmates, but each student must submit their own code. In other words, you can collaborate on Part A to figure out what each function is doing but must then work on your own on part B (where you provide simpler C functions where possible). Your report must indicate whom you collaborated with -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/*
 this function was called CallMeLast in the inclass exercies */
/*  function ques0 returns 1 if x=y and returns 0 if x is not equal to y */
/* the function ans0 does the same in two C statements */

int ques0(int x, int y) {  
    
    int temp;
    
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    
    return !(temp);
}

/* Answer to PART B: */
int ans0(int x, int y) {
    
    int z=0;
    
    if (x==y) {
        z= 0;
    }
    
    else {
        z= 1;
    }
    
    return z;
}

/* QUESTIONS */

/* question 1 */
int ques1(int x) {    /*x = 00000000000000000000000000010100=20 */

    int z;
    int y  = ~x+1;   /*y = 11111111111111111111111111110100 = -20*/
    
    z= (~(y|x));    
    z = (z >> 31); /*Will always be 0*/
    
    return (z & 1); /*z&1=0*/ /*Always returns 0*/
}

/* question 2 */
int ques2(x) {
    
    int mask = x>>31; /*x = 00000000000000000000000000010100=20 -- Will always = 0*/
    int y= (x ^ mask); /*y = 00000000000000000000000000010100=20 -- Will always give the original input value*/
    int z = (~mask + 1);/*This = 0 So basically the entire function returns its input*/
    
    return (y+z);
}

/* question 3 */
int ques3(int x, int y) {
    
    int notX = ~x;
    int notY = ~y; 
    int f = (~x|~y);
    
    return ~(~x | ~y);  /*This function simply performs a bitwise OR operation on the two values*/
}

/* question 4 */
int ques4(int x, int y) {

    int sum = x+y;  /*Sum of the terms x and y*/
    int x_neg = x>>31;/*Bitshifts x to the right 31 bits*/
    int y_neg = y>>31;/*Bitshifts y to the right 31 bits*/
    int s_neg = sum>>31;/*Bitshifts the sum of the terms to the right 31 bits*/
    
    return !(~(x_neg ^ y_neg) & (x_neg ^ s_neg));
}

/* question 5 */
int ques5(int x) {
    
    int result = (x<<31);
    
    result = (result >> 31);
    
    return result; /*This is the same number*/
}

/* question 6 */
int ques6(void) {

    int byte = 0x55;  /*0x55 in hex (85 in decimal)*/
    int word = byte | byte<<8;/*0x55 OR 0x5500 = 0x5555*/
    
    return word | word<<16; /*5555 OR 55550000*/ /*return value = 11010011111011010110110011*/
}

/* question 7 */
int ques7(int x) {

    return x & (~x+1); /*x AND (2's compliment for x)*/
}

/* question 8 */
int ques8(int x) {

    int y= ~x+1;  /*2's compliment for x*/  /*negating input*/
    int z= ((y|x) >> 31); /*(2's compliment for x OR x) bitwise shift to the right 31 spaces*/

    return (z & 1); /* Value of previous operation AND */
}

/* question 9 */
int ques9(int x, int n, int c) {

    int n8 = n << 3; /*n * 8=n8*//*Bitshift the value n to the left 3 places*/ 
    int mask = 0xff << n8; /*Shifts 255 to the left n8 places*/ /*255*(2^16) */  
    int cshift = c << n8; /*Shifts the value c to the left n8 places*/
    int z= (x & ~mask); /*x AND the compliment of mask*/
             
    return (z  | cshift); /*z OR cshift*/
}

/* question 10 */
int ques10(void) {

    int byte = 0xAA; /*value of 170 assigned to byte*/
    int word = byte | byte<<8; /*byte (170) OR (byte shifted left 8 places)*/
               
    return word | word<<16; /*word OR (word shifted left 16 places)*/
}


/* question 11 */
int ques11(int x) {

    int m8  = 0xAA;  /*0xAA = 170 = 10101010*/
    int m89= m8<<8;
    int m16 = m8  | m8  << 8; /*~m8=85=01010101*/ 
    int m32 = m16 | m16 <<16;  /*101010110101010101010110101010=718624170*/
    int fillx = x | m32; /*101010110101010101010110111110=fillx*/
               
    return !~fillx;  /*~fillx= 0101010010101010101001000001*/
}

/* question 12 */
int ques12(int x, int m, int n) { /* x = 00000000000000000000000000010100=20  */ /* m = 00000000000000000000000000010100=20 */ /* n = 00000000000000000000000000010100=20  */
                                 
    int a = ~m+1; /* flips every bit in m and adds one */ /* a = 11111111111111111111111111101100*/
    int b = ~x +1; /* flips every bit in x and adds one */ /* b = 11111111111111111111111111101100 */
                    
    a = x + a; /* adds x + ~m. */ /* 00000000000000000000000    000010100 + (11111111111111111111111111101100)  */
    b = b + n; /* adds n + ~x. */ /* 00000000000000000000000000010100 + (11111111111111111111111111101100)  */
                    
    return !((a|b) >> 31); /* returns the logical NOT of a OR b right shifted 31 bits. */
}

/* question 13 */
int ques13(int x) {

    int mask1, mask2, mask4, mask8, mask16;

    mask2 = 0x33 + (0x33 << 8); /* 0x33 = 51 in decimal. 51 is shifted left 8 bits and the resulting number is added to itself (51). */
    mask2 += mask2 << 16; /*variable mask2 is left shifted 16 bits and the result is added to itself (mask2). */
    mask4 = 0x0F + (0x0F << 8); /* 0x0F = 15 in decimal. 15 is shifted left 8 bits and the resulting number is added to itself (15). */
    mask4 += mask4 << 16;  /*Variable mask4 is left shifted 16 bits and the result is added to itself (mask4). */
    mask8 = 0xFF + (0xFF << 16); /* 0xFF = 255 in decimal. 255 is shifted left 16 bits and the resulting number is added to itself (255). */
    mask16 = 0xFF + (0xFF << 8); /*255 is shifted left 8 bits and the resulting number is added to itself (255). */

    x = (x & mask1) + ((x >> 1) & mask1); /*x AND mask1 + x shifted one bit right AND mask1. */
    x = (x & mask2) + ((x >> 2) & mask2); /* x AND mask2 + x shifted two bits right AND mask2. */
    x = (x & mask4) + ((x >> 4) & mask4); /* x AND mask4 + x shifted four bits right AND mask4. */
    x = (x & mask8) + ((x >> 8) & mask8); /* x AND mask8 + x shifted eight bits right AND mask8. */
    x = (x & mask16) + ((x >> 16) & mask16); /* x AND mask16 + x shifted sixteen bits right AND mask16. */

    return x;
}
    
/* question 14 */
int ques14(int x) {
    
    int result = 0;
    int i;
    
    for (i = 0; i < 32; i++) {  /* loops through a 32 bit number. */
        result ^= (x >> i) & 0x1; /* result XOR x shifted right i bits right AND 1 (in decimal). */
    }
    
    return result;   /* number of ones is even result = 0 */ /* number of ones is odd result = 1 */
}

/* question 15 */
int ques15(int x, int n) { /* for ques15 only, assume n is not a negative number  */

    int temp = (1 << n); /* 1 is shifted left n bits and assigned to variable temp. */
    int z = temp + ~0; /* variable z is assigned temp + NOT 0 (which is 1). */
   
    return (z & x); /* return z AND x. */
}

int main() {
    int a, b;

    int t1;

 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
 	scanf ("%d",&a);
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
 	scanf ("%d", &b);

	t1=ques0(a,b);
	printf("output of ques0 is t1 = %d  \n", t1);

	return 0;
}
