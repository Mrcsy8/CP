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

// Greatest Common Divisor, O(lg a + lg b)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Primes up to n, O(n lg n)
vector<bool> prime;
void primes_to_n(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}

// a to the power of b, O(lg b)
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

//
vector<ll> factorial;
void fact_to_n(ll n)
{
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}

//
vector<ll> inverse_factorial;
void inv_fact_to_n(ll n)
{
    inverse_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inverse_factorial[i] = inverse_factorial[i + 1] * (i + 1) % MOD;
}

//
ll comb_num(ll n, ll m)
{
    return (factorial[n] * inverse_factorial[n - m] % MOD) * inverse_factorial[m] % MOD;
}
//
const int MAXN = 1e7, M = 1e9 + 7;
int INV[MAXN];
// ...
INV[1] = 1;
for (ll a = 2; a < MAXN; a++)
    INV[a] = M - (ll)(M / a) * INV[M % a] % M;