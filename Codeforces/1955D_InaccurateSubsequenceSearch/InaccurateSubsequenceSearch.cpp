#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        multiset<int> b;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++)
        {
            int bt;
            cin >> bt;
            b.insert(bt);
        }
        int tot = 0;
        multiset<int> c,d,e = b;
        for(int i = 0; i < m; i++)
        {
            auto search = c.find(a[i]);
            
            search = e.find(a[i]);
            if(search != e.end())
            {
                e.erase(search);
                d.insert(a[i]);
            }
            else
            {
                c.insert(a[i]);
            }
        }
        if(d.size() >= k)
        {
            tot++;
        }
        for(int l = 1; l <= n-m; l++)
        {
            auto search = c.find(a[l-1]);
            if(search != c.end())
            {
                c.erase(search);
            }
            else
            {
                search = d.find(a[l-1]);
                if(search != d.end())
                {
                    d.erase(search);
                    e.insert(a[l-1]);
                }
            }
            search = e.find(a[l+m-1]);
            if(search != e.end())
            {
                e.erase(search);
                d.insert(a[l+m-1]);
            }
            else
            {
                c.insert(a[l+m-1]);
            }
            if(d.size() >= k)
            {
                tot++;
            }
        }
        cout << tot << "\n";
    }
    return 0;
}