Exemple de systèmes cryptographiques
========

Réalisés dans le cadre du M1 [MIMaTS][] au sein de l'[UFR de Tours][].

Utilisation d'un alphabet codé sous forme de nombres :

		A=0, B=1, C=2, ... , Z=25


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


Cryptosystème de Viegenère
-----
Chiffrement utilisant une clé pour décaler les lettres du message

#####Exemple de chiffrement du message 'CARAMEL' la clé 'MINOU'
On ajoute chaque lettre de la clée au message

		C -> C+M = O
		A -> A+I = I
		R -> R+N = E
		A -> A+O = O
		M -> M+U = G
		E -> E+M = Q
		L -> L+I = T


#####Déchiffrement avec la clé 'MINOU'
On soustrait chaque lettre de la clée au message chiffré

		O -> O-M = C
		I -> I-I = A
		E -> E-N = R
		O -> O-O = A
		G -> G-U = M
		Q -> Q-M = E
		T -> T-I = L


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
    

Chiffrement de hill
-----
On utilise une matrice N*N pour chiffrer des blocs de N lettres.


Chiffrement RSA
-----
On utilise une méthode d'exponentiation.


Exemple de partage de clés avec diffie-hellman
-----
Utilisation de la librairie [GMP][] pour le calcul de clés avec la méthode diffie-hellman.

    
License
-------

Copyright (c) 2012, Mathieu Bolard
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

* Neither the name of Mathieu Bolard, mattlawer nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Mathieu Bolard BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Contact
-------

mattlawer08@gmail.com<br />
http://mathieubolard.com<br />
http://twitter.com/mattlawer


[MIMaTS]: http://mimats.math.univ-tours.fr "Master International de Mathématiques des Transmissions Sécurisées"
[UFR de Tours]: http://www.univ-tours.fr "Université François Rabelais de Tours"
[GMP]: http://gmplib.org "The GNU Multiple Precision Arithmetic Library"