#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int nor = 0, sou = 0, eas = 0, wes = 0;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'N':
                nor++;
                break;
            case 'S':
                sou++;
                break;
            case 'E':
                eas++;
                break;
            case 'W':
                wes++;
                break;
            }
        }
        if ((!(abs(nor - sou) % 2) && !(abs(eas - wes) % 2)) && !(nor == 1 && sou == 1 && !eas && !wes) && !(!nor && !sou && eas == 1 && wes == 1))
        {
            int nor_r = nor / 2, sou_r = sou / 2, eas_r = ceil((float)eas / 2), wes_r = ceil((float)wes / 2);
            int nor_h = ceil((float)nor / 2), sou_h = ceil((float)sou / 2), eas_h = eas / 2, wes_h = wes / 2;
            for (int i = 0; i < n; i++)
            {
                switch (s[i])
                {
                case 'N':
                    if (nor_h)
                    {
                        cout << "H";
                        nor_h--;
                    }
                    else
                    {
                        cout << "R";
                        nor_r--;
                    }
                    break;
                case 'S':
                    if (sou_h)
                    {
                        cout << "H";
                        sou_h--;
                    }
                    else
                    {
                        cout << "R";
                        sou_r--;
                    }
                    break;
                case 'E':
                    if (eas_h)
                    {
                        cout << "H";
                        eas_h--;
                    }
                    else
                    {
                        cout << "R";
                        eas_r--;
                    }
                    break;
                case 'W':
                    if (wes_h)
                    {
                        cout << "H";
                        wes_h--;
                    }
                    else
                    {
                        cout << "R";
                        wes_r--;
                    }
                    break;
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}