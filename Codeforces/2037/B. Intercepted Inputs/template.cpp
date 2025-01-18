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
    int k;
    cin >> k;
    vector<int> a(k);
    multiset<int> a_set;
    REP(i, 0, k)
    {
        cin >> a[i];
        a_set.insert(a[i]);
    }

    int cant = a.size() - 2;
    for (int i = 0; i < k; ++i)
    {
        if (cant % a[i] == 0)
        {
            if (a[i] == cant / a[i] && a_set.count({cant / a[i]}) > 1)
            {
                cout << a[i] << " " << cant / a[i] << "\n";
                break;
            }
            else if (a[i] != cant / a[i] && a_set.find(cant / a[i]) != a_set.end())
            {
                cout << a[i] << " " << cant / a[i] << "\n";
                break;
            }
        }
    }
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