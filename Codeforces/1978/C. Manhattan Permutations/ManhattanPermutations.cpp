#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        ll max_sum;
        if(n%2)
        {
            max_sum = (pow(n,2)-1)/2;
        }
        else
        {
            max_sum = pow(n,2)/2;
        }
        if(k <= max_sum && !(k%2))
        {
            vector<ll> p(n);
            REP(i,0,n-1)
            {
                p[i] = i+1;
            }
            ll i = 0;
            while(k != 0)
            {
                if(k >= (n-i*2-1)*2)
                {
                    p[i] = n-i;
                    p[n-i-1] = i+1;
                    k -= (n-i*2-1)*2;
                }
                else
                {
                    ll ch = k/2 + i;
                    p[i] = ch+1;
                    p[ch] = i+1;
                    k -= (ch-i)*2;
                }
                i++;
            }
            cout << "Yes\n";
            REP(i,0,n-1)
            {
                cout << p[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}