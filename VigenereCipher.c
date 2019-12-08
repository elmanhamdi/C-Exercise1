#include <string.h>
#include <stdio.h>
#include "IStringProcess.h"
#include "IVigenereCipher.h"

int findLetter(char keyword);  // RETURN NUMBER OF LETTER IN A LIST
int convertPositiveModule(int num, int lenght);  //IF MOD IS NEGATIVE IT'S CONVERT IT POSITIVE EQUATION
char plainTextCharChooser(char *plaintext, int num); // IT IS CHOOSE LETTER IN A TEXT WITH GIVEN INDEX

char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};  // I DONT USE ACII, I USE THID LIST FOR CHOOSEING LETTER

char encryptionHelper(char plaintext, char keyword){   // TAKE ONE LETTER FROM PLAINTEXT AND KEYWORD AND RETURN NEW LETTER
    int numKeyword = findLetter(keyword);
    int numPlain = findLetter(plaintext);
    return alphabet[convertPositiveModule((numKeyword + numPlain)%26, 26)];
}
char decryptionHelper(char plaintext, char keyword){    // TAKE ONE LETTER FROM PLAINTEXT AND KEYWORD AND RETURN NEW LETTER
    int numKeyword = findLetter(keyword);
    int numPlain = findLetter(plaintext);

    return alphabet[convertPositiveModule((numPlain - numKeyword)%26, 26)];
}

void encryption(char *keyword, char *plaintext, int num, int len){ // CRYPTE GIVEN KEYWORD WITH GIVEN PLAINTEXT
    if(num < len){
        printf(" %c" ,encryptionHelper(keyword[num], plainTextCharChooser(plaintext,num)));
        encryption(keyword, plaintext, num + 1, len);


    }
}


void decryption(char *keyword, char *plaintext, int num, int len){  // ENCRYPTE GIVEN KEYWORD WITH GIVEN PLAINTEXT
    if(num < len){
        printf(" %c" ,decryptionHelper(keyword[num], plainTextCharChooser(plaintext,num)));
        decryption(keyword, plaintext, num + 1, len);
    }
}

char plainTextCharChooser(char *plaintext, int num){  // CHOOSE RIGHT LETTER IN A TEXT (EXAMPLE 0TH AND 5TH LETTER IN LEMON IS "L")
    if(num >= strlen(plaintext)){
        return(plaintext[num%strlen(plaintext)]);
    }
    else{
        return(plaintext[num]);
    }
}


int findLetter(char keyword){  // FIND  INDEX WITH GIVEN LETTER IN LIST
    int  count = 0;
    while(keyword != alphabet[count]){
        count = count + 1;
    }
    if(count == 27){
        return -1;
    }
    return count;
}

int convertPositiveModule(int num, int lenght){  // CONVERT NEGATIVE MODULE TO POSITIVE (ex.  (-1 MOD)26 = (25 MOD)26 )
    if(num < 0){
        return(num +26);
    }
    else {
        return(num);
    }
}

