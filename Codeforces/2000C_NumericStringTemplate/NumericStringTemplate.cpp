#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int n, m;
string s;

void checkString(string &s, vector<ll> &a)
{
    bool ans = true;
    vector<ll> alpha(26, LONG_LONG_MAX);
    int siz = s.size();
    if (siz != n)
    {
        cout << "NO\n";
        return;
    }
    map<int, char> char_map;
    REP(i, 0, siz)
    {
        if ((char_map.find(a[i]) != char_map.end() && char_map[a[i]] == s[i]) || char_map.find(a[i]) == char_map.end())
            char_map.insert(make_pair(a[i], s[i]));
        else
        {
            cout << "NO\n";
            return;
        }
    }
    REP(i, 0, siz)
    {
        if (alpha[s[i] - 'a'] == LONG_LONG_MAX)
            alpha[s[i] - 'a'] = a[i];
        else if (alpha[s[i] - 'a'] != a[i])
        {
            ans = false;
            break;
        }
    }

    (ans) ? cout << "YES\n" : cout << "NO\n";
}

void solve()
{
    cin >> n;
    vector<ll> a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    cin >> m;
    REP(i, 0, m)
    {
        cin >> s;
        checkString(s, a);
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