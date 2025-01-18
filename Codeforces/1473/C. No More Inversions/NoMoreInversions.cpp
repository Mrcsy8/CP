#include <bits/stdc++.h>

using namespace std;

vector<deque<int>> results;

int main()
{
    int t;
    cin >> t;

    results.resize(t);

    for(int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        for(int j = k; j >= 1; j--)
        {
            if(j <= -n + 2 * k - 1)
            {
                results[i].push_front(j);
            }
            else
            {
                results[i].push_back(j);
            }
        }

    }
    for(auto i: results)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}