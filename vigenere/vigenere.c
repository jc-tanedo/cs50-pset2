#include <cs50.h>
#include <stdio.h>
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

    char sKey[strlen(argv[1])];
    
    for (int i=0, len=strlen(argv[1]); i<len; i++){
        if ((argv[1][i]>='A' && argv[1][i]<='Z')||(argv[1][i]>='a' && argv[1][i]<='z')) {
            sKey[i] = (argv[1][i] % 32) - 1;
        } else {
            printf("Error: Must not contain non-alphabetical characters.\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string plainText = get_string();
    int i=0, k=0;
 
    while (i < strlen(plainText)) {
        if (sKey[k%sizeof(sKey)]<=25) {
            if ( plainText[i]>='A' && plainText[i]<='Z' ) {
                plainText[i] += sKey[k%sizeof(sKey)]-'A';
                plainText[i] %= 26;
                plainText[i] += 'A';
                k++;
            } else if ( plainText[i]>='a' && plainText[i]<='z' ) {
                plainText[i] += sKey[k%sizeof(sKey)]-'a';
                plainText[i] %= 26;
                plainText[i] += 'a';
                k++;
            }
            i++;
        }
    }
  
    printf("ciphertext: %s\n", plainText);
    return 0;
    
}