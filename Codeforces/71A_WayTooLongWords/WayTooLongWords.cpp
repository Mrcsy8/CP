#include <bits/stdc++.h>

using namespace std;

string convert(string word)
{
    int length = word.length();
    if(length <= 10)
    {
        return word;
    }
    return word[0] + to_string(length-2) + word[length - 1];
}

int main()
{
    int n;
    cin >> n;
    queue <string> abb;
    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        abb.push(convert(word));
    }
    int abb_size = abb.size();
    for(int i = 0; i < abb_size; i++)
    {
        cout << abb.front() << endl;
        abb.pop();
    }

    return 0;
}