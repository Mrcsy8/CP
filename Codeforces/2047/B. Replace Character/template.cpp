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
    string s;
    cin >> n >> s;
    vector<int> alpha(26, 0);
    for (int i = 0; i < n; ++i)
        alpha[s[i] - 'a']++;
    int max = 0, index_max = 0, min = INT16_MAX;
    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] > max)
        {
            max = alpha[i];
            index_max = i;
        }
        if (alpha[i] < INT16_MAX && alpha[i] != 0 && alpha[i] < min)
            min = alpha[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (s[i] - 'a' != index_max && alpha[s[i] - 'a'] == min)
        {
            s[i] = 'a' + index_max;
            break;
        }
    }
    for (int i = 0; i < n; ++i)
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