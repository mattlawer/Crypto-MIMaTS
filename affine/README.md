Cryptosystème affine
-----
Chiffrement en aX+b.

#####Exemple de chiffrement avec a<sub>e</sub> = 3 et b<sub>e</sub> = 9

        A -> 3*A+9 = J      "BONJOUR" -> "MZWKZRI"
        B -> 3*B+9 = M
        ...
        Z -> 3*Z+9 = G (avec un alphabet de 26 lettres comme ci-dessus)

#####Déchiffrement de la fonction en a<sub>e</sub>x+b<sub>e</sub>
1. On commence par calculer le a<sub>d</sub> et b<sub>d</sub> de la fonction inverse

    a<sub>d</sub> = a<sub>e</sub><sup>-1</sup> = inverse de a<sub>e</sub> dans Z/26Z</br>
    b<sub>d</sub> = -a<sub>e</sub><sup>-1</sup>b<sub>e</sub> mod 26</br>
    Dans notre cas a<sub>d</sub> = 9 et b<sub>d</sub> = 23</br>
    
2. On utilise la fonction 9x+23 pour déchiffrer :
    
        A -> 9*A+23 = X      "MZWKZRI" -> "BONJOUR"
        B -> 9*B+23 = G
        ...
        Z -> 9*Z+23 = O 