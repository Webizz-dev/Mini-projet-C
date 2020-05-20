#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"

int SaisieChoix(int min, int max)
{
	int nb;
	int buf;
	while (1)
	{
		if (wscanf(L"%d", &nb) == 0)
		{
			do
			{
				buf = getwchar();
			} while (buf != '\n' && buf != EOF);
		}
		else if (min <= nb && nb <= max)
		{
			do
			{
				buf = getwchar();
			} while (buf != '\n' && buf != EOF);
			return nb;
		}
		wprintf(L"Veuillez saisir une valeur valide : ");
	}
}


void DemandeMessage(wchar_t *ptrch)
{
	wprintf(L"Entrez le message a convertir ! (Max : 100 caracteres)\n");
	fgetws(ptrch, 100, stdin);
}

void DemandeValeur(int *ptrValeurDecalage)
{
	wprintf(L"Avec quel valeur voulait vous faire le décalage ?\n");
	*ptrValeurDecalage = SaisieChoix(1, 9999);
}


void DemanderCle(wchar_t *ptrCle)
{
	wprintf(L"Quel clé de chiffrement voulait vous utiliser ?\n");
	fgetws(ptrCle, 100, stdin);
}
