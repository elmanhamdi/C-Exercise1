#include <stdio.h>
#include <string.h>
#include "IVigenereCipher.h"
#include "IStringProcess.h"


int main() {
    char key[100] = "LEMON";
    char plain[100] = "ATTACKATDAWN";
    char *keyword = key;  // USING POINTER BECAUSE MY FUNCITON TAKES PARAMETRES WITH POINTERS CHAR
    char *plaintext = plain;



    int work = 1; // IF THIS IS "0" THE APPLICATION WILL BE END

    printf(" %s", "WELCOME. ");
    printf(" %s", "Current Keyword :  " );
    printf(" %s" ,keyword);


    while(work == 1){
        printf(" %s", "\n\nPlease select one operation ( Press 1-4) \n"
                      "1- ENCRYPTION a Text\n"
                      "2- DECRYPTION a Text\n"
                      "3- Change Keyword\n"
                      "4-Quit\n"
                      "==>");
        int number;
        scanf(" %d", &number);
        switch (number)  // FOR CHOOSING A NUMBER AND CALL FUNCTIONS (ENCRYOTION , DECRYPTION ETC.)
        {
            case 1:
                printf(" %s", "\nEnter a plaintext \n ==>");
                scanf( " %s", plain);
                makeUpper(0,plain);
                encryption(plaintext,keyword, 0, strlen(plaintext));
                break;
            case 2:
                printf(" %s", "\nEnter a plaintext \n ==>");
                scanf( " %s", plaintext);
                makeUpper(0,plain);
                decryption(plaintext,keyword, 0, strlen(plaintext));
                break;
            case 3:
                printf(" %s", "Current Keyword :  " );
                printf(" %s" ,key);
                printf(" %s", "\nEnter new keyword ==>  ");
                scanf(" %s", key);
                makeUpper(0,key);
                printf(" %s","Succesfully Changed");
                break;
            case 4:
                work = 0;
                break;
            default:
                printf(" %s", "Please enter a number between 1-4.");
                break;


        }
    }


    return 0;

}