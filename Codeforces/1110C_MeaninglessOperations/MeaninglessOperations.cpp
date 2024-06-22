#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

set<int> sum_pow2({1});
vector<int> result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--)
    {
        int a;
        cin >> a;
        
        int last = *sum_pow2.rbegin();
        last ++;
        while(a >= last)
        {
            last = last * 2;
            sum_pow2.insert(last - 1);
        }
        if(sum_pow2.find(a) == sum_pow2.end())
        {
            result.push_back(*sum_pow2.upper_bound(a));
        }
        else
        {
            int square_root = sqrt(a);
            bool found = 0;
            for(int j = 3; j <= square_root; j += 2)
            {
                if(a % j == 0)
                {
                    result.push_back(a / j);
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                result.push_back(1);
            }
        }
    }
    for(auto i : result)
    {
        cout << i << endl;
    }
    
   return 0; 
}