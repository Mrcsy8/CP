#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

vector<int> min_sums(1);
vector<vector<int>> results;
unordered_set<int> used;

int main()
{
    int t;
    cin >> t;

    results.resize(t);

    REP(i, 0, t)
    {
        int n, l, r, s;
        cin >> n >> l >> r >> s;

        while(n >= min_sums.size())
        {
            min_sums.push_back(*min_sums.rbegin() + min_sums.size());
        }
        int length = r - l + 1;
        int max_sum = (n*(n+1)-(n-length)*(n-length+1))/2;

        if(s >= min_sums[length] && s <= max_sum)
        {
            results[i].resize(n);
            for(int j = l; j <= r; j++)
            {
                for(int k = n; k >= 1; k--)
                {
                    if(min_sums[length - 1] + k <= s && max_sum >= s - k && used.find(k) == used.end())
                    {
                        results[i][j-1] = k;
                        s -= k;
                        length--;
                        max_sum -= k;
                        used.insert(k);
                        break;
                    }
                }
            }
            for(int j = 1; j <= n; j++)
            {
                if(used.find(j) == used.end())
                {
                    int size = results[i].size();
                    for(int k = 0; k < size; k++)
                    {
                        if(results[i][k] == 0)
                        {
                            results[i][k] = j;
                            break;
                        }
                    }
                }
            }
            used.clear();
        }
        else
        {
            results[i].push_back({-1});
        }
    }
    for(auto i : results)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}