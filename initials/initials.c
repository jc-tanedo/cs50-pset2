#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    
    int initialsCount=0;
    
    string name = get_string();
    char initials[strlen(name)/2];
    
    if (name[0]!=' ') {
        initials[initialsCount] = toupper(name[0]);
        initialsCount++;
    }
    
    for (int i = 0, x = strlen(name); i < x; i++) {
        if (name[i]==' ' && name[i+1]!=' ' && name[i+1]!='\0') {
            initials[initialsCount] = toupper(name[i+1]);
            initialsCount++;
        }
    }
    
    printf("%s\n", initials);
    
}