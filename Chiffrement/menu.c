#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"
#include "demandeutilisateur.h"

void MenuChoixAlgo(int *ptrChoixAlgo, int *ptrChoixAction)
{
	wprintf(L"Choisir le type de chiffrement : \n");
	wprintf(L"0 - Code de César\n");
	wprintf(L"1 - Code de vigenère\n");
	wprintf(L"\n");
	wprintf(L"Saisir le numéro correspondant : ");
	*ptrChoixAlgo = SaisieChoix(0, 1);

	if (*ptrChoixAlgo == 0)
	{
		wprintf(L"Code de césar :\n");
	}
	else
	{
		wprintf(L"Code de vigenère :\n");
	}
	wprintf(L"\n");
	wprintf(L"0 - Chiffrer\n");
	wprintf(L"1 - Déchiffrer\n");
	wprintf(L"\n");
	wprintf(L"Saisir le numéro correspondant : ");
	*ptrChoixAction = SaisieChoix(0, 1);
}
