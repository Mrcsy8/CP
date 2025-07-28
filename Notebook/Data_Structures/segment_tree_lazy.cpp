struct STree { // example: range sum with range addition, open range [a;b)
	vector<ll> st, lazy; int n;
	STree(int n): st(4*n+5, 0), lazy(4*n+5, 0), n(n) {}

	void init(int k, int s, int e, ll *a) {
		lazy[k] = 0;
		if (s + 1 == e) { st[k] = a[s]; return; }
		int m = (s + e) / 2;
		init(2 * k, s, m, a);
		init(2 * k + 1, m, e, a);
		st[k] = st[2 * k] + st[2 * k + 1];
	}

	void push(int k, int s, int e) {
		if (!lazy[k]) return;
		st[k] += (e - s) * lazy[k];
		if (s + 1 < e) {
			lazy[2 * k] += lazy[k];
			lazy[2 * k + 1] += lazy[k];
		}
		lazy[k] = 0;
	}

	void upd(int k, int s, int e, int a, int b, ll v) {
		push(k, s, e);
		if (e <= a || s >= b) return;
		if (s >= a && e <= b) {
			lazy[k] += v;
			push(k, s, e);
			return;
		}
		int m = (s + e) / 2;
		upd(2 * k, s, m, a, b, v);
		upd(2 * k + 1, m, e, a, b, v);
		st[k] = st[2 * k] + st[2 * k + 1];
	}

	ll query(int k, int s, int e, int a, int b) {
		if (e <= a || s >= b) return 0;
		push(k, s, e);
		if (s >= a && e <= b) return st[k];
		int m = (s + e) / 2;
		return query(2 * k, s, m, a, b) + query(2 * k + 1, m, e, a, b);
	}

	void init(ll *a) { init(1, 0, n, a); }
	void upd(int a, int b, ll v) { upd(1, 0, n, a, b, v); }
	ll query(int a, int b) { return query(1, 0, n, a, b); }
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
