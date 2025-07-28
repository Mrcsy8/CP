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

string grid[8];
ll res = 0;

void calc(){
    int per[8] = {0,1,2,3,4,5,6,7};
    do{
        if(grid[0][per[0]] != '.' || grid[1][per[1]] != '.' || grid[2][per[2]] != '.' || grid[3][per[3]] != '.' || grid[4][per[4]] != '.' || grid[5][per[5]] != '.' || grid[6][per[6]] != '.' || grid[7][per[7]] != '.'){
            continue;
        }
        set<int> diag1, diag2;
        diag1.insert(per[0]);diag1.insert(per[1]+1);diag1.insert(per[2]+2);diag1.insert(per[3]+3);diag1.insert(per[4]+4);diag1.insert(per[5]+5);diag1.insert(per[6]+6);diag1.insert(per[7]+7);
        diag2.insert(per[0]+7);diag2.insert(per[1]+6);diag2.insert(per[2]+5);diag2.insert(per[3]+4);diag2.insert(per[4]+3);diag2.insert(per[5]+2);diag2.insert(per[6]+1);diag2.insert(per[7]);
        if(diag1.size() == 8 && diag2.size() == 8){
            res++;
        }
    }
    while(next_permutation(per, per+8));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    forn(i,8){
        cin >> grid[i];
    }
    calc();
    PRT(res);
    return 0;
}