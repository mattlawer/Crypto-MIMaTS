#include <stdio.h>
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

void vigenere(char *msg, char *key, int mode);

int main (int argc, char *argv[], char *arge[]) {
    char message[512], key[64];
    
    printf("Chiffrement Vigenère\n"
           "alphabet {%s} de %d lettres\n\n",alphabet,mod);
    
    printf("Clée ?\n");
    scanf(" %511[^\n]s",key);
    
    printf("Message ?\n");
    scanf(" %511[^\n]s",message);
    
    printf("MSG = \"%s\"\n",message);
    vigenere(message, key, kEncrypy);
    printf("ENC = \"%s\"\n",message);
    vigenere(message, key, KDecrypt);
    printf("DEC = \"%s\"\n",message);
    
    return 0;
}

void vigenere(char *msg, char *key, int mode) {
    if (msg) {
        int maj = 0;
        int klen = strlen(key);
        int index = 0;
        
        while (*msg) {
            
            int i;
            maj = isupper (*msg);
            *msg = tolower (*msg);
            for (i = 0; i < mod; i++) {
                
                if (alphabet[i] == *msg) {
                    index = (mode == kEncrypy) ? (i+indexof(*key))%mod : (i-indexof(*key)+mod)%mod;
                    *msg = alphabet[index];
                    if (maj) {
                        *msg = toupper (*msg);
                    }
                    break;
                }
            }
            msg++;
            key++;
            if (!*key) {
                key-=klen;
            }
        }
    }
}
