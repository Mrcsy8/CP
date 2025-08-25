ll a[N][N];
ll st[2*N][2*N];
#define oper min
#define NEUT INF
struct ST2D { // 2D segment tree for oper over matrix
	int n, m;
	void build(int _n, int _m) {
		n=_n, m=_m;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)
			st[i+n][j+m]=a[i][j];
		for(int i=0;i<n;i++)for(int j=m-1;j;--j)
			st[i+n][j]=oper(st[i+n][j<<1],st[i+n][j<<1|1]);
		for(int i=n-1;i;--i)for(int j=0;j<2*m;j++)
			st[i][j]=oper(st[i<<1][j],st[i<<1|1][j]);
	}
	void upd(int x, int y, ll v) {
		st[x+n][y+m]=v;
		for(int j=y+m;j>1;j>>=1)
			st[x+n][j>>1]=oper(st[x+n][j],st[x+n][j^1]);
		for(int i=x+n;i>1;i>>=1)
			for(int j=y+m;j;j>>=1)
				st[i>>1][j]=oper(st[i][j],st[i^1][j]);
	}
	ll query(int x0, int x1, int y0, int y1) {
		ll r=NEUT;
		for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
			if(i0&1) r=qmerge(r,i0++,y0,y1);
			if(i1&1) r=qmerge(r,--i1,y0,y1);
		}
		return r;
	}
	ll qmerge(ll r, int row, int y0, int y1) {
		for(int j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
			if(j0&1) r=oper(r,st[row][j0++]);
			if(j1&1) r=oper(r,st[row][--j1]);
		}
		return r;
	}
}; // usage: ST2D st; st.build(n,m); st.upd(x,y,v); st.query(x0,x1,y0,y1); ranges [a;b)
