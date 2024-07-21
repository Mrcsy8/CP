#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve()
{
    int n;
    cin >> n;
    multiset<int> a;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.insert(input);
        maxi = max(maxi, input);
    }
    bool check = false;
    while (!a.empty())
    {
        if (a.count(*a.rbegin()) % 2)
            check = true;
        a.erase(*a.rbegin());
    }
    check ? cout << "YES" : cout << "NO";
    cout << "\n";
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