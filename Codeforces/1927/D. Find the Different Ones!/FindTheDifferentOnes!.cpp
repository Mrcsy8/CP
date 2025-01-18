#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPI(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(j,0,n)
        {
            cin >> a[j];
        }
        vector<int> next_diff(n,-1);
        for(int j = n-2; j >= 0; j--)
        {
            if(a[j+1] != a[j])
            {
                next_diff[j] = j+1;
            }
            else
            {
                next_diff[j] = next_diff[j+1];
            }
        }
        int q;
        cin >> q;
        int l, r;
        while(q--)
        {
            cin >> l >> r;
            l--; r--;
            if(next_diff[l] != -1 && next_diff[l] <= r)
            {
                cout << l+1 << " " << next_diff[l]+1 << "\n";
            }
            else
            {
                cout << "-1 -1\n";
            }
        }
    }
    return 0;
}