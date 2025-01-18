#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

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

bool t_prime(ll n)
{
    return (ll)sqrt(n) * (ll)sqrt(n) == n && prime[sqrt(n)];
}

void solve()
{
    primes_to_n(prime, 1e6);
    int n;
    cin >> n;
    ll x;
    REP(i, 0, n)
    {
        cin >> x;
        t_prime(x) ? cout << "YES\n" : cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}