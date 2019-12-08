void makeUpper(int i, char s[100]){   //MAKE A STRING UPPER CASE VIA USING ACII CODES
    for (i = 0; s[i]!='\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] -32;
        }
    }
}


