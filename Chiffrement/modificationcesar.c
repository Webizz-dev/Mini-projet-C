#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "gestionchar.h"

void ModificationCesar(wchar_t *ptrch, int Choix, int ValeurDecalage, wchar_t *ptrAlphabet)
{

    int Val;
    int i = 0;

    while (i < wcslen(ptrch) - 1)
    {
        
        //Suppresion des majuscules
        ptrch[i] = tolower(ptrch[i]);

        if (EstEspace(ptrch[i]) == 1) {
            i++;
        } else {
            int Compteur = 0;
            //Identifier le caractère
            while (ptrAlphabet[Compteur] != ptrch[i])
            {
                Compteur++;
            }
            //prise en compte du Choix & modification de la chaine
            if (Choix == 0)
            {
                Val = (Compteur + ValeurDecalage) % 26;
            }
            else
            {
                Val = (Compteur - ValeurDecalage);
                // Si nombre négatif
                if (Val <= 0)
                {
                    Val = 26 + Val;
                }
            }
            ptrch[i] = ptrAlphabet[Val];
            i++;
        }
    }
}