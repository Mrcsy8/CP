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
        int n;
        cin >> n;
        string s_c;
        cin >> s_c;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            s[i] = (int)s_c[i] - (int)'0';
        }
        int min = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int sum = s[i] * 10 + s[i + 1];
            if (sum == 0)
            {
                min = 0;
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (j != i && j != i + 1)
                {
                    if (s[j] == 0)
                    {
                        min = 0;
                        break;
                    }
                    else if (s[j] != 1)
                    {
                        if (sum == 1)
                            sum = 0;
                        sum += s[j];
                    }
                }
            }
            if (sum < min)
                min = sum;
            if (min == 0)
                break;
        }
        cout << min << "\n";
    }
    return 0;
}