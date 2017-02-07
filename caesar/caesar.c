#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) {
    
    if (argc!=2) {
        if (argc<2) {
            printf("Error: Secret key not provided.\n");
        } else {
            printf("Error: Too many arguments.\n");
        }
        return 1;
    }

    int sKey = atoi(argv[1]);
    
    printf("plaintext: ");
    string plainText = get_string();
    
    for (int i=0, len=strlen(plainText); i<len; i++) {
        if ( plainText[i]>='A' && plainText[i]<='Z' ) {
            plainText[i] += sKey-'A';
            plainText[i] %= 26;
            plainText[i] += 'A';
        } else if ( plainText[i]>='a' && plainText[i]<='z' ) {
            plainText[i] += sKey-'a';
            plainText[i] %= 26;
            plainText[i] += 'a';
        }
    }
    
    printf("ciphertext: %s\n", plainText);
    return 0;
}