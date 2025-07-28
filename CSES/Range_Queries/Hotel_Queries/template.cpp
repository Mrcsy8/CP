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

#define oper max
#define NEUT 0

const int N = 2e5;

struct STree { // segment tree for min over long long, range [a;b)
	vector<ll> st; int n;
	STree(int n): st(4*n+5, NEUT), n(n) {}
	void init(int k, int s, int e, ll *a) {
		if (s+1 == e) { st[k] = a[s]; return; }
		int m = (s+e)/2;
		init(2*k, s, m, a);
		init(2*k+1, m, e, a);
		st[k] = oper(st[2*k], st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v) {
		if (s+1 == e) { st[k] = v; return; }
		int m = (s+e)/2;
		(p < m ? upd(2*k, s, m, p, v) : upd(2*k+1, m, e, p, v));
		st[k] = oper(st[2*k], st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b) {
		if (e <= a || s >= b) return NEUT;
		if (a <= s && e <= b) return st[k];
		int m = (s+e)/2;
		return oper(query(2*k, s, m, a, b),
		            query(2*k+1, m, e, a, b));
	}
	void init(ll *a) { init(1, 0, n, a); }
	void upd(int p, ll v) { upd(1, 0, n, p, v); }
	ll query(int a, int b) { return query(1, 0, n, a, b); }
}; // usage: STree rmq(n); rmq.init(x); rmq.upd(i,v); rmq.query(a,b);

STree rmq(N);

ll f(int a){
    return rmq.query(0,a+1);
}

int bs(ll g, int n){
    int l = -1, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m) >= g) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll h[N];
    forn(i,n){
        cin >> h[i];
    }
    rmq.init(h);
    vector<int> res;
    forn(i,m){
        ll r;
        cin >> r;
        int hot = bs(r, n);
        if(hot != n){
            res.pb(hot+1);
            rmq.upd(hot, rmq.query(hot, hot+1)-r);
        }
        else{
            res.pb(0);
        }
    }
    forn(i,m){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}