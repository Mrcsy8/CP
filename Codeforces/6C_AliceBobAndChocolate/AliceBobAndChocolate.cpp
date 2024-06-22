#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    deque<int> t;
    int input;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        sum += input;
        t.push_back(input);
    }
    int half = sum / 2;

    int time_a = 0, time_b = 0;
    int count_a = 0, count_b = 0;
    while(1)
    {
        time_a += t.front();
        if(time_a <= half)
        {
            count_a ++;
            t.pop_front();
        }
        else
        {
            time_a -= t.front();
            break;
        }
    }
    while(1)
    {
        time_b += t.back();
        if(time_b <= half)
        {
            count_b ++;
            t.pop_back();
        }
        else
        {
            time_b -= t.front();
            break;
        }
    }
    if(time_a + time_b != sum)
    {
        if(time_a > time_b)
        {
            count_b ++;
        }
        else
        {
            count_a ++;
        }
    }
    
    
    printf("%d %d\n", count_a, count_b);

    return 0;
}