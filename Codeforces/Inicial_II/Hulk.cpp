#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 1)
        {
            printf("I hate ");
        }
        else
        {
            printf("I love ");
        }
        printf("that ");
    }
    if(n % 2 == 1)
    {
        printf("I hate ");
    }
    else
    {
        printf("I love ");
    }
    printf("it\n");


    return 0;
}