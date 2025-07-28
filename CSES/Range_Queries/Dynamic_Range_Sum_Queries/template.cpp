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

const ll INF = 1e9 + 8;
int N = 2e5;

ll suma(ll a, ll b){
	return a + b;
}

#define oper suma
#define NEUT 0
struct STree { // segment tree for min over long long
	vector<ll> st; int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>b||e-1<a)return NEUT;
		if(a<=s&&e-1<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n); rmq.init(x); rmq.upd(i,v); rmq.query(a,b); // [a;b] inclusive

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll s[N];
    forn(i,n){
        cin >> s[i];
    }
    STree rmq(n);
    rmq.init(s);
    forn(i,q){
		int o;
		cin >> o;
		o--;
		if(o){
			int a, b;
			cin >> a >> b;
			a--;b--;
			PRT(rmq.query(a,b));
		}
		else{
			int k;
			ll u;
			cin >> k >> u;
			k--;
			rmq.upd(k,u);
		}
        
    }
    return 0;
}