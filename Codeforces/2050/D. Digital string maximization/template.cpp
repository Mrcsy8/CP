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
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i + 1] > s[i] + 1)
        {
            int temp = s[i];
            s[i] = s[i + 1] - 1;
            s[i + 1] = temp;
            i -= 2;
            if (i <= 0)
                i = -1;
        }
    }

    for (int i = 0; i < s.size(); i++)
        cout << s[i];
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