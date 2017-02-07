#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

void nextWord(char buff[], int place);

int main(int argc, string argv[]) {

    if (argc!=2) {
        if (argc<2) {
            printf("Error: Hashed password not provided.\n");
        } else {
            printf("Error: Too many arguments.\n");
        }
        return 1;
    }
    
    string inputHash = argv[1];
    char buff[]="AAAA";
    char salt[]={'0','0'};
    int pwdMatch=1;
    
    salt[0] = (char) argv[1][0];
    salt[1] = (char) argv[1][1];
    
    while (pwdMatch!=0) {
        nextWord(buff, 1);
        printf("%s\r", buff);

        string genHash = crypt(buff,salt);
        pwdMatch = strcmp(inputHash,genHash);
        
    }
    
    if (pwdMatch==0){
        printf("%s\n", buff);
    } else {
        printf("Password not found!\n");
    }
    return 0;
}

void nextWord(char buff[], int place){
    if (place != 0) {
        int len = strlen(buff);
        if (buff[len-place] == 'z') {
            buff[len-place] = 'A';
            nextWord(buff, place+1);
        } else {
            do {
            buff[len-place] += 1;
            } while ((buff[len-place]>'Z' && buff[len-place]<'a') || (buff[len-place]<'A') || (buff[len-place]>'z'));
        }
    }
}