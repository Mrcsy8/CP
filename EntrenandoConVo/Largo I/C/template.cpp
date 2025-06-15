#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)

#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

typedef long long ll;

struct compa {
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) const
    {
        if(a.fst != b.fst)
        {
            return a.fst < b.fst;
        }
        return a.snd > b.snd;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    forn(i,n)
    {
        cin >> x[i];
    }
    ll sum = 0, k_cont = k - 1, maxi = 0;
    pair<ll,ll> res;
    set<pair<ll, ll>, compa> g;
    queue<pair<ll, ll>> cola;
    dforsn(i,n-k,n)
    {
        sum += x[i];
    }
    dforn(i,n-k)
    {
        cola.push(mp(sum, (ll)i + 1));
        sum -= x[i + k];
        sum += x[i];
        if(k_cont > 0)
        {
            k_cont--;
        }
        else
        {
            g.insert(cola.front());
            cola.pop();
            if(sum + (*g.rbegin()).fst >= maxi)
            {
                res.fst = i;
                res.snd = (*g.rbegin()).snd;
                maxi = sum + (*g.rbegin()).fst;
            }
        }
    }
    
    cout << res.fst + 1<< " " << res.snd + 1<< "\n";
    return 0;
}