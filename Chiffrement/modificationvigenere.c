#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"

void ModificationVigenere(wchar_t *ptrch, int Choix, wchar_t *ptrCle, wchar_t *ptrAlphabet)
{
	//Remplir le tableau
	char tab[26][26];

	int nbligne = 0;
	int colone;
	int valeur;
	int ligne = 0;

	while (nbligne < 26)
	{
		colone = 0;
		valeur = nbligne;

		for (int i = 0; i < 26; i++)
		{
			tab[ligne][colone] = ptrAlphabet[valeur];
			colone++;
			valeur++;
			if (valeur == 26)
			{
				valeur = 0;
			}
		}
		ligne++;
		nbligne++;
	}
	//Fin remplissage du Tab
	//Transformation du message
	int i = 0;
	int compteurCle = 0;
	while (i < wcslen(ptrch) - 1)
	{ 

		//On supp les majuscules
		ptrch[i] = tolower(ptrch[i]);
		ptrCle[i] = tolower(ptrCle[i]);

		if (EstEspace(ptrch[i]) == 1) {
			i++;
		} else {
			int indice1 = ptrch[i] - 'a';
			int indice2 = ptrCle[compteurCle] - 'a';

			compteurCle++;
			if (compteurCle == wcslen(ptrCle) - 1)
			{
				compteurCle = 0;
			}

			//Choix 0 = Chiffrement et Choix 1 == Déchiffrement
			if (Choix == 0)
			{
				ptrch[i] = tab[indice1][indice2];
			}
			else
			{
				int valeurdechi = 100;
				int x = 0;
				while (valeurdechi == 100)
				{

					if (tab[indice2][x] == ptrch[i])
					{
						valeurdechi = tab[0][x];
					}
					x++;
				}
				ptrch[i] = valeurdechi;
			}
			i++;
		}
	}
}
