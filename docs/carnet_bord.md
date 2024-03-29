# Carnet de bord

## Séance 1 (21/03/23)

Durant cette séance, nous avons pris connaissance du sujet. Nous avons étudier la documentation AES fournie.
Ensuite, nous avons pris connaissance des fichiers de code fournis. Nous avons pu commencer à mettre en place les premières fonction.
Nous avons définit les classes de type Anneau et Corps en Haskell.
Nous avons ensuite réalisé l'implémentation du corps Z/2Z.
Pour finir, nous avons commencé à réfléchir à comment implémenter des anneaux de polynômes à coefficients dans un corps.

**Objectifs avant la prochaine séance :**
- Ronan :
    - [x] Finir l'implémentation du 3)
    - [x] Faire les tests du 3)
    - [x] Réfléchir à une implémentation du calcul modulo un polynôme
    
- Etienne
    - [x] Réfléchir à une implémentation du calcul modulo un polynôme
    - [x] Faire les tests du 5)

<br>

## Séance 2 (5/04/2023)

Dans cette deuxième séance, nous avons continué l'implémentation en haskell, notamanet en commencant l'inverse module m dans un corps.
Nous avons aussi résolu les nombreux bugs des fonctions déja existantes.
Nous avons ré-étudié la documentation de AES, en se focalisant sur le fonctionnement global du système AES, por avoir une vue plus globale du projet.


**Objectifs avant la prochaine séance :**
- Ronan :
    - [x] Continuer l'étude de la documentation en général
    - [x] DOC
    
- Etienne
    - [x] Faire les tests du 7)
    - [x] Continuer l'étude de la documentation notament en point 4.3

<br>

## Séance 3 (18/04/2023)

Dans cette séance, nous avons continué l'implémentation d'AES. Nous avons commencé les implémentations de SubBytes() et de ShiftRows() d'aes.


**Objectifs avant la prochaine séance :**
- Ronan :
    - [x] MixColumn
    - [x] InvMixColums
    - [x] ShiftRow
    - [x] InvShiftRow
    - [x] KeyExpension
    - [x] tests
    
- Etienne
    - [x] SubBytes
    - [x] InvSubBytes
    - [x] AddRoundKey
    - [x] InvAddRoundKey
    - [x] KeyExpension
    - [x] tests

<br>

## Séance 4 (3/05/2023)

Dans cette séance, nous avons continué l'implémentation d'aes en haskell. Nous avons continué/fini l'implémentation de KeyExpension, puis nous avons mis en place Cipher et InvCipher. Nous avons eu quelques bugs a corriger. Nous avons aussi commencé l'extension de clé pour les autres versions de AES, 192 et 256.

**Objectifs avant la prochaine séance :**
- Ronan :
    - [x] Extension de clé pour les autres versions de AES (192, 256)
    - [x] tests extension clé
    - [x] test cipher 192 et 256
    - [x] (en c) codage shiftRow et son inverse
    - [x] Rédaction d'une documentation
    
- Etienne
    - [x] Corrections et vérification de Cipher et InvCipher
    - [x] tests
    - [x] Rédaction d'une documentation
    - [x] Début du C, reflexion à la structure de donnée à utiliser
    - [x] (en c) codage AddRoundKey
    - [x] (en c) codage SubBytes
    - [x] (en c) codzage InvSubBytes

<br>

## Séance 5 (17/05/2023)
Durant la séance nous avons débuggé les version aes 192 et 256 qui sont maintenant fonctionnelles et avons rédigés des tests pour celles-ci. Nous avons aussi réorganisé le code et commenter les focntions.
Nous avons continuer l'implémentation d'aes en C.

**Objectifs avant la prochaine séance :**
- Ronan :
    - [x] Continuer la documentation
    - [x] Nettoyer le code
    - [x] Continuer le C

- Etienne :
    - [x] Continuer et finir la documentation
    - [x] Continuer le C

 
# Deuxième période

## Séance 6 (5/06/2023)
Durant la séance nous avons continué le code en c.
Nous avons fini l'interface graphique que nous avions commencé dans l'entre-période. 
Nous avons réalisé l'algorithme CBC pour coder et décoder des fichiers de manière fiable.
Nous avons passé beaucoup de temps a debuggé nos programmes.

**Objectifs de la séance :**
- Ronan :
    - [x] Algorithme CBC
    - [x] Correction AES version terminal

