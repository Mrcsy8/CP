#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> operations;
vector<pair<int,int>> result;

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int min = *min_element(arr.begin(), arr.end());
        int ops = n - count(arr.begin(), arr.end(), min);
        
        operations.push_back(ops);
        result.push_back(make_pair(n, min));
    }

    for(int i = 0; i < t; i++)
    {
        cout << operations[i] << "\n";
        for(int j = 0; j < result[i].first; j++)
        {
            cout << result[i].second << " ";
        }
        cout << "\n";
    }
    
    return 0;
}