#include <stdio.h>
#include <string.h> // strlen()
#include <ctype.h> // toupper()...


static const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'/*, ' ', ',', '.', '?', ':'*/};
static int mod = sizeof(alphabet);

void affine(char *str, int a, int b);

int main (int argc, char *argv[], char *arge[]) {
    char message[512];
    int a, b;
    
    printf("Chiffrement affine de la forme y = Ax + B\n"
           "résolution dans Z/%dZ\n\n",mod);
    do {
        printf("Saisir le coefficient A (inversible dans Z/%dZ) : ",mod);
        scanf("%d",&a);
    } while (a == 0); //tout inversible sauf 0 dans Z/pZ avec p premier
    
    if (a>mod) {
        printf(" = %d soit %d dans Z/%dZ\n",a,a%mod,mod);
        a %= mod;
    }else if (b<0) {
        printf("B = %d soit %d dans Z/%dZ\n",a,(a%mod)+mod,mod);
        a = (a%mod)+mod;
    }
    
    
    printf("Saisir le coefficient B : ");
    scanf("%d",&b);
    
    if (b>mod) {
        printf("B = %d soit %d dans Z/%dZ\n",b,b%mod,mod);
        b %= mod;
    }else if (b<0) {
        printf("B = %d soit %d dans Z/%dZ\n",b,(b%mod)+mod,mod);
        b = (b%mod)+mod;
    }
    
    printf("Chiffrement affine de la forme y = %dx + %d\n",a,b);
    
    
    printf("Message ? (1 seule lettre pour tout afficher)\n");
    scanf(" %511[^\n]s",message);
    
    if (strlen(message) == 1) {
        strcpy(message, "A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z- -,-.-?-:");
        printf("Message trop court, voici l'alphabet :\n"
               "%s\n",message);
        affine(message, a, b);
        printf("%s\n",message);
    }else {
        printf("MSG = \"%s\"\n",message);
        affine(message, a, b);
        printf("DEC = \"%s\"\n",message);
    }
    
    return 0;
}

void affine(char *str, int a, int b) {
    if (str) {
        int maj = 0;
        
        while (*str) {
            
            int i;
            maj = isupper (*str);
            *str = tolower (*str);
            for (i = 0; i < mod; i++) {
                
                if (alphabet[i] == *str) {
                    
                    *str = alphabet[((a*i)+b)%mod];
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
