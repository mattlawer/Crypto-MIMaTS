#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()
#include <ctype.h> // toupper()...


static const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'/*, ' ', ',', '.', '?', ':'*/};
static int mod = sizeof(alphabet);

#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define indexof(X) max(strchr(alphabet,X)-alphabet, 0)

enum {
    kEncrypy,
    KDecrypt
};

void substitution(char *msg, char *alphabet1, char *alphabet2);

int main (int argc, char *argv[], char *arge[]) {
    int i,p_index = 0;
    char message[512], phrase[128];
    char *permut = (char*)malloc(mod*sizeof(char));
    char *tmp;
    
    printf("Chiffrement par substitution\n"
           "alphabet {%s} de %d lettres\n\n",alphabet,mod);
    
    printf("Saisir une phrase pour générer les permutations ?\n");
    scanf(" %127[^\n]s",phrase);
    for (i=0; i<strlen(phrase); i++) {
        if (((tmp = strchr(alphabet, phrase[i])) != NULL)
             && (strchr(permut, phrase[i]) == NULL)) {
            permut[p_index] = phrase[i];
            p_index++;
        }
    }
    for (i=0; i<mod; i++) {
        if (strchr(permut, alphabet[i]) == NULL) {
            permut[p_index] = alphabet[i];
            p_index++;
        }
    }
    printf("permut : %s\n",permut);
    
    printf("Message ?\n");
    scanf(" %511[^\n]s",message);
    
    printf("MSG = \"%s\"\n",message);
    substitution(message, (char *)alphabet, permut);
    printf("ENC = \"%s\"\n",message);
    substitution(message, permut, (char *)alphabet);
    printf("DEC = \"%s\"\n",message);
    
    return 0;
}

void substitution(char *msg, char *alphabet1, char *alphabet2) {
    if (msg) {
        int maj = 0;
        
        while (*msg) {
            
            int i;
            maj = isupper (*msg);
            *msg = tolower (*msg);
            for (i = 0; i < mod; i++) {
                
                if (alphabet1[i] == *msg) {
                    *msg = alphabet2[i];
                    if (maj) {
                        *msg = toupper (*msg);
                    }
                    break;
                }
            }
            msg++;
        }
    }
}
