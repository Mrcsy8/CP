#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll x,y;
        cin >> n >> x >> y;

        multiset<pair<int,int>> mods;
        ll tot = 0;
        REP(i,0,n-1)
        {
            ll a;
            cin >> a;
            pair<ll,ll> rest = make_pair(((a%x)+x)%x, ((a%y)+y)%y);
            mods.insert(rest);
        }
        while(!mods.empty())
        {
            pair<ll,ll> rest = *mods.begin();
            pair<ll,ll> comp = make_pair((x-rest.first)%x, rest.second);
            if(rest == comp)
            {
                tot += ((mods.count(rest)-1)*mods.count(rest))/2;
                mods.erase(rest);
            }
            else
            {
                tot += mods.count(rest)*mods.count(comp);
                mods.erase(rest);
                mods.erase(comp);
            }
        }
        cout << tot << "\n";
    }
    return 0;
}