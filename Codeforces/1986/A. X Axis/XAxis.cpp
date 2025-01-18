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
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        cout << max({x1,x2,x3}) - min({x1,x2,x3}) << "\n";
    }
    return 0;
}