#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

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

void solve()
{
    primes_to_n(10e6);
    int n;
    cin >> n;
    multiset<ll> a;
    unordered_multiset<ll> b;
    REP(i, 0, n)
    {
        ll in;
        cin >> in;
        a.insert(in);
    }
    ll ones = a.count(1);
    if (ones <= 1)
    {
        bool prime_found = false;
        bool sum_found = false;
        ll prime_backup;
        for (auto i = a.begin(); i != a.end(); ++i)
        {
            if (!prime_found && prime[*i] == true)
            {
                prime_backup = *i;
                prime_found = true;
            }
            for (auto j = next(i); j != a.end(); ++j)
            {
                if (prime[*i + *j] == true)
                {
                    b.insert(*i);
                    b.insert(*j);
                    sum_found = true;
                    break;
                }
            }
            if (sum_found)
                break;
        }
        if (!sum_found && prime_found)
            b.insert(prime_backup);
    }
    else
    {
        REP(i, 0, ones)
        b.insert(1);
        for (auto i = a.begin(); i != a.end(); ++i)
        {
            if (*i != 1 && prime[*i + 1] == true)
            {
                b.insert(*i);
                break;
            }
        }
    }
    if (b.size() == 0)
        b.insert(*a.begin());
    cout << b.size() << "\n";
    for (const auto &i : b)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}