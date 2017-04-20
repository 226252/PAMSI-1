#ifndef mergesort_HPP
#define mergesort_HPP
using namespace std;
#include "../array.hpp"


/* Scalanie dwoch posortowanych ciagow
tab[pocz...sr] i tab[sr+1...kon] i
wynik zapisuje w tab[pocz...kon] */

void merge(stru::array<int> &tablica,int start, int srodek, int koniec)
{
stru::array<int> tab_pom; // utworzenie tablicy pomocniczej
int i = start, j = srodek+1, k = 0; // zmienne pomocnicze
 
while (i <= srodek && j <= koniec)
{
if (tablica[j] < tablica[i])
{
tab_pom.push_back(tablica[j]);
j++;
}
else
{
tab_pom.push_back(tablica[i]);
i++;
}
k++;
}
 
if (i <= srodek)
{
while (i <= srodek)
{
tab_pom.push_back(tablica[i]);
i++;
k++;
}
}
else
{
while (j <= koniec)
{
tab_pom.push_back(tablica[j]);
j++;
k++;
}
}
 
for (i = 0; i <= koniec-start; i++)
tablica[start+i] = tab_pom[i]; 
 
}

 
/* Procedura sortowania tab[pocz...kon] */
void mergesort(stru::array<int> &array, int pocz, int kon)
{
int sr;
if (pocz<kon) {
sr=(pocz+kon)/2;
mergesort(array, pocz, sr);    // Dzielenie lewej części
mergesort(array, sr+1, kon);   // Dzielenie prawej części
merge(array, pocz, sr, kon);   // Łączenie części lewej i prawej
}
}





#endif