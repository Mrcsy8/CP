#define oper min
#define NEUT INF

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