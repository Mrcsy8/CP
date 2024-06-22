#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

vector<vector<int>> result;

int main()
{
    int t;
    cin >> t;

    result.resize(t);
    REP(i, 0, t)
    {
        int l, r;
        cin >> l >> r;

        bool check = 0;
        l = max(3, l);
        REPI(j, l, r)
        {
            if (!(j % 2))
            {
                result[i].push_back(j / 2);
                result[i].push_back(j / 2);
                check = 1;
                break;
            }
            else
            {
                int root = sqrt(j);
                bool check_break = 0;
                REPI(k, 3, root)
                {
                    if (!(j % k))
                    {
                        result[i].push_back(j / k);
                        result[i].push_back(j - j / k);
                        check = 1;
                        check_break = 1;
                        break;
                    }
                }
                if (check_break)
                {
                    break;
                }
            }
        }
        if (!check)
        {
            result[i].push_back({-1});
        }
    }
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}