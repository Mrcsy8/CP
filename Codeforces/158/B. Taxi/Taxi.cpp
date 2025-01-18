#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count[4] = {0};
    int s;
    for(int i = 0; i < n; i ++)
    {
        cin >> s;
        count[s-1] ++;
    }
    int tot_count = count[3] + count[2] + ceil((float)count[1]/2);
    int open_spaces = count[2] + count[1]%2*2;
    if(open_spaces < count[0])
    {
       tot_count += ceil((float)(count[0]-open_spaces)/4);
    }

    cout << tot_count << endl;
    return 0;
}