#include<bits/stdc++.h>

using namespace std;

bool check_cons(char letter)
{
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y')
    {
        return 0;
    }
    return 1;
}

int main()
{
    string word;
    cin >> word;

    int length = word.length();

    for(int i = 0; i < length; i++)
    {
        word[i] = tolower(word[i]);
        if(check_cons(word[i]))
        {
            cout << "." << word[i];
        }
    }
    cout << endl;

    return 0;
}