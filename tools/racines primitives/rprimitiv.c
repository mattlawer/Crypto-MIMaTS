#include <stdio.h>
#include <stdlib.h> // exit()

int exp_mod(int n, int exp, int mod);
int *racines_primitives(int field);
int premier(int nombre);
int pgcd(int a, int b);

static int num = 0;

int main (int argc, char *argv[], char *arge[]) {
    int i, p;
    
    printf("Saisir le cardinal du corps : ");
    scanf("%d",&p);
    
    while (!premier(p)) {
        getchar();
        printf("NON NON NON !\n");
        printf("Le cardinal doit etre un nombre premier : ");
        scanf("%d",&p);
    }
    
    int *rp = racines_primitives(p);
    
    printf("Racines primitives de F%d : \n",p);
    for (i=0; i<num; i++) {
        printf("%d ",rp[i]);
    }
    
    printf("\n");
            
    return 0;
}

int exp_mod(int n, int exp, int mod) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result = (result*n)%mod;
    return result;
}

int *racines_primitives(int field) {
    int p,k,i,x,j;
    if (!premier(field)) {
        fprintf(stderr, "Ceci n'est pas un corps.");
        return NULL;
    }
    p = field-1;
    
    int *tmpK = malloc(p*sizeof(int));
    
    i=0;
    for (k = 2; k<p; k++) {
        if (p%k == 0) {
            tmpK[i]=k;
            i++;
        }
    }
    
    int *tmpX = malloc(p*sizeof(int));
    
    j=0;
    for (x=2; x<p; x++) {
        int test = 0;
        for (k = 0; k<i; k++) {
            if (!test && exp_mod(x, tmpK[k], field) == 1) {
                test = 1;
                break;
            }
        }
        
        if (!test && exp_mod(x, p, field) == 1) {
            tmpX[j] = x;
            j++;
        }
    }
    
    free(tmpK);
    
    num = j; // passage de la taille du tableau en global
    
    int *X = malloc(j*sizeof(int));
    
    for (x=0; x<j; x++) {
        X[x] = tmpX[x];
    }
    
    free(tmpX);

    return X;
}

int premier(int nombre) {
    int i;
    
    // Inférieur à 2 : pas premier
    if (nombre < 2)
        return 0;
    
    // Egal 2 : premier
    if (nombre == 2)
        return 1;
    
    // Nombre pair autre que 2 : n'est pas premier
    if ((nombre % 2) == 0)
        return 0;
    
    // Teste tous les diviseur inférieur au nombre (de 2 à x-1)
    i = 3;
    while (i*i <= nombre) {
        
        // Si on peut diviser ce nombre : il n'est pas premier
        if ((nombre % i) == 0)
            return 0;
        
        // Passe au prochain diviseur
        i += 2;
    }
    
    // Aucun nombre compris entre 2 et Racine(x)
    // ne le divise : il est premier
    return 1;
}


int pgcd(int a, int b) {
    int r;
    if (a<b) {
        r = a;
        a = b;
        b = r;
        r = 0;
    }
    do {
        r = a%b;        
        if (r != 0) {
            a = b;
            b = r;
        }
    } while (r != 0);
    return b;
}