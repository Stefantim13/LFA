/*
Implementati un automat finit determinist (DFA)

Programul citeste din fisierul “input.txt” urmoatoarele informatii:
-pe prima linie, numarul de stari ale automatului (numit N)
-pe a doua linie, starile automatu(numere intregi, nu nelui aparat consecutive)
-pe linia a treia, numarul de tranzitii (sa il notam M)
-pe urmatoarele M linii, descrierea unei tranzitii, sub formatul:
- x y l, unde x este starea (nodul) din care pleaca tranzitia (muchia, arcul)
y este starea in care ajunge tranzitia, l este litera tranzitiei
-pe urmatoarea linie este scris un numar natural S, care inseamna starea initiala
-pe urmatoarea linie gasim nrF, care inseamna numarul de stari finale
-pe urmatoarea linie gasim nrF numere intregi (nrF<=N), reprezentand starile
finale
-pe urmatoarea linie gasim NrCuv, care inseamna numarul de cuvinte ce
urmeaza a fi verificate
-pe urmatoarele NrCuv linii se gaseste cate un cuvant
Programul vostru trebuie sa afiseze, in fisierul “output.txt”, pe nrCuv linii
separate, unul din cuvinetele DA sau NU, semnificand daca cuvantul respectiv este sau
nu acceptat de automat.
*/


#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");


vector <int> v;
map<int, vector <pair <int, char>>> q;
map <int, bool> f;


void parcurgere(string cuvant, int poz, int stare_actuala)
{
    if(poz < cuvant.length())
    {
        for(auto x: q[stare_actuala])
        {
            if(x.second == cuvant[poz])
                return parcurgere(cuvant, poz + 1, x.first);
        }
        fout << "NU\n";
        return;
    }
    else
    {
        if(f[stare_actuala])
        {
           fout << "DA\n";
            return;
        }
        else
        {
           fout << "NU\n";
            return;
        }
    }
}

int main()
{
    int n, m, x, y, s, nf, nc;
    char l;
    string cuv;


    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> x;
        v.push_back(x);
    }

    fin >> m;
    for(int i = 0; i < m; ++i)
    {
        fin >> x >> y >> l;
        q[x].push_back({y,l});
    }

    fin >> s;
    fin >> nf;
    for(int i = 0; i < nf; ++i)
    {
        fin >> x;
        f[x] = true;
    }

    fin >> nc;
    for(int t = 0 ; t < nc; ++t)
    {
        fin >> cuv;
        parcurgere(cuv, 0, s);
    }
    return 0;
}