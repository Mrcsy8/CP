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
 
typedef long long ll;

class Dist {
    public:
    int index;
    ll distMin;
    ll distMax;
};

class Bridge {
    public:
    int index;
    ll largo;
};

bool comp (const Dist &a, const Dist &b){
	if(a.distMax == b.distMax){
		return a.distMin < b.distMin;
	}
	return a.distMax < b.distMax;
}
struct comp1 {
    bool operator()(const Bridge &a, const Bridge &b) const {
        if(a.largo == b.largo) return a.index < b.index;
        return a.largo < b.largo;
    }
};
 
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<pair<ll,ll>> isl(n);
	forn(i,n){
		ll l, r;
		cin >> l >> r;
		isl[i] = mp(l, r);
	}
	vector<Dist> dist(n-1);
	forn(i,n-1){
		dist[i].distMin = isl[i+1].fst - isl[i].snd;
        dist[i].distMax = isl[i+1].snd - isl[i].fst;
        dist[i].index = i;
	}
	sort(ALL(dist), comp);
	set<Bridge, comp1> b;
	forn(i,m){
		ll a;
		cin >> a;
        Bridge l;
		l.index = i;
        l.largo = a;
        b.insert(l);
	}
	bool res = true;
	ll exc = m - n + 1;
	if(exc < 0){
		cout << "No\n";
		return 0;
	}
    vector<int> ans(n-1);
    forn(i,n-1){
        Bridge c;
        c.index = -1;
        c.largo = dist[i].distMin;
        auto it = b.lower_bound(c);
        if(it == b.end() || it->largo > dist[i].distMax){
            res = false;
            break;
        }
        ans[dist[i].index] = it->index;
        b.erase(it);
    }
	if(res){
		cout << "Yes\n";
		for(auto i : ans){
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
	else{
		cout << "No\n";
	}
	
	return 0;
}
