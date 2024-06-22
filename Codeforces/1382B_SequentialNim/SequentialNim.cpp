#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

vector<int> a_i;
vector<bool> result;

int main()
{
    int t;
    cin >> t;

    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int count_1 = 0;
        bool check_2 = 0;
        REP(j, 0, n)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                count_1++;
            }
            else
            {
                if(!check_2)
                {
                    result.push_back(count_1 % 2);
                    check_2 = 1;
                }
            }
        }
        if(!check_2)
        {
            result.push_back((count_1+1) % 2);
        }
    }

    for(auto i : result)
    {
        if(i)
        {
            cout << "Second" << "\n";
        }
        else
        {
            cout << "First" << "\n";
        }
    }


    return 0;
}