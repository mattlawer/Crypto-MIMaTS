#include<stdio.h>
#include<stdlib.h> //for exit(0);
#include<gmp.h>

int main (void)
{
	//Create a raw socket
    mpz_t a,g,p,b,   A,Kb,Ka,B;
    
    mpz_init(a);
    mpz_init(g);
    mpz_init(p);
    mpz_init(b);
    
    mpz_init(A);
    mpz_init(Ka);
    mpz_init(Kb);
    mpz_init(B);

    printf("\nAlice et Bob choisissent un nombre premier p et une base g.\n");
    
    printf("Saisir p : ");
    gmp_scanf("%Zd",&p);
    
    printf("Saisir g : ");
    gmp_scanf("%Zd",&g);
    
    
    printf("\nAlice choisit a, un nombre secret.\n");
    
    printf("Saisir a : ");
    gmp_scanf("%Zd",&a);
    
    // Alice
    mpz_powm(A,g,a,p); //A = pow(g,a)%p;
    // Alice envoie A (g et p si inconnus de Bob)
    
    gmp_printf("\nElle envoie à Bob la valeur %Zd^%Zd [%Zd] = %Zd\n",g,a,p,A);
    
    printf("\nBob choisit à son tour un nombre secret b.\n");
    
    printf("Saisir b : ");
    gmp_scanf(" %Zd",&b);
    
    // Bob
    mpz_powm(B,g,b,p); //B = pow(g,b)%p;
    // Bob envoie B
    
    gmp_printf("\nBob envoie à Alice la valeur %Zd^%Zd [%Zd] = %Zd\n",g,b,p,B);
    
    // Alice
    mpz_powm(Ka,B,a,p); //Ka = powull(B,a)%p;
    gmp_printf("\nAlice peut maintenant calculer la clé secrète : (%Zd)^%Zd [%Zd] = %Zd\n",B,a,p, Ka);
    
    // Bob
    mpz_powm(Kb,A,b,p); //Kb = pow(A,b)%p;
    gmp_printf("\nBob fait de même et obtient la même clé qu'Alice : (%Zd)^%Zd [%Zd] = %Zd\n\n",A,b,p, Kb);
    
    //gmp_printf("\n##### Resultat ####\n\nAlice :\na = %Zd\ng = %Zd\np = %Zd\nA = %Zd\nK = %Zd\n\nBob :\nb = %Zd\nB = %Zd\nK = %Zd\n\n",a,g,p,A,Ka,b,B,Kb);
    
	return 0;
}

