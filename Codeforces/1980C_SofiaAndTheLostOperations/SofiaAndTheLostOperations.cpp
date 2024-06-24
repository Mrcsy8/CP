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
        vector<long long> a_i, b_i;
        multiset<long long> d_i;
        int n;
        cin >> n;
        REP(j,0,n)
        {
            long long a;
            cin >> a;
            a_i.push_back(a);
        }
        REP(j,0,n)
        {
            long long b;
            cin >> b;
            b_i.push_back(b);
        }
        int m;
        cin >> m;
        long long last;
        REP(j,0,m)
        {
            long long d;
            cin >> d;
            d_i.insert(d);
            last = d;
        }
        bool answer = 1;
        
        REP(j,0,n)
        {
            if(a_i[j] != b_i[j])
            {
                if(d_i.count(b_i[j]))
                {
                    d_i.erase(d_i.find(b_i[j]));
                }
                else
                {
                    answer = 0;
                    break;
                }
            }
        }
        if(answer)
        {
            sort(b_i.begin(), b_i.end());
            int k = 0;
            int size = b_i.size();
            for (int j = size/2; j >= 1; j /= 2) {
                while (k+j < size && b_i[k+j] <= last) k += j;
            }
            if(b_i[k] != last)
            {
                answer = 0;
            }
        }
        result.push_back(answer);
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