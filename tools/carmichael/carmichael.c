#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int premier(int nombre);

int main (int argc, char *argv[], char *arge[]) {
    int i,j,div;
    int N=1200000;
    int *list=malloc(N*sizeof(int));
    for (i=0;i<N;i++) {
        list[i]=(i+1);
    }
    for (i=1;i<N;i++) {
        float list_sqrt = sqrt(list[i]);
        if (list_sqrt-floor(list_sqrt)==0) {
            for (j=i;j<N;j+=(i+1)){
                list[j]=-1;
            }
        }
    }
    int valid=0;
    int chemCount=0;
    int product=1;
    for(i=561; i<N; i++){
        if(!premier(i) && list[i-1]==i){
            for(div=2; div<sqrt(i); div++){
                if(i%div==0 && premier(div)){
                    if((i-1)%(div-1)==0){
                        valid= 1;
                        product*=div;
                        chemCount++;
                        if (product==i)
                            break;
                    }
                    else{
                        valid=0;
                        break;
                    }
                }
            }
            if ((valid == 1) && chemCount>=3 && product==i)
                printf("%d ",i);
            valid=0;
            chemCount=0;
            product=1;
        }
    }
    
    printf("\n");
    
    return 0;
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
