#include <bits/stdc++.h>

using namespace std;

int main()
{
    string players;
    cin >> players;

    int length = players.length();
    char last = players[0];
    int count = 1;
    for(int i = 1; i < length; i++)
    {
        if(players[i] == last)
        {
            count ++;
        }
        else
        {
            last = players[i];
            count = 1;
        }
        if(count == 7)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}