# Mini projet - C

Réalisation d'un **mini projet en C** réalisé par Ugo Legouas & Mehdi Zenasni dans le cadre du module M2101 en 1er année d'IUT INFORMATIQUE à Paul Sabatier
Le sujet traite du **chiffrement** et **déchiffrement** de message grâce à l'algorithme de César et de Vigenère et avec gestion des caractères accentués


![consigne](https://framagit.org/Soulsedge/mini-projet-c/uploads/881549f548234e3e4052515b71c18661/cons.PNG)

## Documentation : 
|Sommaire des fonctions                                                                                    |
| ------                                                                                                   |
|   [SaisieChoix](#saisiechoix) - Saisie de valeur de l'utilisateur                                        |
|   [MenuChoixAlgo](#menuchoixalgo) - Affichage du menu du choix                                           |
|   [DemandeMessage](#demandermessage) - Demande le message à chiffrer à l'utilisateur                     |
|   [EstEspace](#estespace) - Vérifie si le caractère est un espace                                        |
|   [VerificationChar](#demandevaleur) - Vérifie la présence de mauvais caractères                         |
|   [ChangementChar](#changementchar) - Suppresion des accents                                             |
|   [DemandeValeur](#demandevaleur) - Demande de la valeur de décalage                                     |
|   [DemanderCle](#demandercle) - Demande de la clé                                                        |
|   [ModificationVigenere](#modificationVigenere) - Modifie le message via l'algorythme de Vigenère        |
|   [ModificationCesar](#modificationCésar) - Modifie le message via l'algorythme de césar                 |
|   [AffichageResultat](#affichageresultat) - Affiche le résultat                                          |



### SaisieChoix
```c
int SaisieChoix(int Min, int Max)
```
Fonction saisiechoix utilisé pour faire rentrer un nombre à l'utilisateur compris min et max passés en paramètre.
Il gère les caractères et re invite à la saisie si la valeur rentré n'est pas un nombre entre min et max.

>Parameters :
>
>   * int Min- Valeur minimun attendu
>    
>   * int Max - Valeur maximun attendu

>Returns:
>
>  * int - retourne la valeur saisie par l'utilisateur

### MenuChoixAlgo
```c
void MenuChoixAlgo(int *ptrChoixAlgo, int *ptrChoixAction)
```

Fonction menuChoixAlgo permettant d'afficher le menu de choix dans la console utilisateur puis appelle la fonction saisiechoix à deux reprise,
l'un pour ChoixAlgo correspond au choix entre César et Vigenère et secondement pour ChoixAction étant l'action Chiffrer/Déchiffrer
Retourne void car les pointeurs sont passés en paramètre

>Parameters :
>
>  *  int* ptrChoixAlgo- pointeur vers choix de l'algorythme à utiliser (César / Vigenère)
>    
>  *  int* ptrChoixAction - pointeur vers choix Chiffrement / Déchiffrement
  

### EstEspace
```c
int EstEspace (wchar_t Valeur)
```
Fonction qui retourne 1 si le caractère est un espace sinon retourne 0
>Parameters :
>
>  *  wchar_t Valeur - Caractère à vérifier
>    

  
    
### DemandeMessage
```c
void DemandeMessage(wchar_t *ptrch)
```

Fonction demandemessage demandant une chaine de wchar_t à l'utilisateur et étant le message à convertir 
Retourne void car le pointeur est passé en paramètre

>Parameters :
>
>   * wchar_t* ptrch - Pointeur vers le message à convertir 
>    
   

### ChangementChar 
```c
void ChangementChar(wchar_t *ptrch)
```

Fonction changementchar modifiant le message saisie par l'utilisateur pour supprimer les accents et caractères spéciaux
Retourne void car le pointeur est passé en paramètre 

>Parameters :
>
> *   wchar_t* ptrch - Pointeur vers le message à convertir 
>

### VerificationChar
```c
void VerificationChar(wchar_t *ptrch)
```

Fonction VerificationChar qui vérifie si le message ne comporte pas de caractère interdit

>Parameters :
>
> *   wchar_t* ptrch - Pointeur vers le message à convertir 
>




### DemandeValeur
```c
void DemandeValeur(int *ptrValeurDecalage)
```

Fonction demandevaleur demandant à l'utilisateur la valeur de décalage qu'il veut pour l'algorythme de César
Retourne void car le pointeur est passé en paramètre 
>Parameters :
>
>*    int* ptrValeurDecalage - Pointeur vers la valeur de décalage
>    
   

### DemanderCle   
```c
void DemanderCle(wchar_t *ptrCle)
```

Fonction demandercle qui demande à l'utilisateur la cle qu'il veut utiliser pour l'algorythme de vigenère
Retourne void car le pointeur est passé en paramètre 

>Parameters :
>
>*    wchar_t* ptrCle - pointeur vers la clé
> 

    
### ModificationVigenere
```c
void ModificationVigenere(wchar_t *ptrch, int Choix, wchar_t *ptrCle, wchar_t *ptrAlphabet)
```

Fonction modificationVigenere modifiant le message ch passé en paramètre (ptrch) via la clé aussi passé en paramètre (ptrcle), 
il chiffre ou déchifre selon le choix passé en paramètre (choix)

>Parameters :
>
> *  wchar_t* ptrCle - pointeur vers la clé
>   
> *  int choix - Choix chiffrement / déchiffrement
>    
>   * wchar_t* ptrch - pointeur vers le message à chiffrer
>    
>   * wchar_t* ptrAlphabet - pointeur vers l'alphabet 
    
   

### ModificationCesar
```c
void ModificationCesar(wchar_t *ptrch, int Choix, int ValeurDecalage, wchar_t *ptrAlphabet)
```

Fonction modificationCesar modifiant le message ch passé en paramètre (ptrch) via la clé aussi passé en paramètre (ptrcle), 
il chiffre ou déchifre selon le choix passé en paramètre (choix)

>Parameters :
>
>   * int ValeurDecalage - valeur de décalage de l'algorythme de César
>    
>  *  int Choix - choix chiffrement / déchiffrement
>    
>  *  wchar_t* ptrch - pointeur vers le message à chiffrer
>    
>   * wchar_t* ptrAlphabet - pointeur vers l'alphabet 

### AffichageResultat
```c
void AffichageResultat(wchar_t *ch)
```

Fonction affichant le résultat de la chaine une fois modifié par le chiffrement 
>Parameters :
>
>   * wchar_t* ch - pointeur vers le message
>
>    
    
