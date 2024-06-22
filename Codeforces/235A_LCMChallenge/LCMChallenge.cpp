#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int  i = a; i < b; i++)

int main()
{
    long long n;
    cin >> n;
    if(n < 3)
    {
        cout << n << endl;
    }
    else
    {
        if(n%2 == 0)
        {
            if(n % 3 == 0)
            {
                cout << (n-1)*(n-2)*(n-3) << endl;
                
            }
            else
            {
                cout << n*(n-1)*(n-3) << endl;
            }
        }
        else
        {
            cout << n*(n-1)*(n-2) << endl;
        }
        
    }

    return 0;
}