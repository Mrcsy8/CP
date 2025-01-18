#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<int> ind;
        for(int i = 0; i < m; i++)
        {
            int indi;
            cin >> indi;
            ind.insert(indi);
        }
        string c;
        cin >> c;
        sort(c.begin(), c.end());
        int  i = 0;
        while(!ind.empty())
        {
            s[*ind.begin()-1] = c[i];
            ind.erase(ind.begin());
            i++;
        }
        cout << s << "\n";
    }
    return 0;
}