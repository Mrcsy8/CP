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

vector<ll> factors (ll n){
	vector<ll> f;
	for(ll x = 2; x*x <= n; x++){
		while(n%x == 0){
			f.pb(x);
			n /= x;
		}
	}
	if(n > 1) f.pb(n);
	return f;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	vector<ll> a(q);
	forn(i,q){
		cin >> a[i];
	}
	forn(i,q){
		ll cont = 1;
		vector<ll> f = factors(a[i]);
		vector<ll> divsC;
		forn(i,f.size()){
			if(f[i] != f[i+1]){
				divsC.pb(cont);
				cont = 1;
			}
			else{
				cont++;
			}
		}
		
		ll res = 1;
		forn(i,divsC.size()){
			res *= (divsC[i] + 1);
		}
		PRT(res);
	}
	return 0;
}