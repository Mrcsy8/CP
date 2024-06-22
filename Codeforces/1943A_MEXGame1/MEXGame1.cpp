#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

multiset<int> c;
vector<int> result;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        REP(i, 0, n)
        {
            int a;
            cin >> a;
            c.insert(a);
        }
        
        int cont = 0;
        bool life = 0;
        while(c.count(cont) >= 1)
        {
            
            if(c.count(cont) == 1)
            {
                if(life == 1)
                {
                    break;
                }
                life = 1;
            }
            
            cont++;
        }
        
        c.clear();
        result.push_back(cont);
    }

    for(auto i : result)
    {
        cout << i << "\n";
    }

    return 0;
}
