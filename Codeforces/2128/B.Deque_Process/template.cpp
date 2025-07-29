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
        deque<int> p;
        forn(i,n){
            int in;
            cin >> in;
            p.pb(in);
        }
        bool ch = false;
        while(!p.empty()){
            if(p.front() == p.back()){
                cout << "L";
                break;
            }
            int l = p.front(), r = p.back();p.pop_back();p.pop_front();
            if(ch){
                if(r > l){
                    cout << "RL";
                }
                else{
                    cout << "LR";
                }
            }
            else{
                if(l > r){
                    cout << "RL";
                }
                else{
                    cout << "LR";
                }
            }
            ch = !ch;
        }
        cout << "\n";
    }
    return 0;
}