#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

queue<int> a_i, b_i;
vector<vector<int>> result;

int main()
{
    int t;
    cin >> t;

    result.resize(t);
    REP(i,0,t)
    {
        int k, n, m;
        cin >> k >> n >> m;
        int zero[2] = {0, 0};
        while(!a_i.empty())
        {
            a_i.pop();
        }
        while(!b_i.empty())
        {
            b_i.pop();
        }
        REP(j, 0, n)
        {
            int a;
            cin >> a;
            if(!a) zero[0]++;
            a_i.push(a);
        }
        REP(j, 0, m)
        {
            int b;
            cin >> b;
            if(!b) zero[1]++;
            b_i.push(b);
        }
        int j = 0;
        while(!a_i.empty() || !b_i.empty())
        {
            if(!a_i.empty() && !a_i.front())
            {
                result[i].push_back(a_i.front());
                a_i.pop();
                j++;
                continue;
            }
            if(!b_i.empty() && !b_i.front())
            {
                result[i].push_back(b_i.front());
                b_i.pop();
                j++;
                continue;
            }
            if(!a_i.empty() && a_i.front() <= j + k)
            {
                result[i].push_back(a_i.front());
                a_i.pop();
            }
            else if(!b_i.empty() && b_i.front() <= j + k)
            {
                result[i].push_back(b_i.front());
                b_i.pop();
            }
            else
            {
                result[i].clear();
                result[i].push_back({-1});
                break;
            }
        }
    }
    for(auto i : result)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}