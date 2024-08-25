#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s[2];
        cin >> s[0] >> s[1];
        vector<vector<vector<int>>> pref(2, vector<vector<int>>(26, vector<int>(n + 1, 0)));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 26; j++)
                for (int k = 0; k < n; k++)
                    pref[i][j][k + 1] = pref[i][j][k] + (s[i][k] - 'a' == j);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            for (int i = 0; i < 26; i++)
                ans += abs((pref[0][i][r] - pref[0][i][l]) - (pref[1][i][r] - pref[1][i][l]));
            cout << ans / 2 << "\n";
        }
    }
    return 0;
}