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

typedef long long ll;

int n;

void dfs(vector<int> &p, vector<vector<bool>> &a, vector<int> &pos)
{
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> p(n), pos(n);
    forn(i,n)
    {
		cin >> p[i];
		p[i]--;
		pos[p[i]] = i;
	}
	for(auto i : pos)
	{
		DBG(i);
	}
	vector<vector<bool>> a(n, vector<bool>(n));
	
	forn(i,n)
	{
		string val;
		cin >> val;
		forn(j,n)
		{
			a[i][j] = val[j];
		}
	}
	for()
	dfs(p, a, pos);
	forn(i,n)
	{
		cout << p[i] + 1 << " ";
	}
	cout << "\n";
    return 0;
}
