vector<ll> factorial;
void fact_to_n(ll n){
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}

vector<ll> inverse_factorial;
void inv_fact_to_n(ll n){
    inverse_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inverse_factorial[i] = inverse_factorial[i + 1] * (i + 1) % MOD;
}

ll comb_num(ll n, ll m){
    return (factorial[n] * inverse_factorial[n - m] % MOD) * inverse_factorial[m] % MOD;
}