#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<string> names;
    unordered_map<string, int> names_data;

    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        names.push(input);
    }

    for(int i = 0; i < n; i++)
    {
        string name = names.front();
        names.pop();
        int number = names_data[name];
        if(number != 0)
        {
            cout << name << number << "\n";
        }
        else
        {
            cout << "OK\n";
        }
        names_data[name] ++;
    }
}