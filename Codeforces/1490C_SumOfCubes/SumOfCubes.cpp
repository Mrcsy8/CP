#include<bits/stdc++.h>
 
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

vector<bool> result;

int main()
{
    int t;
    cin >> t;

    REP(i,0,t)
    {
        long long x;
        cin >> x;

        long long max = cbrt(x);
        bool check = 0;
        for(int a = 1; a <= max; a++)
        {
            long long a_cube = pow(a,3);
            long long b = cbrt(x-a_cube);
            if(b > 0 && pow(b, 3) == x - a_cube)
            {
                result.push_back({1});
                check = 1;
                break;
            }
        }
        if(!check)
        {
            result.push_back({0});
        }
    }
    for(auto i : result)
    {
        if(i)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}