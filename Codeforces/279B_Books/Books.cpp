#include <bits/stdc++.h>

using namespace std;

int search(vector<int> A, int time)
{
    int n = int(A.size());
    
    int max_size = 0;
    int sum_time = 0;

    int j = 0;

    for(int i = 0; i < n; i++)
    {

        while (j < n && sum_time + A[j] <= time)
        {
            sum_time += A[j];
            j++;
        }

        int size_ij = j-i;
        if(max_size < size_ij)
        {
            max_size = size_ij;
        }
        sum_time -= A[i];
    }
    return max_size;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    vector<int> books;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        books.push_back(a);
    }

    printf("%d\n", search(books, t));

    return 0;
}