- Etienne :
    - [x] Continuer l'interface graphique et l'integrer dans le code
    - [x] Gérer la lecture et l'écriture des fichiers


## Séance 7 (6/06/2023)

Durant cette deuxième séance de la deuxième période, nous allons continuer a implémenter la version CBC d'aes.

Nous avons commencé par utiliser l'outil callgrind, utilisé comme ceci :

> ```valgrind --tool=callgrind <programme>```

Ce qui permet de générer un fichier contenant tout les points de mesures du logiciel. Nous avons eu des problèmes car il n'executait pas le fichier, cer nous avions laissé fsanitize dans les options de compilations. <br> Une fois le fichier de mesures obtenu, nous avons utilisé l'interface de kcachegrind et ouvert le fichier. <br> Nous avons obtenu le graph ci-dessous.
![Alt text](opti.png "perf")

Nous avons alors essayé de trouver des solutions pour optimiser le code, notement de multpoly qui est appelé plus de 33 millions de fois pour encoder un fichier de 1,8mo. <br> <br>

Après avoir recu l'extension de sujet par mail, nous avons implémenté le mode ECB en mode cryptage et décryptage. <br> <br>

Nous avons ensuite codé une fonction pour encoder des fichiers BMP selon les deux modes : ECB et CBC. Nous avons observé le défaut de ECB en observant l'image. <br> <br> <br>

Image Originale
![Alt text](entree.png "origine")
Image encodée ECB
![Alt text](sortie_ecb.png "ecb")
Image encodée CBC
![Alt text](sortie_cbc.png "cbc")



**Objectifs de la séance :**
- Ronan :
    - [x] Algorithme CBC
    - [x] Algorithme ECB
    - [x] Essai optimisation registre processeur

- Etienne :
    - [x] Optimisation du code
    - [x] Coder des fichiers bmp en ecb et cbc
    - [x] ui
  

## Séance 8 (7/06/2023)

Durant cette troisième séance de la deuxième période, nous avons continué à optimiser le code, et à améliorer l'ihm.

Nous avons essayé de calculer l'entropie de l'encodage des pixel de l'image ci dessus pour comparer les versions cbc et ecb d'encodage de fichier.
Nous n'avons pas réussi à la calculer, cependant on a pu remarquer que les pixel était plus uniformément réparti avec la version cbc.

Nous avons également adapté notre code afin de gérer l'encodage des fichiers de la même manière que celle attendue lors de l'évaluation, c'est-à-dire encoder la taille des fichiers sur 4 octets en début de fichier.

Pour l'optimisation, nous avons implémenté une version d'aes utilisant les instructions aes du processeur ce qui nous a permis d'atteindre des vitesses dépassant le Go/s. Cependant nous devons adapter notre mesure des performances d'AES car la lecture et l'écriture des fichiers est lente (mesurer entre la  fin de la lecture et le début de l'écriture).
Nous nous sommmes appuyés sur la documentation des instructions fournie par Intel : 
> https://www.intel.com/content/dam/doc/white-paper/advanced-encryption-standard-new-instructions-set-paper.pdf

Nous avons aussi essayé d'implémenter un système de hash en sha256 afin de pouvoir rentrer un mot de passe de n'importe quelle longueur en guise de "clé".


**Objectifs de la séance :**
- Ronan :
    - [x] Implémentation AES avec les instructions processeur
    - [x] Adaptation du code pour l'encodage des fichiers

- Etienne :
    - [x] Finaliser l'encodage des fichiers bmp
    - [x] Calculer l'entropie
    - [x] Améliorer l'ihm


## Séance 9 (8/06/2023)

Durant cette dernière séance de projet, nous allons finaliser l'encrypatge des fichiers pour correspondre au mode d'encryptage de l'évaluation, nettoyer et réorganiser le code

Nous avons mesurer l'augmentation des performances avec l'ajout des instructions processeur. Ci-dessous deux implémentations de addRoundKey, une avec une boucle for de base, et une autre avec des instructions processeur qui permettent dirrectement de faire un XOR sur 128 bits.

Voici le code avec un for :

```c
void addRoundKey(byte *state, const byte *key) { 
    for (int i = 0; i < 16; i++) {
        state[i] = state[i] ^ key[i];
    }
}
```

Et le code avec les instrucations processeurs :

```c
void addRoundKey(byte *state, const byte *key) {
    __m128i* state128 = (__m128i*) state;
    __m128i* key128 = (__m128i*) key;
    *state128 = _mm_xor_si128(*state128, *key128);
}
```

