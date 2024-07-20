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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int water = 0;
        int pos = -1;
        bool dead = false, finish = false;
        while (!dead && !finish)
        {
            if (pos + m >= n)
            {
                finish = true;
                break;
            }
            bool jumped = false;
            bool swim = true;
            for (int i = pos + m; i > pos; i--)
            {
                if (s[i] == 'L')
                {
                    pos = i;
                    jumped = true;
                    swim = false;
                }
            }
            if (swim)
            {
                for (int i = pos + m; i > pos; i--)
                {
                    if (s[i] == 'W')
                    {
                        jumped = true;
                        pos = i;
                        do
                        {
                            pos++;
                            water++;
                        } while (pos < n && s[pos] == 'W');
                        if (pos != n && s[pos] == 'C')
                        {
                            dead = true;
                            break;
                        }
                    }
                }
            }
            if (!jumped || water > k)
            {
                dead = true;
            }
        }
        if (finish)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}