#include <stdio.h>
#include <stdlib.h> //for exit(0);
#include <string.h>
#include <math.h>
#include <gmp.h>
#include "numlib.h"

static const char alphabet[] = {'*','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z', ' ', ',', '.', '?', ':'};

static int size_alphabet = (int)sizeof(alphabet);

#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define indexof(X) max(strchr(alphabet,X)-alphabet, 0)

mpz_t* message_to_blocks(char *msg, int blocksize);
void pow_blocks(mpz_t* blocks, int n_blocks, mpz_t pow, mpz_t mod);

int main (int argc, char *argv[], char *arge[])
{
    char msg[256];
    mpz_t p, q, N, e, d, phiN;
    mpz_t *blocks;
    
    mpz_init(p);
    mpz_init(q);
    mpz_init(N);
    mpz_init(e);
    mpz_init(d);
    mpz_init(phiN);
    
    //printf("index a : %d\nc: %d\n",indexof('a'),indexof('A'));

    printf("\nAlice choisit 2 nombres premiers p et q.\n");
    
    printf("Saisir p [ex 45013] : ");
    gmp_scanf("%Zd",&p);
    
    printf("Saisir q [ex 39191] : ");
    gmp_scanf("%Zd",&q);
    
    mpz_mul(N, p, q); // N=p*q;
    gmp_printf("\np: %Zd\nq: %Zd\n",p,q);
    
    mpz_sub_ui(p, p, 1); // p-=1;
    mpz_sub_ui(q, q, 1); // q-=1;
    
    mpz_mul(phiN, p, q); // phiN=(p-1)*(q-1);
    
    gmp_printf("N: %Zd\n\np-1: %Zd\nq-1: %Zd\nphiN: %Zd\n\n",N,p,q,phiN);
    
    printf("Saisir e premier avec phiN [ex 214231]: ");
    gmp_scanf("%Zd",&e);
    while (!premiers(phiN, e)) {
        gmp_printf("%Zd n'est pas premier avec %Zd\n",e,phiN);
        gmp_printf("Saisir e premier avec %Zd : ",phiN);
        gmp_scanf("%Zd",&e);
    }
    
    if (inverse(d, e, phiN)) {
        gmp_printf("L'inverse de e [phiN], d= %Zd\n",d);
    }else {
        printf("pas d'inverse.\n");
    }
    
    printf("Saisir un message : ");
    scanf(" %[^\n]s",msg);
    
    int i;
    int taille_block = 2;
    int len = strlen(msg);
    int blocks_cnt = ceil((float)len/taille_block);
    
    blocks = message_to_blocks(msg, taille_block);
    printf("Blocks :\n");
    
    for (i=0; i<blocks_cnt; i++) {
        gmp_printf("%Zd, ",blocks[i]);
    }
    printf("\b\b\n\n");
    
    // Chiffrement avec e
    pow_blocks(blocks, blocks_cnt, e, N);
    printf("Secret Blocks :\n");
    
    for (i=0; i<blocks_cnt; i++) {
        gmp_printf("%Zd, ",blocks[i]);
    }
    printf("\b\b\n\n");
    
    
    // Déchiffrement avec d
    pow_blocks(blocks, blocks_cnt, d, N);
    printf("Décript Blocks :\n");
    
    for (i=0; i<blocks_cnt; i++) {
        gmp_printf("%Zd, ",blocks[i]);
    }
    printf("\b\b\n\n");
    
    for (i=0; i<blocks_cnt; i++) {
        mpz_clear(blocks[i]);
    }
    
    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(N);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(phiN);
    
	return 0;
}


mpz_t* message_to_blocks(char *msg, int blocksize) {
    mpz_t offset, tmp;
    mpz_init(offset);
    mpz_init(tmp);
    int i,j,index, len = strlen(msg);
    int blocks = ceil((float)len/(float)blocksize);
    
    //printf("message %s\nmessage de longueur %d\ndivisé en %d blocks de taille %d\n\n",msg,len,blocks,blocksize);
    
    mpz_t *tableau = malloc(blocks*sizeof(mpz_t));
    for (i=0; i<blocks; i++) {
        mpz_init(tableau[i]);
        
        for (j=0; j<blocksize; j++) {
            
            if (j==0) {
                mpz_set_ui(offset, 1);
            }else {
                mpz_mul_ui(offset, offset, (unsigned long int)size_alphabet);
            }
            index = (blocksize*i)+j;
            if (index<len) {
                mpz_mul_ui(tmp, offset, indexof(msg[index]));
                mpz_add(tableau[i], tableau[i], tmp);
            }
        }
    }
    
    mpz_clear(offset);
    mpz_clear(tmp);
    
    return tableau;
}

void pow_blocks(mpz_t* blocks, int n_blocks, mpz_t pow, mpz_t mod) {
    int i;
    for (i=0; i<n_blocks; i++) {
        mpz_powm(blocks[i], blocks[i], pow, mod);
    }
}
