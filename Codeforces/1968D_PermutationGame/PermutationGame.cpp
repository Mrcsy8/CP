#include<bits/stdc++.h>
 
using namespace std;
 
#define REP(i, a, b) for(int i = a; i < b; i++)

vector<int> p_i, result;
vector<long long> a_i;

void calc_score(vector<long long> &scores, int pos, long long k, vector<bool> &visited)
{
    if(visited[pos] || !k)
    {
        return;
    }
    visited[pos] = true;
    scores.push_back(a_i[pos]+scores.back());
    calc_score(scores, p_i[pos]-1, k-1, visited);
}
long long max_score(vector<long long> &scores, int k)
{
    int size = scores.size();
    long long max_score = scores[size-1] + (k+1-size)*(scores[size-1] - scores[size-2]);
    long long stay_score;
    for(int i = 1; i < size; i++)
    {
        stay_score = scores[i-1] + (scores[i] - scores[i-1])*(k-i+1);
        if(stay_score > max_score)
        {
            max_score = stay_score;
        }
    }
    return max_score;
}

int main()
{
    int t;
    cin >> t;

    REP(i,0,t)
    {
        int n, pb, ps;
        long long k;
        cin >> n >> k >> pb >> ps;
        p_i.resize(n);
        a_i.resize(n);
        REP(j, 0, n)
        {
            cin >> p_i[j];
        }
        REP(j, 0, n)
        {
            cin >> a_i[j];
        }
        vector<long long> scores(1,0);
        vector<bool> visited(n,false);
        calc_score(scores, pb-1, k, visited);
        long long score_b = max_score(scores, k);

        scores.assign(1,0);
        visited.assign(n,0);
        calc_score(scores, ps-1, k, visited);
        long long score_s = max_score(scores, k);

        if(score_b > score_s)
        {
            result.push_back({1});
        }
        else if(score_b < score_s)
        {
            result.push_back({2});
        }
        else
        {
            result.push_back({0});
        }
        p_i.clear();
        a_i.clear();
    }
    for(auto i: result)
    {
        switch(i)
        {
            case 0:
            cout << "Draw\n";
            break;
            case 1:
            cout << "Bodya\n";
            break;
            case 2:
            cout << "Sasha\n";
        }
    }
    return 0;
}