Les tests sont effectués sur 100.000.000 de tours.
| Mode |  Temps |
|--:|:----------|
| for                    | 0.274662 |
| instruction processeur | 0.062970 |

Nous observons bien que le temps est ralativement diminué avec les instructions processeurs. En effet, pour encoder un fichier de 1.8mo, nous avions trouvé à l'aide de vallgrind que la fonction addRoundKey esrt appelée 1.000.000 fois, ce qui change grandement le temps d'execution. <br>
Nous avons ensuite observé le code assembleur généré à l'aide de la commande :
>```objdump -M intel -dS monprogramme > monprogramme.dump```

Nous obtenons des résultats bien différents qui sont résumés ci-dessous :

Avec le for :

```asm
0000000000001570 <f1>:
    1570:	48 8d 56 01          	lea    rdx,[rsi+0x1]
    1574:	48 89 f8             	mov    rax,rdi
    1577:	48 29 d0             	sub    rax,rdx
    157a:	48 83 f8 0e          	cmp    rax,0xe
    157e:	76 10                	jbe    1590 <f1+0x20>
    1580:	c5 fa 6f 06          	vmovdqu xmm0,XMMWORD PTR [rsi]
    1584:	c5 f9 ef 07          	vpxor  xmm0,xmm0,XMMWORD PTR [rdi]
    1588:	c5 fa 7f 07          	vmovdqu XMMWORD PTR [rdi],xmm0
    158c:	c3                   	ret    
    158d:	0f 1f 00             	nop    DWORD PTR [rax]
    1590:	0f b6 06             	movzx  eax,BYTE PTR [rsi]
    1593:	30 07                	xor    BYTE PTR [rdi],al
    1595:	0f b6 46 01          	movzx  eax,BYTE PTR [rsi+0x1]
    1599:	30 47 01             	xor    BYTE PTR [rdi+0x1],al
    159c:	0f b6 46 02          	movzx  eax,BYTE PTR [rsi+0x2]
    15a0:	30 47 02             	xor    BYTE PTR [rdi+0x2],al
    15a3:	0f b6 46 03          	movzx  eax,BYTE PTR [rsi+0x3]
    15a7:	30 47 03             	xor    BYTE PTR [rdi+0x3],al
    15aa:	0f b6 46 04          	movzx  eax,BYTE PTR [rsi+0x4]
    15ae:	30 47 04             	xor    BYTE PTR [rdi+0x4],al
    15b1:	0f b6 46 05          	movzx  eax,BYTE PTR [rsi+0x5]
    15b5:	30 47 05             	xor    BYTE PTR [rdi+0x5],al
    15b8:	0f b6 46 06          	movzx  eax,BYTE PTR [rsi+0x6]
    15bc:	30 47 06             	xor    BYTE PTR [rdi+0x6],al
    15bf:	0f b6 46 07          	movzx  eax,BYTE PTR [rsi+0x7]
    15c3:	30 47 07             	xor    BYTE PTR [rdi+0x7],al
    15c6:	0f b6 46 08          	movzx  eax,BYTE PTR [rsi+0x8]
    15ca:	30 47 08             	xor    BYTE PTR [rdi+0x8],al
    15cd:	0f b6 46 09          	movzx  eax,BYTE PTR [rsi+0x9]
    15d1:	30 47 09             	xor    BYTE PTR [rdi+0x9],al
    15d4:	0f b6 46 0a          	movzx  eax,BYTE PTR [rsi+0xa]
    15d8:	30 47 0a             	xor    BYTE PTR [rdi+0xa],al
    15db:	0f b6 46 0b          	movzx  eax,BYTE PTR [rsi+0xb]
    15df:	30 47 0b             	xor    BYTE PTR [rdi+0xb],al
    15e2:	0f b6 46 0c          	movzx  eax,BYTE PTR [rsi+0xc]
    15e6:	30 47 0c             	xor    BYTE PTR [rdi+0xc],al
    15e9:	0f b6 46 0d          	movzx  eax,BYTE PTR [rsi+0xd]
    15ed:	30 47 0d             	xor    BYTE PTR [rdi+0xd],al
    15f0:	0f b6 46 0e          	movzx  eax,BYTE PTR [rsi+0xe]
    15f4:	30 47 0e             	xor    BYTE PTR [rdi+0xe],al
    15f7:	0f b6 46 0f          	movzx  eax,BYTE PTR [rsi+0xf]
    15fb:	30 47 0f             	xor    BYTE PTR [rdi+0xf],al
    15fe:	c3                   	ret    
    15ff:	90                   	nop
```
Sans le for :

