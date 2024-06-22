#include <bits/stdc++.h>

using namespace std;

char last_line_painted(char grid[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        if(grid[i][0] == '.') continue;
        for(int j = 1; j < 8; j++)
        {
            if(grid[i][j] != grid[i][j-1])
            {
                break;
            }
            else if(j == 7)
            {
                return grid[i][j];
            }
        }
    }
    for(int i = 0; i < 8; i++)
    {
        if(grid[0][i] == '.') continue;
        for(int j = 1; j < 8; j++)
        {
            if(grid[j][i] != grid[j-1][i])
            {
                break;
            }
            else if(j == 7)
            {
                return grid[j][i];
            }
        }
    }
    return ' ';
}

int main()
{
    int t;
    cin >> t;


    char grid[8][8];
    vector<char> results;
    
    for(int i = 0; i < t; i++)
    {
        string line;
        
        for(int j = 0; j < 8; j++)
        {
            cin >> line;
            for(int k = 0; k < 8; k++)
            {
                grid[j][k] = line[k];
            }
        }
        
        results.push_back(last_line_painted(grid));
    }

    
    for(auto i : results)
    {
        printf("%c\n", i);
    }


    return 0;
}