#import "numlib.h"

void pgcd(mpz_t result, mpz_t op1, mpz_t op2) {
    mpz_t a,b,r;
    mpz_init(a);
    mpz_init(b);
    mpz_init(r);
    mpz_set(a, op1);
    mpz_set(b, op2);
    
    do {
        mpz_mod(r, a, b);
        if (mpz_cmp_si(r, 0) != 0) {
            mpz_set(a, b);
            mpz_set(b, r);
        }
    } while (mpz_cmp_si(r, 0) != 0);
    mpz_set(result, b);
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);
}

int premier(mpz_t nombre) {
    mpz_t tmp, i;
    mpz_init(tmp);
    mpz_init(i);
    
    // Inférieur à 2 : pas premier
    if (mpz_cmp_si(nombre, 2) < 0) {
        mpz_clear(tmp);
        mpz_clear(i);
        return 0;
    }
    
    
    // Egal 2 : premier
    if (mpz_cmp_si(nombre, 2) == 0) {
        mpz_clear(tmp);
        mpz_clear(i);
        return 1;
    }
    
    // Nombre pair autre que 2 : n'est pas premier
    mpz_mod_ui(tmp, nombre, 2);
    if (mpz_cmp_si(tmp, 0) == 0) {
        mpz_clear(tmp);
        mpz_clear(i);
        return 0;
    }
    
    // Teste tous les diviseur inférieur au nombre (de 2 à x-1)
    mpz_set_si(i, 9);
    while (mpz_cmp(tmp, nombre) <= 0) {
        
        // Si on peut diviser ce nombre : il n'est pas premier
        mpz_mod(tmp, nombre, i);
        if (mpz_cmp_si(tmp, 0) == 0) {
            mpz_clear(tmp);
            mpz_clear(i);
            return 0;
        }
        
        // Passe au prochain diviseur
        mpz_add_ui(i, i, 2);
        mpz_mul(tmp, i, i);
    }
    
    mpz_clear(tmp);
    mpz_clear(i);
    
    // Aucun nombre compris entre 2 et Racine(x)
    // ne le divise : il est premier
    return 1;
}

int premiers(mpz_t n1, mpz_t n2) {
    mpz_t tmp;
    mpz_init(tmp);
    pgcd(tmp, n1, n2);
    if (mpz_cmp_si(tmp, 1) == 0) {
        mpz_clear(tmp);
        return 1;
    }
    mpz_clear(tmp);
    return 0;
}

int inverse(mpz_t res, mpz_t b, mpz_t n) {
    mpz_t n0, b0, t0, t, q, r, temp;
    mpz_init(n0);
    mpz_init(b0);
    mpz_init(t0);
    mpz_init(t);
    mpz_init(q);
    mpz_init(r);
    mpz_init(temp);
    
    mpz_set(n0, n);
    mpz_set(b0, b);
    mpz_set_si(t, 1);
    
    mpz_fdiv_q(q, n0, b0);
    
    mpz_mul(r, q, b0);
    mpz_neg(r, r);
    mpz_add(r, r, n0);
    
    //gmp_printf("\nn0: %Zd\nb0: %Zd\nt0: %Zd\nt: %Zd\nq: %Zd\n\r: %Zd\n\n",n0,b0,t0,t,q,r);
    
    while (mpz_cmp_si(r, 0) > 0) {
        mpz_mul(temp, q, t);
        mpz_neg(temp, temp);
        mpz_add(temp, temp, t0);
        
        if ((mpz_cmp_si(temp, 0) >= 0)) {
            mpz_mod(temp, temp, n);
        }else {
            mpz_neg(temp, temp);
            mpz_mod(temp, temp, n);
            mpz_neg(temp, temp);
            mpz_add(temp, temp, n);
        }
        mpz_set(t0, t);
        mpz_set(t, temp);
        mpz_set(n0, b0);
        mpz_set(b0, r);
        
        mpz_fdiv_q(q, n0, b0);
        
        mpz_mul(r, q, b0);
        mpz_neg(r, r);
        mpz_add(r, r, n0);
        //gmp_printf("\nn0: %Zd\nb0: %Zd\nt0: %Zd\nt: %Zd\nq: %Zd\nr: %Zd\n\n",n0,b0,t0,t,q,r);
    }
    
    if ((mpz_cmp_si(b0, 1) != 0)) {
        mpz_clear(n0);
        mpz_clear(b0);
        mpz_clear(t0);
        mpz_clear(t);
        mpz_clear(q);
        mpz_clear(r);
        mpz_clear(temp);
        return 0; // pas d'inverse
    }
    mpz_set(res, t);
    
    mpz_clear(n0);
    mpz_clear(b0);
    mpz_clear(t0);
    mpz_clear(t);
    mpz_clear(q);
    mpz_clear(r);
    mpz_clear(temp);
    return 1; // inverse calculé
}

