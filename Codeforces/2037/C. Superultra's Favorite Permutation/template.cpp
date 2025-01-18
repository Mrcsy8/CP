#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    bool ans = false;
    int odd, even;
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 2; j <= n; j += 2)
        {
            if (!prime[i + j])
            {
                odd = i;
                even = j;
                ans = true;
                break;
            }
        }
        if (ans)
            break;
    }
    if (ans)
    {
        for (int i = 2; i <= n; i += 2)
        {
            if (i != even)
                cout << i << " ";
        }
        cout << even << " " << odd << " ";
        for (int i = 1; i <= n; i += 2)
        {
            if (i != odd)
                cout << i << " ";
        }
    }
    else
    {
        cout << -1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    primes_to_n(2 * (10e5));
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}