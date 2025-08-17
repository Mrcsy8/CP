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
    int n;
    cin >> n;
    vector<string> nums((1 << n));
    forn(i,n){
        forn(j,(1 << n)){
            forn(k,(1 << i)){
                if(j == (1 << n)) break;
                nums[j] += '0';
                j++;
            }
            forn(k,(1 << i+1)){
                if(j == (1 << n)) break;
                nums[j] += '1';
                j++;
            }
            forn(k,(1 << i)){
                if(j == (1 << n)) break;
                nums[j] += '0';
                j++;
            }
            j--;
        }
    }
    forn(i,(1 << n)){
        PRT(nums[i]);
    }
    return 0;
}