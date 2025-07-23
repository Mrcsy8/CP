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
    
    int n;
    vector<int> dstr, part;
    vector<pair<int, int>> beacon;
    
    void solveDst(int i){
        auto d = lower_bound(ALL(beacon), mp(beacon[i].fst - beacon[i].snd,0));
        //DBG(part[i-1] - part[d - beacon.begin()]);
        //DBG(i-1 - (d - beacon.begin()));
        DBG(part[i] - part[d - beacon.begin()]);
        dstr[i] = part[i] - part[d - beacon.begin()] + i - (d - beacon.begin());
        part[i + 1] += dstr[i];
        /*
        int cont = 0, j = i - 1;
        while(j >= 0){
            if(beacon[i].fst - beacon[i].snd <= beacon[j].fst){
                cont++;
                cont -= dstr[j];
            }
            else{
                break;
            }
            j--;
        }
        dstr[i] = cont;
        */    
    }
    
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n;
        beacon.resize(n);
        dstr.resize(n);
        part.resize(n + 1);
        forn(i,n){
            int a, b;
            cin >> a >> b;
            beacon[i] = mp(a,b);
        }
        dstr[0] = 0;
        part[0] = 0;
        forsn(i,1,n){
            solveDst(i);
        }
        forn(i,n){
            DBG(part[i]);
        }
        forn(i,n){
            DBG(dstr[i]);
        }
        int rest = 0, s = 0;
        dforn(i,n){
            s += -dstr[i] + 1;
            rest = min(rest, s);
        }
        int cont = 0;
        dforn(i,n){
            int romp = beacon[i].fst - beacon[i].snd;
            i--;
            while(i >= 0 && beacon[i].fst >= romp){
                i--;
                cont++;
            }
            i++;
        }
        PRT(cont + rest);
        return 0;
    }