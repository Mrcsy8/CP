#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool compareSecondFirst(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.S != b.S)
        return a.S < b.S;
    return (a.F < b.F);
}

bool searchSecond(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.S < b.S;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++)
        {
            ll input;
            cin >> input;
            a[i] = make_pair(input, input % k);
        }
        sort(a.begin(), a.end(), compareSecondFirst);
        ll ops = 0;
        if (n % 2)
        {
            bool odd = false;
            ll i = 0;
            while (i < n)
            {
                auto low = lower_bound(a.begin(), a.end(), a[i], searchSecond);
                auto up = upper_bound(a.begin(), a.end(), a[i], searchSecond);
                ll siz_x = up - low;
                if (siz_x % 2)
                {
                    if (!odd)
                    {
                        odd = true;
                        vector<ll> x(siz_x);
                        for (int i = 0; i < siz_x; i++)
                        {
                            x[i] = a[low - a.begin() + i].F;
                        }
                        ll siz_fix = siz_x / 2 + 1;
                        vector<ll> prefix(siz_fix), sufix(siz_fix);
                        for (int i = 1; i < siz_fix; i++)
                        {
                            prefix[i] = prefix[i - 1] + x[i * 2 - 1] - x[i * 2 - 2];
                        }
                        for (int i = siz_fix - 2; i >= 0; i--)
                        {
                            sufix[i] = sufix[i + 1] + x[i * 2 + 2] - x[i * 2 + 1];
                        }
                        ll min_diff = LONG_LONG_MAX;
                        for (int i = 0; i < siz_fix; i++)
                        {
                            ll diff = prefix[i] + sufix[i];
                            if (diff < min_diff)
                                min_diff = diff;
                        }
                        ops += min_diff / k;
                        i += siz_x;
                    }
                    else
                    {
                        ops = -1;
                        break;
                    }
                }
                else
                {
                    while (a[low - a.begin()].S == a[i].S)
                    {
                        ops += (a[i + 1].F - a[i].F) / k;
                        i += 2;
                    }
                }
            }
            cout << ops << "\n";
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i].S == a[i + 1].S)
                {
                    ops += (a[i + 1].F - a[i].F) / k;
                    i++;
                }
                else
                {
                    ops = -1;
                    break;
                }
            }
            cout << ops << "\n";
        }
    }
    return 0;
}