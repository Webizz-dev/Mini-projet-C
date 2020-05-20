#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "AffichageResultat.h"
#include "GestionChar.h"
#include "Menu.h"
#include "ModificationVigenere.h"
#include "ModificationCesar.h"
#include "Demandeutilisateur.h"


void main()
{

	struct lconv *loc;
	setlocale(LC_ALL, "");
	loc = localeconv();

	//Demande choix algorithme & choix Chiffrement/Déchiffrement
	int ChoixAlgo;
	int *ptrChoixAlgo = &ChoixAlgo;

	int ChoixAction;
	int *ptrChoixAction = &ChoixAction;

	//L'alphabet tout simplement
	wchar_t Alphabet[26] = {L"abcdefghijklmnopqrstuvwxyz"};

	//Message à chiffrer
	wchar_t ch[100];

	//Valeur de décalage
	int ValeurDecalage;
	int *ptrValeurDecalage = &ValeurDecalage;

	//Clé pour vigenère
	wchar_t Cle[10];

	//Affichage menu de sélection
	MenuChoixAlgo(ptrChoixAlgo, ptrChoixAction);
	//Demande du message à chiffrer à l'utilisateur
	DemandeMessage(ch);

	//vérification caractères interdits
	if (VerificationChar(ch) ==1) {
		wprintf(L"Votre message contient des caractères interdits ! Veuillez ressayer après suppression du problème\n");
	} else {
		
		//On enleve les caractères accentués
		ChangementChar(ch);

		//On regarde choix Césat ou Vigenère
		if (ChoixAlgo == 0)
		{

			//Demande de la valeur de décalage
			DemandeValeur(ptrValeurDecalage);
			//Modification César
			ModificationCesar(ch, ChoixAction, ValeurDecalage, Alphabet);
		}
		else
		{
			//Demande de la clé
			DemanderCle(Cle);
			//Modification Vigenère
			ModificationVigenere(ch, ChoixAction, Cle, Alphabet);
		}

		//Affichage du résultat
		AffichageResultat(ch);
	}
}
