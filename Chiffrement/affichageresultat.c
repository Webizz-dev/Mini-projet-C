#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"

void AffichageResultat(wchar_t *ch)
{
	wprintf(L"Voici le résultat : %ls\n", ch);
	FILE *fp;
	fp = fopen("resultat.txt", "w+");
	if (fp)
	{
		fputws(ch, fp);
		wprintf(L"Votre résultat a aussi été enregistré dans le fichier resultat.txt !\n");

	}
	else
	{
		wprintf(L"Erreur à l'ouverture du fichier\n");
	}
	fclose(fp);
}
