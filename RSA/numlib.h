#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void pgcd(mpz_t result, mpz_t op1, mpz_t op2);
int premier(mpz_t nombre);
int premiers(mpz_t n1, mpz_t n2);
int inverse(mpz_t inv, mpz_t nombre, mpz_t mod);
