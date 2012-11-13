Cryptosystème césar
-----
Utilisation d'un simple décallage sur l'alphabet utilisé.

#####Exemple de chiffrement avec une clé k = 1

        A -> A+1 = B        "TEST" -> "UFTU"
        B -> B+1 = C
        ...
        Z -> Z+1 = A
        
#####Déchiffrement avec k = 1

        A -> A-1 = Z        "UFTU" -> "TEST"
        B -> B-1 = A
        ...
        Z -> Z-1 = Y