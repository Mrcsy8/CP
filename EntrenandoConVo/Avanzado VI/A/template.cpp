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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> nums((s.size()+1)/2);
    for(int i = 0;i < s.size(); i += 2)
    {
        nums[i/2] = s[i] - '0';
    }
    sort(ALL(nums));
    
    forn(i, nums.size())
    {
        cout << nums[i];
        if(i != nums.size() - 1)
        {
            cout << "+";
        }
    }
    cout << "\n";
    return 0;
}