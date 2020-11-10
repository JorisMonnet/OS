#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

//transform a char to an int via the ascii array
int charToInt(char c) { 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
}

//transform an int from a char via the ascii array
char intToChar(int num) { 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 

void strev(char *str) {
    int len = strlen(str); 
    for (int i = 0; i < len/2; i++) { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 

//transform a number from any base to the decimal base, return the int result
int toDecimal(char *str, int base) { 
    int power = 1;  
    int num = 0;  

    for (int i = strlen(str) - 1; i >= 0; i--) { 
        if (charToInt(str[i]) >= base) { 
           printf("Invalid Number"); 
           return -1; 
        } 
        num += charToInt(str[i]) * power; 
        power = power * base; 
    } 
    return num; 
} 

//transform a decimal number to the string which represents the number in any base 
char* fromDecimal(char res[], int base, int inputNum) { 
    int index = 0; 

    while (inputNum > 0) { 
        res[index++] = intToChar(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
    strev(res); 
    return res;
} 

int main(int argc,char *argv[]){
    if(argc > 3){                               //verification of the number of arguments
        char *A=argv[1];
        int B = atoi(argv[2]);
        int C = atoi(argv[3]);
        if(A[0]!='-'&&B>1&&C>1&&B<37&&C<37){    //verification on arguments
            int dec=toDecimal(A,B);
            char result[100];
            fromDecimal(result,C,dec);
            printf("%s en base %d donne %s en base %d\n",A,B,result,C);
            return 0;
        } else{
            puts("Error invalid arguments");
            return -1;
        }
    }
    else{
        puts("Error invalid arguments");
        return -1;
    }
}