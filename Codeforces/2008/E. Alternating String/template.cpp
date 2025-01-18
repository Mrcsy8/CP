#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)

#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

typedef long long ll;

int score(vector<int> alpEven, vector<int> alpOdd, int n)
{

    int maxiEven = -1, maxiOdd = -1;
    forn(i, 26)
    {
        maxiEven = max(maxiEven, alpEven[i]);
        maxiOdd = max(maxiOdd, alpOdd[i]);
    }
    return n - maxiEven - maxiOdd;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> alpEven(26, 0), alpOdd(26, 0);
        if (n % 2 == 1)
        {
            forsn(i, 1, n)
            {
                if (i % 2 == 0)
                {
                    alpOdd[s[i] - 'a']++;
                }
                else
                {
                    alpEven[s[i] - 'a']++;
                }
            }
            n--;
            ll mini = LONG_LONG_MAX, index = -1;
            forn(i, n + 1)
            {
                ll tem = score(alpEven, alpOdd, n);
                if (tem < mini)
                {
                    index = i;
                    mini = tem;
                }
                if (i != n)
                {
                    if (i % 2 == 0)
                    {
                        alpEven[s[i] - 'a']++;
                        alpEven[s[i + 1] - 'a']--;
                    }
                    else
                    {
                        alpOdd[s[i] - 'a']++;
                        alpOdd[s[i + 1] - 'a']--;
                    }
                }
            }
            cout << mini + 1 << "\n";
        }
        else
        {
            forn(i, n)
            {
                if (i % 2 == 0)
                {
                    alpEven[s[i] - 'a']++;
                }
                else
                {
                    alpOdd[s[i] - 'a']++;
                }
            }
            cout << score(alpEven, alpOdd, n) << "\n";
        }
    }
    return 0;
}