```asm
    1600:	c5 f9 6f 0f          	vmovdqa xmm1,XMMWORD PTR [rdi]
    1604:	c5 f1 ef 06          	vpxor  xmm0,xmm1,XMMWORD PTR [rsi]
    1608:	c5 f9 7f 07          	vmovdqa XMMWORD PTR [rdi],xmm0
    160c:	c3                   	ret    
    160d:	0f 1f 00             	nop    DWORD PTR [rax]

```

Nous comprenons alors la différence obtenue au temps d'execution. Il y a beaucoup moins d'appels avec les instructions processeur.


De plus, nous avons résolu beaucoup de problèmes, notament des warnings pour rendre plus robuste notre code et rarifier les bugs.


**Objectifs de la séance :**
- Ronan :
    - [x] Optimisation et affichage performance AES
    - [x] Corrections de bugs
    - [x] Correction warnings

- Etienne :
    - [x] Gestion de l'entrée de mdp
    - [x] Mesure des performances et comparaison
    - [x] Corrections de bugs
    - [x] Fichiers de tests

# Séance 10 (9/06/23)

Regardons le gain de performance de mixColumn en précalculant les valeurs.

Voici le code optimisé avec les multiplications précalculées:

```c
    byte output[16];

    for (int i = 0; i < 4; i++) {
        output[i*4] = mixTable02[state[i*4]] ^ mixTable03[state[(i*4)+1]] ^ state[((i*4)+2)] ^ state[((i*4)+3)];
        output[(i*4)+1] = (state[i*4]) ^ mixTable02[state[(i*4)+1]] ^ mixTable03[state[(i*4+2)]] ^ (state[(i*4+3)]);
        output[(i*4)+2] = (state[i*4]) ^ (state[(i*4)+1]) ^ mixTable02[state[(i*4+2)]] ^ mixTable03[state[(i*4+3)]];
        output[(i*4)+3] = (mixTable03[state[i*4]]) ^ (state[(i*4)+1]) ^ (state[(i*4+2)]) ^ mixTable02[state[(i*4+3)]];
    }
```

Et le code avec les multiplications:

```c
    byte output[16];

    for (int i = 0; i < 4; i++) {
        output[i*4] = multPoly(0x02, state[i*4]) ^ multPoly(0x03, state[(i*4)+1]) ^ state[((i*4)+2)] ^ state[((i*4)+3)];
        output[(i*4)+1] = (state[i*4]) ^ multPoly(0x02, state[(i*4)+1]) ^ multPoly(0x03, state[(i*4+2)]) ^ (state[(i*4+3)]);
        output[(i*4)+2] = (((state[i*4]) ^ (state[(i*4)+1]) ^ multPoly(0x02, state[(i*4+2)]) ^ multPoly(0x03, state[(i*4+3)])));
        output[(i*4)+3] = ((multPoly(0x03, state[i*4]) ^ (state[(i*4)+1]) ^ (state[(i*4+2)]) ^ multPoly(0x02, state[(i*4+3)])));
    }
```

Les tests sont effectués sur 100.000.000 de tours.
| Mode |  Temps |
|--:|:----------|
| Multiplications précalculées          | 0.945364 |
| Multiplications non précalculées      | 7.636789 |

On voit que le temps d'execution est grandement diminué, on divise le temps par 7. On enleve 8 opérations de multiplication à chaque appel de mixColumn, ce qui laisse uniquement des xor.
<br>*Pour la mesure des performances, toutes les optimisations sont activées*<br>

**Performances encodage 1Go en AES 128 en CBC:**

En utilisant les instructions processeur:
- Temps AES : 0,789 s
- Vitesse AES : 1267,922 mo/s

Sans utiliser les instructions processeur:
- Temps AES : 14,559 s
- Vitesse AES : 68,685 mo/s

On voit que la différence de performance est de x18.
Pour le décodage, les vitesse sont similaires.

**Performances encodage 1Go en AES 128 en ECB:**

En utilisant les instructions processeur:
- Temps AES : 0,298 s
- Vitesse AES : 3352,420 mo/s

Sans utiliser les instructions processeur:
- Temps AES : 14,242 s
- Vitesse AES : 70.215 mo/s

On voit que la différence de performance est de x48.