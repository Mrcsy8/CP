#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int sunk(vector<ll> &ships, ll &k, int n)
{
    if(*(ships.end()-1) <= k)
    {
        return n;
    }
    ll l, r;
    l = k/2;
    r = k/2;
    if(k%2)
    {
        l++;
    }
    ll ships_sunk_l = upper_bound(ships.begin(), ships.end(), l) - ships.begin();
    ll ships_sunk_r = ships.end() - 1 - lower_bound(ships.begin(), ships.end(), *(ships.end()-1)-r);
    ll tot_sunk = ships_sunk_l + ships_sunk_r;
    return tot_sunk;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> ships(n);
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            sum += a;
            ships[i] = sum;
        }
        cout << sunk(ships, k, n) << "\n";
    }
    return 0;
}