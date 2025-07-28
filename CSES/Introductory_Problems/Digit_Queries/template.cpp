#include <bits/stdc++.h>
using namespace std;

#define forsn(i, s, n) for (int i = int(s); i < int(n); i++)
#define dforsn(i, s, n) for (int i = int(n) - 1; i >= int(s); i--)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) dforsn(i, 0, n)

#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
#define PRT(x) cout<<x<<"\n";

typedef long long ll;

ll inter[] = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889, 98888888889, 1088888888889, 11888888888889, 128888888888889, 1388888888888889, 14888888888888889, 158888888888888889, 1688888888888888889, 3388888888888888872};
ll nueve[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999, 99999999999999, 999999999999999, 9999999999999999, 99999999999999999, 999999999999999999};

ll power(ll a, ll b){
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2);
        return p * p;
    }
    else
    {
        ll p = power(a, (b - 1) / 2);
        return p * p * a;
    }
}

int dig_pos(ll n, int pos){
    return (n / power(10,pos)) % 10; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        int dig = upper_bound(inter, inter + 19, k) - inter;
        ll dif = k - inter[dig-1];
        ll num = nueve[dig-1] + dif / dig;
        if(dif % dig == 0){
            PRT(dig_pos(num, 0));
        }
        else{
            PRT(dig_pos(num+1, dig - dif%dig));
        }
    }
    return 0;
}