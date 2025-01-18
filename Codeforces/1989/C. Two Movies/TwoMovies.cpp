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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int sum_a = 0, sum_b = 0;
        int minus = 0, plus = 0;
        for (int i = 0; i < n; i++)
        {

            if (a[i] == 1 && b[i] == 1)
                plus++;
            else if (a[i] == -1 && b[i] == -1)
                minus++;
            else
            {
                if (a[i] > b[i])
                    sum_a += a[i];
                else
                    sum_b += b[i];
            }
        }
        while (plus--)
        {
            if (sum_a > sum_b)
                sum_b++;
            else
                sum_a++;
        }
        while (minus--)
        {
            if (sum_a > sum_b)
                sum_a--;
            else
                sum_b--;
        }
        cout << min(sum_a, sum_b) << "\n";
    }
    return 0;
}