#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

vector<vector<int>> rectangles_inside;

int num_inside_rectangles(int n, int m, int k)
{
    if(k == 1)
    {
        return (((n-2)*(n-1))/2)*(((m-2)*(m-1))/2);
    }
    else
    {
        int sum = 0;
        for(int i = 1 + (k-1) * 2; i <= n - 2; i++)
        {
            for(int j = 1 + (k-1) * 2; j <= m - 2; j++)
            {
                if(rectangles_inside[i][j] == -1)
                {
                    rectangles_inside[i][j] = (n-i-1)*(m-j-1)*num_inside_rectangles(i, j, k-1) % MOD;
                }
                sum += rectangles_inside[i][j] % MOD;
            }
        }
        return sum;
    }
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    rectangles_inside.resize(n);
    for(int i = 0; i < n; i++)
    {
        rectangles_inside[i].resize(m, {-1});
    }
    
    printf("%d\n", num_inside_rectangles(n, m, k));

    return 0;
}