#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    string n;
    cin >> n;
    ll twos = 0, nines = 0, tot = 0;
    for (int i = 0; i < n.size(); i++)
    {
        tot += n[i] - '0';
        if (n[i] == '2')
            twos++;
        if (n[i] == '3')
            nines++;
    }
    tot = tot % 9;
    if (tot == 0)
    {
        cout << "YES\n";
        return;
    }

    bool ans = false;
    while (twos != 0 || nines != 0)
    {
        if (tot % 9 == 3 && nines >= 1 || tot % 9 == 6 && nines >= 2)
        {
            ans = true;
            break;
        }
        else if (twos > 0)
        {
            tot += 2;
            twos--;
        }
        else
            break;
        if (tot % 9 == 0)
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}