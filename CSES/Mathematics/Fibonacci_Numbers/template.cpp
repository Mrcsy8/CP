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

const ll MOD = 1e9 + 7;

long double power(long double a, ll b){
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        long double p = power(a, b / 2);
        return fmodl(p * p, MOD);
    }
    else
    {
        long double p = power(a, (b - 1) / 2);
        return fmodl(fmodl(p * p, MOD) * a, MOD);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    long double r1 = (1+sqrt(5))/2, r2 = (1-sqrt(5))/2;
    long double res = (pow(r1,n) + pow(r2,n)) / sqrt(5);
    PRT(res);
    return 0;
}