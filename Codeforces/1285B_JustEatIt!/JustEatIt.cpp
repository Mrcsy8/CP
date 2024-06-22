#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

vector<long long> partial_sums;
vector<bool> results;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        long long tot_sum = 0;
        
        partial_sums.clear();
        partial_sums.push_back({0});
        REP(i, 1, n+1)
        {
            long long a;
            cin >> a;
            tot_sum += a;
            partial_sums.push_back(tot_sum);
        }

        auto max = max_element(partial_sums.begin(), partial_sums.end());
        auto min = partial_sums.end() - 1;

        for(auto i = partial_sums.end() - 2; i >= partial_sums.begin(); i--)
        {
            if(*min > *i)
            {
                min = i;
            }
        }

        if(*max - *min < partial_sums[n] || (min == partial_sums.begin() && max == partial_sums.end() - 1))
        {
            results.push_back({1});
        }
        else
        {
            results.push_back({0});
        }
    }

    for(auto i : results)
    {
        if(i == 1)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}