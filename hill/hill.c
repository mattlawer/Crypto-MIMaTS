#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()
#include <ctype.h> // toupper()...
#include <math.h>

#define BLOC 2

//#define DEBUG

#ifdef DEBUG
#   define dprint(fmt, ...) printf(("%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define dprint(...)
#endif


static const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z', ' ', ',', '.', '?', ':'};

static int mod = (int)sizeof(alphabet);


int det(int **matrice, int taille);
void append(char *s, char c);
void strtab(char *s, int *tableau);
void multimat(int *m1, int **m2, int *result);

void crypt_hill(char *str, int **matrice);


int main (int argc, char *argv[], char *arge[]) {
    int i,j,t;
    int **hill = (int**) malloc(BLOC*BLOC * sizeof(int));
    
    char message[512];
    
    printf("Chiffrement de hill\n\n");
    
    // Saisie matrice
    do {
        printf("Entrez les %d chiffres de la matrice inversible : ",BLOC*BLOC);
        
        for(i=0;i<BLOC;i++)
        {
            hill[i] = (int*) malloc(BLOC * sizeof(int));
            for(j=0;j<BLOC;j++)
                scanf("%d",&hill[i][j]);
        }
        
        printf("det = %d\n",det(hill,BLOC));
    } while (det(hill,BLOC) == 0);
    
    // Affichage
    for (i = 0; i < BLOC; i++)
	    for (j = 0; j < BLOC; j++)
            dprint("M[%d][%d] = %d\n", i, j, hill[i][j]);
    printf("\n");
    
    
    // Saisie du message
    printf("Entrez un message : ");
    scanf(" %511[^\n]s",message);
    
    t=strlen(message)%BLOC;
    while (t>0) {
        append(message, alphabet[arc4random()%mod]);
        t--;
    }
    
    printf("message = \"%s\"\n",message);
    
    crypt_hill(message, hill);
    
    printf("crypt = \"%s\"\n",message);
    
    free(hill);
    
    return 0;
}

int det(int **matrice, int taille){
    if (taille == 2) {
        return matrice[0][0]*matrice[1][1]-matrice[1][0]*matrice[0][1];
    }
    return 0;
}

void append(char* s, char c){
    s[strlen(s)] = c;
    s[strlen(s)+1] = '\0';
}

void strtab(char *s, int *tableau) {
    int i, j;
    for (i = 0; *s != '\0'; s++,i++) {
        for (j=0; j<mod; j++) {
            if (alphabet[j] == tolower(*s)) {
                tableau[i] = j;
                break;
            }
        }
    }
}

void crypt_hill(char *str, int **matrice) {
    int i, offset = 0;
    if (str) {
        
        char block[BLOC];
        
        // tableau pour stocker les chaines en int
        int *tab = (int*) malloc(BLOC * sizeof(int));
        
        // tableau pour mettre les résultats
        int *crypt = (int*) malloc(BLOC * sizeof(int));
        
        while (*str) {

            for (i = 0; i<BLOC; i++) {
                tab[i] = 0;
                crypt[i] = 0;
            }
            
            strncpy(block, str, BLOC);
            block[BLOC] = '\0';            
            strtab(block, tab);
            dprint("block = \"%s\" -> (%d,%d) -> ",block ,tab[0],tab[1]);
            
            multimat(tab, matrice, crypt);
            
            // Affichage
            dprint("(%d,%d) -> ",crypt[0]%mod, crypt[1]%mod);
            dprint("\"%c%c\"\n",alphabet[crypt[0]%mod], alphabet[crypt[1]%mod]);

            for (i = 0; i<BLOC; i++)
                str[offset+i] = alphabet[crypt[i]%mod];

            offset+=BLOC;
            str+=BLOC;
        }
        free(tab);
        free(crypt);
    }
}


void multimat(int *m1, int **m2, int *result) {
    // m1 -> tableau de taille BLOC
    // m2 -> matrice de hill de BLOC*BLOC
    int i,j;
    for (i=0;i<BLOC;i++) {
		for (j=0;j<BLOC;j++) {
            // Bidouillage pour zapper les négatifs
			result[i] = (((m1[j] * m2[i][j] + result[i])%mod)+mod)%mod;
		}
	}
}


