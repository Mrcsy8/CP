#include<bits/stdc++.h>

using namespace std;

vector<int> operations;
vector<vector<vector<int>>> result;

int main()
{
    int t;
    cin >> t;

    result.resize(t);
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> a_i;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            a_i.push_back(a);
        }
        auto min_ele = min_element(a_i.begin(), a_i.end());
        int ops = 0;
        int index = (int)distance(a_i.begin(), min_ele);
        for(int j = 0; j < n; j++)
        {

            if(j != index)
            {
                if(index%2 == j%2)
                {
                    result[i].push_back({index + 1, j + 1, *min_ele, *min_ele});
                }
                else
                {
                    result[i].push_back({index + 1, j + 1, *min_ele, *min_ele+1});
                }
                
                ops++;
            }
        }
        operations.push_back(ops);
    }

    for(int i = 0; i < t; i++)
    {
        cout << operations[i] << "\n";
        for(auto i : result[i])
        {
            for(auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}