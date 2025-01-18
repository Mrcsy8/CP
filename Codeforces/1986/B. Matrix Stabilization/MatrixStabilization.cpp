#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

void stabilize(vector<vector<ll>> &matrix, int &n, int &m)
{
    bool change = true;
    while(change)
    {
        change = false;
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < m; j++)
            {                
                ll up, down, left, right;
                if(i == 0)
                {
                    up = -1;
                }
                else
                {
                    up = matrix[i-1][j];
                }
                if(i == n-1)
                {
                    down = -1;
                }
                else
                {
                    down = matrix[i+1][j];
                }
                if(j == 0)
                {
                    left = -1;
                }
                else
                {
                    left = matrix[i][j-1];
                } 
                if(j == m-1)
                {
                    right = -1;
                }
                else
                {
                    right = matrix[i][j+1];
                }
                ll maxim = max({up,down,right,left});
                if(maxim < matrix[i][j])
                {
                    change = true;
                    matrix[i][j] = maxim;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> matrix(n);
        for(int i = 0; i < n; i++)
        {
            matrix[i].resize(m);
            for(int j = 0; j < m; j++)
            {
                ll a;
                cin >> a;
                matrix[i][j] = a;
            }
        }
        stabilize(matrix, n, m);
        for(auto i : matrix)
        {
            for(auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}