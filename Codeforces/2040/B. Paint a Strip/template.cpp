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
    int n;
    cin >> n;
    int fto = 2, ones = 4;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    while (n > ones)
    {
        fto++;
        ones = (ones + 1) * 2;
    }
    cout << fto << "\n";
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