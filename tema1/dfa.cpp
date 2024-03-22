/*

Implementati un automat finit determinist (DFA).

Programul citeste din fisierul “input.txt” urmoatoarele informatii:

-pe prima linie, numarul de stari ale automatului (numit N)
-pe a doua linie, starile automatului (numere intregi, nu neaparat consecutive)
-pe linia a treia, numarul de tranzitii (sa il notam M)
-pe urmatoarele M linii, descrierea unei tranzitii, sub formatul:
	- x y l, unde x este starea (nodul) din care pleaca tranzitia (muchia, arcul) y este starea in care ajunge tranzitia, l este litera tranzitiei
-pe urmatoarea linie este scris un numar natural S, care inseamna starea initiala
-pe urmatoarea linie gasim nrF, care inseamna numarul de stari finale
-pe urmatoarea linie gasim nrF numere intregi (nrF<=N), reprezentand starile finale
-pe urmatoarea linie gasim NrCuv, care inseamna numarul de cuvinte ce urmeaza a fi verificate
-pe urmatoarele NrCuv linii se gaseste cate un cuvant

	Programul vostru trebuie sa afiseze, in fisierul “output.txt”, pe nrCuv linii separate, unul din cuvinetele DA sau NU, semnificand daca cuvantul respectiv este sau nu acceptat de automat.

*/

#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1e5 + 5;
vector <int> v,f;
vector <pair<int,int>> q;
int main()
{
	int n, m, x, y, s, nrf, nrc;
	char l;
	string c;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		cin >> x >> y >> l;
		q[x].push_back()
	}
	cin >> s;
	cin >> nrf;
	for(int i = 1; i <= nrf; ++i)
	{
		cin >> x;
		f.push_back(x);
	}
	cin >> nrc;
	for(int i = 1; i <= nrc; ++i)
	{
		cin >> c;
	}
	return 0;
}
