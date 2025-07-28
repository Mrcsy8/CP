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

const int N = 1000;

#define oper sum
#define NEUT 0

int sum(int n, int m){
    return n + m;
}

int a[N][N];
int st[2*N][2*N];

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
	void upd(int x, int y, int v) {
		st[x+n][y+m]=v;
		for(int j=y+m;j>1;j>>=1)
			st[x+n][j>>1]=oper(st[x+n][j],st[x+n][j^1]);
		for(int i=x+n;i>1;i>>=1)
			for(int j=y+m;j;j>>=1)
				st[i>>1][j]=oper(st[i][j],st[i^1][j]);
	}
	int query(int x0, int x1, int y0, int y1) {
		int r=NEUT;
		for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
			if(i0&1) r=qmerge(r,i0++,y0,y1);
			if(i1&1) r=qmerge(r,--i1,y0,y1);
		}
		return r;
	}
	int qmerge(int r, int row, int y0, int y1) {
		for(int j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
			if(j0&1) r=oper(r,st[row][j0++]);
			if(j1&1) r=oper(r,st[row][--j1]);
		}
		return r;
	}
}; // usage: ST2D st; st.build(n,m); st.upd(x,y,v); st.query(x0,x1,y0,y1); ranges [a;b)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    forn(i,n){
        string s;
        cin >> s;
        forn(j,n){
            if(s[j] == '.'){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 1;
            }
        }
    }
    ST2D seg;
    seg.build(n,n);
    forn(i,q){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;y1--;y2--;
        PRT(seg.query(x1,x2+1,y1,y2+1));
    }
    return 0;
}