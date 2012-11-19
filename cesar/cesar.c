#include <stdio.h>
#include <string.h> // strcmp()
#include <ctype.h> // toupper()...

const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'};
static int mod = sizeof(alphabet);

void cesar (char *str, int decalage);

int main (int argc, char *argv[], char *arge[]) {
    char message[512];
    int k;
    
    printf("Chiffrement césar\n\n");
    printf("Saisir un message à chiffrer : ");
    scanf("%511[^\n]s",message);
    
    printf("Saisir un nombre clé : ");
    scanf("%d",&k);
    k=(k+mod)%mod;
    
    cesar(message, k);
    printf("crypté  = %s\n",message);
    cesar(message, -k);
    printf("message = %s\n",message);
    
    return 0;
}

void cesar (char *str, int decalage) {
    if (str) {
        int maj = 0;
        
        while (*str) {
            int i;
            
            maj = isupper (*str);
            *str = tolower (*str);
            for (i = 0; i < mod; i++) {
                
                if (alphabet[i] == *str) {
                    
                    *str = alphabet[(i+decalage)%mod];
                    if (maj) {
                        *str = toupper (*str);
                    }
                    break;
                }
            }
            str++;
        }
    }
}
