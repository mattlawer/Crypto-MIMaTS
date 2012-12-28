#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}point;

int shank(int base, int reste, int field);
int inverse(int nombre, int mod);
int isRacine(int base, int field);
int exp_mod(int n, int exp, int mod);
int premier(int nombre);

int main (int argc, char *argv[], char *arge[]) {
    int b, r, F;
    
    printf("Saisir le cardinal du corps : ");
    scanf("%d",&F);
    
    while (!premier(F)) {
        getchar();
        printf("NON NON NON !\n");
        printf("Le cardinal doit etre un nombre premier : ");
        scanf("%d",&F);
    }
    
    printf("Saisir la base du log : ");
    scanf("%d",&b);
    
    while (!isRacine(b, F)) {
        getchar();
        printf("%d n'est pas racine primitive dans F%d !\n",b,F);
        printf("Saisir la base du log : ");
        scanf("%d",&b);
    }
    
    printf("Saisir X, pour calculer log(X) : ");
    scanf("%d",&r);
    
    printf("\nCalcul de log%d(%d) dans F%d\n",b,r,F);
    printf("-> %d\n",shank(b,r,F));
            
    return 0;
}

int shank(int base, int reste, int field) {
    int j,i, g,s, t;
    int m = ceil(sqrt(field-1));
    
    // décomposition en puissances de nombres premiers
    point *L = malloc(m*sizeof(point));
    for (j=0; j<m; j++) {
        L[j].x = j;
        L[j].y = exp_mod(base, j, field);
    }
    
	// Tri du tableau L
	point tmp;
	for(i=0; i<m; i++) {
		s=i;
		for(j=i+1; j<m; j++)
			if(L[j].y<L[s].y) s=j;
        
		if (s != i) {
			tmp=L[s];
			L[s]=L[i];
			L[i]=tmp;
        }
    }
    
    g = inverse(exp_mod(base, m, field), field);
    s = reste;
    
    t=0;
    for (i=0; i<m; i++) {
        for (j=0; j<m; j++) {
            if (L[j].y == s) {
                t= 1;
                break;
            }
        }
        if (t) 
            break;
        else
            s = (s*g)%field;
    }
    
    if (!t) {
        free(L);
        return -1;
    }
    
    s = m*i+L[j].x;
    free(L);
    
    return s;
}

// retourne -1 si nombre n'a pas d'inverse modulo mod
int inverse(int nombre, int mod) {
    int m = mod, n = nombre, t0 = 0, t = 1;
    int q = floor((float)m/n);
    int r = m-q*n;
    
    while (r>0) {
        int tmp = t0-q*t;
        if (tmp >= 0) {
            tmp = tmp%mod;
        }
        else {
            tmp = mod-((-tmp)%mod);
        }
        t0=t;
        t=tmp;
        m=n;
        n=r;
        q=floor((float)m/n);
        r=m-q*n;
    }
    if (n != 1) {
        fprintf(stderr,"Error : %d n'as pas d'inverse modulo %d\n",nombre,mod);
        return -1;
    }
    return t;
}

int isRacine(int base, int field) {
    int d, o = field-1;
    for (d=2; d<ceil(sqrt(field)); d++) { // recherche des diviseurs de o
        if (o%d == 0    // si d divise o et (base^d=1 ou base^(o/d)=1)
            && (exp_mod(base, d, field) == 1 || exp_mod(base, o/d, field) == 1)) {
            return 0;
        }
    }
    // pour tout d|o, d≠o base^d≠1 => base est racine primitive de field
    return 1;
}

int exp_mod(int n, int exp, int mod) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result = (result*n)%mod;
    return result;
}

int premier(int nombre) {
    int i;
    if (nombre == 2)
        return 1;
    if (nombre < 2 || (nombre % 2) == 0)
        return 0;
    i = 3;
    while (i*i <= nombre) {
        if ((nombre % i) == 0)
            return 0;
        i += 2;
    }
    return 1;
}