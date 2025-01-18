#include <bits/stdc++.h>

using namespace std;

vector<int> knights;
set<int> alive;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    knights.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        alive.insert(i);
    }
    
    for(int i = 0; i < m; i++)
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--;
        r--;
        x--;

        auto it = alive.lower_bound(l);
        while (it != alive.end() && *it <= r)
        {
            if (*it != x)
            {
                knights[*it] = x + 1;
                it = alive.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
    
    for(auto i : knights)
    {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}