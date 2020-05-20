#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"

int EstEspace (wchar_t Valeur) {
	if (Valeur == ' ') return 1;
	return 0;
}

int VerificationChar(wchar_t* ptrch) 
{
	
	int i =0;
	while (i < wcslen(ptrch)-1) {
		
		switch(ptrch[i]) {
			case L'$': 
			case L'<':
			case L'>':
			case L',':
			case L'/':
			case L'*':
			case L'.':
			case L'+':
			case L'-':
			case L'%':
				return 1;
				break;
			default:
				break;
		}
		i++;
	}
	return 0;		
}

void ChangementChar(wchar_t *ptrch)
{
	int i = 0;

	while (i < wcslen(ptrch))
	{ //à - â - ä - é - è - ê - ë - ï - î - ô - ö - ù - û - ü - ÿ - ç

		ptrch[i] = tolower(ptrch[i]);

		// le tolower ne marche pas sur les maj. avec accent
		switch (ptrch[i])
		{
		case L'à':
		case L'À':
		case L'â':
		case L'Â':
		case L'ä':
		case L'Ä':
			ptrch[i] = L'a';
			break;
		case L'é':
		case L'É':
		case L'è':
		case L'È':
		case L'ê':
		case L'Ê':
		case L'ë':
		case L'Ë':
			ptrch[i] = L'e';
			break;
		case L'ï':
		case L'Ï':
		case L'î':
		case L'Î':
			ptrch[i] = L'i';
			break;
		case L'ô':
		case L'Ô':
		case L'ö':
		case L'Ö':
			ptrch[i] = L'o';
			break;
		case L'ù':
		case L'Ù':
		case L'û':
		case L'Û':
		case L'ü':
		case L'Ü':
			ptrch[i] = L'u';
			break;
		case L'ÿ':
			ptrch[i] = L'y';
			break;
		case L'ç':
			ptrch[i] = L'c';
			break; 	
		default:
			break;
		}
		i++;
	}
}
