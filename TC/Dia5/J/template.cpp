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
#define PRT(x) cout<<x<<"\n";

typedef long long ll;

vector<ll> factorial;
vector<ll> inverse_factorial;
ll MOD;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2);
        return p * p % MOD;
    }
    else
    {
        ll p = power(a, (b - 1) / 2);
        return p * p % MOD * a % MOD;
    }
}

void fact_to_n(ll n)
{
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}

void inv_fact_to_n(ll n)
{
    inverse_factorial.resize(n+1);
    inverse_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inverse_factorial[i] = inverse_factorial[i + 1] * (i + 1) % MOD;
}

ll comb_num(ll n, ll m)
{
    return (factorial[n] * inverse_factorial[n - m] % MOD) * inverse_factorial[m] % MOD;
}

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> MOD;
    vector<int> col(n,0);
    forn(i,m){
        string s;
        cin >> s;
        forn(i,n){
            if(s[i] == '1'){
                col[i]++;
            }
        }
    }
    fact_to_n(500);
    inv_fact_to_n(500);
    ll cant1 = 0, cant2 = 0;
    forn(i,n){
        if(col[i] == 0){
            cant2++;
        }
        if(col[i] == 1){
            cant1++;
        }
    }
    DBG(cant2);
    ll res = 1, sum = cant2 * 2 + cant1 % MOD;
    while(sum >= 2){
        res = res * comb_num(sum,2) % MOD;
        sum -= 2;
    }
    sum = cant2 * 2 + cant1 % MOD;
    res -= (((cant2 * (n-m))%MOD * comb_num(sum-2,2))%MOD * power(power(2,cant2-1),phi(MOD) - 1))%MOD;
    res = (res + MOD) % MOD; 
    DBG(res);
    DBG(power(2,cant2));
    res = res * power(power(2,cant2),phi(MOD) -1) % MOD;
    PRT(res);
    return 0;
}