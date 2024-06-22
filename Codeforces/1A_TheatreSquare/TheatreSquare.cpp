#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;

    cout << (long long)(ceil((long double)n/a)*ceil((long double)m/a));

    return 0;
}