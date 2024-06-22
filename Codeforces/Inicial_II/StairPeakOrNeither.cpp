#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);


    if(a > b)
    {
        printf("NONE");
    }
    else if(c > b)
    {
        printf("STAIR");
    }
    else
    {   
        printf("PEAK");
    }
    return 0;
}