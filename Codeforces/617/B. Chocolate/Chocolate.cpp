#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

vector<bool> chocolate;

int main()
{
    int n;
    cin >> n;


    bool check = 0;
    REP(i,0,n)
    {
        bool a;
        cin >> a;
        chocolate.push_back(a);
        if(a == 1)
        {
            check = 1;
        }
    }
    int cont = 0;
    long long tot = 0;

    for(auto i = find(chocolate.begin(), chocolate.end(), 1) + 1; i < chocolate.end(); i++)
    {
        if(*i)
        {
            if(tot == 0)
            {
                tot = 1 + cont;
            }
            else
            {
                tot *= (1 + cont);
            }
            cont = 0;
        }
        else
        {
            cont++;
        }
    }
    if(check == 1 && tot == 0)
    {
        tot = 1;
    }

    cout << tot << "\n";

    return 0;
}