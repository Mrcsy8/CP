#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

vector<ll> factorial;
void fact_to_n(ll n)
{
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i;
}

bool divisibility_by_3(ll n, ll d)
{
    if (n > 2 || (factorial[n] * d) % 3 == 0)
        return true;
    return false;
}

bool divisibility_by_7(ll n, ll d)
{
    if (n > 5)
        return true;
    int rests_dec[6] = {0, 1, 4, 6, 5, 2};
    ll rest = factorial[n] % 6;
    if ((rests_dec[rest] * d) % 7 == 0)
        return true;
    return false;
}

bool divisibility_by_9(ll n, ll d)
{
    if (n > 8 || (factorial[n] * d) % 9 == 0)
        return true;
    return false;
}

void solve()
{
    ll n, d;
    cin >> n >> d;
    cout << "1 ";
    if (divisibility_by_3(n, d))
        cout << "3 ";
    if (d == 0 || d == 5)
        cout << "5 ";
    if (divisibility_by_7(n, d))
        cout << "7 ";
    if (divisibility_by_9(n, d))
        cout << "9 ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact_to_n(15);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}