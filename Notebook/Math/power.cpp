const ll MOD = 1e9 + 7;
ll power(ll a, ll b){
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll p = power(a, b / 2);
        return p * p % MOD;
    }
    else
    {
        ll p = power(a, (b - 1) / 2);
        return p * p % MOD * a % MOD;
    }
}