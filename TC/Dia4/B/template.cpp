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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<tuple<int,int,int>> plants(n);
        vector<unordered_map<int,int>> times(3);
        forn(i,n){
            int x;
            cin >> x;
            times[0][x]++;
            int y;
            cin >> y;
            times[1][y]++;
            int z;
            cin >> z;
            times[2][z]++;
            plants[i] = make_tuple(x,y,z);
        }
        priority_queue<int> vals;
        int i = 0;
        for(auto [a,b,c] : plants){
            vals.push(-max(times[0][a],max(times[1][b], times[2][c])));
            i++;
        }
        forn(k, n){
            while(!vals.empty() && -vals.top() <= k){
                vals.pop();
            }
            cout << n - vals.size() << " ";
        }
        cout << "\n";
    }
    return 0;
}