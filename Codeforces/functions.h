#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

// NUMBER THEORY

// Greatest Common Divisor, O(lg a + lg b)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Primes up to n, O(n lg n)
vector<bool> prime;
void primes_to_n(vector<bool> &prime, ll n)
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
int MOD = 1e2;
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