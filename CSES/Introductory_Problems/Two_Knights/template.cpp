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

bool check(int x, int y, int n){
	if(min(x,y) < 0 || max(x,y) > n){
		return false;
	}
	return true;
} 

ll esp(int x, int y, int n){
	ll cont = 0;
	cont += check(x-2,y-1,n);
	cont += check(x-2,y+1,n);
	cont += check(x+2,y-1,n);
	cont += check(x+2,y+1,n);
	cont += check(x-1,y-2,n);
	cont += check(x-1,y+2,n);
	cont += check(x+1,y-2,n);
	cont += check(x+1,y+2,n);
	return ((ll)n+1) * (n+1) - cont - 1;
}

void calc(int r){
    if(r == 0){
		PRT(0);
		return;
	}
	if(r == 1){
		PRT(6);
		return;
	}
	if(r == 2){
		PRT(28);
		return;
	}
	ll res;
	res = ((ll)r-3)*(r-3)*(((ll)r+1)*(r+1)-9)/2;	
	forn(i,r-1){
		res += 4*esp(0,i,r);
	}
	res -= 4 * (r-2);
	PRT(res);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    cin >> n;
    forn(i,n){
		calc(i);
	}
    return 0;
}