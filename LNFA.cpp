/*
Implementati un Lambda-NFA. Lambda-NFA-ul trebuie sa fie citit din fisier iar
programul trebuie sa verifice, pentru mai multe cuvinte citite din fisier, daca ele
sunt acceptate sau nu de automat. Aveți grijă la cazul în care există cicluri cu
lambda.
*/

#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");


vector <int> v;
map<int, vector <pair <int, char>>> q, qq;
map <int, bool> f, viz;
void vizitat(int nod, int stare_actuala)
{
    viz[nod] = 1;
    for(auto x: qq[nod])
    {
        if(x.second == '0' && !viz[x.first])
        {
            for(auto y: q[x.second])
                q[stare_actuala].push_back(y);
            vizitat(x.first, stare_actuala);
        }
    }
}

void parcurgere(string cuvant, int poz, int stare_actuala)
{
    int k = 1;
    queue <pair <int,int> > qu;
    qu.push({stare_actuala, poz});
    while(!qu.empty())
    {
        pair <int,int> nod_curent = qu.front();
        qu.pop();
        if(nod_curent.second == cuvant.length() && f[nod_curent.first])
        {
            cout << "DA\n";
            return;
        }

        for(auto vec: q[nod_curent.first])
        {
            if(nod_curent.second < cuvant.length() && vec.second == cuvant[nod_curent.second])
            {
                qu.push({vec.first, nod_curent.second + 1});
            }
        }
    }
    cout << "NU\n";

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
        qq[x].push_back({y,l});
        if(l != '0')
            q[x].push_back({y,l});
    }

    fin >> s;
    fin >> nf;
    for(int i = 0; i < nf; ++i)
    {
        fin >> x;
        f[x] = true;
    }

    for(int i = 0; i < n; ++i)
    {
        if(q[v[i]].size() != 0)
        {
            for(auto z: q[v[i]])
            {
                viz.clear();
                vizitat(z.second, z.second);
            }
        }
    }

    fin >> nc;
    for(int t = 0 ; t < nc; ++t)
    {
        fin >> cuv;
        parcurgere(cuv, 0, s);
    }
    return 0;
}