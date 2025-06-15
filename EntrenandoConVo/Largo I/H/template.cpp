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
#define PNT(x) cout<<x<<"\n";

typedef long long ll;

int n, m, c;

bool check(vector<int> &sh){
    forn(i,n-1){
        if(sh[i] == 0 || sh[i+1] == 0 || sh[i] > sh[i+1])
        {
            return false;
        }
    }
    return true;
}

int actualizar(vector<int> &sh, int p){
    int ind = ceil(p / (c/ (double)n)) - 1;
    if(sh[ind] == 0){
        sh[ind] = p;
        return ind;
    }
    if(p > sh[ind]){
        while(sh[ind] != 0 && sh[ind] <= p && ind != n-1){
            ind++;
        }
        sh[ind] = p;
        return ind;
    }
    if(p < sh[ind]){
        while(sh[ind] != 0 && sh[ind] >= p && ind != 0){
            ind--;
        }
        sh[ind] = p;
        return ind;
    }
    int l = ind;
    int r = ind;
    while(l != 0 && sh[l] == sh[ind]){
        l--;
    }
    while(r != n-1 && sh[r] == sh[ind]){
        r++;
    }
    if(sh[l] == 0){
        sh[l] = p;
        return l;
    }
    if(sh[r] == 0){
        sh[r] = p;
        return r;
    }
    if(sh[l] != sh[ind]){
        sh[l] = p;
        return l;
    }
    sh[r] = p;
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    vector<int> sh(n,0);
    while(m--){
        int p;
        cin >> p;
        cout << actualizar(sh, p) + 1 << endl;
        fflush(stdout);
        if(check(sh)){
            break;
        }
    }
    return 0;
}