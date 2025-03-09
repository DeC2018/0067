#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char * output = (char *)malloc(sizeOutput + 1);
    int sum = 0;
    
    output[sizeOutput] = '\0';
    
    while(sizeA > 0 || sizeB > 0 || sum > 0) {
        
        if(sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;   
}

int main() {
    // Example 1
    char a1[] = "11";
    char b1[] = "1";
    char *result1 = addBinary(a1, b1);
    printf("Input: a = \"11\", b = \"1\"\n");
    printf("Output: \"%s\"\n", result1);

    // Example 2
    char a2[] = "1010";
    char b2[] = "1011";
    char *result2 = addBinary(a2, b2);
    printf("Input: a = \"1010\", b = \"1011\"\n");
    printf("Output: \"%s\"\n", result2);

    free(result1);
    free(result2);

    return 0;
}
