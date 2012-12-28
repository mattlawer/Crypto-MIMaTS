#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


int *glouton(int *objets, int n, int taille_sac);
int *optimal(int *objets, int n, int taille_sac);
void triselect(int *t, int n);
int taille_objets(int *objets, int n);

int main (int argc, char *argv[], char *arge[]) {
    int no, taille, i;
    
    
    printf("Taille su sac : ");
    scanf("%d",&taille);
    
    printf("Nombre d'objets : ");
    scanf("%d",&no);
    
    int *objets = malloc(no*sizeof(int));
    
    for (i=0; i<no; i++) {
        printf("Taille de l'objet %d : ",i);
        scanf("%d",&objets[i]);
    }
    
    // tri par taille décroissante
    triselect(objets, no);
    
    printf("Sac : %d\n",taille);
    printf("Objets : {");
    for (i=0; i<no; i++)
        printf(" %d,",objets[i]);
    printf("\b }\n\n");
    
    int *sac = glouton(objets, no, taille);
    printf("Sac (Glouton) : {");
    for (i=0; i<no; i++)
        printf(" %d,",sac[i]);
    printf("\b }\n");
    printf("taille utilisée : %d / %d\n\n",taille_objets(sac,no), taille);
    
    sac = optimal(objets, no, taille);
    printf("Sac (Optimal) : {");
    for (i=0; i<no; i++)
        printf(" %d,",sac[i]);
    printf("\b }\n");
    printf("taille utilisée : %d / %d\n",taille_objets(sac,no), taille);
            
    return 0;
}


int *glouton(int *objets, int n, int taille_sac) {
    int i, o_conso = 0;
    
    int *bagages = malloc(n*sizeof(int));
    
    for (i=0; i<n; i++) {
        if ((objets[i] + o_conso) <= taille_sac) {
            bagages[i] = objets[i];
            o_conso += objets[i];
        }else {
            bagages[i] = 0;
        }
    }
    
    return bagages;
}

int *optimal(int *objets, int n, int taille_sac) {
    int i;
    int *bagages = calloc(n, sizeof(int));
    
    if (n<=0) {
        int *v = calloc(1,sizeof(int));
        return v;
    }
    
    int *l1 = optimal(objets, n-1, taille_sac);
    
    if (objets[n-1] <= taille_sac) {
        int *l2 = optimal(objets, n-1, taille_sac-objets[n-1]);
        //return max( optimal pour n-1, (optimal pour n-1 avec taille-objets[n-1])+objets[n-1] )
        if (taille_objets(l1, n-1) > taille_objets(l2, n-1)+objets[n-1]) {
            for (i=0; i<(n-1); i++) {
                bagages[i] = l1[i];
            }
        }else {
            for (i=0; i<(n-1); i++) {
                bagages[i] = l2[i];
            }
            bagages[n-1] = objets[n-1];
        }       
    }
    else {
        //return optimal pour n-1 objets avec le dernier obj à 0
        for (i=0; i<(n-1); i++) {
            bagages[i] = l1[i];
        }
    }
    
    // affichage de chaque étape de la résolution
    /*printf("{ ");
    for (i=0; i<n; i++) {
        printf("%d, ",bagages[i]);
    }
    printf("\b\b }\n");*/
    
    return bagages;
}

void triselect(int *t, int n) {
	int i,j,max, tmp;
	for(i=0;i<n;i++) {
		max=i;
		for(j=i+1;j<n;j++)
			if(t[j]>t[max])  max=j;
		if (max != i) {
			tmp=t[max];
			t[max]=t[i];
			t[i]=tmp;
        }
    }
}

int taille_objets(int *objets, int n) {
    int i, t = 0;
    for (i=0; i<n; i++) {
        t+=objets[i];
    }
    return t;
}